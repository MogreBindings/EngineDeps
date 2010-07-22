#ifndef                         DefXML
//=============================+=====================================+=
//#pragma                         once
//=============================+=====================================+=
  #define                       DefEnum( type, nxtype )               [MyDocAttr( nxtype::typeid, "", false )] public enum class type {
  #define                       DefEnumFlags( type, nxtype )          [Flags()] DefEnum( type, nxtype )
  #define                       DefEnumEnd                            };
  #define                       DefEnumVal( name, token )             /*[MyDocAttr( Enum::typeid, #token, false )] */name = token,

//=============================+=====================================+=
                                BeginNamespace

#else
  #define                       DefEnum( type, nxtype )               "<enum name=\"" #type "\" nxtype=\"" #nxtype "\">\n"
  #define                       DefEnumFlags( type, nxtype )          "<enum name=\"" #type "\" nxtype=\"" #nxtype "\" flags=\"true\">\n"
  #define                       DefEnumEnd                            "</enum>\n"
  #define                       DefEnumVal( name, token )             "  <value name=\"" #name "\" token=\"" #token "\"/>\n"
#endif

//=============================+=====================================+=
DefEnum                       ( ErrorCodes                          , NxErrorCode )
  
    DefEnumVal                ( NoError                             , NXE_NO_ERROR )
    DefEnumVal                ( InvalidParameter                    , NXE_INVALID_PARAMETER )
    DefEnumVal                ( InvalidOperation                    , NXE_INVALID_OPERATION )
    DefEnumVal                ( OutOfMemory                         , NXE_OUT_OF_MEMORY )
    DefEnumVal                ( InternalError                       , NXE_INTERNAL_ERROR )
    DefEnumVal                ( Assertion                           , NXE_ASSERTION )
    DefEnumVal                ( Info                                , NXE_DB_INFO )
    DefEnumVal                ( Warning                             , NXE_DB_WARNING )
    DefEnumVal                ( Print                               , NXE_DB_PRINT )


DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( AssertResponses                     , NxAssertResponse )
  
    DefEnumVal                ( Continue                            , NX_AR_CONTINUE )
    DefEnumVal                ( Ignore                              , NX_AR_IGNORE )
    DefEnumVal                ( Breakpoint                          , NX_AR_BREAKPOINT )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( Parameters                          , NxParameter )

    DefEnumVal                ( SkinWidth                           , NX_SKIN_WIDTH )
    DefEnumVal                ( DefaultSleepLinVelSquared           , NX_DEFAULT_SLEEP_LIN_VEL_SQUARED )
    DefEnumVal                ( DefaultSleepAngVelSquared           , NX_DEFAULT_SLEEP_ANG_VEL_SQUARED )
    DefEnumVal                ( BounceThreshold                     , NX_BOUNCE_THRESHOLD )
    DefEnumVal                ( DynFrictScaling                     , NX_DYN_FRICT_SCALING )
    DefEnumVal                ( StaFrictScaling                     , NX_STA_FRICT_SCALING )
    DefEnumVal                ( MaxAngularVelocity                  , NX_MAX_ANGULAR_VELOCITY )
    DefEnumVal                ( ContinuousCd                        , NX_CONTINUOUS_CD )
    DefEnumVal                ( VisualizationScale                  , NX_VISUALIZATION_SCALE )
    DefEnumVal                ( VisualizeWorldAxes                  , NX_VISUALIZE_WORLD_AXES )
    DefEnumVal                ( VisualizeBodyAxes                   , NX_VISUALIZE_BODY_AXES )
    DefEnumVal                ( VisualizeBodyMassAxes               , NX_VISUALIZE_BODY_MASS_AXES )
    DefEnumVal                ( VisualizeBodyLinVelocity            , NX_VISUALIZE_BODY_LIN_VELOCITY )
    DefEnumVal                ( VisualizeBodyAngVelocity            , NX_VISUALIZE_BODY_ANG_VELOCITY )
    DefEnumVal                ( VisualizeBodyJointGroups            , NX_VISUALIZE_BODY_JOINT_GROUPS )
    DefEnumVal                ( VisualizeJointLocalAxes             , NX_VISUALIZE_JOINT_LOCAL_AXES )
    DefEnumVal                ( VisualizeJointWorldAxes             , NX_VISUALIZE_JOINT_WORLD_AXES )
    DefEnumVal                ( VisualizeJointLimits                , NX_VISUALIZE_JOINT_LIMITS )
    DefEnumVal                ( VisualizeContactPoint               , NX_VISUALIZE_CONTACT_POINT )
    DefEnumVal                ( VisualizeContactNormal              , NX_VISUALIZE_CONTACT_NORMAL )
    DefEnumVal                ( VisualizeContactError               , NX_VISUALIZE_CONTACT_ERROR )
    DefEnumVal                ( VisualizeContactForce               , NX_VISUALIZE_CONTACT_FORCE )
    DefEnumVal                ( VisualizeActorAxes                  , NX_VISUALIZE_ACTOR_AXES )
    DefEnumVal                ( VisualizeCollisionAabbs             , NX_VISUALIZE_COLLISION_AABBS )
    DefEnumVal                ( VisualizeCollisionShapes            , NX_VISUALIZE_COLLISION_SHAPES )
    DefEnumVal                ( VisualizeCollisionAxes              , NX_VISUALIZE_COLLISION_AXES )
    DefEnumVal                ( VisualizeCollisionCompounds         , NX_VISUALIZE_COLLISION_COMPOUNDS )
    DefEnumVal                ( VisualizeCollisionVnormals          , NX_VISUALIZE_COLLISION_VNORMALS )
    DefEnumVal                ( VisualizeCollisionFnormals          , NX_VISUALIZE_COLLISION_FNORMALS )
    DefEnumVal                ( VisualizeCollisionEdges             , NX_VISUALIZE_COLLISION_EDGES )
    DefEnumVal                ( VisualizeCollisionSpheres           , NX_VISUALIZE_COLLISION_SPHERES )
    DefEnumVal                ( VisualizeCollisionStatic            , NX_VISUALIZE_COLLISION_STATIC )
    DefEnumVal                ( VisualizeCollisionDynamic           , NX_VISUALIZE_COLLISION_DYNAMIC )
    DefEnumVal                ( VisualizeCollisionFree              , NX_VISUALIZE_COLLISION_FREE )
    DefEnumVal                ( VisualizeCollisionCcd               , NX_VISUALIZE_COLLISION_CCD )
    DefEnumVal                ( VisualizeCollisionSkeletons         , NX_VISUALIZE_COLLISION_SKELETONS )
    DefEnumVal                ( VisualizeFluidEmitters              , NX_VISUALIZE_FLUID_EMITTERS )
    DefEnumVal                ( VisualizeFluidPosition              , NX_VISUALIZE_FLUID_POSITION )
    DefEnumVal                ( VisualizeFluidVelocity              , NX_VISUALIZE_FLUID_VELOCITY )
    DefEnumVal                ( VisualizeFluidKernelRadius          , NX_VISUALIZE_FLUID_KERNEL_RADIUS )
    DefEnumVal                ( VisualizeFluidBounds                , NX_VISUALIZE_FLUID_BOUNDS )
    DefEnumVal                ( VisualizeFluidPackets               , NX_VISUALIZE_FLUID_PACKETS )
    DefEnumVal                ( VisualizeFluidMotionLimit           , NX_VISUALIZE_FLUID_MOTION_LIMIT )
    DefEnumVal                ( VisualizeFluidDynCollision          , NX_VISUALIZE_FLUID_DYN_COLLISION )
    DefEnumVal                ( VisualizeFluidStcCollision          , NX_VISUALIZE_FLUID_STC_COLLISION )
    DefEnumVal                ( VisualizeFluidMeshPackets           , NX_VISUALIZE_FLUID_MESH_PACKETS )
    DefEnumVal                ( VisualizeFluidDrains                , NX_VISUALIZE_FLUID_DRAINS )
    DefEnumVal                ( VisualizeFluidPacketData            , NX_VISUALIZE_FLUID_PACKET_DATA )
    DefEnumVal                ( VisualizeClothMesh                  , NX_VISUALIZE_CLOTH_MESH )
    DefEnumVal                ( VisualizeClothCollisions            , NX_VISUALIZE_CLOTH_COLLISIONS )
    DefEnumVal                ( VisualizeClothSelfcollisions        , NX_VISUALIZE_CLOTH_SELFCOLLISIONS )
    DefEnumVal                ( VisualizeClothWorkpackets           , NX_VISUALIZE_CLOTH_WORKPACKETS )
    DefEnumVal                ( VisualizeClothSleep                 , NX_VISUALIZE_CLOTH_SLEEP )
    DefEnumVal                ( VisualizeClothSleepVertex           , NX_VISUALIZE_CLOTH_SLEEP_VERTEX )
    DefEnumVal                ( VisualizeClothTearableVertices      , NX_VISUALIZE_CLOTH_TEARABLE_VERTICES )
    DefEnumVal                ( VisualizeClothTearing               , NX_VISUALIZE_CLOTH_TEARING )
    DefEnumVal                ( VisualizeClothAttachment            , NX_VISUALIZE_CLOTH_ATTACHMENT )
    DefEnumVal                ( VisualizeClothValidbounds           , NX_VISUALIZE_CLOTH_VALIDBOUNDS )
    DefEnumVal                ( VisualizeSoftbodyMesh               , NX_VISUALIZE_SOFTBODY_MESH )
    DefEnumVal                ( VisualizeSoftbodyCollisions         , NX_VISUALIZE_SOFTBODY_COLLISIONS )
    DefEnumVal                ( VisualizeSoftbodyWorkpackets        , NX_VISUALIZE_SOFTBODY_WORKPACKETS )
    DefEnumVal                ( VisualizeSoftbodySleep              , NX_VISUALIZE_SOFTBODY_SLEEP )
    DefEnumVal                ( VisualizeSoftbodySleepVertex        , NX_VISUALIZE_SOFTBODY_SLEEP_VERTEX )
    DefEnumVal                ( VisualizeSoftbodyTearableVertices   , NX_VISUALIZE_SOFTBODY_TEARABLE_VERTICES )
    DefEnumVal                ( VisualizeSoftbodyTearing            , NX_VISUALIZE_SOFTBODY_TEARING )
    DefEnumVal                ( VisualizeSoftbodyAttachment         , NX_VISUALIZE_SOFTBODY_ATTACHMENT )
    DefEnumVal                ( VisualizeSoftbodyValidbounds        , NX_VISUALIZE_SOFTBODY_VALIDBOUNDS )
    DefEnumVal                ( AdaptiveForce                       , NX_ADAPTIVE_FORCE )
    DefEnumVal                ( CollVetoJointed                     , NX_COLL_VETO_JOINTED )
    DefEnumVal                ( TriggerTriggerCallback              , NX_TRIGGER_TRIGGER_CALLBACK )
    DefEnumVal                ( VisualizeActiveVertices             , NX_VISUALIZE_ACTIVE_VERTICES )
    DefEnumVal                ( CcdEpsilon                          , NX_CCD_EPSILON )
    DefEnumVal                ( SolverConvergenceThreshold          , NX_SOLVER_CONVERGENCE_THRESHOLD )
    DefEnumVal                ( BboxNoiseLevel                      , NX_BBOX_NOISE_LEVEL )
    DefEnumVal                ( ImplicitSweepCacheSize              , NX_IMPLICIT_SWEEP_CACHE_SIZE )
    DefEnumVal                ( DefaultSleepEnergy                  , NX_DEFAULT_SLEEP_ENERGY )
    DefEnumVal                ( ConstantFluidMaxPackets             , NX_CONSTANT_FLUID_MAX_PACKETS )
    DefEnumVal                ( ConstantFluidMaxParticlesPerStep    , NX_CONSTANT_FLUID_MAX_PARTICLES_PER_STEP )
    DefEnumVal                ( VisualizeForceFields                , NX_VISUALIZE_FORCE_FIELDS )
    DefEnumVal                ( AsynchronousMeshCreation            , NX_ASYNCHRONOUS_MESH_CREATION )
    DefEnumVal                ( ForceFieldCustomKernelEpsilon       , NX_FORCE_FIELD_CUSTOM_KERNEL_EPSILON )
    DefEnumVal                ( ImprovedSpringSolver                , NX_IMPROVED_SPRING_SOLVER )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( SceneFlags                          , NxSceneFlags )
  
    DefEnumVal                ( DisableCollisions                   , NX_SF_DISABLE_COLLISIONS )
    DefEnumVal                ( SeparateThread                      , NX_SF_SIMULATE_SEPARATE_THREAD )
    DefEnumVal                ( EnableMultiThread                   , NX_SF_ENABLE_MULTITHREAD )
    DefEnumVal                ( EnableActiveTransforms              , NX_SF_ENABLE_ACTIVETRANSFORMS )
    DefEnumVal                ( RestrictedScene                     , NX_SF_RESTRICTED_SCENE )
    DefEnumVal                ( DisableSceneMutex                   , NX_SF_DISABLE_SCENE_MUTEX )
    DefEnumVal                ( ForceConeFriction                   , NX_SF_FORCE_CONE_FRICTION )
    DefEnumVal                ( SequentialPrimary                   , NX_SF_SEQUENTIAL_PRIMARY )
    DefEnumVal                ( FluidPerformanceHint                , NX_SF_FLUID_PERFORMANCE_HINT )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( ContactPairFlags                    , NxContactPairFlag )
  
    DefEnumVal                ( IgnorePair                          , NX_IGNORE_PAIR )
    DefEnumVal                ( NotifyOnStartTouch                  , NX_NOTIFY_ON_START_TOUCH )
    DefEnumVal                ( NotifyOnEndTouch                    , NX_NOTIFY_ON_END_TOUCH )
    DefEnumVal                ( NotifyOnTouch                       , NX_NOTIFY_ON_TOUCH )
    DefEnumVal                ( NotifyOnImpact                      , NX_NOTIFY_ON_IMPACT )
    DefEnumVal                ( NotifyOnRoll                        , NX_NOTIFY_ON_ROLL )
    DefEnumVal                ( NotifyOnSlide                       , NX_NOTIFY_ON_SLIDE )
    DefEnumVal                ( NotifyForces                        , NX_NOTIFY_FORCES )
    DefEnumVal                ( NotifyOnStartTouchForceThreshold    , NX_NOTIFY_ON_START_TOUCH_FORCE_THRESHOLD )
    DefEnumVal                ( NotifyOnEndTouchForceThreshold      , NX_NOTIFY_ON_END_TOUCH_FORCE_THRESHOLD )
    DefEnumVal                ( NotifyOnTouchForceThreshold         , NX_NOTIFY_ON_TOUCH_FORCE_THRESHOLD )
    DefEnumVal                ( NotifyContactModification           , NX_NOTIFY_CONTACT_MODIFICATION )
    DefEnumVal                ( NotifyAll                           , NX_NOTIFY_ALL )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( ForceModes                          , NxForceMode )
  
    DefEnumVal                ( Force                               , NX_FORCE )
    DefEnumVal                ( Impulse                             , NX_IMPULSE )
    DefEnumVal                ( VelocityChange                      , NX_VELOCITY_CHANGE )
    DefEnumVal                ( SmoothImpulse                       , NX_SMOOTH_IMPULSE )
    DefEnumVal                ( SmoothVelocityChange                , NX_SMOOTH_VELOCITY_CHANGE )
    DefEnumVal                ( Acceleration                        , NX_ACCELERATION )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( MaterialFlags                       , NxMaterialFlag )
  
    DefEnumVal                ( Anisotropic                         , NX_MF_ANISOTROPIC )
    DefEnumVal                ( DisableFriction                     , NX_MF_DISABLE_FRICTION )
    DefEnumVal                ( DisableStrongFriction               , NX_MF_DISABLE_STRONG_FRICTION )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( CombineModes                        , NxCombineMode )
  
    DefEnumVal                ( Average                             , NX_CM_AVERAGE )
    DefEnumVal                ( Min                                 , NX_CM_MIN )
    DefEnumVal                ( Multiply                            , NX_CM_MULTIPLY )
    DefEnumVal                ( Max                                 , NX_CM_MAX )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( ShapeFlags                          , NxShapeFlag )
  
    DefEnumVal                ( TriggerOnEnter                      , NX_TRIGGER_ON_ENTER )
    DefEnumVal                ( TriggerOnLeave                      , NX_TRIGGER_ON_LEAVE )
    DefEnumVal                ( TriggerOnStay                       , NX_TRIGGER_ON_STAY )
    DefEnumVal                ( TriggerEnable                       , TriggerOnEnter | TriggerOnLeave | TriggerOnStay )
    DefEnumVal                ( Visualization                       , NX_SF_VISUALIZATION )
    DefEnumVal                ( DisableCollision                    , NX_SF_DISABLE_COLLISION )
    DefEnumVal                ( FeatureIndices                      , NX_SF_FEATURE_INDICES )
    DefEnumVal                ( DisableRaycasting                   , NX_SF_DISABLE_RAYCASTING )
    DefEnumVal                ( PointContactForce                   , NX_SF_POINT_CONTACT_FORCE )
    DefEnumVal                ( FluidDrain                          , NX_SF_FLUID_DRAIN )
    DefEnumVal                ( FluidDisableCollision               , NX_SF_FLUID_DISABLE_COLLISION )
    DefEnumVal                ( FluidTwoway                         , NX_SF_FLUID_TWOWAY )
    DefEnumVal                ( DisableResponse                     , NX_SF_DISABLE_RESPONSE )
    DefEnumVal                ( DynamicDynamicCCD                   , NX_SF_DYNAMIC_DYNAMIC_CCD )
    DefEnumVal                ( DisableSceneQueries                 , NX_SF_DISABLE_SCENE_QUERIES )
    DefEnumVal                ( ClothDrain                          , NX_SF_CLOTH_DRAIN )
    DefEnumVal                ( ClothDisableCollision               , NX_SF_CLOTH_DISABLE_COLLISION )
    DefEnumVal                ( ClothTwoway                         , NX_SF_CLOTH_TWOWAY )
    DefEnumVal                ( SoftbodyDrain                       , NX_SF_SOFTBODY_DRAIN )
    DefEnumVal                ( SoftbodyDisableCollision            , NX_SF_SOFTBODY_DISABLE_COLLISION )
    DefEnumVal                ( SoftbodyTwoway                      , NX_SF_SOFTBODY_TWOWAY )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( TriggerFlags                        , NxTriggerFlag )
  
    DefEnumVal                ( TriggerOnEnter                      , NX_TRIGGER_ON_ENTER )
    DefEnumVal                ( TriggerOnLeave                      , NX_TRIGGER_ON_LEAVE )
    DefEnumVal                ( TriggerOnStay                       , NX_TRIGGER_ON_STAY )
    DefEnumVal                ( TriggerEnable                       , TriggerOnEnter | TriggerOnLeave | TriggerOnStay )
    DefEnumVal                ( Visualization                       , NX_SF_VISUALIZATION )
    DefEnumVal                ( DisableCollision                    , NX_SF_DISABLE_COLLISION )
    DefEnumVal                ( FeatureIndices                      , NX_SF_FEATURE_INDICES )
    DefEnumVal                ( DisableRaycasting                   , NX_SF_DISABLE_RAYCASTING )
    DefEnumVal                ( PointContactForce                   , NX_SF_POINT_CONTACT_FORCE )
    DefEnumVal                ( FluidDrain                          , NX_SF_FLUID_DRAIN )
    DefEnumVal                ( FluidDisableCollision               , NX_SF_FLUID_DISABLE_COLLISION )
    DefEnumVal                ( FluidTwoway                         , NX_SF_FLUID_TWOWAY )
    DefEnumVal                ( DisableResponse                     , NX_SF_DISABLE_RESPONSE )
    DefEnumVal                ( DynamicDynamicCCD                   , NX_SF_DYNAMIC_DYNAMIC_CCD )
    DefEnumVal                ( DisableSceneQueries                 , NX_SF_DISABLE_SCENE_QUERIES )
    DefEnumVal                ( ClothDrain                          , NX_SF_CLOTH_DRAIN )
    DefEnumVal                ( ClothDisableCollision               , NX_SF_CLOTH_DISABLE_COLLISION )
    DefEnumVal                ( ClothTwoway                         , NX_SF_CLOTH_TWOWAY )
    DefEnumVal                ( SoftbodyDrain                       , NX_SF_SOFTBODY_DRAIN )
    DefEnumVal                ( SoftbodyDisableCollision            , NX_SF_SOFTBODY_DISABLE_COLLISION )
    DefEnumVal                ( SoftbodyTwoway                      , NX_SF_SOFTBODY_TWOWAY )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( ShapeTypes                          , NxShapeType )
  
    DefEnumVal                ( Plane                               , NX_SHAPE_PLANE )
    DefEnumVal                ( Sphere                              , NX_SHAPE_SPHERE )
    DefEnumVal                ( Box                                 , NX_SHAPE_BOX )
    DefEnumVal                ( Capsule                             , NX_SHAPE_CAPSULE )
    DefEnumVal                ( Wheel                               , NX_SHAPE_WHEEL )
    DefEnumVal                ( Convex                              , NX_SHAPE_CONVEX )
    DefEnumVal                ( Mesh                                , NX_SHAPE_MESH )
    DefEnumVal                ( Heightfield                         , NX_SHAPE_HEIGHTFIELD )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( ShapesTypes                         , NxShapesType )
  
    DefEnumVal                ( Static                              , NX_STATIC_SHAPES )
    DefEnumVal                ( Dynamic                             , NX_DYNAMIC_SHAPES )
    DefEnumVal                ( All                                 , NX_ALL_SHAPES )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( TimeStepMethods                     , NxTimeStepMethod )
  
    DefEnumVal                ( Fixed                               , NX_TIMESTEP_FIXED )
    DefEnumVal                ( Variable                            , NX_TIMESTEP_VARIABLE )
    DefEnumVal                ( Inherit                             , NX_TIMESTEP_INHERIT )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( SimulationTypes                     , NxSimulationType )
  
    DefEnumVal                ( Software                            , NX_SIMULATION_SW )
    DefEnumVal                ( Hardware                            , NX_SIMULATION_HW )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( ThreadPriorities                    , NxThreadPriority )
  
    DefEnumVal                ( High                                , NX_TP_HIGH )
    DefEnumVal                ( AboveNormal                         , NX_TP_ABOVE_NORMAL )
    DefEnumVal                ( Normal                              , NX_TP_NORMAL )
    DefEnumVal                ( BelowNormal                         , NX_TP_BELOW_NORMAL )
    DefEnumVal                ( Low                                 , NX_TP_LOW )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( PruningStructures                   , NxPruningStructure )
  
    DefEnumVal                ( None                                , NX_PRUNING_NONE )
    DefEnumVal                ( Octree                              , NX_PRUNING_OCTREE )
    DefEnumVal                ( Quadtree                            , NX_PRUNING_QUADTREE )
    DefEnumVal                ( DynamicAABBTree                     , NX_PRUNING_DYNAMIC_AABB_TREE )
    DefEnumVal                ( StaticAABBTree                      , NX_PRUNING_STATIC_AABB_TREE )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( BroadPhaseTypes                     , NxBroadPhaseType )
  
    DefEnumVal                ( SAPSingle                           , NX_BP_TYPE_SAP_SINGLE )
    DefEnumVal                ( SAPMulti                            , NX_BP_TYPE_SAP_MULTI )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( CompartmentTypes                    , NxCompartmentType )
  
    DefEnumVal                ( SwRigidBody                         , NX_COMPARTMENT_SW_RIGIDBODY )
    DefEnumVal                ( HwRigidBody                         , NX_COMPARTMENT_HW_RIGIDBODY )
    DefEnumVal                ( SwFluid                             , NX_COMPARTMENT_SW_FLUID )
    DefEnumVal                ( HwFluid                             , NX_COMPARTMENT_HW_FLUID )
    DefEnumVal                ( SwCloth                             , NX_COMPARTMENT_SW_CLOTH )
    DefEnumVal                ( HwCloth                             , NX_COMPARTMENT_HW_CLOTH )
    DefEnumVal                ( SwSoftbody                          , NX_COMPARTMENT_SW_SOFTBODY )
    DefEnumVal                ( HwSoftbody                          , NX_COMPARTMENT_HW_SOFTBODY )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( RaycastBits                         , NxRaycastBit )
  
    DefEnumVal                ( Shape                               , NX_RAYCAST_SHAPE )
    DefEnumVal                ( Impact                              , NX_RAYCAST_IMPACT )
    DefEnumVal                ( Normal                              , NX_RAYCAST_NORMAL )
    DefEnumVal                ( FaceIndex                           , NX_RAYCAST_FACE_INDEX )
    DefEnumVal                ( Distance                            , NX_RAYCAST_DISTANCE )
    DefEnumVal                ( UV                                  , NX_RAYCAST_UV )
    DefEnumVal                ( FaceNormal                          , NX_RAYCAST_FACE_NORMAL )
    DefEnumVal                ( Material                            , NX_RAYCAST_MATERIAL )
    DefEnumVal                ( All                                 , 0xFFFFFFFF )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( JointTypes                          , NxJointType )
  
    DefEnumVal                ( Prismatic                           , NX_JOINT_PRISMATIC )
    DefEnumVal                ( Revolute                            , NX_JOINT_REVOLUTE )
    DefEnumVal                ( Cylindrical                         , NX_JOINT_CYLINDRICAL )
    DefEnumVal                ( Spherical                           , NX_JOINT_SPHERICAL )
    DefEnumVal                ( PointOnLine                         , NX_JOINT_POINT_ON_LINE )
    DefEnumVal                ( PointInPlane                        , NX_JOINT_POINT_IN_PLANE )
    DefEnumVal                ( Distance                            , NX_JOINT_DISTANCE )
    DefEnumVal                ( Pulley                              , NX_JOINT_PULLEY )
    DefEnumVal                ( Fixed                               , NX_JOINT_FIXED )
    DefEnumVal                ( D6                                  , NX_JOINT_D6 )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( JointFlags                          , NxJointFlag )
  
    DefEnumVal                ( CollisionEnabled                    , NX_JF_COLLISION_ENABLED )
    DefEnumVal                ( Visualization                       , NX_JF_VISUALIZATION )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( DistanceJointFlags                  , NxDistanceJointFlag )
  
    DefEnumVal                ( MaxDistanceEnabled                  , NX_DJF_MAX_DISTANCE_ENABLED )
    DefEnumVal                ( MinDistanceEnabled                  , NX_DJF_MIN_DISTANCE_ENABLED )
    DefEnumVal                ( SpringEnabled                       , NX_DJF_SPRING_ENABLED )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( PulleyJointFlags                    , NxPulleyJointFlag )
  
    DefEnumVal                ( IsRigid                             , NX_PJF_IS_RIGID )
    DefEnumVal                ( MotorEnabled                        , NX_PJF_MOTOR_ENABLED )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( RevoluteJointFlags                  , NxRevoluteJointFlag )
  
    DefEnumVal                ( LimitEnabled                        , NX_RJF_LIMIT_ENABLED )
    DefEnumVal                ( MotorEnabled                        , NX_RJF_MOTOR_ENABLED )
    DefEnumVal                ( SpringEnabled                       , NX_RJF_SPRING_ENABLED )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( JointProjectionModes                , NxJointProjectionMode )
  
    DefEnumVal                ( None                                , NX_JPM_NONE )
    DefEnumVal                ( PointMindist                        , NX_JPM_POINT_MINDIST )
    DefEnumVal                ( LinearMindist                       , NX_JPM_LINEAR_MINDIST )

