//=============================+=====================================+=
//public ref class              Physics

    public:
      ref struct                ProxyParameters:                      public giNxProxy<NxPhysicsSDK>
        {
          internal:
            ProxyParameters(NxPhysicsSDK* ptr): giNxProxy( ptr ) { }

          public:
            #define             DefFlag( name, token ) \
            property float      name \
              { \
                float           get()                                 { return data->getParameter( token ); } \
                void            set(float v)                          { data->setParameter( token, v ); } \
              }

            DefFlag(            SkinWidth                           , NX_SKIN_WIDTH )
            DefFlag(            DefaultSleepLinVelSquared           , NX_DEFAULT_SLEEP_LIN_VEL_SQUARED )
            DefFlag(            DefaultSleepAngVelSquared           , NX_DEFAULT_SLEEP_ANG_VEL_SQUARED )
            DefFlag(            BounceThreshold                     , NX_BOUNCE_THRESHOLD )
            DefFlag(            DynFrictScaling                     , NX_DYN_FRICT_SCALING )
            DefFlag(            StaFrictScaling                     , NX_STA_FRICT_SCALING )
            DefFlag(            MaxAngularVelocity                  , NX_MAX_ANGULAR_VELOCITY )
            DefFlag(            ContinuousCd                        , NX_CONTINUOUS_CD )
            DefFlag(            VisualizationScale                  , NX_VISUALIZATION_SCALE )
            DefFlag(            VisualizeWorldAxes                  , NX_VISUALIZE_WORLD_AXES )
            DefFlag(            VisualizeBodyAxes                   , NX_VISUALIZE_BODY_AXES )
            DefFlag(            VisualizeBodyMassAxes               , NX_VISUALIZE_BODY_MASS_AXES )
            DefFlag(            VisualizeBodyLinVelocity            , NX_VISUALIZE_BODY_LIN_VELOCITY )
            DefFlag(            VisualizeBodyAngVelocity            , NX_VISUALIZE_BODY_ANG_VELOCITY )
            DefFlag(            VisualizeBodyJointGroups            , NX_VISUALIZE_BODY_JOINT_GROUPS )
            DefFlag(            VisualizeJointLocalAxes             , NX_VISUALIZE_JOINT_LOCAL_AXES )
            DefFlag(            VisualizeJointWorldAxes             , NX_VISUALIZE_JOINT_WORLD_AXES )
            DefFlag(            VisualizeJointLimits                , NX_VISUALIZE_JOINT_LIMITS )
            DefFlag(            VisualizeContactPoint               , NX_VISUALIZE_CONTACT_POINT )
            DefFlag(            VisualizeContactNormal              , NX_VISUALIZE_CONTACT_NORMAL )
            DefFlag(            VisualizeContactError               , NX_VISUALIZE_CONTACT_ERROR )
            DefFlag(            VisualizeContactForce               , NX_VISUALIZE_CONTACT_FORCE )
            DefFlag(            VisualizeActorAxes                  , NX_VISUALIZE_ACTOR_AXES )
            DefFlag(            VisualizeCollisionAabbs             , NX_VISUALIZE_COLLISION_AABBS )
            DefFlag(            VisualizeCollisionShapes            , NX_VISUALIZE_COLLISION_SHAPES )
            DefFlag(            VisualizeCollisionAxes              , NX_VISUALIZE_COLLISION_AXES )
            DefFlag(            VisualizeCollisionCompounds         , NX_VISUALIZE_COLLISION_COMPOUNDS )
            DefFlag(            VisualizeCollisionVnormals          , NX_VISUALIZE_COLLISION_VNORMALS )
            DefFlag(            VisualizeCollisionFnormals          , NX_VISUALIZE_COLLISION_FNORMALS )
            DefFlag(            VisualizeCollisionEdges             , NX_VISUALIZE_COLLISION_EDGES )
            DefFlag(            VisualizeCollisionSpheres           , NX_VISUALIZE_COLLISION_SPHERES )
            DefFlag(            VisualizeCollisionStatic            , NX_VISUALIZE_COLLISION_STATIC )
            DefFlag(            VisualizeCollisionDynamic           , NX_VISUALIZE_COLLISION_DYNAMIC )
            DefFlag(            VisualizeCollisionFree              , NX_VISUALIZE_COLLISION_FREE )
            DefFlag(            VisualizeCollisionCcd               , NX_VISUALIZE_COLLISION_CCD )
            DefFlag(            VisualizeCollisionSkeletons         , NX_VISUALIZE_COLLISION_SKELETONS )
            DefFlag(            VisualizeFluidEmitters              , NX_VISUALIZE_FLUID_EMITTERS )
            DefFlag(            VisualizeFluidPosition              , NX_VISUALIZE_FLUID_POSITION )
            DefFlag(            VisualizeFluidVelocity              , NX_VISUALIZE_FLUID_VELOCITY )
            DefFlag(            VisualizeFluidKernelRadius          , NX_VISUALIZE_FLUID_KERNEL_RADIUS )
            DefFlag(            VisualizeFluidBounds                , NX_VISUALIZE_FLUID_BOUNDS )
            DefFlag(            VisualizeFluidPackets               , NX_VISUALIZE_FLUID_PACKETS )
            DefFlag(            VisualizeFluidMotionLimit           , NX_VISUALIZE_FLUID_MOTION_LIMIT )
            DefFlag(            VisualizeFluidDynCollision          , NX_VISUALIZE_FLUID_DYN_COLLISION )
            DefFlag(            VisualizeFluidStcCollision          , NX_VISUALIZE_FLUID_STC_COLLISION )
            DefFlag(            VisualizeFluidMeshPackets           , NX_VISUALIZE_FLUID_MESH_PACKETS )
            DefFlag(            VisualizeFluidDrains                , NX_VISUALIZE_FLUID_DRAINS )
            DefFlag(            VisualizeFluidPacketData            , NX_VISUALIZE_FLUID_PACKET_DATA )
            DefFlag(            VisualizeClothMesh                  , NX_VISUALIZE_CLOTH_MESH )
            DefFlag(            VisualizeClothCollisions            , NX_VISUALIZE_CLOTH_COLLISIONS )
            DefFlag(            VisualizeClothSelfcollisions        , NX_VISUALIZE_CLOTH_SELFCOLLISIONS )
            DefFlag(            VisualizeClothWorkpackets           , NX_VISUALIZE_CLOTH_WORKPACKETS )
            DefFlag(            VisualizeClothSleep                 , NX_VISUALIZE_CLOTH_SLEEP )
            DefFlag(            VisualizeClothSleepVertex           , NX_VISUALIZE_CLOTH_SLEEP_VERTEX )
            DefFlag(            VisualizeClothTearableVertices      , NX_VISUALIZE_CLOTH_TEARABLE_VERTICES )
            DefFlag(            VisualizeClothTearing               , NX_VISUALIZE_CLOTH_TEARING )
            DefFlag(            VisualizeClothAttachment            , NX_VISUALIZE_CLOTH_ATTACHMENT )
            DefFlag(            VisualizeClothValidbounds           , NX_VISUALIZE_CLOTH_VALIDBOUNDS )
            DefFlag(            VisualizeSoftbodyMesh               , NX_VISUALIZE_SOFTBODY_MESH )
            DefFlag(            VisualizeSoftbodyCollisions         , NX_VISUALIZE_SOFTBODY_COLLISIONS )
            DefFlag(            VisualizeSoftbodyWorkpackets        , NX_VISUALIZE_SOFTBODY_WORKPACKETS )
            DefFlag(            VisualizeSoftbodySleep              , NX_VISUALIZE_SOFTBODY_SLEEP )
            DefFlag(            VisualizeSoftbodySleepVertex        , NX_VISUALIZE_SOFTBODY_SLEEP_VERTEX )
            DefFlag(            VisualizeSoftbodyTearableVertices   , NX_VISUALIZE_SOFTBODY_TEARABLE_VERTICES )
            DefFlag(            VisualizeSoftbodyTearing            , NX_VISUALIZE_SOFTBODY_TEARING )
            DefFlag(            VisualizeSoftbodyAttachment         , NX_VISUALIZE_SOFTBODY_ATTACHMENT )
            DefFlag(            VisualizeSoftbodyValidbounds        , NX_VISUALIZE_SOFTBODY_VALIDBOUNDS )
            DefFlag(            AdaptiveForce                       , NX_ADAPTIVE_FORCE )
            DefFlag(            CollVetoJointed                     , NX_COLL_VETO_JOINTED )
            DefFlag(            TriggerTriggerCallback              , NX_TRIGGER_TRIGGER_CALLBACK )
            DefFlag(            VisualizeActiveVertices             , NX_VISUALIZE_ACTIVE_VERTICES )
            DefFlag(            CcdEpsilon                          , NX_CCD_EPSILON )
            DefFlag(            SolverConvergenceThreshold          , NX_SOLVER_CONVERGENCE_THRESHOLD )
            DefFlag(            BboxNoiseLevel                      , NX_BBOX_NOISE_LEVEL )
            DefFlag(            ImplicitSweepCacheSize              , NX_IMPLICIT_SWEEP_CACHE_SIZE )
            DefFlag(            DefaultSleepEnergy                  , NX_DEFAULT_SLEEP_ENERGY )
            DefFlag(            ConstantFluidMaxPackets             , NX_CONSTANT_FLUID_MAX_PACKETS )
            DefFlag(            ConstantFluidMaxParticlesPerStep    , NX_CONSTANT_FLUID_MAX_PARTICLES_PER_STEP )
            DefFlag(            VisualizeForceFields                , NX_VISUALIZE_FORCE_FIELDS )
            DefFlag(            AsynchronousMeshCreation            , NX_ASYNCHRONOUS_MESH_CREATION )
            DefFlag(            ForceFieldCustomKernelEpsilon       , NX_FORCE_FIELD_CUSTOM_KERNEL_EPSILON )
            DefFlag(            ImprovedSpringSolver                , NX_IMPROVED_SPRING_SOLVER )

            #undef              DefFlag
        };

    internal:
      ProxyParameters^          parameters;

    public:
      property ProxyParameters^ Parameters
        {
          ProxyParameters^      get()                                 { return parameters; }
        }

//  };
//=============================+=====================================+=
