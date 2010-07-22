//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       ConvexMesh;

//=============================+=====================================+=
public ref struct               ConvexMeshDesc:                       public giNxProxyData<NxConvexMeshDesc>
  {
    private:
      ConvexMeshDesc(NxConvexMeshDesc& data): BaseType( data ) { }

    internal:
      static ConvexMeshDesc^    Wrap(NxConvexMeshDesc& data)          { return gcnew ConvexMeshDesc( data ); }

    public:
      ConvexMeshDesc() { }

      ConvexMeshDesc(IntPtr Points)
        {
          this->PointsPtr         = Points;
          this->PointsByteStride  = 12;
          this->Flags            |= ConvexFlags::ComputeConvex;
        }

      ConvexMeshDesc(IntPtr Points, IntPtr Triangles)
        {
          this->PointsPtr           = Points;
          this->TrianglesPtr        = Triangles;
          this->PointsByteStride    = 12;
          this->TrianglesByteStride = 12;
        }

      ~ConvexMeshDesc() { UnpinPinned(); }

    public:
      DefValidDefaultUnpin
      DefPinFuncs( ConvexMeshDesc )

    public:
      DefPtr( void,             Triangles,                            triangles, triangleStrideBytes )
      DefPtr( void,             Points,                               points,    pointStrideBytes )

      DefP0( unsigned,          VertexCount,                          numVertices )
      DefP0( unsigned,          TriangleCount,                        numTriangles )
      DefPc( ConvexFlags,       Flags,                 NxConvexFlags, flags )
  };

//=============================+=====================================+=
                                EndNamespace
