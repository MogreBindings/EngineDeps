//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "MeshData.h"
#include                       "RaycastObjects.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       ClothMesh;

//=============================+=====================================+= // TODO: has name
public ref struct               ClothDesc:                            public giNxProxyData<NxClothDesc>
  {
    internal:
      typedef                   ThisNamespace::ClothMesh              giClothMesh;
      typedef                   ThisNamespace::GroupsMask             giGroupsMask;
      typedef                   ThisNamespace::MeshData               giMeshData;

    private:
      ClothDesc(NxClothDesc& desc): BaseType( desc ) { }

    internal:
      static inline ClothDesc^  Wrap(NxClothDesc& desc)               { return gcnew ClothDesc( desc ); }

      giClothMesh^              clothmesh;

      void                      CopyCustom(ClothDesc^ Original)
        {
          clothmesh = Original->clothmesh;
        }

    public:
      ClothDesc() { this->MeshData->AutoManageCounts = true; }

      ~ClothDesc()
        {
          clothmesh = nullptr;

          DefProxyDestroy( GroupsMask );
          DefProxyDestroy( MeshData );
        }

      !ClothDesc()
        {
        }
  
    public:
      DefDataConstructors( ClothDesc )

    public:
      property giClothMesh^     ClothMesh                             { giClothMesh^ get(); void set(giClothMesh^); }

      DefPx( Matrix4x4,         GlobalPose,                           globalPose )
      DefP0( float,             Thickness,                            thickness )
      DefP0( float,             Density,                              density )
      DefP0( float,             BendingStiffness,                     bendingStiffness )
      DefP0( float,             StretchingStiffness,                  stretchingStiffness )
      DefP0( float,             DampingCoefficient,                   dampingCoefficient )
      DefP0( float,             Friction,                             friction )
      DefP0( float,             Pressure,                             pressure )
      DefP0( float,             TearFactor,                           tearFactor )
      DefP0( float,             CollisionResponseCoefficient,         collisionResponseCoefficient )
      DefP0( float,             AttachmentResponseCoefficient,        attachmentResponseCoefficient )
      DefP0( float,             AttachmentTearFactor,                 attachmentTearFactor )
      DefP0( float,             ToFluidResponseCoefficient,           toFluidResponseCoefficient )
      DefP0( float,             FromFluidResponseCoefficient,         fromFluidResponseCoefficient )
      DefP0( float,             MinAdhereVelocity,                    minAdhereVelocity )
      DefP0( unsigned,          SolverIterationCount,                 solverIterations )
      DefPx( Vector3,           ExternalAcceleration,                 externalAcceleration )
      DefPx( Vector3,           WindAcceleration,                     windAcceleration )
      DefP0( float,             WakeUpCounter,                        wakeUpCounter )
      DefP0( float,             SleepLinearVelocity,                  sleepLinearVelocity )
      DefPc( unsigned,          CollisionGroup,     NxCollisionGroup, collisionGroup )
      DefPc( unsigned,          ForceFieldMaterial,            NxU16, forceFieldMaterial )
      DefPx( AxisAlignedBox,    ValidBounds,                          validBounds )
      DefP0( float,             RelativeGridSpacing,                  relativeGridSpacing )
      DefPc( ClothFlags,        Flags,                         NxU32, flags )

    public:
                                DefProxyGetSet( giGroupsMask, GroupsMask, groupsMask )
                                DefProxyGetSet( giMeshData, MeshData, meshData )
  };

//=============================+=====================================+=
                                EndNamespace
