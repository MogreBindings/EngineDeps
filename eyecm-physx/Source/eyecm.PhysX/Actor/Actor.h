//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "BodyDesc.h"
#include                       "ActorDesc.h"
#include                       "userentityreport.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Shape;
ref class                       Scene;
value struct                    SweepQueryHit;
ref class                       SweepQueryHits;

// TODO: StaticActor base class would be nice
//=============================+=====================================+=
public ref class                Actor:                                public giNxNamedObject<NxActor, Actor, giNxRegisteredObject<Scene> >
  {
    internal:
      typedef                   ThisNamespace::Scene                  giScene;

      ActorUserDataType         user;

      giNxRegisteredObject<Actor>^ First;

    private:
      typedef                   ReadOnlyCollection<Shape^>            ShapeList;

      ShapeList^                shapelist;
      static long               counter;

    internal:
      Actor(Scene^ Scene, NxActor* ptr, ActorDesc^ Desc);

      static Actor^             Wrap(NxActor* ptr);

    public:
      ~Actor();

    public:
      property
      ActorUserDataType         ActorUserDataName
        {
          ActorUserDataType     get()                                 { return user; }
          void                  set(ActorUserDataType v)              { user = v; }
        }

      property giScene^         Scene
        {
          giScene^              get()                                 { return Owner; }
        }

      //-------------------------------------------------------------
      //-------------------------------------------------------------
      //-------------------------------------------------------------

      property bool             IsDynamic
        {
          bool                  get()                                 { return ptr->isDynamic(); }
        }

      property float            ComputedKineticEnergy
        {
          float                 get()                                 { return ptr->computeKineticEnergy(); }
        }

      property unsigned         Group
        {
          unsigned              get()                                 { return ptr->getGroup(); }
          void                  set(unsigned v)                       { ptr->setGroup( static_cast<NxActorGroup>( v ) ); }
        }

      property unsigned         DominanceGroup
        {
          unsigned              get()                                 { return ptr->getDominanceGroup(); }
          void                  set(unsigned v)                       { ptr->setDominanceGroup( static_cast<NxDominanceGroup>( v ) ); }
        }

      property unsigned         SolverIterationCount
        {
          unsigned              get()                                 { return ptr->getSolverIterationCount(); }
          void                  set(unsigned v)                       { ptr->setSolverIterationCount( v ); }
        }

      property float            ContactReportThreshold
        {
          float                 get()                                 { return ptr->getContactReportThreshold(); }
          void                  set(float v)                          { ptr->setContactReportThreshold( v ); }
        }

      property ContactPairFlags ContactReportFlags
        {
          ContactPairFlags      get()                                 { return static_cast<ContactPairFlags>( ptr->getContactReportFlags() ); }
          void                  set(ContactPairFlags f)               { ptr->setContactReportFlags( static_cast<NxU32>( f ) ); }
        }

      property unsigned         ForceFieldMaterial
        {
          unsigned              get()                                 { return ptr->getForceFieldMaterial(); }
          void                  set(unsigned v)                       { ptr->setForceFieldMaterial( static_cast<NxForceFieldMaterial>( v ) ); }
        }

      void                      ResetUserActorPairFiltering()         { ptr->resetUserActorPairFiltering(); }


      //-------------------------------------------------------------
      //---------------------== Global pose ==-----------------------
      //-------------------------------------------------------------

      property Vector3          GlobalPosition
        {
          Vector3               get()                                 { return FromNx( ptr->getGlobalPosition() ); }
          void                  set(Vector3 v)                        { ptr->setGlobalPosition( ToNx( v ) ); }
        }

      property Matrix4x4        GlobalPose
        {
          Matrix4x4             get()                                 { return FromNx( ptr->getGlobalPose() ); }
          void                  set(Matrix4x4 v)                      { ptr->setGlobalPose( ToNx( v ) ); }
        }

      property Matrix3x3        GlobalOrientation
        {
          Matrix3x3             get()                                 { return FromNx( ptr->getGlobalOrientation() ); }
          void                  set(Matrix3x3 v)                      { ptr->setGlobalOrientation( ToNx( v ) ); }
        }

      property Quaternion       GlobalOrientationQuaternion
        {
          Quaternion            get()                                 { return FromNx( ptr->getGlobalOrientationQuat() ); }
          void                  set(Quaternion v)                     { ptr->setGlobalOrientationQuat( ToNx( v ) ); }
        }


      //-------------------------------------------------------------
      //---------------------== Kinematic actors ==------------------
      //-------------------------------------------------------------

      void                      MoveGlobalPose(Matrix4x4 v)           { ptr->moveGlobalPose( ToNx( v ) ); }
      void                      MoveGlobalPosition(Vector3 v)         { ptr->moveGlobalPosition( ToNx( v ) ); }
      void                      MoveGlobalOrientation(Matrix3x3 v)    { ptr->moveGlobalOrientation( ToNx( v ) ); }
      void                      MoveGlobalOrientation(Quaternion v)   { ptr->moveGlobalOrientationQuat( ToNx( v ) ); }


      //-------------------------------------------------------------
      //---------------------== Mass manipulation ==-----------------
      //-------------------------------------------------------------

      property Matrix4x4        CMassOffsetLocalPose
        {
          void                  set(Matrix4x4 v)                      { ptr->setCMassOffsetLocalPose( ToNx( v ) ); }
        }

      property Vector3          CMassOffsetLocalPosition
        {
          void                  set(Vector3 v)                        { ptr->setCMassOffsetLocalPosition( ToNx( v ) ); }
        }

      property Matrix3x3        CMassOffsetLocalOrientation
        {
          void                  set(Matrix3x3 v)                      { ptr->setCMassOffsetLocalOrientation( ToNx( v ) ); }
        }

      property Matrix4x4        CMassOffsetGlobalPose
        {
          void                  set(Matrix4x4 v)                      { ptr->setCMassOffsetGlobalPose( ToNx( v ) ); }
        }

      property Vector3          CMassOffsetGlobalPosition
        {
          void                  set(Vector3 v)                        { ptr->setCMassOffsetGlobalPosition( ToNx( v ) ); }
        }

      property Matrix3x3        CMassOffsetGlobalOrientation
        {
          void                  set(Matrix3x3 v)                      { ptr->setCMassOffsetGlobalOrientation( ToNx( v ) ); }
        }

      property Matrix4x4        CMassGlobalPose
        {
          Matrix4x4             get()                                 { return FromNx( ptr->getCMassGlobalPose() ); }
          void                  set(Matrix4x4 v)                      { ptr->setCMassGlobalPose( ToNx( v ) ); }
        }

      property Vector3          CMassGlobalPosition
        {
          Vector3               get()                                 { return FromNx( ptr->getCMassGlobalPosition() ); }
          void                  set(Vector3 v)                        { ptr->setCMassGlobalPosition( ToNx( v ) ); }
        }

      property Matrix3x3        CMassGlobalOrientation
        {
          Matrix3x3             get()                                 { return FromNx( ptr->getCMassGlobalOrientation() ); }
          void                  set(Matrix3x3 v)                      { ptr->setCMassGlobalOrientation( ToNx( v ) ); }
        }

      property Matrix4x4        CMassLocalPose
        {
          Matrix4x4             get()                                 { return FromNx( ptr->getCMassLocalPose() ); }
        }

      property Vector3          CMassLocalPosition
        {
          Vector3               get()                                 { return FromNx( ptr->getCMassLocalPosition() ); }
        }

      property Matrix3x3        CMassLocalOrientation
        {
          Matrix3x3             get()                                 { return FromNx( ptr->getCMassLocalOrientation() ); }
        }

      property float            Mass
        {
          float                 get()                                 { return ptr->getMass(); }
          void                  set(float v)                          { ptr->setMass( v ); }
        }

      property Vector3          MassSpaceInertiaTensor
        {
          Vector3               get()                                 { return FromNx( ptr->getMassSpaceInertiaTensor() ); }
          void                  set(Vector3 v)                        { ptr->setMassSpaceInertiaTensor( ToNx( v ) ); }
        }

      property Matrix3x3        GlobalInertiaTensor
        {
          Matrix3x3             get()                                 { return FromNx( ptr->getGlobalInertiaTensor() ); }
        }

      property Matrix3x3        GlobalInertiaTensorInverse
        {
          Matrix3x3             get()                                 { return FromNx( ptr->getGlobalInertiaTensorInverse() ); }
        }

      void                      UpdateMassFromShapes(float Density, float TotalMass) { ptr->updateMassFromShapes( Density, TotalMass ); }


      //-------------------------------------------------------------
      //---------------------== Damping ==---------------------------
      //-------------------------------------------------------------

      property float            LinearDamping
        {
          float                 get()                                 { return ptr->getLinearDamping(); }
          void                  set(float v)                          { ptr->setLinearDamping( v ); }
        }

      property float            AngularDamping
        {
          float                 get()                                 { return ptr->getAngularDamping(); }
          void                  set(float v)                          { ptr->setAngularDamping( v ); }
        }


      //-------------------------------------------------------------
      //---------------------== Velocity ==--------------------------
      //-------------------------------------------------------------

      property Vector3          LinearVelocity
        {
          Vector3               get()                                 { return FromNx( ptr->getLinearVelocity() ); }
          void                  set(Vector3 v)                        { ptr->setLinearVelocity( ToNx( v ) ); }
        }

      property Vector3          AngularVelocity
        {
          Vector3               get()                                 { return FromNx( ptr->getAngularVelocity() ); }
          void                  set(Vector3 v)                        { ptr->setAngularVelocity( ToNx( v ) ); }
        }

      property float            MaxAngularVelocity
        {
          float                 get()                                 { return ptr->getMaxAngularVelocity(); }
          void                  set(float v)                          { ptr->setMaxAngularVelocity( v ); }
        }


      //-------------------------------------------------------------
      //---------------------== CCD ==-------------------------------
      //-------------------------------------------------------------

      property float            CCDMotionThreshold
        {
          float                 get()                                 { return ptr->getCCDMotionThreshold(); }
          void                  set(float v)                          { ptr->setCCDMotionThreshold( v ); }
        }


      //-------------------------------------------------------------
      //---------------------== Momentum ==--------------------------
      //-------------------------------------------------------------

      property Vector3          LinearMomentum
        {
          Vector3               get()                                 { return FromNx( ptr->getLinearMomentum() ); }
          void                  set(Vector3 v)                        { ptr->setLinearMomentum( ToNx( v ) ); }
        }

      property Vector3          AngularMomentum
        {
          Vector3               get()                                 { return FromNx( ptr->getAngularMomentum() ); }
          void                  set(Vector3 v)                        { ptr->setAngularMomentum( ToNx( v ) ); }
        }


      //-------------------------------------------------------------
      //---------------------== Sleeping ==--------------------------
      //-------------------------------------------------------------

      property bool             IsGroupSleeping
        {
          bool                  get()                                 { return ptr->isGroupSleeping(); }
        }

      property bool             IsSleeping
        {
          bool                  get()                                 { return ptr->isSleeping(); }
        }

      property float            SleepLinearVelocity
        {
          float                 get()                                 { return ptr->getSleepLinearVelocity(); }
          void                  set(float v)                          { ptr->setSleepLinearVelocity( v ); }
        }

      property float            SleepAngularVelocity
        {
          float                 get()                                 { return ptr->getSleepAngularVelocity(); }
          void                  set(float v)                          { ptr->setSleepAngularVelocity( v ); }
        }

      property float            SleepEnergyThreshold
        {
          float                 get()                                 { return ptr->getSleepEnergyThreshold(); }
          void                  set(float v)                          { ptr->setSleepEnergyThreshold( v ); }
        }

      void                      WakeUp()                              { WakeUp( NX_SLEEP_INTERVAL ); }
      void                      WakeUp(float Interval)                { ptr->wakeUp( Interval ); }

      void                      PutToSleep()                          { ptr->putToSleep(); }

    public:
      //-------------------------------------------------------------
      //---------------------== ProxyActorFlags ==-------------------
      //-------------------------------------------------------------

    public:
      ref class                 ProxyActorFlags:                      public giNxProxy<NxActor>
        {
          internal:
            ProxyActorFlags(NxActor* data): giNxProxy( data ) { }

          public:
          #define               DefFlag( name, token ) \
            virtual \
            property bool       name \
              { \
                bool            get()                                 { return data->readActorFlag( token ); } \
                void            set(bool v)                           { if( v ) data->raiseActorFlag( token ); else data->clearActorFlag( token ); } \
              } \

            DefFlag           ( DisableCollision                      , NX_AF_DISABLE_COLLISION )
            DefFlag           ( DisableResponse                       , NX_AF_DISABLE_RESPONSE )
            DefFlag           ( LockCom                               , NX_AF_LOCK_COM )
            DefFlag           ( FluidDisableCollision                 , NX_AF_FLUID_DISABLE_COLLISION )
            DefFlag           ( ContactModification                   , NX_AF_CONTACT_MODIFICATION )
            DefFlag           ( ForceConeFriction                     , NX_AF_FORCE_CONE_FRICTION )
            DefFlag           ( UserActorPairFiltering                , NX_AF_USER_ACTOR_PAIR_FILTERING )

          #undef                DefFlag
        };

    private:
      ProxyActorFlags^          flags;

    public:
      property ProxyActorFlags^ ActorFlags
        {
          ProxyActorFlags^      get()                                 { return flags; }
        }


    public:
      //-------------------------------------------------------------
      //---------------------== ProxyBodyFlags ==--------------------
      //-------------------------------------------------------------

    public:
      ref class                 ProxyBodyFlags:                       public giNxProxy<NxActor>//, IBodyFlags
        {
          internal:
            ProxyBodyFlags(NxActor* data): giNxProxy( data ) { }

          public:
          #define               DefFlag( name, token ) \
            virtual \
            property bool       name \
              { \
                bool            get()                                 { return data->readBodyFlag( token ); } \
                void            set(bool v)                           { if( v ) data->raiseBodyFlag( token ); else data->clearBodyFlag( token ); } \
              } \

            DefFlag           ( DisableGravity                        , NX_BF_DISABLE_GRAVITY )
            DefFlag           ( FrozenPosX                            , NX_BF_FROZEN_POS_X )
            DefFlag           ( FrozenPosY                            , NX_BF_FROZEN_POS_Y )
            DefFlag           ( FrozenPosZ                            , NX_BF_FROZEN_POS_Z )
            DefFlag           ( FrozenRotX                            , NX_BF_FROZEN_ROT_X )
            DefFlag           ( FrozenRotY                            , NX_BF_FROZEN_ROT_Y )
            DefFlag           ( FrozenRotZ                            , NX_BF_FROZEN_ROT_Z )
            DefFlag           ( FrozenPos                             , NX_BF_FROZEN_POS )
            DefFlag           ( FrozenRot                             , NX_BF_FROZEN_ROT )
            DefFlag           ( Frozen                                , NX_BF_FROZEN )
            DefFlag           ( Kinematic                             , NX_BF_KINEMATIC )
            DefFlag           ( Visualization                         , NX_BF_VISUALIZATION )
            DefFlag           ( FilterSleepVel                        , NX_BF_FILTER_SLEEP_VEL )
            DefFlag           ( EnergySleepTest                       , NX_BF_ENERGY_SLEEP_TEST )

          #undef                DefFlag
        };

    private:
      ProxyBodyFlags^           bodyflags;

    public:
      property ProxyBodyFlags^  BodyFlags
        {
          ProxyBodyFlags^       get()                                 { return bodyflags; }
        }

    public:
      //-------------------------------------------------------------
      //---------------------== Forces ==----------------------------
      //-------------------------------------------------------------

      void                      AddForceAtPos(Vector3 Force, Vector3 Position )                                         { AddForceAtPos( Force, Position, ForceModes::Force, true ); }
      void                      AddForceAtPos(Vector3 Force, Vector3 Position, ForceModes Mode )                        { AddForceAtPos( Force, Position, Mode, true ); }
      void                      AddForceAtPos(Vector3 Force, Vector3 Position, ForceModes Mode, bool WakeUp )           { ptr->addForceAtPos( ToNx( Force ), ToNx( Position ), static_cast<NxForceMode>( Mode ), WakeUp );}

      void                      AddForceAtLocalPos( Vector3 Force,  Vector3 Position )                                    { AddForceAtLocalPos( Force, Position, ForceModes::Force, true ); }
      void                      AddForceAtLocalPos( Vector3 Force,  Vector3 Position, ForceModes Mode )                   { AddForceAtLocalPos( Force, Position, Mode, true ); }
      void                      AddForceAtLocalPos( Vector3 Force,  Vector3 Position, ForceModes Mode, bool WakeUp )      { ptr->addForceAtLocalPos( ToNx( Force ), ToNx( Position ), static_cast<NxForceMode>( Mode ), WakeUp );}

      void                      AddLocalForceAtPos( Vector3 Force,  Vector3 Position )                                    { AddLocalForceAtPos( Force, Position, ForceModes::Force, true ); }
      void                      AddLocalForceAtPos( Vector3 Force,  Vector3 Position, ForceModes Mode )                   { AddLocalForceAtPos( Force, Position, Mode, true ); }
      void                      AddLocalForceAtPos( Vector3 Force,  Vector3 Position, ForceModes Mode, bool WakeUp )      { ptr->addLocalForceAtPos( ToNx( Force ), ToNx( Position ), static_cast<NxForceMode>( Mode ), WakeUp );}

      void                      AddLocalForceAtLocalPos( Vector3 Force,  Vector3 Position )                               { AddLocalForceAtLocalPos( Force, Position, ForceModes::Force, true ); }
      void                      AddLocalForceAtLocalPos( Vector3 Force,  Vector3 Position, ForceModes Mode )              { AddLocalForceAtLocalPos( Force, Position, Mode, true ); }
      void                      AddLocalForceAtLocalPos( Vector3 Force,  Vector3 Position, ForceModes Mode, bool WakeUp ) { ptr->addLocalForceAtLocalPos( ToNx( Force ), ToNx( Position ), static_cast<NxForceMode>( Mode ), WakeUp );}


      void                      AddForce( Vector3 Force )                                      { AddForce( Force, ForceModes::Force, true ); }
      void                      AddForce( Vector3 Force, ForceModes Mode )                     { AddForce( Force, Mode, true ); }
      void                      AddForce( Vector3 Force, ForceModes Mode, bool WakeUp )        { ptr->addForce( ToNx( Force ), static_cast<NxForceMode>( Mode ), WakeUp );}

      void                      AddLocalForce( Vector3 Force )                                 { AddLocalForce( Force, ForceModes::Force, true ); }
      void                      AddLocalForce( Vector3 Force, ForceModes Mode )                { AddLocalForce( Force, Mode, true ); }
      void                      AddLocalForce( Vector3 Force, ForceModes Mode, bool WakeUp )   { ptr->addLocalForce( ToNx( Force ), static_cast<NxForceMode>( Mode ), WakeUp );}

      void                      AddTorque( Vector3 Torque )                                    { AddTorque( Torque, ForceModes::Force, true ); }
      void                      AddTorque( Vector3 Torque, ForceModes Mode )                   { AddTorque( Torque, Mode, true ); }
      void                      AddTorque( Vector3 Torque, ForceModes Mode, bool WakeUp )      { ptr->addTorque( ToNx( Torque ), static_cast<NxForceMode>( Mode ), WakeUp );}

      void                      AddLocalTorque( Vector3 Torque )                               { AddLocalTorque( Torque, ForceModes::Force, true ); }
      void                      AddLocalTorque( Vector3 Torque, ForceModes Mode )              { AddLocalTorque( Torque, Mode, true ); }
      void                      AddLocalTorque( Vector3 Torque, ForceModes Mode, bool WakeUp ) { ptr->addLocalTorque( ToNx( Torque ), static_cast<NxForceMode>( Mode ), WakeUp );}

    public:
      unsigned                  LinearSweep(Vector3 Motion, SweepFlags Flags, Object^ UserData, unsigned MaxHits, [Out] SweepQueryHits^% Shapes, IUserEntityReport<SweepQueryHit>^ Report);

    public:
      //-------------------------------------------------------------
      //---------------------== Shapes ==----------------------------
      //-------------------------------------------------------------

      property ShapeList^       Shapes
        {
          ShapeList^            get()                                 { return shapelist; }
        }

      Shape^                    CreateShape(ShapeDesc^ Shape);

    public:
                                DefSaveToDesc( Actor )
  };

//=============================+=====================================+=
                                EndNamespace

