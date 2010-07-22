//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "PhysicsCollection.h"
#include                       "Physics.h"
#include                       "Scene.h"
#include                       "SceneDesc.h"
#include                       "Material.h"
#include                       "Joint.h"
#include                       "JointDesc.h"
#include                       "Actor.h"
#include                       "ActorDesc.h"
#include                       "Shape.h"
#include                       "SimpleTriangleMesh.h"
#include                       "TriangleMesh.h"
#include                       "ConvexMesh.h"
#include                       "HeightField.h"
#include                       "ClothMesh.h"
#include                       "ClothDesc.h"
#include                       "Cloth.h"
#include                       "FluidDesc.h"
#include                       "Fluid.h"
#include                       "SoftBodyMesh.h"
#include                       "SoftBody.h"
#include                       "EffectorDesc.h"
#include                       "Effector.h"
#include                       "ForceField.h"

//=============================+=====================================+=
typedef                         Dictionary<String^, String^>          PropsType;
typedef                         Dictionary<Shape^, PropsType^>        ShapePropsType;

//=============================+=====================================+=
#pragma warning( disable:       4100 )

//=============================+=====================================+=
public ref class                ThisNamespace::NxuNotify
  {
    public:
      virtual Scene^            PreNotifyScene(unsigned Index, SceneDesc^ Desc, PropsType^ UserProperties)                                                { return nullptr; }
      virtual bool              PreNotifySceneInstance(String^ Name, String^ SceneName, PropsType^ UserProperties, Matrix4x4% Transform, unsigned Depth)  { return true; }
      virtual void              NotifyScene(unsigned Index, Scene^ Scene, PropsType^ UserProperties)                                                      { }
      virtual void              NotifySceneFailed(unsigned Index, SceneDesc^ Desc, PropsType^ UserProperties)                                             { }

    public:
      virtual bool              PreNotifyMaterial(MaterialDesc^ Desc, PropsType^ UserProperties)    { return true; }
      virtual void              NotifyMaterial(Material^ Material, PropsType^ UserProperties)       { }
      virtual void              NotifyMaterialFailed(MaterialDesc^ Desc, PropsType^ UserProperties) { }

    public:
      virtual bool              PreNotifyJoint(JointDesc^ Desc, PropsType^ UserProperties)    { return true; }
      virtual void              NotifyJoint(Joint^ Joint, PropsType^ UserProperties)          { }
      virtual void              NotifyJointFailed(JointDesc^ Desc, PropsType^ UserProperties) { }

    public:
      virtual bool              PreNotifyActor(ActorDesc^ Desc, PropsType^ UserProperties)                                { return true; }
      virtual void              NotifyActor(Actor^ Actor, PropsType^ UserProperties, ShapePropsType^ ShapeUserProperties) { }
      virtual void              NotifyActorFailed(ActorDesc^ Desc, PropsType^ UserProperties)                             { }
      //virtual void              NotifySaveActor(NxActor *pActor, const char** pUserProperties){}

    public:
      virtual bool              PreNotifyTriangleMesh(TriangleMeshDesc^ Desc, PropsType^ UserProperties)    { return true; }
      virtual void              NotifyTriangleMesh(TriangleMesh^ TriangleMesh, PropsType^ UserProperties)   { }
      virtual void              NotifyTriangleMeshFailed(TriangleMeshDesc^ Desc, PropsType^ UserProperties) { }

    public:
      virtual bool              PreNotifyConvexMesh(ConvexMeshDesc^ Desc, PropsType^ UserProperties)    { return true; }
      virtual void              NotifyConvexMesh(ConvexMesh^ ConvexMesh, PropsType^ UserProperties)     { }
      virtual void              NotifyConvexMeshFailed(ConvexMeshDesc^ Desc, PropsType^ UserProperties) { }

    public:
      virtual bool              PreNotifyCCDSkeleton(SimpleTriangleMesh^ Desc, PropsType^ UserProperties)     { return true; }
      virtual void              NotifyCCDSkeleton(CCDSkeleton^ Skeleton, PropsType^ UserProperties)           { }
      virtual void              NotifyCCDSkeletonFailed(SimpleTriangleMesh^ Desc, PropsType^ UserProperties)  { }

    public:
      virtual bool              PreNotifyHeightField(HeightFieldDesc^ Desc, PropsType^ UserProperties)    { return true; }
      virtual void              NotifyHeightField(HeightField^ Skeleton, PropsType^ UserProperties)       { }
      virtual void              NotifyHeightFieldFailed(HeightFieldDesc^ Desc, PropsType^ UserProperties) { }

    public:
      virtual bool              PreNotifyClothMesh(ClothMeshDesc^ Desc, PropsType^ UserProperties)    { return true; }
      virtual void              NotifyClothMesh(ClothMesh^ ClothMesh, PropsType^ UserProperties)      { }
      virtual void              NotifyClothMeshFailed(ClothMeshDesc^ Desc, PropsType^ UserProperties) { }

    public:
      virtual bool              PreNotifyCloth(ClothDesc^ Desc, PropsType^ UserProperties)    { return false; }
      virtual void              NotifyCloth(Cloth^ Cloth, PropsType^ UserProperties)          { }
      virtual void              NotifyClothFailed(ClothDesc^ Desc, PropsType^ UserProperties) { }

    public:
      virtual bool              PreNotifyFluid(FluidDesc^ Desc, PropsType^ UserProperties)    { return false; }
      virtual void              NotifyFluid(Fluid^ Fluid, PropsType^ UserProperties)          { }
      virtual void              NotifyFluidFailed(FluidDesc^ Desc, PropsType^ UserProperties) { }

    public:
      virtual bool              PreNotifySoftBodyMesh(SoftBodyMeshDesc^ Desc, PropsType^ UserProperties)    { return true; }
      virtual void              NotifySoftBodyMesh(SoftBodyMesh^ SoftBodyMesh, PropsType^ UserProperties)   { }
      virtual void              NotifySoftBodyMeshFailed(SoftBodyMeshDesc^ Desc, PropsType^ UserProperties) { }

    public:
      virtual bool              PreNotifySoftBody(SoftBodyDesc^ Desc, PropsType^ UserProperties)    { return false; }
      virtual void              NotifySoftBody(SoftBody^ SoftBody, PropsType^ UserProperties)       { }
      virtual void              NotifySoftBodyFailed(SoftBodyDesc^ Desc, PropsType^ UserProperties) { }

    public:
      virtual bool              PreNotifySpringAndDamperEffector(SpringAndDamperEffectorDesc^ Desc, PropsType^ UserProperties)              { return true; }
      virtual void              NotifySpringAndDamperEffector(SpringAndDamperEffector^ SpringAndDamperEffector, PropsType^ UserProperties)  { }
      virtual void              NotifySpringAndDamperEffectorFailed(SpringAndDamperEffectorDesc^ Desc, PropsType^ UserProperties)           { }

    public:
      virtual bool              PreNotifyForceField(ForceFieldDesc^ Desc, PropsType^ UserProperties)    { return true; }
      virtual void              NotifyForceField(ForceField^ Skeleton, PropsType^ UserProperties)       { }
      virtual void              NotifyForceFieldFailed(ForceFieldDesc^ Desc, PropsType^ UserProperties) { }
  };

