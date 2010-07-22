//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "FluidDesc.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Fluid;

//=============================+=====================================+=
public ref class                FluidEmitter:                         public giNxNamedObject<NxFluidEmitter, FluidEmitter, giNxRegisteredObject<Fluid>>
  {
    internal:
      typedef                   ThisNamespace::Fluid                  giFluid;

      FluidEmitter(giFluid^, NxFluidEmitter*);

      static FluidEmitter^      Wrap(NxFluidEmitter*);

    public:
      ~FluidEmitter();
      !FluidEmitter();

    public:
      property giFluid^         Fluid
        {
          giFluid^              get()                                 { return Owner; }
        }

    public:
                                DefLoadSaveToDesc( FluidEmitter )
    public:
      DefMx( Matrix4x4,         GlobalPose,                           GlobalPose )
      DefMx( Vector3,           GlobalPosition,                       GlobalPosition )
      DefMx( Matrix3x3,         GlobalOrientation,                    GlobalOrientation )
      DefMx( Matrix4x4,         LocalPose,                            LocalPose )
      DefMx( Vector3,           LocalPosition,                        LocalPosition )
      DefMx( Matrix3x3,         LocalOrientation,                     LocalOrientation )
      Defm0( float,             DimensionX,                           DimensionX )
      Defm0( float,             DimensionY,                           DimensionY )
      DefMx( Vector3,           RandomPosition,                       RandomPos )
      DefM0( float,             RandomAngle,                          RandomAngle )
      DefM0( float,             FluidVelocityMagnitude,               FluidVelocityMagnitude )
      DefM0( float,             Rate,                                 Rate )
      DefM0( float,             ParticleLifetime,                     ParticleLifetime )
      DefM0( float,             RepulsionCoefficient,                 RepulsionCoefficient )
      Defm0( unsigned,          MaxParticleCount,                     MaxParticles )
      Defm0( unsigned,          EmittedParticleCount,                 NbParticlesEmitted )

      property Shape^           FrameShape                            { Shape^ get(); void set(Shape^); }

      EmitterShapes             GetShape(EmitterShapes Shape)
        {
          return static_cast<EmitterShapes>( ptr->getShape( static_cast<NxEmitterShape>( Shape ) ) );
        }

      EmitterTypes              GetType(EmitterTypes Type)
        {
          return static_cast<EmitterTypes>( ptr->getType( static_cast<NxEmitterType>( Type ) ) );
        }

      void                      ResetEmission(unsigned MaxParticleCount)
        {
          ptr->resetEmission( MaxParticleCount );
        }

      ref struct                ProxyFlags:                           public giNxProxy<NxType> // TODO: check if flags can be unified, and how NX_BOOL works on flags
        {
          internal:
            ProxyFlags(NxType* ptr): BaseType( ptr ) { }

          public:
            property bool       default[FluidEmitterFlags]
              {
                bool            get(FluidEmitterFlags flag)           { return FromNx( data->getFlag( static_cast<NxFluidEmitterFlag>( flag ) ) ); }
                void            set(FluidEmitterFlags flag, bool v)   { data->setFlag( static_cast<NxFluidEmitterFlag>( flag ), v ); }
              }
        };
                                DefProxyGetSetX( ProxyFlags, Flags, DefNothing, ptr );
  };

//=============================+=====================================+=
                                EndNamespace
