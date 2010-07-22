//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "MeshData.h"
#include                       "RaycastObjects.h"
#include                       "SoftBodySplitPair.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       SoftBodyMesh;

//=============================+=====================================+= // TODO: has name
public ref struct               SoftBodyDesc:                         public giNxProxyData<NxSoftBodyDesc>
  {
    internal:
      typedef                   ThisNamespace::SoftBodyMesh           giSoftBodyMesh;
      typedef                   ThisNamespace::GroupsMask             giGroupsMask;
      typedef                   ThisNamespace::MeshData               giMeshData;

    private:
      SoftBodyDesc(NxSoftBodyDesc& desc): BaseType( desc ) { }

    internal:
      static inline
      SoftBodyDesc^             Wrap(NxSoftBodyDesc& desc)               { return gcnew SoftBodyDesc( desc ); }

      giSoftBodyMesh^           softbodymesh;

    internal:
      void                      CopyCustom(SoftBodyDesc^ Original)
        {
          softbodymesh = Original->softbodymesh;
        }

    public:
      SoftBodyDesc() { this->MeshData->AutoManageCounts = true; }
      ~SoftBodyDesc()
        {
          softbodymesh = nullptr;

          DefProxyDestroy( GroupsMask );
          DefProxyDestroy( MeshData );
          DefProxyDestroy( SplitPairData );
        }

      !SoftBodyDesc()
        {
        }

    public:
      DefDataConstructors( SoftBodyDesc )

    public:
      property giSoftBodyMesh^  SoftBodyMesh                          { giSoftBodyMesh^ get(); void set(giSoftBodyMesh^); }

      DefPx( Matrix4x4,         GlobalPose,                           globalPose )
      DefP0( float,             ParticleRadius,                       particleRadius )
      DefP0( float,             Density,                              density )
      DefP0( float,             VolumeStiffness,                      volumeStiffness )
      DefP0( float,             StretchingStiffness,                  stretchingStiffness )
      DefP0( float,             DampingCoefficient,                   dampingCoefficient )
      DefP0( float,             Friction,                             friction )
      DefP0( float,             TearFactor,                           tearFactor )
      DefP0( float,             CollisionResponseCoefficient,         collisionResponseCoefficient )
      DefP0( float,             AttachmentResponseCoefficient,        attachmentResponseCoefficient )
      DefP0( float,             AttachmentTearFactor,                 attachmentTearFactor )
      DefP0( float,             ToFluidResponseCoefficient,           toFluidResponseCoefficient )
      DefP0( float,             FromFluidResponseCoefficient,         fromFluidResponseCoefficient )
      DefP0( float,             MinAdhereVelocity,                    minAdhereVelocity )
      DefP0( unsigned,          SolverIterationCount,                 solverIterations )
      DefPx( Vector3,           ExternalAcceleration,                 externalAcceleration )
      DefP0( float,             WakeUpCounter,                        wakeUpCounter )
      DefP0( float,             SleepLinearVelocity,                  sleepLinearVelocity )
      DefPc( unsigned,          CollisionGroup,     NxCollisionGroup, collisionGroup )
      DefPc( unsigned,          ForceFieldMaterial,            NxU16, forceFieldMaterial )
      DefPx( AxisAlignedBox,    ValidBounds,                          validBounds )
      DefP0( float,             RelativeGridSpacing,                  relativeGridSpacing )
      DefPc( SoftBodyFlags,     Flags,                         NxU32, flags )

    public:
                                DefProxyGetSet(    giGroupsMask,          GroupsMask,    groupsMask )
                                DefProxyGetSet(    giMeshData,            MeshData,      meshData )
                                DefProxyGetSetPin( SoftBodySplitPairData, SplitPairData, splitPairData )
  };

//=============================+=====================================+=
                                EndNamespace