DefEnumEnd
//=============================+=====================================+=
DefEnumFlags                  ( SphericalJointFlags                 , NxSphericalJointFlag )
  
    DefEnumVal                ( TwistLimitEnabled                   , NX_SJF_TWIST_LIMIT_ENABLED )
    DefEnumVal                ( SwingLimitEnabled                   , NX_SJF_SWING_LIMIT_ENABLED )
    DefEnumVal                ( TwistSpringEnabled                  , NX_SJF_TWIST_SPRING_ENABLED )
    DefEnumVal                ( SwingSpringEnabled                  , NX_SJF_SWING_SPRING_ENABLED )
    DefEnumVal                ( JointSpringEnabled                  , NX_SJF_JOINT_SPRING_ENABLED )
    DefEnumVal                ( PerpendicularDirConstraints         , NX_SJF_PERPENDICULAR_DIR_CONSTRAINTS )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( JointStates                         , NxJointState )
  
    DefEnumVal                ( Unbound                             , NX_JS_UNBOUND )
    DefEnumVal                ( Simulating                          , NX_JS_SIMULATING )
    DefEnumVal                ( Broken                              , NX_JS_BROKEN )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( NXUFileTypes                        , NXUFileTypes )
  
    DefEnumVal                ( Binary                              , NXU::FT_BINARY )
    DefEnumVal                ( XML                                 , NXU::FT_XML )
    DefEnumVal                ( Collada                             , NXU::FT_COLLADA )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( SimulationStatuses                  , NxSimulationStatus )
  
    DefEnumVal                ( AllFinished                         , NX_ALL_FINISHED )
    DefEnumVal                ( PrimaryFinished                     , NX_PRIMARY_FINISHED )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( QueryReportResults                  , NxQueryReportResult )
  
    DefEnumVal                ( Continue                            , NX_SQR_CONTINUE )
    DefEnumVal                ( AbortQuery                          , NX_SQR_ABORT_QUERY )
    DefEnumVal                ( AbortAllQueries                     , NX_SQR_ABORT_ALL_QUERIES )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( SceneQueryExecuteModes              , NxSceneQueryExecuteMode )
  
    DefEnumVal                ( Synchronous                         , NX_SQE_SYNCHRONOUS )
    DefEnumVal                ( Asynchronous                        , NX_SQE_ASYNCHRONOUS )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( SweepFlags                          , NxSweepFlags )
  
    DefEnumVal                ( Statics                             , NX_SF_STATICS )
    DefEnumVal                ( Dynamics                            , NX_SF_DYNAMICS )
    DefEnumVal                ( Asyn                                , NX_SF_ASYNC )
    DefEnumVal                ( AllHits                             , NX_SF_ALL_HITS )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( Platforms                           , NxPlatform )
  
    DefEnumVal                ( PC                                  , PLATFORM_PC )
    DefEnumVal                ( Xenon                               , PLATFORM_XENON )
    DefEnumVal                ( Playstation3                        , PLATFORM_PLAYSTATION3 )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( HeightFieldAxes                     , NxHeightFieldAxis )
  
    DefEnumVal                ( X                                   , NX_X )
    DefEnumVal                ( Y                                   , NX_Y )
    DefEnumVal                ( Z                                   , NX_Z )
    DefEnumVal                ( NotHeightField                      , NX_NOT_HEIGHTFIELD )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( MeshFlags                           , NxMeshFlags )
  
    DefEnumVal                ( FlipNormals                         , NX_MF_FLIPNORMALS )
    DefEnumVal                ( Indices16Bit                        , NX_MF_16_BIT_INDICES )
    DefEnumVal                ( HardwareMesh                        , NX_MF_HARDWARE_MESH )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( InternalArrays                      , NxInternalArray )
  
    DefEnumVal                ( Triangles                           , NX_ARRAY_TRIANGLES )
    DefEnumVal                ( Vertices                            , NX_ARRAY_VERTICES )
    DefEnumVal                ( Normals                             , NX_ARRAY_NORMALS )
    DefEnumVal                ( HullVertices                        , NX_ARRAY_HULL_VERTICES )
    DefEnumVal                ( HullPolygons                        , NX_ARRAY_HULL_POLYGONS )
    DefEnumVal                ( TrianglesRemap                      , NX_ARRAY_TRIANGLES_REMAP )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( InternalFormats                     , NxInternalFormat )
  
    DefEnumVal                ( NoData                              , NX_FORMAT_NODATA )
    DefEnumVal                ( Float                               , NX_FORMAT_FLOAT )
    DefEnumVal                ( Byte                                , NX_FORMAT_BYTE )
    DefEnumVal                ( Short                               , NX_FORMAT_SHORT )
    DefEnumVal                ( Int                                 , NX_FORMAT_INT )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( MeshShapeFlags                      , NxMeshShapeFlag )
  
    DefEnumVal                ( SmoothSphereCollisions              , NX_MESH_SMOOTH_SPHERE_COLLISIONS )
    DefEnumVal                ( DoubleSided                         , NX_MESH_DOUBLE_SIDED )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( TriangleFlags                       , NxTriangleFlags )
  
    DefEnumVal                ( ActiveEdge01                        , NXTF_ACTIVE_EDGE01 )
    DefEnumVal                ( ActiveEdge12                        , NXTF_ACTIVE_EDGE12 )
    DefEnumVal                ( ActiveEdge20                        , NXTF_ACTIVE_EDGE20 )
    DefEnumVal                ( DoubleSided                         , NXTF_DOUBLE_SIDED )
    DefEnumVal                ( BoundaryEdge01                      , NXTF_BOUNDARY_EDGE01 )
    DefEnumVal                ( BoundaryEdge12                      , NXTF_BOUNDARY_EDGE12 )
    DefEnumVal                ( BoundaryEdge20                      , NXTF_BOUNDARY_EDGE20 )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( QueryFlags                          , NxQueryFlags )
  
    DefEnumVal                ( WorldSpace                          , NX_QUERY_WORLD_SPACE )
    DefEnumVal                ( FirstContact                        , NX_QUERY_FIRST_CONTACT )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( ConvexFlags                         , NxConvexFlags )
  
    DefEnumVal                ( FlipNormals                         , NX_CF_FLIPNORMALS )
    DefEnumVal                ( Indices16Bit                        , NX_CF_16_BIT_INDICES )
    DefEnumVal                ( ComputeConvex                       , NX_CF_COMPUTE_CONVEX )
    DefEnumVal                ( InflateConvex                       , NX_CF_INFLATE_CONVEX )
    DefEnumVal                ( UseUncompressedNormals              , NX_CF_USE_UNCOMPRESSED_NORMALS )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( WheelShapeFlags                     , NxWheelShapeFlags )
  
    DefEnumVal                ( WheelAxisContactNormal              , NX_WF_WHEEL_AXIS_CONTACT_NORMAL )
    DefEnumVal                ( InputLatSlipVelocity                , NX_WF_INPUT_LAT_SLIPVELOCITY )
    DefEnumVal                ( InputLngSlipVelocity                , NX_WF_INPUT_LNG_SLIPVELOCITY )
    DefEnumVal                ( UnscaledSpringBehavior              , NX_WF_UNSCALED_SPRING_BEHAVIOR )
    DefEnumVal                ( AxleSpeedOverride                   , NX_WF_AXLE_SPEED_OVERRIDE )
    DefEnumVal                ( EmulateLegacyWheel                  , NX_WF_EMULATE_LEGACY_WHEEL )
    DefEnumVal                ( ClampedFriction                     , NX_WF_CLAMPED_FRICTION )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( D6JointMotions                      , NxD6JointMotion )
  
    DefEnumVal                ( Locked                              , NX_D6JOINT_MOTION_LOCKED )
    DefEnumVal                ( Limited                             , NX_D6JOINT_MOTION_LIMITED )
    DefEnumVal                ( Free                                , NX_D6JOINT_MOTION_FREE )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( D6JointDriveTypes                   , NxD6JointDriveType )
  
    DefEnumVal                ( Position                            , NX_D6JOINT_DRIVE_POSITION )
    DefEnumVal                ( Velocity                            , NX_D6JOINT_DRIVE_VELOCITY )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( D6JointFlags                        , NxD6JointFlag )
  
    DefEnumVal                ( SlerpDrive                          , NX_D6JOINT_SLERP_DRIVE )
    DefEnumVal                ( GearEnabled                         , NX_D6JOINT_GEAR_ENABLED )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( HeightFieldFormats                  , NxHeightFieldFormat )
  
    DefEnumVal                ( S16TM                               , NX_HF_S16_TM )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( HeightFieldFlags                    , NxHeightFieldFlags )
  
    DefEnumVal                ( NoBoundaryEdges                     , NX_HF_NO_BOUNDARY_EDGES )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( NxClothVertexFlags                  , NxClothVertexFlags )
  
    DefEnumVal                ( Attached                            , NX_CLOTH_VERTEX_ATTACHED )
    DefEnumVal                ( Tearable                            , NX_CLOTH_VERTEX_TEARABLE )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( ClothFlags                          , NxClothFlag )
  
    DefEnumVal                ( Pressure                            , NX_CLF_PRESSURE )
    DefEnumVal                ( Static                              , NX_CLF_STATIC )
    DefEnumVal                ( DisableCollision                    , NX_CLF_DISABLE_COLLISION )
    DefEnumVal                ( SelfCollision                       , NX_CLF_SELFCOLLISION )
    DefEnumVal                ( Visualization                       , NX_CLF_VISUALIZATION )
    DefEnumVal                ( Gravity                             , NX_CLF_GRAVITY )
    DefEnumVal                ( Bending                             , NX_CLF_BENDING )
    DefEnumVal                ( BendingOrtho                        , NX_CLF_BENDING_ORTHO )
    DefEnumVal                ( Damping                             , NX_CLF_DAMPING )
    DefEnumVal                ( CollisionTwoway                     , NX_CLF_COLLISION_TWOWAY )
    DefEnumVal                ( TriangleCollision                   , NX_CLF_TRIANGLE_COLLISION )
    DefEnumVal                ( Tearable                            , NX_CLF_TEARABLE )
    DefEnumVal                ( Hardware                            , NX_CLF_HARDWARE )
    DefEnumVal                ( ComDamping                          , NX_CLF_COMDAMPING )
    DefEnumVal                ( ValidBounds                         , NX_CLF_VALIDBOUNDS )
    DefEnumVal                ( FluidCollision                      , NX_CLF_FLUID_COLLISION )
    DefEnumVal                ( DisableDynamicCCD                   , NX_CLF_DISABLE_DYNAMIC_CCD )
    DefEnumVal                ( Adhere                              , NX_CLF_ADHERE )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( ClothVertexAttachmentStatuses       , NxClothVertexAttachmentStatus )
  
    DefEnumVal                ( None                                , NX_CLOTH_VERTEX_ATTACHMENT_NONE )
    DefEnumVal                ( Global                              , NX_CLOTH_VERTEX_ATTACHMENT_GLOBAL )
    DefEnumVal                ( Shape                               , NX_CLOTH_VERTEX_ATTACHMENT_SHAPE )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( MeshDataFlags                       , NxMeshDataFlags )
  
    DefEnumVal                ( Indices16Bit                        , NX_MDF_16_BIT_INDICES )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( MeshDataDirtyBufferFlags            , NxMeshDataDirtyBufferFlags )
  
    DefEnumVal                ( VertexPositionsDirty                , NX_MDF_VERTICES_POS_DIRTY )
    DefEnumVal                ( VertexNormalsDirty                  , NX_MDF_VERTICES_NORMAL_DIRTY )
    DefEnumVal                ( IndicesDirty                        , NX_MDF_INDICES_DIRTY )
    DefEnumVal                ( ParentIndicesDirty                  , NX_MDF_PARENT_INDICES_DIRTY )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( ClothAttachmentFlags                , NxClothAttachmentFlag )
  
    DefEnumVal                ( Twoway                              , NX_CLOTH_ATTACHMENT_TWOWAY )
    DefEnumVal                ( Tearable                            , NX_CLOTH_ATTACHMENT_TEARABLE )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( EmitterTypes                        , NxEmitterType )
  
    DefEnumVal                ( ConstantPressure                    , NX_FE_CONSTANT_PRESSURE )
    DefEnumVal                ( ConstantFlowRate                    , NX_FE_CONSTANT_FLOW_RATE )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( EmitterShapes                       , NxEmitterShape )
  
    DefEnumVal                ( Rectangular                         , NX_FE_RECTANGULAR )
    DefEnumVal                ( Ellipse                             , NX_FE_ELLIPSE )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( FluidEmitterFlags                   , NxFluidEmitterFlag )
  
    DefEnumVal                ( Visualization                       , NX_FEF_VISUALIZATION )
    DefEnumVal                ( ForceOnBody                         , NX_FEF_FORCE_ON_BODY )
    DefEnumVal                ( AddBodyVelocity                     , NX_FEF_ADD_BODY_VELOCITY )
    DefEnumVal                ( Enabled                             , NX_FEF_ENABLED )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( FluidFlags                          , NxFluidFlag )
  
    DefEnumVal                ( Visualization                       , NX_FF_VISUALIZATION )
    DefEnumVal                ( DisableGravity                      , NX_FF_DISABLE_GRAVITY )
    DefEnumVal                ( CollisionTwoway                     , NX_FF_COLLISION_TWOWAY )
    DefEnumVal                ( Enabled                             , NX_FF_ENABLED )
    DefEnumVal                ( Hardware                            , NX_FF_HARDWARE )
    DefEnumVal                ( PriorityMode                        , NX_FF_PRIORITY_MODE )
    DefEnumVal                ( ProjectToPlane                      , NX_FF_PROJECT_TO_PLANE )
    DefEnumVal                ( ForceStrictCookingFormat            , NX_FF_FORCE_STRICT_COOKING_FORMAT )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( FluidSimulationMethods              , NxFluidSimulationMethod )
  
    DefEnumVal                ( SPH                                 , NX_F_SPH )
    DefEnumVal                ( ParticleInteraction                 , NX_F_NO_PARTICLE_INTERACTION )
    DefEnumVal                ( MixedMode                           , NX_F_MIXED_MODE )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( FluidCollisionMethods               , NxFluidCollisionMethod )
  
    DefEnumVal                ( Static                              , NX_F_STATIC )
    DefEnumVal                ( Dynamic                             , NX_F_DYNAMIC )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( FluidEventTypes                     , NxFluidEventType )
  
    DefEnumVal                ( NoParticlesLeft                     , NX_FET_NO_PARTICLES_LEFT )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( FluidEmitterEventTypes              , NxFluidEmitterEventType )
  
    DefEnumVal                ( EmitterEmpty                        , NX_FEET_EMITTER_EMPTY )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( SoftBodyVertexFlags                 , NxSoftBodyVertexFlags )
  
    DefEnumVal                ( Tearable                            , NX_SOFTBODY_VERTEX_TEARABLE )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( SoftBodyMeshFlags                   , NxSoftBodyMeshFlags )
  
    DefEnumVal                ( Indices16Bit                        , NX_SOFTBODY_MESH_16_BIT_INDICES )
    DefEnumVal                ( Tearable                            , NX_SOFTBODY_MESH_TEARABLE  )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( SoftBodyFlags                       , NxSoftBodyFlag )
  
    DefEnumVal                ( Static                              , NX_SBF_STATIC )
    DefEnumVal                ( DisableCollision                    , NX_SBF_DISABLE_COLLISION )
    DefEnumVal                ( SelfCollision                       , NX_SBF_SELFCOLLISION )
    DefEnumVal                ( Visualization                       , NX_SBF_VISUALIZATION )
    DefEnumVal                ( Gravity                             , NX_SBF_GRAVITY )
    DefEnumVal                ( VolumeConservation                  , NX_SBF_VOLUME_CONSERVATION )
    DefEnumVal                ( Damping                             , NX_SBF_DAMPING )
    DefEnumVal                ( CollisionTwoway                     , NX_SBF_COLLISION_TWOWAY )
    DefEnumVal                ( Tearable                            , NX_SBF_TEARABLE )
    DefEnumVal                ( Hardware                            , NX_SBF_HARDWARE )
    DefEnumVal                ( ComDamping                          , NX_SBF_COMDAMPING )
    DefEnumVal                ( ValidBounds                         , NX_SBF_VALIDBOUNDS )
    DefEnumVal                ( FluidCollision                      , NX_SBF_FLUID_COLLISION )
    DefEnumVal                ( DisableDynamicCCD                   , NX_SBF_DISABLE_DYNAMIC_CCD )
    DefEnumVal                ( Adhere                              , NX_SBF_ADHERE )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( SoftBodyAttachmentFlags             , NxSoftBodyAttachmentFlag )
  
    DefEnumVal                ( Twoway                              , NX_SOFTBODY_ATTACHMENT_TWOWAY )
    DefEnumVal                ( Tearable                            , NX_SOFTBODY_ATTACHMENT_TEARABLE )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( ContactConstrainChangeFlags         , NxUserContactModify::NxContactConstraintChange )
  
    DefEnumVal                ( None                                , NxUserContactModify::NX_CCC_NONE )

    DefEnumVal                ( MinImpulse                          , NxUserContactModify::NX_CCC_MINIMPULSE )
    DefEnumVal                ( MaxImpulse                          , NxUserContactModify::NX_CCC_MAXIMPULSE )
    DefEnumVal                ( Error                               , NxUserContactModify::NX_CCC_ERROR )
    DefEnumVal                ( Target                              , NxUserContactModify::NX_CCC_TARGET )

    DefEnumVal                ( LocalPosition0                      , NxUserContactModify::NX_CCC_LOCALPOSITION0 )
    DefEnumVal                ( LocalPosition1                      , NxUserContactModify::NX_CCC_LOCALPOSITION1 )
    DefEnumVal                ( LocalOrientation0                   , NxUserContactModify::NX_CCC_LOCALORIENTATION0 )
    DefEnumVal                ( LocalOrientation1                   , NxUserContactModify::NX_CCC_LOCALORIENTATION1 )

    DefEnumVal                ( StaticFriction0                     , NxUserContactModify::NX_CCC_STATICFRICTION0 )
    DefEnumVal                ( StaticFriction1                     , NxUserContactModify::NX_CCC_STATICFRICTION1 )
    DefEnumVal                ( DynamicFriction0                    , NxUserContactModify::NX_CCC_DYNAMICFRICTION0 )
    DefEnumVal                ( DynamicFriction1                    , NxUserContactModify::NX_CCC_DYNAMICFRICTION1  )
    DefEnumVal                ( Restitution                         , NxUserContactModify::NX_CCC_RESTITUTION )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( EffectorTypes                       , NxEffectorType )
  
    DefEnumVal                ( SpringAndDamper                     , NX_EFFECTOR_SPRING_AND_DAMPER )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( ForceFieldCoordinates               , NxForceFieldCoordinates )
  
    DefEnumVal                ( Cartesian                           , NX_FFC_CARTESIAN )
    DefEnumVal                ( Spherical                           , NX_FFC_SPHERICAL )
    DefEnumVal                ( Cylindrical                         , NX_FFC_CYLINDRICAL )
    DefEnumVal                ( Toroidal                            , NX_FFC_TOROIDAL )

