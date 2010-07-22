//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Scene.h"
#include                       "RaycastObjects.h"
#include                       "nxlist.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public interface class          ISceneQueryReport
  {
    public:
      QueryReportResults        OnBooleanQuery(Object^ UserData, bool Result);
      QueryReportResults        OnRaycastQuery(Object^ UserData, ReadOnlyCollection<RaycastHit>^ Hits);
      QueryReportResults        OnShapeQuery(Object^ UserData, ReadOnlyCollection<Shape^>^ Hits);
      QueryReportResults        OnSweepQuery(Object^ UserData, ReadOnlyCollection<SweepQueryHit>^ Hits);
  };

//=============================+=====================================+=
class                           giSceneQueryReport:                   public NxSceneQueryReport
  {
    public:
      gcroot<ISceneQueryReport^> Report;

      giSceneQueryReport(ISceneQueryReport^ Report): Report( Report ) { }

    private:
      inline static Object^     ToUserData(void* userData);
        //{
        //  return userData ? *static_cast<gcroot<Object^>*>( userData ) : nullptr;
        //}

      NxQueryReportResult        onBooleanQuery(void* userData, bool result)
        {
          return static_cast<NxQueryReportResult>( Report->OnBooleanQuery( ToUserData( userData ), result ) );
        }

      NxQueryReportResult        onRaycastQuery(void* userData, NxU32 nbHits, const NxRaycastHit* hits)
        {
          typedef giNxStaticList<RaycastHit, const NxRaycastHit, RaycastHit> RaycastList;

          RaycastList^        list   = gcnew RaycastList( hits, nbHits );
          NxQueryReportResult result = static_cast<NxQueryReportResult>( Report->OnRaycastQuery( ToUserData( userData ), list ) );

          delete list;
          return result;
        }

      NxQueryReportResult        onShapeQuery(void* userData, NxU32 nbHits, NxShape** hits)
        {
          typedef giNxStaticList<Shape, NxShape*> ShapeList;

          ShapeList^          list   = gcnew ShapeList( hits, nbHits );
          NxQueryReportResult result = static_cast<NxQueryReportResult>( Report->OnShapeQuery( ToUserData( userData ), list ) );

          delete list;
          return result;
        }

      NxQueryReportResult        onSweepQuery(void* userData, NxU32 nbHits, NxSweepQueryHit* hits)
        {
          typedef giNxStaticList<SweepQueryHit, NxSweepQueryHit, SweepQueryHit> SweepQueryList;

          SweepQueryList^     list   = gcnew SweepQueryList( hits, nbHits );
          NxQueryReportResult result = static_cast<NxQueryReportResult>( Report->OnSweepQuery( ToUserData( userData ), list ) );

          delete list;
          return result;
        }
  };

//=============================+=====================================+=
public ref struct               SceneQueryDesc:                       public giNxData<NxSceneQueryDesc>
  {
    internal:
      ISceneQueryReport^        report;

      const NxSceneQueryDesc&   Update()
        {
          if( report == nullptr ) throw gcnew Exception();

          data->report = new giSceneQueryReport( report );
          return *data;
        }

    public:
      SceneQueryDesc() { }
      SceneQueryDesc(ISceneQueryReport^ Report, SceneQueryExecuteModes ExecuteMode) { this->Report = Report; this->ExecuteMode = ExecuteMode; }

    public:
                                DefValidDefaultX( report = nullptr; data->setToDefault(); PostSet(); )

    public:
      property
      SceneQueryExecuteModes    ExecuteMode
        {
          SceneQueryExecuteModes get()                                { return static_cast<SceneQueryExecuteModes>( data->executeMode ); }
          void                   set(SceneQueryExecuteModes v)        { data->executeMode = static_cast<NxSceneQueryExecuteMode>( v ); }
        }

      property
      ISceneQueryReport^        Report
        {
          ISceneQueryReport^    get()                                 { return report; }
          void                  set(ISceneQueryReport^ v)             { report = v; }
        }
  };

//=============================+=====================================+=
private struct                  DeleteItem
  {
    gcroot<Object^>             root;
    DeleteItem*                 next;          
    
    DeleteItem(SceneQuery^ q, Object^ obj);
  };
  
