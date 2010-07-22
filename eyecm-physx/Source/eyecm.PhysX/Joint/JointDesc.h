//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "MiscDesc.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Actor;

//=============================+=====================================+=
public ref struct               JointDesc:                            public giNxProxyData<NxJointDesc>
  {
    private:
      typedef                   ThisNamespace::Actor                  giActor;
      typedef                   ThisNamespace::JointFlags             giJointFlags;

    protected:
      virtual void              Init()
        {
          firstactor  = gcnew ProxyActor( 0, data );
          secondactor = gcnew ProxyActor( 1, data );
        }

    internal:
      JointDesc(NxJointDesc* data): BaseType( data )
        {
          Init();
        }

      ~JointDesc()
        {
          delete firstactor;  firstactor  = nullptr;
          delete secondactor; secondactor = nullptr;
        }

      JointDesc(NxJointDesc& desc): BaseType( desc ) { Init(); }

      static JointDesc^         Wrap(NxJointDesc& desc);

    public:
      JointDesc^                Clone();

    public:
      property JointTypes       Type
        {
          JointTypes            get()                                 { return static_cast<JointTypes>( data->getType() ); }
        }

      property Vector3          GlobalAnchor
        {
          void                  set(Vector3 v)                        { data->setGlobalAnchor( ToNx( v ) ); }
        }

      property Vector3          GlobalAxis
        {
          void                  set(Vector3 v)                        { data->setGlobalAxis( ToNx( v ) ); }
        }

      property float            MaxForce
        {
          float                 get()                                 { return data->maxForce; }
          void                  set(float v)                          { data->maxForce = v; }
        }

      property float            MaxTorque
        {
          float                 get()                                 { return data->maxTorque; }
          void                  set(float v)                          { data->maxTorque = v; }
        }

      property float            SolverExtrapolationFactor
        {
          float                 get()                                 { return data->solverExtrapolationFactor; }
          void                  set(float v)                          { data->solverExtrapolationFactor = v; }
        }

      property bool             UseAccelerationSpring
        {
          bool                  get()                                 { return data->useAccelerationSpring != 0; }
          void                  set(bool v)                           { data->useAccelerationSpring = v ? 1 : 0; }
        }

      property giJointFlags     JointFlags
        {
          giJointFlags          get()                                 { return static_cast<giJointFlags>( data->jointFlags ); }
          void                  set(giJointFlags v)                   { data->jointFlags = static_cast<NxU32>( v ); }
        }

    public:
      ref struct                ProxyActor:                           public giNxProxy<NxJointDesc>
        {
          protected:
            int                 idx;

          internal:
            ProxyActor(int idx, NxJointDesc* data): giNxProxy( data ), idx( idx ) { }

          public:
            property giActor^   Actor
              {
                giActor^        get();
                void            set(giActor^ v);
              }

          property Vector3      LocalNormal
            {
              Vector3           get()                                 { return FromNx( data->localNormal[idx] ); }
              void              set(Vector3 v)                        { data->localNormal[idx] = ToNx( v ); }
            }

          property Vector3      LocalAxis
            {
              Vector3           get()                                 { return FromNx( data->localAxis[idx] ); }
              void              set(Vector3 v)                        { data->localAxis[idx] = ToNx( v ); }
            }

          property Vector3      LocalAnchor
            {
              Vector3           get()                                 { return FromNx( data->localAnchor[idx] ); }
              void              set(Vector3 v)                        { data->localAnchor[idx] = ToNx( v ); }
            }
        };

    internal:
      ProxyActor^               firstactor;
      ProxyActor^               secondactor;

    public:
      property ProxyActor^      First
        {
          ProxyActor^           get()                                 { return firstactor; }
        }

      property ProxyActor^      Second
        {
          ProxyActor^           get()                                 { return secondactor; }
        }

    internal:
      String^                   name;

    public:
      property String^          Name
        {
          String^               get()                                 { return name; }
          void                  set(String^ v)                        { name = v; }
        }

    public:
      void                      SetActors(Actor^ First, Actor^ Second);

    public:
                                DefValidDefault
  };

