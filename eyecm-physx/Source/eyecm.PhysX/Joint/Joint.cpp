//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Joint.h"
#include                       "JointDesc.h"
#include                       "Scene.h"
#include                       "Actor.h"
#include                       "PhysicsCollection.h"

//=============================+=====================================+=
                                Joint::Joint(giScene^ Scene, NxJoint* ptr, JointDesc^ Desc):
                                  giNxNamedObject( ptr )
  {
    Register( Scene );

    Name = Desc != nullptr ? Desc->Name : nullptr;

    limitplanes = gcnew ProxyLimitPlanes( ptr );
  }

//=============================+=====================================+=
                                Joint::~Joint()
  {
    if( !ptr ) return;

    delete limitplanes; limitplanes = nullptr;

    NxScene* scene = Owner->ptr;

    Unregister();

    if( !scene ) return; // scene is disposing, no need to release explicitly

    scene->releaseJoint( *ptr );
  }

//=============================+=====================================+=
Actor^                          Joint::ActorFirst::get()              { NxActor *a, *b; ptr->getActors( &a, &b ); return Actor::CastOrNull( a ); }
Actor^                          Joint::ActorSecond::get()             { NxActor *a, *b; ptr->getActors( &a, &b ); return Actor::CastOrNull( b ); }

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
#define                         DefJointX( name, init ) \
                                DefRecastPtr( Nx##name##Joint, Joint ) \
      \
      name##Joint(giScene^ Scene, NxJoint* ptr, JointDesc^ Desc): Joint( Scene, ptr, Desc ) { init } \
      \
    public: \
                                DefLoadSaveToDesc( name##Joint )

//=============================+=====================================+=
#define                         DefJoint( name )                      DefJointX( name, {} )
#define                         DefJointI( name )                     DefJointX( name, Init(); )


//=============================+=====================================+=
public ref class                CylindricalJoint:                     public Joint { DefJoint( Cylindrical ) };
public ref class                DistanceJoint:                        public Joint { DefJoint( Distance ) };
public ref class                FixedJoint:                           public Joint { DefJoint( Fixed ) };
public ref class                PointInPlaneJoint:                    public Joint { DefJoint( PointInPlane ) };
public ref class                PointOnLineJoint:                     public Joint { DefJoint( PointOnLine ) };
public ref class                PrismaticJoint:                       public Joint { DefJoint( Prismatic ) };

//=============================+=====================================+=
public ref class                PulleyJoint:                          public Joint
  {
      DefJoint(                 Pulley )

    internal:
      void                      OnMotorChanged(NxMotorDesc* data)     { ptr->setMotor( *data ); }

    public:
      ~PulleyJoint()
        {
          DefProxyDestroy( Motor );
        }
      !PulleyJoint()
        {
        }

    public:
      DefProxyGetSetM( PulleyJoint, MotorDesc, Motor )

      DefMc( PulleyJointFlags,  Flags,             NxPulleyJointFlag, Flags )
  };

//=============================+=====================================+=
public ref class                RevoluteJoint:                        public Joint
  {
      DefJoint(                 Revolute )

    internal:
      void                      OnSpringChanged(NxSpringDesc* data)         { ptr->setSpring( *data ); }
      void                      OnMotorChanged(NxMotorDesc* data)           { ptr->setMotor( *data ); }
      void                      OnLimitsChanged(NxJointLimitPairDesc* data) { ptr->setLimits( *data ); }

    public:
      ~RevoluteJoint()
        {
          DefProxyDestroy( Spring )
          DefProxyDestroy( Motor  )
          DefProxyDestroy( Limits )
        }
      !RevoluteJoint()
        {
        }

    public:
      DefProxyGetSetM( RevoluteJoint, SpringDesc,         Spring )
      DefProxyGetSetM( RevoluteJoint, MotorDesc,          Motor  )
      DefProxyGetSetM( RevoluteJoint, JointLimitPairDesc, Limits )

    public:
      DefMc (
        RevoluteJointFlags,     Flags,
        NxU32,                  Flags
      )
      DefMc(
        JointProjectionModes,   ProjectionMode,
        NxJointProjectionMode,  ProjectionMode
      )

      Defm0( float,             Angle,                                Angle )
      Defm0( float,             Velocity,                             Velocity )
  };

//=============================+=====================================+=
public ref class                SphericalJoint:                       public Joint
  {
      DefJoint(                 Spherical )

    public:
      DefMc (
        SphericalJointFlags,    Flags,
        NxU32,                  Flags
      )
      DefMc(
        JointProjectionModes,   ProjectionMode,
        NxJointProjectionMode,  ProjectionMode
      )
  };

//=============================+=====================================+=
public ref class                D6Joint:                              public Joint
  {
      DefJoint(                 D6 )

    public:
      property Vector3          DrivePosition
        {
          void                  set(Vector3 v)                        { ptr->setDrivePosition( ToNx( v ) ); }
        }

      property Quaternion       DriveOrientation
        {
          void                  set(Quaternion v)                     { ptr->setDriveOrientation( ToNx( v ) ); }
        }

      property Vector3          DriveLinearVelocity
        {
          void                  set(Vector3 v)                        { ptr->setDriveLinearVelocity( ToNx( v ) ); }
        }

      property Vector3          DriveAngularVelocity
        {
          void                  set(Vector3 v)                        { ptr->setDriveAngularVelocity( ToNx( v ) ); }
        }
  };

//=============================+=====================================+=
                                EndNamespace


//=============================+=====================================+=
Joint^                          Joint::Wrap(Joint::giScene^ Scene, NxJoint* ptr, JointDesc^ Desc)
  {
    #define                     DefWrap( name )\
      if( Nx##name##Joint* j = ptr->is##name##Joint() ) return gcnew name##Joint( Scene, ptr, Desc );

      DefWrap( Cylindrical )
      DefWrap( Distance )
      DefWrap( Fixed )
      DefWrap( PointInPlane )
      DefWrap( PointOnLine )
      DefWrap( Prismatic )
      DefWrap( Pulley )
      DefWrap( Revolute )
      DefWrap( Spherical )
      DefWrap( D6 )

    #undef                      DefWrap

    throw gcnew Exception();
  }

//=============================+=====================================+=
Joint^                          Joint::Wrap(NxJoint* ptr)
  {
    return Wrap( giScene::Cast( &ptr->getScene() ), ptr, nullptr );
  }

//=============================+=====================================+=
Joint^                          Scene::CreateJoint(JointDesc^ Desc)
  {
    NxJoint* jointptr = ptr->createJoint( *Desc->data );
    return jointptr ? Joint::Wrap( this, jointptr, Desc ) : nullptr;
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddJoint(Joint^ Object, UserPropertiesType UserProperties, String^ ID)
  {
    const char* id    = ToNx( ID );
    const char* props = ToChar( UserProperties );

    bool Result = addJoint( *this->ptr, *Object->ptr, props, id );
    
    delete[] props;
    delete[] id;
    return Result;
  }