DefEnumEnd
  
//=============================+=====================================+=
DefEnumFlags                  ( ForceFieldFlags                     , NxForceFieldFlags )
   
    DefEnumVal                ( VolumetricScalingFluid              , NX_FFF_VOLUMETRIC_SCALING_FLUID )
    DefEnumVal                ( VolumetricScalingCloth              , NX_FFF_VOLUMETRIC_SCALING_CLOTH )
    DefEnumVal                ( VolumetricScalingSoftBody           , NX_FFF_VOLUMETRIC_SCALING_SOFTBODY )
    DefEnumVal                ( VolumetricScalingRigidBody          , NX_FFF_VOLUMETRIC_SCALING_RIGIDBODY )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( ForceFieldShapeGroupFlags           , NxForceFieldShapeGroupFlags )
      
    DefEnumVal                ( ExcludeGroup                        , NX_FFSG_EXCLUDE_GROUP )

DefEnumEnd 

//=============================+=====================================+=
DefEnum                       ( ForceFieldTypes                     , NxForceFieldType )
  
    DefEnumVal                ( Gravitational                       , NX_FF_TYPE_GRAVITATIONAL )
    DefEnumVal                ( Other                               , NX_FF_TYPE_OTHER )
    DefEnumVal                ( NoInteraction                       , NX_FF_TYPE_NO_INTERACTION )

