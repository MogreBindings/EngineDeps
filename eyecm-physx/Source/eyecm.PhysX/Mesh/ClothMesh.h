//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "SimpleTriangleMesh.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       ClothMesh;
ref class                       Physics;

//=============================+=====================================+=
public ref struct               ClothMeshDesc:                        public SimpleTriangleMesh
  {
                                DefRecastData( NxClothMeshDesc, SimpleTriangleMesh )
    private:
      ClothMeshDesc(NxClothMeshDesc& data): SimpleTriangleMesh( data ) { }

    internal:
      inline static
      ClothMeshDesc^            Wrap(NxClothMeshDesc& data)         { return gcnew ClothMeshDesc( data ); }

    internal:
      void                      PostSet() new;

    public:
      ClothMeshDesc(): SimpleTriangleMesh( new NxClothMeshDesc ) { }

      ClothMeshDesc(IntPtr Points, IntPtr Triangles):
        SimpleTriangleMesh( new NxClothMeshDesc, Points, Triangles ) { }

      ~ClothMeshDesc() { UnpinPinned(); }

    public:
      ClothMeshDesc(ClothMeshDesc^ Original):
        SimpleTriangleMesh( Original->IsDisposed ? new NxClothMeshDesc : new NxClothMeshDesc( *Original->data ) )
        {
          DefThrowOnDisposed( Original, ClothMeshDesc, "clone" )
          CopyCustom( Original );
          PostSet();
        }

    public:
      DefValidDefaultNewUnpin
      DefCloneCopyFuncsOnly( ClothMeshDesc, new )
      DefPinFuncsX( ClothMeshDesc, new )

    public:
      DefPtr( void,             VertexMasses,                         vertexMasses, vertexMassStrideBytes )
      DefPtr( void,             VertexFlags,                          vertexFlags,  vertexFlagStrideBytes )

      DefP0( float,             WeldingDistance,                      weldingDistance )
  };

//=============================+=====================================+=
public ref class                ClothMesh:                            public giNxProxy<NxClothMesh, giNxRegisteredObject<Physics> >
  {
    internal:
      ClothMesh(Physics^ Physics, NxClothMesh* data);

    public:
      ~ClothMesh();

    public:
      DefR0( unsigned,          ReferenceCount,                       getReferenceCount() )

    public:
                                DefSaveToDescX( ClothMeshDesc, data )
  };


//=============================+=====================================+=
                                EndNamespace
