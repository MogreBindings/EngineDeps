//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "SimpleTriangleMesh.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       TriangleMesh;

//=============================+=====================================+=
public ref struct               TriangleMeshDesc:                     public SimpleTriangleMesh
  {
                                DefRecastData( NxTriangleMeshDesc, SimpleTriangleMesh )
    private:
      TriangleMeshDesc(NxTriangleMeshDesc& data): SimpleTriangleMesh( data ) { }

    internal:
      static TriangleMeshDesc^  Wrap(NxTriangleMeshDesc& data)        { return gcnew TriangleMeshDesc( data ); }

    internal:
      void                      PostSet() new;

    public:
      TriangleMeshDesc(): SimpleTriangleMesh( new NxTriangleMeshDesc ) { }

      TriangleMeshDesc(IntPtr Points, IntPtr Triangles):
        SimpleTriangleMesh( new NxTriangleMeshDesc, Points, Triangles ) { }

      ~TriangleMeshDesc() { UnpinPinned(); }

    public:
      TriangleMeshDesc(TriangleMeshDesc^ Original):
        SimpleTriangleMesh( Original->IsDisposed ? new NxTriangleMeshDesc : new NxTriangleMeshDesc( *Original->data ) )
        {
          DefThrowOnDisposed( Original, TriangleMeshDesc, "clone" )
          CopyCustom( Original );
          PostSet();
        }

    public:
      DefValidDefaultNew
      DefCloneCopyFuncsOnly( TriangleMeshDesc, new )
      DefPinFuncsX( TriangleMeshDesc, new )

    public:
      DefPtr( void,             MaterialIndices,                      materialIndices, materialIndexStride )

      DefP0( float,             ConvexEdgeThreshold,                  convexEdgeThreshold )
  };

//=============================+=====================================+=
                                EndNamespace