DefEnumEnd 

//=============================+=====================================+=
DefEnum                       ( ForceFieldKernelTypes               , NxForcFieldKernelType )
   
    DefEnumVal                ( LinearKernel                        , NX_FFK_LINEAR_KERNEL )
    DefEnumVal                ( CustomKernel                        , NX_FFK_CUSTOM_KERNEL )

DefEnumEnd

//=============================+=====================================+=
public enum class               DebuggerEventMasks
  {
    DefEnumVal                ( Everything                          , NX_DBG_EVENTMASK_EVERYTHING                 )
    // Basic object            
    DefEnumVal                ( BasicObjects                        , NX_DBG_EVENTMASK_BASIC_OBJECTS              )
    DefEnumVal                ( BasicObjectsDynamicData             , NX_DBG_EVENTMASK_BASIC_OBJECTS_DYNAMIC_DATA )
    DefEnumVal                ( BasicObjectsStaticData              , NX_DBG_EVENTMASK_BASIC_OBJECTS_STATIC_DATA  )
    DefEnumVal                ( BasicObjectsAllData                 , NX_DBG_EVENTMASK_BASIC_OBJECTS_ALL_DATA     )
    // Joints                  
    DefEnumVal                ( Joints                              , NX_DBG_EVENTMASK_JOINTS                     )
    DefEnumVal                ( JointsData                          , NX_DBG_EVENTMASK_JOINTS_DATA                )
    // Contacts                
    DefEnumVal                ( Contacts                            , NX_DBG_EVENTMASK_CONTACTS                   )
    DefEnumVal                ( ContactsData                        , NX_DBG_EVENTMASK_CONTACTS_DATA              )
    // Triggers                
    DefEnumVal                ( Triggers                            , NX_DBG_EVENTMASK_TRIGGERS                   )
    // Profiling               
    DefEnumVal                ( Profiling                           , NX_DBG_EVENTMASK_PROFILING                  )
    // Cloth                   
    DefEnumVal                ( Cloth                               , NX_DBG_EVENTMASK_CLOTH                      )
    DefEnumVal                ( ClothDynamicData                    , NX_DBG_EVENTMASK_CLOTH_DYNAMIC_DATA         )
    DefEnumVal                ( ClothStaticData                     , NX_DBG_EVENTMASK_CLOTH_STATIC_DATA          )
    DefEnumVal                ( ClothAllData                        , NX_DBG_EVENTMASK_CLOTH_ALL_DATA             )
    // Fluid                   
    DefEnumVal                ( Fluid                               , NX_DBG_EVENTMASK_FLUID                      )
    DefEnumVal                ( FluidDynamicData                    , NX_DBG_EVENTMASK_FLUID_DYNAMIC_DATA         )
    DefEnumVal                ( FluidStaticData                     , NX_DBG_EVENTMASK_FLUID_STATIC_DATA          )
    DefEnumVal                ( FluidAllData                        , NX_DBG_EVENTMASK_FLUID_ALL_DATA             )

  };

