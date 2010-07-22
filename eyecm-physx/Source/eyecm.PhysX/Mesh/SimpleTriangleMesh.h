//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public ref struct               SimpleTriangleMesh:                   public giNxProxyData<NxSimpleTriangleMesh>
  {
    protected:
      SimpleTriangleMesh(NxSimpleTriangleMesh& data): BaseType( data ) { }

    internal:
      static
      SimpleTriangleMesh^       Wrap(NxSimpleTriangleMesh& data)      { return gcnew SimpleTriangleMesh( data ); }

    internal:
      SimpleTriangleMesh(NxSimpleTriangleMesh* data): BaseType( data ) { }

      SimpleTriangleMesh(NxSimpleTriangleMesh* data, IntPtr Points, IntPtr Triangles): BaseType( data )
        {
          this->PointsPtr           = Points;
          this->TrianglesPtr        = Triangles;
          this->PointsByteStride    = 12;
          this->TrianglesByteStride = 12;
        }

    public:
      SimpleTriangleMesh() { }

      ~SimpleTriangleMesh() { UnpinPinned(); }

    public:
      DefValidDefaultUnpin
      DefCloneCopy( SimpleTriangleMesh )
      DefPinFuncs( SimpleTriangleMesh )

      DefPtr( void,             Triangles,                            triangles, triangleStrideBytes )
      DefPtr( void,             Points,                               points,    pointStrideBytes )

    public:
      DefP0( unsigned,          VertexCount,                          numVertices )
      DefP0( unsigned,          TriangleCount,                        numTriangles )
      DefPc( MeshFlags,         Flags,                   NxMeshFlags, flags )
  };

//=============================+=====================================+=
                                EndNamespace

