//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Physics;

//=============================+=====================================+=
public ref struct               SoftBodyMeshDesc:                     public giNxProxyData<NxSoftBodyMeshDesc>
  {
    private:
      SoftBodyMeshDesc(NxSoftBodyMeshDesc& data): BaseType( data ) { }

    internal:
      inline static
      SoftBodyMeshDesc^         Wrap(NxSoftBodyMeshDesc& data)        { return gcnew SoftBodyMeshDesc( data ); }

    public:
      SoftBodyMeshDesc(): BaseType( new NxSoftBodyMeshDesc ) { }

      ~SoftBodyMeshDesc() { UnpinPinned(); }

    public:
      DefValidDefaultUnpin
      DefCloneCopy( SoftBodyMeshDesc )
      DefPinFuncs( SoftBodyMeshDesc )

    public:
      DefPtr( void,             VertexMasses,                         vertexMasses, vertexMassStrideBytes  )
      DefPtr( void,             VertexFlags,                          vertexFlags,  vertexFlagStrideBytes  )
      DefPtr( void,             Vertices,                             vertices,     vertexStrideBytes      )
      DefPtr( void,             Tetrahedra,                           tetrahedra,   tetrahedronStrideBytes )

      DefP0( unsigned,          VertexCount,                          numVertices )
      DefP0( unsigned,          TetrahedronCount,                     numTetrahedra )
      DefPc( SoftBodyMeshFlags, Flags,                         NxU32, flags )
  };

//=============================+=====================================+=
public ref class                SoftBodyMesh:                         public giNxProxy<NxSoftBodyMesh, giNxRegisteredObject<Physics> >
  {
    internal:
      SoftBodyMesh(Physics^ Physics, NxSoftBodyMesh* data);

    public:
      ~SoftBodyMesh();

    public:
      DefR0( unsigned,          ReferenceCount,                       getReferenceCount() )

    public:
                                DefSaveToDescX( SoftBodyMeshDesc, data )
  };

//=============================+=====================================+=
                                EndNamespace