//=============================+=====================================+=
class                           ThisNamespace::giNxuNotify:           public NXU_userNotify
  {
    private:
      PropsType^                Parse(const char* userProps)
        {
          unsigned int count;
          const char** props = NXU::parseUserProperties( userProps, count );

          PropsType^ Result = gcnew PropsType();

          for( unsigned int i = 0; i < count; i++ )
            Result->Add( gcnew String( props[2 * i + 0] ), gcnew String( props[2 * i + 1] ) );

          return Result;
        }

    private:
      gcroot<NxuNotify^>       iface;
      gcroot<Physics^>         physics;

    public:
      giNxuNotify(NxuNotify^ iface, Physics^ physics): iface( iface ), physics( physics ) { }

    private:
      //-------------------------------------------------------------
      //---------------------== Scene ==-----------------------------
      //-------------------------------------------------------------

      NxScene*                  NXU_preNotifyScene(unsigned  int  index, NxSceneDesc& desc, const char* userProperties)
        {
          SceneDesc^ Desc   = SceneDesc::Wrap( desc );
          Scene^     Result = iface->PreNotifyScene( index, Desc, Parse( userProperties ) );

          delete Desc;
          return Result == nullptr ? 0 : Result->ptr;
        }

      bool                       NXU_preNotifySceneInstance(const char* name, const char* sceneName, const char* userProperties, NxMat34& rootNode, NxU32 depth)
        {
          Matrix4x4 transform = FromNx( rootNode );
          if( !iface->PreNotifySceneInstance( FromNx( name ), FromNx( sceneName ), Parse( userProperties ), transform, depth ) ) return false;

          rootNode = ToNx( transform );
          return true;
        }

      void                      NXU_notifyScene(NxU32 index, NxScene* scene, const char* userProperties)
        {
          iface->NotifyScene( index, Scene::CastOrWrap( physics, scene ), Parse( userProperties ) );
        }

      void                      NXU_notifySceneFailed(unsigned int index, NxSceneDesc& desc, const char* userProperties)
        {
          SceneDesc^ Desc = SceneDesc::Wrap( desc );

          iface->NotifySceneFailed( index, Desc, Parse( userProperties ) );
          delete Desc;
        }


      //-------------------------------------------------------------
      //---------------------== Material ==--------------------------
      //-------------------------------------------------------------

      bool                       NXU_preNotifyMaterial(NxMaterialDesc& desc, const char* userProperties)
        {
          MaterialDesc^ Desc   = MaterialDesc::Wrap( desc );
          bool          result = iface->PreNotifyMaterial( Desc, Parse( userProperties ) );

          delete Desc;
          return result;
        }

      void                       NXU_notifyMaterial(NxMaterial* ptr, const char* userProperties)
        {
          Material^ m = ptr->userData ? Material::Cast( ptr ) : Material::CastOrWrap( ptr );
          iface->NotifyMaterial( m, Parse( userProperties ) );
        }

      void                       NXU_notifyMaterialFailed(NxMaterialDesc& desc, const char* userProperties)
        {
          MaterialDesc^ Desc = MaterialDesc::Wrap( desc );

          iface->NotifyMaterialFailed( Desc, Parse( userProperties ) );
          delete Desc;
        }


      //-------------------------------------------------------------
      //---------------------== Joint ==-----------------------------
      //-------------------------------------------------------------

      bool                      NXU_preNotifyJoint(NxJointDesc& desc, const char* userProperties)
        {
          JointDesc^ Desc   = JointDesc::Wrap( desc );
          bool       result = iface->PreNotifyJoint( Desc, Parse( userProperties ) );

          delete Desc;
          return result;
        }

      void                      NXU_notifyJoint(NxJoint* ptr, const char* userProperties)
        {
          iface->NotifyJoint( Joint::Wrap( ptr ), Parse( userProperties ) );
        }

      void                      NXU_notifyJointFailed(NxJointDesc& desc, const char* userProperties)
        {
          JointDesc^ Desc = JointDesc::Wrap( desc );

          iface->NotifyJointFailed( Desc, Parse( userProperties ) );
          delete Desc;
        }


      //-------------------------------------------------------------
      //---------------------== Actor ==-----------------------------
      //-------------------------------------------------------------

      bool                      NXU_preNotifyActor(NxActorDesc& desc, const char* userProperties)
        {
          ActorDesc^ Desc   = ActorDesc::Wrap( physics, desc );
          bool       result = iface->PreNotifyActor( Desc, Parse( userProperties ) );

          delete Desc;
          return result;
        }

      void                      NXU_notifyActor(NxActor* ptr, const char* userProperties)
        {
          unsigned        sc     = ptr->getNbShapes();
          NxShape *const* shapes = ptr->getShapes();
          const char**    props  = new const char*[sc];

          for( unsigned i = 0; i < sc; i++ )
            props[i] = static_cast<const char*>( shapes[i]->userData );

          Actor^          a          = Actor::Wrap( ptr );
          ShapePropsType^ shapeprops = gcnew ShapePropsType();

          for( unsigned i = 0; i < sc; i++ ) {

            Shape^ shape = Shape::CastOrNull( shapes[i] );
            if( shape == nullptr ) continue;

            shapeprops->Add( shape, Parse( props[i] ) );
          }
          //
          delete[] props;
          //
          iface->NotifyActor( a, Parse( userProperties ), shapeprops );
        }

      void                      NXU_notifyActorFailed(NxActorDesc& desc, const char* userProperties)
        {
          ActorDesc^ Desc = ActorDesc::Wrap( physics, desc );

          iface->NotifyActorFailed( ActorDesc::Wrap( physics, desc ), Parse( userProperties ) );
          delete Desc;
        }

      void                      NXU_notifySaveActor(NxActor *pActor, const char** pUserProperties){}


      //-------------------------------------------------------------
      //---------------------== TriangleMesh ==----------------------
      //-------------------------------------------------------------

      bool                       NXU_preNotifyTriangleMesh(NxTriangleMeshDesc& desc, const char* userProperties)
        {
          TriangleMeshDesc^ Desc   = TriangleMeshDesc::Wrap( desc );
          bool              result = iface->PreNotifyTriangleMesh( Desc, Parse( userProperties ) );

          delete Desc;
          return result;
        }

      void                       NXU_notifyTriangleMesh(NxTriangleMesh* mesh, const char* userProperties)
        {
          iface->NotifyTriangleMesh( physics->WrapOrGet( *mesh ), Parse( userProperties ) );
        }

      void                       NXU_notifyTriangleMeshFailed(NxTriangleMeshDesc& desc, const char* userProperties)
        {
          TriangleMeshDesc^ Desc = TriangleMeshDesc::Wrap( desc );

          iface->NotifyTriangleMeshFailed( Desc, Parse( userProperties ) );
          delete Desc;
        }


      //-------------------------------------------------------------
      //---------------------== ConvexMesh ==------------------------
      //-------------------------------------------------------------

      bool                       NXU_preNotifyConvexMesh(NxConvexMeshDesc& desc, const char* userProperties)
        {
          ConvexMeshDesc^ Desc   = ConvexMeshDesc::Wrap( desc );
          bool            result = iface->PreNotifyConvexMesh( Desc, Parse( userProperties ) );

          delete Desc;
          return result;
        }

      void                       NXU_notifyConvexMesh(NxConvexMesh* mesh, const char* userProperties)
        {
          iface->NotifyConvexMesh( physics->WrapOrGet( *mesh ), Parse( userProperties ) );
        }

      void                       NXU_notifyConvexMeshFailed(NxConvexMeshDesc& desc, const char* userProperties)
        {
          ConvexMeshDesc^ Desc = ConvexMeshDesc::Wrap( desc );

          iface->NotifyConvexMeshFailed( Desc, Parse( userProperties ) );
          delete Desc;
        }


      //-------------------------------------------------------------
      //---------------------== CCDSkeleton ==-----------------------
      //-------------------------------------------------------------

      bool                       NXU_preNotifyCCDSkeleton(NxSimpleTriangleMesh& desc, const char* userProperties)
        {
          SimpleTriangleMesh^ Desc   = SimpleTriangleMesh::Wrap( desc );
          bool                result = iface->PreNotifyCCDSkeleton( Desc, Parse( userProperties ) );

          delete Desc;
          return result;
        }

      void                       NXU_notifyCCDSkeleton(NxCCDSkeleton* skeleton, const char* userProperties)
        {
          iface->NotifyCCDSkeleton( physics->WrapOrGet( *skeleton ), Parse( userProperties ) );
        }

      void                       NXU_notifyCCDSkeletonFailed(NxSimpleTriangleMesh& desc, const char* userProperties)
        {
          SimpleTriangleMesh^ Desc = SimpleTriangleMesh::Wrap( desc );

          iface->NotifyCCDSkeletonFailed( Desc, Parse( userProperties ) );
          delete Desc;
        }


      //-------------------------------------------------------------
      //---------------------== HeightField ==-----------------------
      //-------------------------------------------------------------

      bool                      NXU_preNotifyHeightField(NxHeightFieldDesc& desc, const char* userProperties)
        {
          HeightFieldDesc^ Desc   = HeightFieldDesc::Wrap( desc );
          bool             result = iface->PreNotifyHeightField( Desc, Parse( userProperties ) );

          delete Desc;
          return result;
        }

      void                      NXU_notifyHeightField(NxHeightField* hfieldptr, const char* userProperties)
        {
          iface->NotifyHeightField( physics->WrapOrGet( *hfieldptr ), Parse( userProperties ) );
        }

      void                      NXU_notifyHeightFieldFailed(NxHeightFieldDesc& desc, const char* userProperties)
        {
          HeightFieldDesc^ Desc = HeightFieldDesc::Wrap( desc );

          iface->NotifyHeightFieldFailed( Desc, Parse( userProperties ) );
          delete Desc;
        }


      //-------------------------------------------------------------
      //---------------------== ClothMesh ==-------------------------
      //-------------------------------------------------------------

      bool                      NXU_preNotifyClothMesh(NxClothMeshDesc& desc, const char* userProperties)
        {
          ClothMeshDesc^ Desc   = ClothMeshDesc::Wrap( desc );
          bool           result = iface->PreNotifyClothMesh( Desc, Parse( userProperties ) );

          delete Desc;
          return result;
        }

      void                      NXU_notifyClothMesh(NxClothMesh* cmesh, const char* userProperties)
        {
          iface->NotifyClothMesh( physics->WrapOrGet( *cmesh ), Parse( userProperties ) );
        }

      void                      NXU_notifyClothMeshFailed(NxClothMeshDesc& desc, const char* userProperties)
        {
          ClothMeshDesc^ Desc = ClothMeshDesc::Wrap( desc );

          iface->NotifyClothMeshFailed( Desc, Parse( userProperties ) );
          delete Desc;
        }


      //-------------------------------------------------------------
      //---------------------== Cloth ==-----------------------------
      //-------------------------------------------------------------

      bool                      NXU_preNotifyCloth(NxClothDesc& desc, const char* userProperties)
        {
          ClothDesc^ Desc   = ClothDesc::Wrap( desc );
          bool       result = iface->PreNotifyCloth( Desc, Parse( userProperties ) );

          delete Desc;
          return result;
        }

      void                      NXU_notifyCloth(NxCloth* cloth, const char* userProperties)
        {
          iface->NotifyCloth( Cloth::Wrap( cloth ), Parse( userProperties ) );
        }

      void                      NXU_notifyClothFailed(NxClothDesc& desc, const char* userProperties)
        {
          ClothDesc^ Desc = ClothDesc::Wrap( desc );

          iface->NotifyClothFailed( Desc, Parse( userProperties ) );
          delete Desc;
        }


      //-------------------------------------------------------------
      //---------------------== Fluid ==-----------------------------
      //-------------------------------------------------------------

      bool                      NXU_preNotifyFluid(NxFluidDesc& desc, const char* userProperties)
        {
          FluidDesc^ Desc   = FluidDesc::Wrap( desc );
          bool       result = iface->PreNotifyFluid( Desc, Parse( userProperties ) );

          delete Desc;
          return result;
        }

      void                      NXU_notifyFluid(NxFluid* fluid, const char* userProperties)
        {
          iface->NotifyFluid( Fluid::Wrap( fluid ), Parse( userProperties ) );
        }

      void                      NXU_notifyFluidFailed(NxFluidDesc& desc, const char* userProperties)
        {
          FluidDesc^ Desc = FluidDesc::Wrap( desc );

          iface->NotifyFluidFailed( Desc, Parse( userProperties ) );
          delete Desc;
        }



      //-------------------------------------------------------------
      //---------------------== SoftBodyMesh ==----------------------
      //-------------------------------------------------------------

      bool                      NXU_preNotifySoftBodyMesh(NxSoftBodyMeshDesc& desc, const char* userProperties)
        {
          SoftBodyMeshDesc^ Desc   = SoftBodyMeshDesc::Wrap( desc );
          bool              result = iface->PreNotifySoftBodyMesh( Desc, Parse( userProperties ) );

          delete Desc;
          return result;
        }

      void                      NXU_notifySoftBodyMesh(NxSoftBodyMesh* sbmesh, const char* userProperties)
        {
          iface->NotifySoftBodyMesh( physics->WrapOrGet( *sbmesh ), Parse( userProperties ) );
        }

      void                      NXU_notifySoftBodyMeshFailed(NxSoftBodyMeshDesc& desc, const char* userProperties)
        {
          SoftBodyMeshDesc^ Desc = SoftBodyMeshDesc::Wrap( desc );

          iface->NotifySoftBodyMeshFailed( Desc, Parse( userProperties ) );
          delete Desc;
        }



      //-------------------------------------------------------------
      //---------------------== SoftBody ==--------------------------
      //-------------------------------------------------------------

      bool                      NXU_preNotifySoftBody(NxSoftBodyDesc& desc, const char* userProperties)
        {
          SoftBodyDesc^ Desc = SoftBodyDesc::Wrap( desc );
          bool          result = iface->PreNotifySoftBody( Desc, Parse( userProperties ) );

          delete Desc;
          return result;
        }

      void                      NXU_notifySoftBody(NxSoftBody* softbodyptr, const char* userProperties)
        {
          iface->NotifySoftBody( SoftBody::Wrap( softbodyptr ), Parse( userProperties ) );
        }

      void                      NXU_notifySoftBodyFailed(NxSoftBodyDesc& desc, const char* userProperties)
        {
          SoftBodyDesc^ Desc = SoftBodyDesc::Wrap( desc );

          iface->NotifySoftBodyFailed( Desc, Parse( userProperties ) );
          delete Desc;
        }


      //-------------------------------------------------------------
      //---------------------== SpringAndDamperEffector ==-----------
      //-------------------------------------------------------------

      bool                      NXU_preNotifySpringAndDamperEffector(NxSpringAndDamperEffectorDesc& desc, const char* userProperties)
        {
          SpringAndDamperEffectorDesc^ Desc   = SpringAndDamperEffectorDesc::Wrap( desc );
          bool                         result = iface->PreNotifySpringAndDamperEffector( Desc, Parse( userProperties ) );
          
          delete Desc;
          return result;
        }
        
      void                      NXU_notifySpringAndDamperEffector(NxSpringAndDamperEffector* effectorptr, const char* userProperties)
        {
          iface->NotifySpringAndDamperEffector( SpringAndDamperEffector::Wrap( effectorptr ), Parse( userProperties ) );
        }

      void                      NXU_notifySpringAndDamperEffectorFailed(NxSpringAndDamperEffectorDesc& desc, const char* userProperties)
        {
          SpringAndDamperEffectorDesc^ Desc = SpringAndDamperEffectorDesc::Wrap( desc );
          
          iface->NotifySpringAndDamperEffectorFailed( Desc, Parse( userProperties ) );          
          delete Desc;
        }


      //-------------------------------------------------------------
      //---------------------== ForceField ==------------------------
      //-------------------------------------------------------------

      bool                      NXU_preNotifyForceField(NxForceFieldDesc& desc, const char* userProperties)
        {
          ForceFieldDesc^ Desc   = ForceFieldDesc::Wrap( physics, desc );
          bool            result = iface->PreNotifyForceField( Desc, Parse( userProperties ) );
          
          delete Desc;
          return result;
        }
        
      void                      NXU_notifyForceField(NxForceField* ffptr, const char* userProperties)
        {
          iface->NotifyForceField( ForceField::Wrap( ffptr ), Parse( userProperties ) );
        }

      void                      NXU_notifyForceFieldFailed(NxForceFieldDesc& desc, const char* userProperties)
        {
          ForceFieldDesc^ Desc   = ForceFieldDesc::Wrap( physics, desc );
          
          iface->NotifyForceFieldFailed( Desc, Parse( userProperties ) );          
          delete Desc;
        }


      //-------------------------------------------------------------
      //-------------------------------------------------------------
      //-------------------------------------------------------------

      void                      NXU_notifyCompartment(NxCompartment  *compartment){};

      bool                      NXU_preNotifyCompartment(NxCompartmentDesc &compartment) { return  true; };

      void                      NXU_notifyCompartmentFailed(NxCompartmentDesc &compartment) {  };
};

