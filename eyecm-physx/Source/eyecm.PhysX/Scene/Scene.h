//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "userentityreport.h"
#include                       "nxenumerable.h"
#include                       "SceneDesc.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Physics;
ref struct                      MaterialDesc;
ref class                       Material;
ref struct                      ActorDesc;
ref class                       Actor;
ref class                       Shape;
ref class                       Joint;
ref struct                      JointDesc;

interface class                 IRaycastReport;
value struct                    RaycastHit;


ref class                       DebugRenderable;

value struct                    ActiveTransform;
ref class                       ActiveTransforms;

ref class                       SceneQuery;
ref struct                      SceneQueryDesc;

ref struct                      ClothDesc;
ref class                       Cloth;

ref struct                      FluidDesc;
ref class                       Fluid;

ref struct                      SoftBodyDesc;
ref class                       SoftBody;

ref struct                      EffectorDesc;
ref class                       Effector;

ref struct                      ForceFieldDesc;
ref class                       ForceField;
ref struct                      ForceFieldShapeGroupDesc;
ref class                       ForceFieldShapeGroup;
ref struct                      ForceFieldLinearKernelDesc;
ref class                       ForceFieldLinearKernel;

ref class                       ControllerManager;

ref class                       PhysicsCollection;

//=============================+=====================================+=
public ref class                Scene:                                public giNxObject<NxScene, Scene, giNxRegisteredObject<Physics> >
  {
    internal:
      typedef                   ThisNamespace::Physics                giPhysics;

      giNxRegisteredObject<Scene>^ First;

    internal:
      Scene(giPhysics^ Physics, SceneDesc^ Desc, NxScene* ptr);

      static Scene^             CastOrWrap(giPhysics^ physics, NxScene* ptr)
        {
          Scene^ sceneref = CastOrNull( ptr );
          return sceneref == nullptr ? gcnew Scene( physics, nullptr, ptr ) : sceneref;
        }

    public:
      ~Scene();
      !Scene();

    public:
      property giPhysics^       Physics
        {
          giPhysics^            get()                                 { return Owner; }
        }

      property Vector3          Gravity
        {
          Vector3               get()                                 { NxVec3 g; ptr->getGravity( g ); return FromNx( g ); }
          void                  set(Vector3 g)                        { ptr->setGravity( ToNx( g ) ); }
        }

      property bool             IsWritable
        {
          bool                  get()                                 { return ptr->isWritable(); }
        }

      Defmc( SceneFlags,        Flags,                                Flags )
      Defm0( unsigned,          StaticShapeCount,                     NbStaticShapes )
      Defm0( unsigned,          DynamicShapeCount,                    NbDynamicShapes )
      Defm0( unsigned,          TotalShapeCount,                      TotalNbShapes )

      DefM0( float,             MaxCPUForLoadBalancing,               MaxCPUForLoadBalancing )
      DefM0( unsigned,          DynamicTreeRebuildRateHint,           DynamicTreeRebuildRateHint )
      DefM0( unsigned,          SolverBatchSize,                      SolverBatchSize )

    public:
      property bool             IsSimulationComplete
        {
          bool                  get()                                 { return CheckResults( SimulationStatuses::AllFinished, false ); }
        }

    public:
      void                      Simulate(double dt)                   { ptr->simulate( static_cast<NxReal>( dt ) ); }

      void                      FlushStream()                         { ptr->flushStream(); }
      void                      FlushCaches()                         { ptr->flushCaches(); }

      void                      ShutdownWorkerThreads()               { ptr->shutdownWorkerThreads(); }

      bool                      FetchResults(SimulationStatuses Parts, bool Blocking)
        {
          return ptr->fetchResults( static_cast<NxSimulationStatus>( Parts ), Blocking );
        }

      bool                      CheckResults(SimulationStatuses Parts, bool Blocking)
        {
          return ptr->checkResults( static_cast<NxSimulationStatus>( Parts ), Blocking );
        }

      DebugRenderable^          GetDebugRenderable();
      ActiveTransforms^         GetActiveTransforms();

      Actor^                    CreateActor(ActorDesc^ Desc);
      Material^                 CreateMaterial(MaterialDesc^ Desc);
      Joint^                    CreateJoint(JointDesc^ Desc);
      SceneQuery^               CreateSceneQuery(SceneQueryDesc^ Desc);
      Cloth^                    CreateCloth(ClothDesc^ Desc);
      Fluid^                    CreateFluid(FluidDesc^ Desc);
      SoftBody^                 CreateSoftBody(SoftBodyDesc^ Desc);
      Effector^                 CreateEffector(EffectorDesc^ Desc);
      ForceField^               CreateForceField(ForceFieldDesc^ Desc);
      ForceFieldLinearKernel^   CreateForceFieldLinearKernel(ForceFieldLinearKernelDesc^ Desc);
      ForceFieldShapeGroup^     CreateForceFieldShapeGroup(ForceFieldShapeGroupDesc^ Desc);
      
      ref struct                ProxyForceFieldScale:                 public giNxProxy<NxScene>
        {
          internal:
            ProxyForceFieldScale(NxScene* ptr): BaseType( ptr ) {}

          public:
            unsigned            CreateVariety()                       { return GetNx()->createForceFieldVariety(); }
            void                ReleaseVariety(unsigned v)            { GetNx()->releaseForceFieldVariety( static_cast<NxForceFieldVariety>( v ) ); }
            property unsigned   HighestVariety
              {
                unsigned        get()                                 { return GetNx()->getHighestForceFieldVariety(); }
              }

            unsigned            CreateMaterial()                      { return GetNx()->createForceFieldMaterial(); }
            void                ReleaseMaterial(unsigned v)           { GetNx()->releaseForceFieldMaterial( static_cast<NxForceFieldMaterial>( v ) ); }
            property unsigned   HighestMaterial
              {
                unsigned        get()                                 { return GetNx()->getHighestForceFieldMaterial(); }
              }
 
            property float      default[unsigned, unsigned]
              {             
                float           get(unsigned Variety, unsigned Material) 
                  { 
                    return GetNx()->getForceFieldScale( static_cast<NxForceFieldVariety>( Variety ), static_cast<NxForceFieldMaterial>( Material ) ); 
                  }
                  
                void            set(unsigned Variety, unsigned Material, float Scale) 
                  { 
                    GetNx()->setForceFieldScale( static_cast<NxForceFieldVariety>( Variety ), static_cast<NxForceFieldMaterial>( Material ), Scale ); 
                  }
              }
      };

      DefProxyGetSetX( ProxyForceFieldScale, ForceFieldScale, DefNothing, GetNx() )
      
      // TODO: cookfluidmeshhotspot

      void                      LockQueries()                         { ptr->lockQueries(); }
      void                      UnlockQueries()                       { ptr->unlockQueries(); }

      PhysicsCollection^        ExtractCollection()                      { return ExtractCollection( nullptr ); }
      PhysicsCollection^        ExtractCollection(String^ CollectionID)  { return ExtractCollection( CollectionID, nullptr ); }
      PhysicsCollection^        ExtractCollection(String^ CollectionID, String^ SceneID);

      #include                 "Scene.List.h"
      #include                 "Scene.Limits.h"
      #include                 "Scene.Timing.h"
      #include                 "Scene.Pairs.h"
      #include                 "Scene.Raycast.h"
      #include                 "Scene.Overlap.h"
      #include                 "Scene.Report.h"
  };

//=============================+=====================================+=
                                EndNamespace