//=============================+=====================================+=
DefEnum                       ( ControllerTypes,                      NxControllerType )

	  DefEnumVal                ( Box,                                  NX_CONTROLLER_BOX     )
	  DefEnumVal                ( Capsule,                              NX_CONTROLLER_CAPSULE )

DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( CapsuleClimbingModes,                 NxCapsuleClimbingMode )

	  DefEnumVal                ( Easy                                , CLIMB_EASY        )
	  DefEnumVal                ( Constrained                         , CLIMB_CONSTRAINED )

DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( CCTInteractionFlags,                  NxCCTInteractionFlag )

	  DefEnumVal                ( Include,                              NXIF_INTERACTION_INCLUDE    )
    DefEnumVal                ( Exclude,                              NXIF_INTERACTION_EXCLUDE    )
	  DefEnumVal                ( UseFilter,                            NXIF_INTERACTION_USE_FILTER )
	  
DefEnumEnd

//=============================+=====================================+=
DefEnum                       ( ControllerActions,                    NxControllerAction )

	  DefEnumVal                ( None,                                 NX_ACTION_NONE )
	  DefEnumVal                ( Push,                                 NX_ACTION_PUSH )
	  
DefEnumEnd

//=============================+=====================================+=
DefEnumFlags                  ( ControllerFlags,                      NxControllerFlag )

	  DefEnumVal                ( Sides,                                NXCC_COLLISION_SIDES )
	  DefEnumVal                ( Up,                                   NXCC_COLLISION_UP    )
	  DefEnumVal                ( Down,                                 NXCC_COLLISION_DOWN  )
	  
DefEnumEnd

//=============================+=====================================+=
#ifndef                         DefXML
                                EndNamespace
#endif
