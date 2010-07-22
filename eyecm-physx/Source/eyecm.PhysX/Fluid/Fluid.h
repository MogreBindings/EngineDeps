//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "FluidDesc.h"
#include                       "RaycastObjects.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Scene;
ref class                       FluidEmitter;

//=============================+=====================================+=
public ref class                Fluid:                                public giNxNamedObject<NxFluid, Fluid, giNxRegisteredObject<Scene>>
  {
    internal:
      typedef                   ThisNamespace::Scene                  giScene;
      typedef                   ThisNamespace::GroupsMask             giGroupsMask;

      giNxRegisteredObject<Fluid>^ First;

    internal:
      Fluid(giScene^, NxFluid*, FluidDesc ^);

      static Fluid^             Wrap(NxFluid* ptr, FluidDesc ^);
      static Fluid^             Wrap(NxFluid* ptr)                    { return Wrap( ptr, nullptr ); }

    public:
      ~Fluid();
      !Fluid();

                                DefLoadSaveToDesc( Fluid )

    public:
      ref struct                ProxyFlags:                           public giNxProxy<NxType> // TODO: check if flags can be unified, and how NX_BOOL works on flags
        {
          internal:
            ProxyFlags(NxType* ptr): BaseType( ptr ) { }

          public:
            property bool       default[FluidFlags]
              {
                bool            get(FluidFlags flag)                  { return FromNx( data->getFlag( static_cast<NxFluidFlag>( flag ) ) ); }
                void            set(FluidFlags flag, bool v)          { data->setFlag( static_cast<NxFluidFlag>( flag ), v ); }
              }
        };
                                DefProxyGetSetX( ProxyFlags, Flags, DefNothing, ptr );
    private:
      //-------------------------------------------------------------
      //---------------------== Emitters ==--------------------------
      //-------------------------------------------------------------

      typedef                   ReadOnlyCollection<FluidEmitter^>     EmitterList;

      EmitterList^              emitterlist;

    public:
      property EmitterList^     Emitters
        {
          EmitterList^          get()                                 { return emitterlist; }
        }

      FluidEmitter^             CreateEmitter(FluidEmitterDesc^ Desc);

      bool                      SaveEmittersToFluidDesc([Out] FluidDesc^% Desc);

    public:
      //-------------------------------------------------------------
      //-------------------------------------------------------------
      //-------------------------------------------------------------

      property giScene^         Scene
        {
          giScene^              get()                                 { return Owner; }
        }

    public:
      DefMc( unsigned,          ForceFieldMaterial, NxForceFieldMaterial, ForceFieldMaterial )


    internal:
      //-------------------------------------------------------------
      //---------------------== Particles ==-------------------------
      //-------------------------------------------------------------

      typedef                   ThisNamespace::FluidPacketData        giFluidPacketData;

      void                      OnParticleWriteDataChanged(NxParticleData* data)              { ptr->setParticlesWriteData( *data ); }
      void                      OnParticleDeletionIDWriteDataChanged(NxParticleIdData* data)  { ptr->setParticleDeletionIdWriteData( *data ); }
      void                      OnParticleCreationIDWriteDataChanged(NxParticleIdData* data)  { ptr->setParticleCreationIdWriteData( *data ); }
      void                      OnFluidPacketDataChanged(NxFluidPacketData* data)             { ptr->setFluidPacketData( *data ); }

    public:
      unsigned                  AddParticles(ParticleData^ Data)      { return AddParticles( Data, false ); }
      unsigned                  AddParticles(ParticleData^ Data, bool AppendIDs)
        {
          return ptr->addParticles( *Data->data, AppendIDs );
        }

      void                      RemoveAllParticles()                  { ptr->removeAllParticles(); }

      void                      UpdateParticles(ParticleUpdateData^ Data)
        {
          ptr->updateParticles( *Data->data );
        }

      DefProxyGetSetGPin( Fluid, ParticleData,      ParticlesWriteData,          ParticleWriteData )
      DefProxyGetSetGPin( Fluid, ParticleIDData,    ParticleDeletionIdWriteData, ParticleDeletionIDWriteData )
      DefProxyGetSetGPin( Fluid, ParticleIDData,    ParticleCreationIdWriteData, ParticleCreationIDWriteData )
      DefProxyGetSetGPin( Fluid, giFluidPacketData, FluidPacketData,             FluidPacketData )

      DefM0( unsigned,          ParticleReserveCount,                 NumReserveParticles )
      DefM0( unsigned,          CurrentParticleLimit,                 CurrentParticleLimit )


    public:
      //-------------------------------------------------------------
      //---------------------== Fluid Parameters ==------------------
      //-------------------------------------------------------------

      DefMc(
        FluidSimulationMethods, SimulationMethod, NxFluidSimulationMethod, SimulationMethod
      )
      DefM0( float,             Stiffness,                            Stiffness )
      DefM0( float,             Viscosity,                            Viscosity )
      DefM0( float,             SurfaceTension,                       SurfaceTension )
      DefM0( float,             Damping,                              Damping )
      DefM0( float,             FadeInTime,                           FadeInTime )
      DefMx( Vector3,           ExternalAcceleration,                 ExternalAcceleration )
      DefMx( Plane,             ProjectionPlane,                      ProjectionPlane )


      //-------------------------------------------------------------
      //---------------------== Collisions ==------------------------
      //-------------------------------------------------------------

      DefMc(
        FluidCollisionMethods,  CollisionMethod, NxFluidCollisionMethod, CollisionMethod
      )
      DefM0( float,             RestitutionForStaticShapes,           RestitutionForStaticShapes )
      DefM0( float,             DynamicFrictionForStaticShapes,       DynamicFrictionForStaticShapes )
      DefM0( float,             StaticFrictionForStaticShapes,        StaticFrictionForStaticShapes )
      DefM0( float,             AttractionForStaticShapes,            AttractionForStaticShapes )
      DefM0( float,             RestitutionForDynamicShapes,          RestitutionForDynamicShapes )
      DefM0( float,             DynamicFrictionForDynamicShapes,      DynamicFrictionForDynamicShapes )
      DefM0( float,             StaticFrictionForDynamicShapes,       StaticFrictionForDynamicShapes )
      DefM0( float,             AttractionForDynamicShapes,           AttractionForDynamicShapes )
      DefM0( float,             CollisionResponseCoefficient,         CollisionResponseCoefficient )


    internal:
      //-------------------------------------------------------------
      //---------------------== Property Read Back ==----------------
      //-------------------------------------------------------------

      void                      OnGroupsMaskChanged(NxGroupsMask* data) { ptr->setGroupsMask( *data ); }

    public:
      Defm0( unsigned,          MaxParticleCount,                     MaxParticles )
      Defm0( float,             KernelRadiusMultiplier,               KernelRadiusMultiplier )
      Defm0( float,             MotionLimitMultiplier,                MotionLimitMultiplier )
      Defm0( float,             CollisionDistanceMultiplier,          CollisionDistanceMultiplier )
      Defm0( unsigned,          PacketSizeMultiplier,                 PacketSizeMultiplier )
      Defm0( float,             RestParticlesPerMeter,                RestParticlesPerMeter )
      Defm0( float,             RestDensity,                          RestDensity )
      Defm0( float,             RestParticleDistance,                 RestParticleDistance )
      Defm0( float,             ParticleMass,                         ParticleMass )
      DefMc( unsigned,          Group,              NxCollisionGroup, Group )
      Defm0( unsigned,          PPUTime,                              PPUTime )

      property AxisAlignedBox   WorldBounds
        {
          AxisAlignedBox        get()                                 { NxBounds3 result; ptr->getWorldBounds( result ); return FromNx( result ); }
        }

      DefProxyGetSetm( Fluid, giGroupsMask, GroupsMask )
  };

//=============================+=====================================+=
                                EndNamespace
