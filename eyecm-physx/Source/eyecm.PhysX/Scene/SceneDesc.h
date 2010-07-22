//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
interface class                 IUserNotify;
interface class                 IFluidUserNotify;
interface class                 IUserContactModify;
interface class                 IUserTriggerReport;
interface class                 IUserContactReport;
interface class                 IUserActorPairFiltering;

//=============================+=====================================+=
public ref struct               SceneLimits:                          public giNxData<NxSceneLimits>
  {
    public:
      DefP0( unsigned,          ActorCount,                     maxNbActors )
      DefP0( unsigned,          BodyCount,                      maxNbBodies )
      DefP0( unsigned,          StaticShapeCount,               maxNbStaticShapes )
      DefP0( unsigned,          DynamicShapeCount,              maxNbDynamicShapes )
      DefP0( unsigned,          JointCount,                     maxNbJoints )
  };

//=============================+=====================================+=
public ref struct               SceneDesc:                            giNxProxyData<NxSceneDesc>
  {
    public:
      SceneDesc() {}

      SceneDesc(SceneFlags Flags) { this->Flags = Flags; }

      ~SceneDesc() { limits = nullptr; this->!SceneDesc(); }
      !SceneDesc() { if( !ignorebounds ) { delete data->maxBounds; data->maxBounds = 0; } }

    internal:
      SceneDesc(NxSceneDesc& desc): BaseType( desc ) { ignorebounds = true; } // HACK: something wrong with bounds while loading from file

      inline static SceneDesc^  Wrap(NxSceneDesc& desc)               { return gcnew SceneDesc( desc ); }

    public:
      DefPx( Vector3,           Gravity,                              gravity )
      DefP0( float,             MaxTimeStep,                          maxTimestep )
      DefP0( unsigned,          MaxIterationCount,                    maxIter )
      DefPc( TimeStepMethods,   TimeStepMethod,     NxTimeStepMethod, timeStepMethod )
      DefPc( SimulationTypes,   SimulationType,     NxSimulationType, simType )
      DefPx( bool,              GroundPlane,                          groundPlane )
      DefPx( bool,              BoundsPlanes,                         boundsPlanes )
      DefPc( SceneFlags,        Flags,                         NxU32, flags )
      DefP0( unsigned,          SimThreadStackSize,                   simThreadStackSize )
      DefPc( ThreadPriorities,  SimThreadPriority,  NxThreadPriority, simThreadPriority )
      DefP0( unsigned,          SimThreadMask,                        simThreadMask )
      DefP0( unsigned,          WorkerThreadStackSize,                workerThreadStackSize )
      DefPc( ThreadPriorities,  WorkerThreadPriority,NxThreadPriority,workerThreadPriority )
      DefP0( unsigned,          InternalThreadCount,                  internalThreadCount )
      DefP0( unsigned,          ThreadMask,                           threadMask )
      DefP0( unsigned,          BackgroundThreadCount,                backgroundThreadCount )
      DefP0( unsigned,          BackgroundThreadMask,                 backgroundThreadMask )
      DefPc( ThreadPriorities,  BackgroundThreadPriority,NxThreadPriority,backgroundThreadPriority )
      DefP0( unsigned,          UpAxis,                               upAxis )
      DefP0( unsigned,          SubdivisionLevel,                     subdivisionLevel )
      DefPc( PruningStructures, StaticStructure,  NxPruningStructure, staticStructure )
      DefPc( PruningStructures, DynamicStructure, NxPruningStructure, dynamicStructure )
      DefPc( BroadPhaseTypes,   BroadPhaseType,     NxBroadPhaseType, bpType )
      DefP0( unsigned,          GridCellXCount,                       nbGridCellsX )
      DefP0( unsigned,          GridCellYCount,                       nbGridCellsY )
      DefP0( unsigned,          SolverBatchSize,                      solverBatchSize )
      DefP0( unsigned,          DynamicTreeRebuildRateHint,           dynamicTreeRebuildRateHint )

    private:
      SceneLimits^              limits;
      bool                      ignorebounds;
      //
      template<typename T> 
      ref class                 Chooser 
      { 
        public: 
          typedef               Nullable<T>                           t; 
          //
          static bool           HasValue(t val)                       { return val.HasValue; }
          static T              GetValue(t val)                       { return val.Value;    }
      };
      //
      template<typename T> 
      ref class                 Chooser<T^> 
      { 
        public: 
          typedef               T^                                    t; 
          //
          static bool           HasValue(t)                           { return true; }
          static T^             GetValue(t val)                       { return val;  }
      };
      //
      typedef                   Chooser<AxisAlignedBox>               NullableAABBChooser;
      typedef                   Chooser<AxisAlignedBox>::t            NullableAABB;
      //
      NullableAABB              bounds;
      //
    public:
      DefValidDefaultX(

        ptrUserNotify             = nullptr;
        ptrFluidUserNotify        = nullptr;
        ptrUserContactModify      = nullptr;
        ptrUserTriggerReport      = nullptr;
        ptrUserContactReport      = nullptr;
        ptrUserActorPairFiltering = nullptr;

        limits        = nullptr;
        bounds        = NullableAABB();
        ignorebounds  = false;

        data->setToDefault();
        PostSet();
      )

    public:
      property
      NullableAABB              MaxBounds
        {
          NullableAABB          get()                                 { return bounds; }

          void                  set(NullableAABB v)
            {
              if( !NullableAABBChooser::HasValue( v ) ) { delete data->maxBounds; data->maxBounds = 0; }
              else {

                if( data->maxBounds == 0 ) data->maxBounds = new NxBounds3();
                *data->maxBounds = ToNx( NullableAABBChooser::GetValue( v ) );
              }
              bounds = v;
            }
        }

      property SceneLimits^     Limits
        {
          SceneLimits^          get()                                 { return limits; }
          void                  set(SceneLimits^ v)
            {
              limits = v;
              data->limits = v ? v->data : 0;
            }
        }

    public:
      #define                   DefReport(type) \
        interface class ThisNamespace::I##type; \
      private: \
        I##type^                ptr##type; \
      public: \
        property I##type^       type \
          { \
            I##type^            get()                                 { return ptr##type; } \
            void                set(I##type^ v)                       { ptr##type = v; } \
          }

        DefReport(              UserNotify )
        DefReport(              FluidUserNotify )
        DefReport(              UserContactModify )
        DefReport(              UserTriggerReport )
        DefReport(              UserContactReport )
        DefReport(              UserActorPairFiltering )

      #undef                    DefReport
  };

//=============================+=====================================+=
                                EndNamespace

