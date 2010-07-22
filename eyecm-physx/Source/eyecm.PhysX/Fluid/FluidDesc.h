//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"
#include                       "nxarraylist.h"
#include                       "ParticleData.h"
#include                       "RaycastObjects.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Shape;

//=============================+=====================================+= // TODO: has name
public ref struct               FluidEmitterDesc:                     public giNxData<NxFluidEmitterDesc>
  {
    private:
      FluidEmitterDesc(NxType& desc): BaseType( desc ) { }

    internal:      
      inline static FluidEmitterDesc^ Wrap(NxType& desc) { return gcnew FluidEmitterDesc( desc ); }

    internal:
      typedef                   ThisNamespace::Shape                  giShape;

      FluidEmitterDesc(const NxType& desc): BaseType( desc ) { }
      
    public:
      FluidEmitterDesc() { }

    public:
      DefPx( Matrix4x4,         RelativePose,                         relPose )
      DefPc( EmitterTypes,      Type,                          NxU32, type )
      DefP0( unsigned,          MaxParticleCount,                     maxParticles )
      DefPc( EmitterShapes,     Shape,                         NxU32, shape )
      DefP0( float,             DimensionX,                           dimensionX )
      DefP0( float,             DimensionY,                           dimensionY )
      DefPx( Vector3,           RandomPosition,                       randomPos )
      DefP0( float,             RandomAngle,                          randomAngle )
      DefP0( float,             FluidVelocityMagnitude,               fluidVelocityMagnitude )
      DefP0( float,             Rate,                                 rate )
      DefP0( float,             ParticleLifetime,                     particleLifetime )
      DefP0( float,             RepulsionCoefficient,                 repulsionCoefficient )
      DefPc( FluidEmitterFlags, Flags,                         NxU32, flags )

      property giShape^         FrameShape                            { giShape^ get(); void set(giShape^); }

    public:
                                DefValidDefault
  };

//=============================+=====================================+=
public ref struct               FluidDesc:                            public giNxProxyData<NxFluidDesc>
  {
    private:
      FluidDesc(NxType& desc): BaseType( desc ) { InitEmitters(); }

    internal:
      typedef                   ThisNamespace::GroupsMask             giGroupsMask;

    internal:
      inline static FluidDesc^  Wrap(NxFluidDesc& desc)               { return gcnew FluidDesc( desc ); }

      void                      CopyCustom(FluidDesc^ Desc)
        {
          // TODO: need to copy emitters list?
          //
          DefProxyCopyFast( GroupsMask )
          //
          DefProxyCopyFast( InitialParticleData )
          DefProxyCopyFast( ParticleWriteData )
          DefProxyCopyFast( ParticleDeletionIDWriteData )
          DefProxyCopyFast( ParticleCreationIDWriteData )
          DefProxyCopyFast( FluidPacketData )
        }

    internal:
      FluidDesc(const NxType& desc): BaseType( desc ) { InitEmitters(); }

    public:
      FluidDesc() { InitEmitters(); }
      ~FluidDesc() 
        {
/*          this->!FluidDesc();
        }
        
      !FluidDesc()
        {*/
          DeinitEmitters(); 
          //
          DefProxyDestroy( GroupsMask )
          //
          DefProxyDestroy( InitialParticleData )
          DefProxyDestroy( ParticleWriteData )
          DefProxyDestroy( ParticleDeletionIDWriteData )
          DefProxyDestroy( ParticleCreationIDWriteData )
          DefProxyDestroy( FluidPacketData )
        }


    public:
      #define                 __temp__                                NxArray<NxFluidEmitterDesc, NxAllocatorDefault>
                                DefArrayListX( FluidEmitterDesc, Emitters, &data->emitters, __temp__ )
      #undef                  __temp__

    public:
                                DefCloneCopy( FluidDesc );
                                DefValidDefaultX( listEmitters->Clear(); data->setToDefault(); )
    public:

      DefPc( FluidFlags,        Flags,                  NxFluidFlag, flags );

      //-------------------------------------------------------------
      //---------------------== Properties ==------------------------
      //-------------------------------------------------------------
      DefP0( unsigned,          MaxParticleCount,                     maxParticles )
      DefP0( unsigned,          ReserveParticleCount,                 numReserveParticles )
      DefP0( float,             RestParticlesPerMeter,                restParticlesPerMeter )
      DefP0( float,             RestDensity,                          restDensity )
      DefP0( float,             KernelRadiusMultiplier,               kernelRadiusMultiplier )
      DefP0( float,             MotionLimitMultiplier,                motionLimitMultiplier )
      DefP0( float,             CollisionDistanceMultiplier,          collisionDistanceMultiplier )
      DefP0( unsigned,          PacketSizeMultiplier,                 packetSizeMultiplier )

      //-------------------------------------------------------------
      //---------------------== Fluid Parameters ==------------------
      //-------------------------------------------------------------

      DefP0( float,             Stiffness,                            stiffness )
      DefP0( float,             Viscosity,                            viscosity )
      DefP0( float,             SurfaceTension,                       surfaceTension )
      DefP0( float,             Damping,                              damping )
      DefP0( float,             FadeInTime,                           fadeInTime )
      DefPx( Vector3,           ExternalAcceleration,                 externalAcceleration )
      DefPx( Plane,             ProjectionPlane,                      projectionPlane )

      //-------------------------------------------------------------
      //---------------------== Collisions ==------------------------
      //-------------------------------------------------------------

      DefPc(
        FluidCollisionMethods,  CollisionMethod, NxFluidCollisionMethod, collisionMethod
      )
      DefP0( float,             RestitutionForStaticShapes,           restitutionForStaticShapes )
      DefP0( float,             DynamicFrictionForStaticShapes,       dynamicFrictionForStaticShapes )
      DefP0( float,             StaticFrictionForStaticShapes,        staticFrictionForStaticShapes )
      DefP0( float,             AttractionForStaticShapes,            attractionForStaticShapes )
      DefP0( float,             RestitutionForDynamicShapes,          restitutionForDynamicShapes )
      DefP0( float,             DynamicFrictionForDynamicShapes,      dynamicFrictionForDynamicShapes )
      DefP0( float,             StaticFrictionForDynamicShapes,       staticFrictionForDynamicShapes )
      DefP0( float,             AttractionForDynamicShapes,           attractionForDynamicShapes )
      DefP0( float,             CollisionResponseCoefficient,         collisionResponseCoefficient )

      DefPc(
        FluidSimulationMethods, SimulationMethod, NxFluidSimulationMethod, simulationMethod
      )
      DefPc( unsigned,          Group,              NxCollisionGroup, collisionGroup )

      DefProxyGetSet( giGroupsMask, GroupsMask, groupsMask );

      //-------------------------------------------------------------
      //---------------------== Particles ==-------------------------
      //-------------------------------------------------------------

      DefPc( unsigned,          ForceFieldMaterial, NxForceFieldMaterial, forceFieldMaterial )

      typedef                   ThisNamespace::FluidPacketData        giFluidPacketData;

      DefProxyGetSetPin( ParticleData,      InitialParticleData,         initialParticleData );
      DefProxyGetSetPin( ParticleData,      ParticleWriteData,           particlesWriteData );
      DefProxyGetSetPin( ParticleIDData,    ParticleDeletionIDWriteData, particleDeletionIdWriteData );
      DefProxyGetSetPin( ParticleIDData,    ParticleCreationIDWriteData, particleCreationIdWriteData );
      DefProxyGetSetPin( giFluidPacketData, FluidPacketData,             fluidPacketData );
  };

//=============================+=====================================+=
                                EndNamespace
