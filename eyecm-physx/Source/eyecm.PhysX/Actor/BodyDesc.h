//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public ref struct               BodyDesc:                             giNxProxyData<NxBodyDesc>
  {
    private:
      BodyDesc(NxBodyDesc& data): BaseType( data ) { }

    internal:
      inline static BodyDesc^   Wrap(const NxBodyDesc* desc)          { return gcnew BodyDesc( const_cast<NxBodyDesc&>( *desc ) ); }

      DefDataConstructors( BodyDesc )

    public:
      BodyDesc() { Init(); }

      BodyDesc(float LinearDamping, float AngularDamping)
        {
          Init();

          this->LinearDamping  = LinearDamping;
          this->AngularDamping = AngularDamping;
        }

      ~BodyDesc() { bodyflags = nullptr; }

    public:
      property Matrix4x4        MassLocalPose
        {
          Matrix4x4             get()                                 { return FromNx( data->massLocalPose ); }
          void                  set(Matrix4x4 v)                      { data->massLocalPose = ToNx( v ); }
        }

      property Vector3          MassSpaceInertia
        {
          Vector3               get()                                 { return FromNx( data->massSpaceInertia ); }
          void                  set(Vector3 v)                        { data->massSpaceInertia = ToNx( v ); }
        }

      property float            Mass
        {
          float                 get()                                 { return data->mass; }
          void                  set(float v)                          { data->mass = v; }
        }

      property Vector3          LinearVelocity
        {
          Vector3               get()                                 { return FromNx( data->linearVelocity ); }
          void                  set(Vector3 v)                        { data->linearVelocity = ToNx( v ); }
        }

      property Vector3          AngularVelocity
        {
          Vector3               get()                                 { return FromNx( data->angularVelocity ); }
          void                  set(Vector3 v)                        { data->angularVelocity = ToNx( v ); }
        }

      property float            WakeUpCounter
        {
          float                 get()                                 { return data->wakeUpCounter; }
          void                  set(float v)                          { data->wakeUpCounter = v; }
        }

      property float            LinearDamping
        {
          float                 get()                                 { return data->linearDamping; }
          void                  set(float v)                          { data->linearDamping = v; }
        }

      property float            AngularDamping
        {
          float                 get()                                 { return data->angularDamping; }
          void                  set(float v)                          { data->angularDamping = v; }
        }

      property float            MaxAngularVelocity
        {
          float                 get()                                 { return data->maxAngularVelocity; }
          void                  set(float v)                          { data->maxAngularVelocity = v; }
        }

      property float            CCDMotionThreshold
        {
          float                 get()                                 { return data->CCDMotionThreshold; }
          void                  set(float v)                          { data->CCDMotionThreshold = v; }
        }

      property float            SleepLinearVelocity
        {
          float                 get()                                 { return data->sleepLinearVelocity; }
          void                  set(float v)                          { data->sleepLinearVelocity = v; }
        }

      property float            SleepAngularVelocity
        {
          float                 get()                                 { return data->sleepAngularVelocity; }
          void                  set(float v)                          { data->sleepAngularVelocity = v; }
        }

      property unsigned         SolverIterationCount
        {
          unsigned              get()                                 { return data->solverIterationCount; }
          void                  set(unsigned v)                       { data->solverIterationCount = v; }
        }

      property float            SleepEnergyThreshold
        {
          float                 get()                                 { return data->sleepEnergyThreshold; }
          void                  set(float v)                          { data->sleepEnergyThreshold = v; }
        }

      property float            SleepDamping
        {
          float                 get()                                 { return data->sleepDamping; }
          void                  set(float v)                          { data->sleepDamping = v; }
        }

      property float            ContactReportThreshold
        {
          float                 get()                                 { return data->contactReportThreshold; }
          void                  set(float v)                          { data->contactReportThreshold= v; }
        }

    public:
      //-------------------------------------------------------------
      //---------------------== IBodyFlags ==------------------------
      //-------------------------------------------------------------

    public:
      ref class                 ProxyBodyFlags
        {
          private:
            NxBodyDesc*         data;

          internal:
            ProxyBodyFlags(NxBodyDesc* data) { this->data = data; }

          public:
          #define               DefFlag( name, token ) \
            virtual \
            property bool       name \
              { \
                bool            get()                                 { return (data->flags & token) == token; } \
                void            set(bool v)                           { if( v ) data->flags |= token; else data->flags &= ~token; } \
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

      void                      Init()
        {
          bodyflags = gcnew ProxyBodyFlags( data );
        }

    public:
      property ProxyBodyFlags^  BodyFlags
        {
          ProxyBodyFlags^       get()                                 { return bodyflags; }
        }
  };

//=============================+=====================================+=
                                EndNamespace