//=============================+=====================================+=
NXU_userNotify*                 CreateNxuNotify(NxuNotify^ iface, Physics^ physics)
  {
    return new giNxuNotify( iface == nullptr ? gcnew NxuNotify() : iface, physics );
  }

//=============================+=====================================+=
void                            DeleteNxuNotify(NXU_userNotify*& n)   { delete static_cast<giNxuNotify*>( n ); n = 0; }


//=============================+=====================================+=
PhysicsCollection^              Physics::ExtractCollection(String^ CollectionID, NxuNotify^ Notify)
  {
    const char*  collid = ToNx( CollectionID );
    giNxuNotify* un     = Notify == nullptr ? 0 : new giNxuNotify( Notify, this );
    
    NXU::NxuPhysicsCollection* collptr = NXU::extractCollectionSDK( this->ptr, collid, un );
    PhysicsCollection^         Result  = gcnew PhysicsCollection( collptr );

    delete[] collid;
    delete un;
    return Result;    
  }

//=============================+=====================================+=
bool                            Physics::CoreDump(String^ Filename, NXUFileTypes Type, bool SaveDefaults, bool Cook, NxuNotify^ Notify)
  {
    const char*  filename = ToNx( Filename );
    giNxuNotify* un       = Notify == nullptr ? 0 : new giNxuNotify( Notify, this );

    bool Result = NXU::coreDump( this->ptr, filename, static_cast<NXU::NXU_FileType>( Type ), SaveDefaults, Cook, un );

    delete[] filename;
    delete un;
    return Result;    
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddEntireScene(Scene^ Scene, UserPropertiesType UserProperties, String^ SceneID, NxuNotify^ Notify)
  {
    const char*  id    = ToNx( SceneID );
    giNxuNotify* un    = Notify == nullptr ? 0 : new giNxuNotify( Notify, Scene->Owner );
    const char*  props = ToChar( UserProperties );

    bool Result = addEntireScene( *this->ptr, *Scene->ptr, props, id, un );

    delete[] props;
    delete[] id;
    delete un;
    return Result;
  }