//=============================+=====================================+=
public ref class                SceneQuery:                           public giNxProxy<NxSceneQuery, giNxRegisteredObject<Scene> >
  {
    internal:
      typedef                   ThisNamespace::Scene                  giScene;
      typedef                   ThisNamespace::Sphere                 giSphere;
      typedef                   ThisNamespace::AxisAlignedBox         giAABB;
      typedef                   ThisNamespace::Capsule                giCapsule;
      typedef                   ThisNamespace::OrientedBox            giOBB;
      typedef                   ThisNamespace::GroupsMask             giGroupsMask;

      ref struct                PlaneHolder
        {
            NxPlane*            ps;

            PlaneHolder(int count) { ps = new NxPlane[count]; }

            ~PlaneHolder() { this->!PlaneHolder(); }
            !PlaneHolder() { delete[] ps; ps = 0; }
        };

      List<PlaneHolder^>^       planeholderstodelete;

    internal:
      NxScene*                  scenebackupptr;
      giSceneQueryReport*       reportbackupptr;

      SceneQuery(giScene^ Scene, NxSceneQuery* data):
        giNxProxy( data ), todelete( 0 )
        {
          scenebackupptr  = Scene->ptr;
          reportbackupptr = static_cast<giSceneQueryReport*>( data->getQueryReport() );

          planeholderstodelete = gcnew List<PlaneHolder^>();

          Register( Scene );
        }

    public:
      ~SceneQuery()
        {
          if( !data ) return;

          Unregister();

          scenebackupptr->releaseSceneQuery( *data ); // always need to release explicitly, else a potentially active report object may get deleted before scene is disposed
          //
          DeferredDelete();
          //
          delete planeholderstodelete;
          //
          this->!SceneQuery();
        }
        
      !SceneQuery()
        {
          DeleteItems();
          //delete todelete;
          delete reportbackupptr; reportbackupptr = 0;
          //
          scenebackupptr = 0;
        }

    internal:
      DeleteItem*               todelete;
        
    private:
      void                      DeleteItems() // deletes all unmanaged wrappers for userdatas used since last Finish
        {
          while( todelete )
          {
            DeleteItem* next = todelete->next;
            //
            delete todelete;
            //
            todelete = next;
          }
        }

      void                      DeferredDelete() 
        {
          DeleteItems();
          //
          planeholderstodelete->Clear();
        }
        
      void*                     Wrap(Object^ UserData) // allows managed userdatas to travel through unmanaged callback maze
        {
          if( UserData == nullptr ) return 0;

          return new DeleteItem( this, UserData );
        }

    public:
      property giScene^         Scene
        {
          giScene^              get()                                 { return Owner; }
        }

      property
      ISceneQueryReport^        Report
        {
          ISceneQueryReport^    get()                                 { return reportbackupptr->Report; }
        }

      property
      SceneQueryExecuteModes    ExecuteMode
        {
          SceneQueryExecuteModes get()                                { return static_cast<SceneQueryExecuteModes>( data->getExecuteMode() ); }
        }

      void                      Execute()
        {
          data->execute();
          if( ExecuteMode == SceneQueryExecuteModes::Synchronous ) DeferredDelete();
        }

      bool                      Finish()                              { return Finish( false ); }
      bool                      Finish(bool Block)
        {
          if( !data->finish( Block ) ) return false;
          DeferredDelete();
          return true;
        }

    public:

      //-------------------------------------------------------------
      //-------------------------------------------------------------
      //-------------------------------------------------------------

      bool                      CheckOverlapAABB(giAABB AABox, ShapesTypes Types)                                                  { return CheckOverlapAABB( AABox, Types, 0xFFFFFFFF ); }
      bool                      CheckOverlapAABB(giAABB AABox, ShapesTypes Types, unsigned ActiveGroups)                           { return CheckOverlapAABB( AABox, Types, ActiveGroups, nullptr ); }
      bool                      CheckOverlapAABB(giAABB AABox, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask) { return CheckOverlapAABB( AABox, Types, ActiveGroups, GroupsMask, nullptr ); }
      bool                      CheckOverlapAABB(giAABB AABox, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask, Object^ UserData)
        {
          return data->checkOverlapAABB( ToNx( AABox ), static_cast<NxShapesType>( Types ), ActiveGroups, GroupsMask == nullptr ? 0 : GroupsMask->data, Wrap( UserData ) );
        }

      bool                      CheckOverlapCapsule(giCapsule Capsule, ShapesTypes Types)                                                  { return CheckOverlapCapsule( Capsule, Types, 0xFFFFFFFF ); }
      bool                      CheckOverlapCapsule(giCapsule Capsule, ShapesTypes Types, unsigned ActiveGroups)                           { return CheckOverlapCapsule( Capsule, Types, ActiveGroups, nullptr ); }
      bool                      CheckOverlapCapsule(giCapsule Capsule, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask) { return CheckOverlapCapsule( Capsule, Types, ActiveGroups, GroupsMask, nullptr ); }
      bool                      CheckOverlapCapsule(giCapsule Capsule, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask, Object^ UserData)
        {
          return data->checkOverlapCapsule( ToNx( Capsule ), static_cast<NxShapesType>( Types ), ActiveGroups, GroupsMask == nullptr ? 0 : GroupsMask->data, Wrap( UserData ) );
        }

      bool                      CheckOverlapSphere(giSphere Sphere, ShapesTypes Types)                                                   { return CheckOverlapSphere( Sphere, Types, 0xFFFFFFFF ); }
      bool                      CheckOverlapSphere(giSphere Sphere, ShapesTypes Types, unsigned ActiveGroups)                            { return CheckOverlapSphere( Sphere, Types, ActiveGroups, nullptr ); }
      bool                      CheckOverlapSphere(giSphere Sphere, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask)  { return CheckOverlapSphere( Sphere, Types, ActiveGroups, GroupsMask, nullptr ); }
      bool                      CheckOverlapSphere(giSphere Sphere, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask, Object^ UserData)
        {
          return data->checkOverlapSphere( ToNx( Sphere ), static_cast<NxShapesType>( Types ), ActiveGroups, GroupsMask == nullptr ? 0 : GroupsMask->data, Wrap( UserData ) );
        }

      bool                      CheckOverlapOBB(giOBB Box, ShapesTypes Types)                                                  { return CheckOverlapOBB( Box, Types, 0xFFFFFFFF ); }
      bool                      CheckOverlapOBB(giOBB Box, ShapesTypes Types, unsigned ActiveGroups)                           { return CheckOverlapOBB( Box, Types, ActiveGroups, nullptr ); }
      bool                      CheckOverlapOBB(giOBB Box, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask) { return CheckOverlapOBB( Box, Types, ActiveGroups, GroupsMask, nullptr ); }
      bool                      CheckOverlapOBB(giOBB Box, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask, Object^ UserData)
        {
          return data->checkOverlapOBB( ToNx( Box ), static_cast<NxShapesType>( Types ), ActiveGroups, GroupsMask == nullptr ? 0 : GroupsMask->data, Wrap( UserData ) );
        }


      //-------------------------------------------------------------
      //-------------------------------------------------------------
      //-------------------------------------------------------------

      unsigned                  OverlapAABBShapes(giAABB AABox, ShapesTypes Types)                                                  { return OverlapAABBShapes( AABox, Types, 0xFFFFFFFF ); }
      unsigned                  OverlapAABBShapes(giAABB AABox, ShapesTypes Types, unsigned ActiveGroups)                           { return OverlapAABBShapes( AABox, Types, ActiveGroups, nullptr ); }
      unsigned                  OverlapAABBShapes(giAABB AABox, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask) { return OverlapAABBShapes( AABox, Types, ActiveGroups, GroupsMask, nullptr ); }
      unsigned                  OverlapAABBShapes(giAABB AABox, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask, Object^ UserData)
        {
          return data->overlapAABBShapes( ToNx( AABox ), static_cast<NxShapesType>( Types ), ActiveGroups, GroupsMask == nullptr ? 0 : GroupsMask->data, Wrap( UserData ) );
        }

      unsigned                  OverlapCapsuleShapes(giCapsule Capsule, ShapesTypes Types)                                                  { return OverlapCapsuleShapes( Capsule, Types, 0xFFFFFFFF ); }
      unsigned                  OverlapCapsuleShapes(giCapsule Capsule, ShapesTypes Types, unsigned ActiveGroups)                           { return OverlapCapsuleShapes( Capsule, Types, ActiveGroups, nullptr ); }
      unsigned                  OverlapCapsuleShapes(giCapsule Capsule, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask) { return OverlapCapsuleShapes( Capsule, Types, ActiveGroups, GroupsMask, nullptr ); }
      unsigned                  OverlapCapsuleShapes(giCapsule Capsule, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask, Object^ UserData)
        {
          return data->overlapCapsuleShapes( ToNx( Capsule ), static_cast<NxShapesType>( Types ), ActiveGroups, GroupsMask == nullptr ? 0 : GroupsMask->data, Wrap( UserData ) );
        }

      unsigned                  OverlapSphereShapes(giSphere Sphere, ShapesTypes Types)                                                   { return OverlapSphereShapes( Sphere, Types, 0xFFFFFFFF ); }
      unsigned                  OverlapSphereShapes(giSphere Sphere, ShapesTypes Types, unsigned ActiveGroups)                            { return OverlapSphereShapes( Sphere, Types, ActiveGroups, nullptr ); }
      unsigned                  OverlapSphereShapes(giSphere Sphere, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask)  { return OverlapSphereShapes( Sphere, Types, ActiveGroups, GroupsMask, nullptr ); }
      unsigned                  OverlapSphereShapes(giSphere Sphere, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask, Object^ UserData)
        {
          return data->overlapSphereShapes( ToNx( Sphere ), static_cast<NxShapesType>( Types ), ActiveGroups, GroupsMask == nullptr ? 0 : GroupsMask->data, Wrap( UserData ) );
        }

      unsigned                  OverlapOBBShapes(giOBB Box, ShapesTypes Types)                                                  { return OverlapOBBShapes( Box, Types, 0xFFFFFFFF ); }
      unsigned                  OverlapOBBShapes(giOBB Box, ShapesTypes Types, unsigned ActiveGroups)                           { return OverlapOBBShapes( Box, Types, ActiveGroups, nullptr ); }
      unsigned                  OverlapOBBShapes(giOBB Box, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask) { return OverlapOBBShapes( Box, Types, ActiveGroups, GroupsMask, nullptr ); }
      unsigned                  OverlapOBBShapes(giOBB Box, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask, Object^ UserData)
        {
          return data->overlapOBBShapes( ToNx( Box ), static_cast<NxShapesType>( Types ), ActiveGroups, GroupsMask == nullptr ? 0 : GroupsMask->data, Wrap( UserData ) );
        }


      //-------------------------------------------------------------
      //-------------------------------------------------------------
      //-------------------------------------------------------------

      bool                      RaycastAnyShape(Line Ray, ShapesTypes Which)                                                                { return RaycastAnyShape( Ray, Which, 0xFFFFFFFF ); }
      bool                      RaycastAnyShape(Line Ray, ShapesTypes Which, unsigned Groups)                                               { return RaycastAnyShape( Ray, Which, Groups, NX_MAX_F32 ); }
      bool                      RaycastAnyShape(Line Ray, ShapesTypes Which, unsigned Groups, float MaxDistance)                            { return RaycastAnyShape( Ray, Which, Groups, MaxDistance, nullptr ); }
      bool                      RaycastAnyShape(Line Ray, ShapesTypes Which, unsigned Groups, float MaxDistance, giGroupsMask^ GroupsMask ) { return RaycastAnyShape( Ray, Which, Groups, MaxDistance, GroupsMask, nullptr ); }
      bool                      RaycastAnyShape(Line Ray, ShapesTypes Which, unsigned Groups, float MaxDistance, giGroupsMask^ GroupsMask, Object^ UserData)
        {
          return data->raycastAnyShape( ToNx( Ray ), static_cast<NxShapesType>( Which ), Groups, MaxDistance, GroupsMask == nullptr ? 0 : GroupsMask->data, 0, Wrap( UserData ) );
        }


      //-------------------------------------------------------------
      //-------------------------------------------------------------
      //-------------------------------------------------------------

      Shape^                    RaycastClosestShape(Line Ray, ShapesTypes Which, [Out] RaycastHit% Hit)                                                                                  { return RaycastClosestShape( Ray, Which, Hit, 0xFFFFFFFF ); }
      Shape^                    RaycastClosestShape(Line Ray, ShapesTypes Which, [Out] RaycastHit% Hit, unsigned Groups)                                                                 { return RaycastClosestShape( Ray, Which, Hit, Groups, NX_MAX_F32 ); }
      Shape^                    RaycastClosestShape(Line Ray, ShapesTypes Which, [Out] RaycastHit% Hit, unsigned Groups, float MaxDistance)                                              { return RaycastClosestShape( Ray, Which, Hit, Groups, MaxDistance, RaycastBits::All ); }
      Shape^                    RaycastClosestShape(Line Ray, ShapesTypes Which, [Out] RaycastHit% Hit, unsigned Groups, float MaxDistance, RaycastBits Bits)                            { return RaycastClosestShape( Ray, Which, Hit, Groups, MaxDistance, Bits, nullptr ); }
      Shape^                    RaycastClosestShape(Line Ray, ShapesTypes Which, [Out] RaycastHit% Hit, unsigned Groups, float MaxDistance, RaycastBits Bits, giGroupsMask^ GroupsMask)  { return RaycastClosestShape( Ray, Which, Hit, Groups, MaxDistance, Bits, GroupsMask, nullptr ); }
      Shape^                    RaycastClosestShape(Line Ray, ShapesTypes Which, [Out] RaycastHit% Hit, unsigned Groups, float MaxDistance, RaycastBits Bits, giGroupsMask^ GroupsMask, Object^ UserData)
        {
          NxRaycastHit hit;
          Shape^       result = Shape::CastOrNull( data->raycastClosestShape( ToNx( Ray ), static_cast<NxShapesType>( Which ), hit, Groups, MaxDistance, static_cast<NxRaycastBit>( Bits ), GroupsMask == nullptr ? 0 : GroupsMask->data, 0, Wrap( UserData ) ) );

          Hit = RaycastHit( hit );
          return result;
        }


      //-------------------------------------------------------------
      //-------------------------------------------------------------
      //-------------------------------------------------------------

      unsigned                  RaycastAllShapes(Line Ray, ShapesTypes Which)                                                                                  { return RaycastAllShapes( Ray, Which, 0xFFFFFFFF ); }
      unsigned                  RaycastAllShapes(Line Ray, ShapesTypes Which, unsigned Groups)                                                                 { return RaycastAllShapes( Ray, Which, Groups, NX_MAX_F32 ); }
      unsigned                  RaycastAllShapes(Line Ray, ShapesTypes Which, unsigned Groups, float MaxDistance)                                              { return RaycastAllShapes( Ray, Which, Groups, MaxDistance, RaycastBits::All ); }
      unsigned                  RaycastAllShapes(Line Ray, ShapesTypes Which, unsigned Groups, float MaxDistance, RaycastBits Bits)                            { return RaycastAllShapes( Ray, Which, Groups, MaxDistance, Bits, nullptr ); }
      unsigned                  RaycastAllShapes(Line Ray, ShapesTypes Which, unsigned Groups, float MaxDistance, RaycastBits Bits, giGroupsMask^ GroupsMask)  { return RaycastAllShapes( Ray, Which, Groups, MaxDistance, Bits, GroupsMask, nullptr ); }
      unsigned                  RaycastAllShapes(Line Ray, ShapesTypes Which, unsigned Groups, float MaxDistance, RaycastBits Bits, giGroupsMask^ GroupsMask, Object^ UserData)
        {
          return data->raycastAllShapes( ToNx( Ray ), static_cast<NxShapesType>( Which ), Groups, MaxDistance, static_cast<NxRaycastBit>( Bits ), GroupsMask == nullptr ? 0 : GroupsMask->data, Wrap( UserData ) );
        }


      //-------------------------------------------------------------
      //-------------------------------------------------------------
      //-------------------------------------------------------------

    internal:
      template<typename T>
      unsigned                  DoCullShapes(T Planes, int count, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask, Object^ UserData)
        {
          PlaneHolder^ ps = gcnew PlaneHolder( count );

          for( int i = 0; i < count; i++ )
            ps->ps[i] = ToNx( Planes[i] );

          unsigned result = data->cullShapes( count, ps->ps, static_cast<NxShapesType>( Types ), ActiveGroups, GroupsMask == nullptr ? 0 : GroupsMask->data, Wrap( UserData ) );

          planeholderstodelete->Add( ps );
          return result;
        }

    public:
      unsigned                  CullShapes(array<Plane>^ Planes, ShapesTypes Types)                                                   { return CullShapes( Planes, Types, 0xFFFFFFFF ); }
      unsigned                  CullShapes(array<Plane>^ Planes, ShapesTypes Types, unsigned ActiveGroups)                            { return CullShapes( Planes, Types, ActiveGroups, nullptr ); }
      unsigned                  CullShapes(array<Plane>^ Planes, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask)  { return CullShapes( Planes, Types, ActiveGroups, GroupsMask, nullptr ); }
      unsigned                  CullShapes(array<Plane>^ Planes, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask, Object^ UserData)
        {
          return DoCullShapes( Planes, Planes->Length, Types, ActiveGroups, GroupsMask, UserData );
        }

      unsigned                  CullShapes(IList<Plane>^ Planes, ShapesTypes Types)                                                   { return CullShapes( Planes, Types, 0xFFFFFFFF ); }
      unsigned                  CullShapes(IList<Plane>^ Planes, ShapesTypes Types, unsigned ActiveGroups)                            { return CullShapes( Planes, Types, ActiveGroups, nullptr ); }
      unsigned                  CullShapes(IList<Plane>^ Planes, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask)  { return CullShapes( Planes, Types, ActiveGroups, GroupsMask, nullptr ); }
      unsigned                  CullShapes(IList<Plane>^ Planes, ShapesTypes Types, unsigned ActiveGroups, giGroupsMask^ GroupsMask, Object^ UserData)
        {
          return DoCullShapes( Planes, Planes->Count, Types, ActiveGroups, GroupsMask, UserData );
        }

      //-------------------------------------------------------------
      //-------------------------------------------------------------
      //-------------------------------------------------------------

      unsigned                  LinearOBBSweep(giOBB Box, Vector3 Motion, SweepFlags Flags)                                                   { return LinearOBBSweep( Box, Motion, Flags, 0xFFFFFFFF ); }
      unsigned                  LinearOBBSweep(giOBB Box, Vector3 Motion, SweepFlags Flags, unsigned ActiveGroups)                            { return LinearOBBSweep( Box, Motion, Flags, ActiveGroups, nullptr ); }
      unsigned                  LinearOBBSweep(giOBB Box, Vector3 Motion, SweepFlags Flags, unsigned ActiveGroups, giGroupsMask^ GroupsMask)  { return LinearOBBSweep( Box, Motion, Flags, ActiveGroups, GroupsMask, nullptr ); }
      unsigned                  LinearOBBSweep(giOBB Box, Vector3 Motion, SweepFlags Flags, unsigned ActiveGroups, giGroupsMask^ GroupsMask, Object^ UserData)
        {
          return data->linearOBBSweep( ToNx( Box ), ToNx( Motion ), static_cast<NxSweepFlags>( Flags ), ActiveGroups, GroupsMask == nullptr ? 0 : GroupsMask->data, Wrap( UserData ) );
        }

      unsigned                  LinearCapsuleSweep(giCapsule Capsule, Vector3 Motion, SweepFlags Flags)                                                   { return LinearCapsuleSweep( Capsule, Motion, Flags, 0xFFFFFFFF ); }
      unsigned                  LinearCapsuleSweep(giCapsule Capsule, Vector3 Motion, SweepFlags Flags, unsigned ActiveGroups)                            { return LinearCapsuleSweep( Capsule, Motion, Flags, ActiveGroups, nullptr ); }
      unsigned                  LinearCapsuleSweep(giCapsule Capsule, Vector3 Motion, SweepFlags Flags, unsigned ActiveGroups, giGroupsMask^ GroupsMask)  { return LinearCapsuleSweep( Capsule, Motion, Flags, ActiveGroups, GroupsMask, nullptr ); }
      unsigned                  LinearCapsuleSweep(giCapsule Capsule, Vector3 Motion, SweepFlags Flags, unsigned ActiveGroups, giGroupsMask^ GroupsMask, Object^ UserData)
        {
          return data->linearCapsuleSweep( ToNx( Capsule ), ToNx( Motion ), static_cast<NxSweepFlags>( Flags ), ActiveGroups, GroupsMask == nullptr ? 0 : GroupsMask->data, Wrap( UserData ) );
        }
  };

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
                         inline DeleteItem::DeleteItem(SceneQuery^ q, Object^ obj):
                          root( obj )
  {
    this->next = q->todelete;
    //
    q->todelete = this;
  }

//=============================+=====================================+=
inline Object^                  giSceneQueryReport::ToUserData(void* userData)
  {
    return userData ? static_cast<DeleteItem*>( userData )->root : nullptr;
  }

//=============================+=====================================+=
SceneQuery^                     Scene::CreateSceneQuery(SceneQueryDesc^ Desc)
  {
    NxSceneQuery* scenequeryptr = ptr->createSceneQuery( Desc->Update() );
    return scenequeryptr ? gcnew SceneQuery( this, scenequeryptr ) : nullptr;
  }