//=============================+=====================================+=
#define                         DefJointDesc( type ) \
                                DefRecastData( Nx##type##JointDesc, JointDesc ) \
    private: \
      type##JointDesc(NxJointDesc& desc): JointDesc( desc ) { } \
    internal: \
      static inline JointDesc^  Wrap(NxJointDesc& desc)               { return gcnew type##JointDesc( desc ); } \
    public: \
      type##JointDesc(type##JointDesc^ Original): JointDesc( new Nx##type##JointDesc ) \
        { \
          DefThrowOnDisposed( Original, type##Jointdesc, "clone" ) \
          *data = *Original->data; \
          CopyCustom( Original ); \
          PostSet(); \
        } \
    type##JointDesc^            Copy(type##JointDesc^ From) \
      { \
        DefThrowOnDisposed( this, type##JointDesc, "copy to" ) \
        DefThrowOnDisposed( From, type##JointDesc, "copy from" ) \
        *data = *From->data; \
        CopyCustom( From ); \
        PostSet(); \
        return this;  \
      } \
    type##JointDesc^            Clone() new                           { return gcnew type##JointDesc( this ); } \
    \
                                DefValidDefaultXX( data->setToDefault(); PostSet(); , new )


//=============================+=====================================+=
public ref struct               CylindricalJointDesc:                 public JointDesc
  {
    internal:
      DefJointDesc(             Cylindrical );

    public:
      CylindricalJointDesc(): JointDesc( new NxCylindricalJointDesc ) { }
  };

//=============================+=====================================+=
public ref struct               FixedJointDesc:                       public JointDesc
  {
    internal:
      DefJointDesc(             Fixed );

    public:
      FixedJointDesc(): JointDesc( new NxFixedJointDesc ) { }
  };

//=============================+=====================================+=
public ref struct               PointInPlaneJointDesc:                public JointDesc
  {
    internal:
      DefJointDesc(             PointInPlane );

    public:
      PointInPlaneJointDesc(): JointDesc( new NxPointInPlaneJointDesc ) { }
  };

//=============================+=====================================+=
public ref struct               PointOnLineJointDesc:                public JointDesc
  {
    internal:
      DefJointDesc(             PointOnLine );

    public:
      PointOnLineJointDesc(): JointDesc( new NxPointOnLineJointDesc ) { }
  };

//=============================+=====================================+=
public ref struct               PrismaticJointDesc:                   public JointDesc
  {
    internal:
      DefJointDesc(             Prismatic );

    public:
      PrismaticJointDesc(): JointDesc( new NxPrismaticJointDesc ) { }
  };

//=============================+=====================================+=
public ref struct               DistanceJointDesc:                    public JointDesc
  {
    internal:
      DefJointDesc(             Distance );

    public:
      DistanceJointDesc(): JointDesc( new NxDistanceJointDesc ) { }

      ~DistanceJointDesc()
        {
          DefProxyDestroy( Spring )
        }

      !DistanceJointDesc()
        {
        }

  public:
                                DefProxyGetSet( SpringDesc, Spring, spring )
    public:
      DefP0( float,             MaxDistance,                          maxDistance )
      DefP0( float,             MinDistance,                          minDistance )
      DefPc(
        DistanceJointFlags,     Flags,
        NxDistanceJointFlag,    flags
      )
  };

//=============================+=====================================+=
public ref struct               PulleyJointDesc:                      public JointDesc
  {
    internal:
      DefJointDesc(             Pulley );

    protected:
      virtual void              Init() override
        {
          firstactor  = gcnew ProxyPulley( 0, data );
          secondactor = gcnew ProxyPulley( 1, data );
        }

    public:
      PulleyJointDesc(): JointDesc( new NxPulleyJointDesc ) { Init(); }

      ~PulleyJointDesc()
        {
          DefProxyDestroy( Motor )
        }
      !PulleyJointDesc()
        {
        }

    public:
      ref struct                ProxyPulley:                          public ProxyActor
        {
          public:
            ProxyPulley(int idx, NxJointDesc* data): ProxyActor( idx, data ) { }

          public:
            property Vector3    Pulley
              {
                Vector3         get()                                 { return FromNx( static_cast<NxPulleyJointDesc*>( data )->pulley[idx] ); }
                void            set(Vector3 v)                        { static_cast<NxPulleyJointDesc*>( data )->pulley[idx] = ToNx( v ); }
              }
        };

    public:
      property ProxyPulley^     First
        {
          ProxyPulley^          get() new                             { return static_cast<ProxyPulley^>( firstactor ); }
        }

      property ProxyPulley^     Second
        {
          ProxyPulley^          get() new                             { return static_cast<ProxyPulley^>( secondactor ); }
        }

    public:
      DefP0( float,             Distance,                             distance )
      DefP0( float,             Stiffness,                            stiffness )
      DefP0( float,             Ratio,                                ratio )
      DefPc( PulleyJointFlags,  Flags,             NxPulleyJointFlag, flags )

                                DefProxyGetSet( MotorDesc, Motor, motor )
  };

//=============================+=====================================+=
public ref struct               RevoluteJointDesc:                    public JointDesc
  {
    internal:
      DefJointDesc(             Revolute );

    public:
      RevoluteJointDesc(): JointDesc( new NxRevoluteJointDesc ) { }

      ~RevoluteJointDesc()
        {
          DefProxyDestroy( Spring )
          DefProxyDestroy( Motor  )
          DefProxyDestroy( Limit  )
        }
      !RevoluteJointDesc()
        {
        }

    public:
                                DefProxyGetSet( SpringDesc, Spring, spring )
                                DefProxyGetSet( MotorDesc, Motor, motor )

                                DefProxyGetSet( JointLimitPairDesc, Limit, limit )

    public:
      DefP0( float,             ProjectionDistance,                   projectionDistance )
      DefP0( float,             ProjectionAngle,                      projectionAngle )
      DefPc(
        RevoluteJointFlags,     Flags,
        NxRevoluteJointFlag,    flags
      )
      DefPc (
        JointProjectionModes,   ProjectionMode,
        NxJointProjectionMode,  projectionMode
      )
  };

//=============================+=====================================+=
public ref struct               SphericalJointDesc:                   public JointDesc
  {
    internal:
      DefJointDesc(             Spherical );

    public:
      SphericalJointDesc(): JointDesc( new NxSphericalJointDesc ) {}

      ~SphericalJointDesc()
        {
          DefProxyDestroy( TwistSpring )
          DefProxyDestroy( SwingSpring )
          DefProxyDestroy( JointSpring )
          DefProxyDestroy( SwingLimit  )
          DefProxyDestroy( TwistLimit  )
        }
      !SphericalJointDesc()
        {
        }

    public:
      DefProxyGetSet( SpringDesc,         TwistSpring,                twistSpring )
      DefProxyGetSet( SpringDesc,         SwingSpring,                swingSpring )
      DefProxyGetSet( SpringDesc,         JointSpring,                jointSpring )
      DefProxyGetSet( JointLimitDesc,     SwingLimit,                 swingLimit )
      DefProxyGetSet( JointLimitPairDesc, TwistLimit,                 twistLimit )

      DefP0( float,             ProjectionDistance,                   projectionDistance )
      DefPx( Vector3,           SwingAxis,                            swingAxis )
      DefPc(
        SphericalJointFlags,    Flags,
        NxSphericalJointFlag,   flags
      )
      DefPc (
        JointProjectionModes,   ProjectionMode,
        NxJointProjectionMode,  projectionMode
      )
  };

//=============================+=====================================+=
public ref struct               D6JointDesc:                          public JointDesc
  {
    internal:
      DefJointDesc(             D6 );

    public:
      D6JointDesc(): JointDesc( new NxD6JointDesc() ) { }

      ~D6JointDesc()
        {
          DefProxyDestroy( LinearLimit )
          DefProxyDestroy( Swing1Limit )
          DefProxyDestroy( Swing2Limit )
          DefProxyDestroy( TwistLimit  )
          DefProxyDestroy( XDrive      )
          DefProxyDestroy( YDrive      )
          DefProxyDestroy( ZDrive      )
          DefProxyDestroy( SwingDrive  )
          DefProxyDestroy( TwistDrive  )
          DefProxyDestroy( SlerpDrive  )
        }
      !D6JointDesc()
        {
        }

    public:
      #define                   DefJLSD( name, token )                DefProxyGetSet( JointLimitSoftDesc, name, token )
      DefJLSD(                  LinearLimit,                          linearLimit )
      DefJLSD(                  Swing1Limit,                          swing1Limit )
      DefJLSD(                  Swing2Limit,                          swing2Limit )
      #undef                    DefJLSD

      DefProxyGetSet(
        JointLimitSoftPairDesc, TwistLimit,                           twistLimit )

      #define                   DefJDD( name, token )                 DefProxyGetSet( JointDriveDesc, name, token )
      DefJDD(                   XDrive,                               xDrive )
      DefJDD(                   YDrive,                               yDrive )
      DefJDD(                   ZDrive,                               zDrive )
      DefJDD(                   SwingDrive,                           swingDrive )
      DefJDD(                   TwistDrive,                           twistDrive )
      DefJDD(                   SlerpDrive,                           slerpDrive )
      #undef                    DefJDD

      DefPc( D6JointMotions,    XMotion,             NxD6JointMotion, xMotion )
      DefPc( D6JointMotions,    YMotion,             NxD6JointMotion, yMotion )
      DefPc( D6JointMotions,    ZMotion,             NxD6JointMotion, zMotion )
      DefPc( D6JointMotions,    Swing1Motion,        NxD6JointMotion, swing1Motion )
      DefPc( D6JointMotions,    Swing2Motion,        NxD6JointMotion, swing2Motion )
      DefPc( D6JointMotions,    TwistMotion,         NxD6JointMotion, twistMotion )

      DefPx( Vector3,           DrivePosition,                        drivePosition )
      DefPx( Quaternion,        DriveOrientation,                     driveOrientation )
      DefPx( Vector3,           DriveLinearVelocity,                  driveLinearVelocity )
      DefPx( Vector3,           DriveAngularVelocity,                 driveAngularVelocity )
      DefPc(
        JointProjectionModes,   ProjectionMode,
        NxJointProjectionMode,  projectionMode
      )
      DefP0( float,             ProjectionDistance,                   projectionDistance )
      DefP0( float,             ProjectionAngle,                      projectionAngle )
      DefP0( float,             GearRatio,                            gearRatio )
      DefPc( D6JointFlags,      Flags,                 NxD6JointFlag, flags )
  };

//=============================+=====================================+=
                                EndNamespace
