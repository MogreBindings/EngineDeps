//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
struct                          giMeshDataCounts
  {
      NxU32                     IndexCount;
      NxU32                     ParentIndexCount;
      NxU32                     VertexCount;
      NxU32                     DirtyBufferFlags;

      giMeshDataCounts(NxU32 i) { IndexCount = ParentIndexCount = VertexCount = DirtyBufferFlags = i; }
  };

//=============================+=====================================+= // TODO: has Name,
public ref struct               MeshData:                             public DefCBProxyBase<NxMeshData>
  {
    internal:
      DefCBProxyConstructorsX( MeshData, DefValidDefaultX( DeinitManaged(); data->setToDefault(); UnpinAll(); AutoManageCounts = true; ) )

    public:
      MeshData() { AutoManageCounts = true; }
      MeshData(bool AutoManageCounts) { this->AutoManageCounts = AutoManageCounts; }

      ~MeshData() { DeinitManaged();   }
      !MeshData() { DeinitUnmanaged(); }

    public:
      generic<typename T> where T: System::ValueType
      void                      PinVertices(array<T>^ Source, int PositionsByteOffset, int NormalsByteOffset, int ByteStride);
      void                      UnpinVertices();

    public:
      DefPinCntFuncs( MeshData, giMeshDataCounts )

    public:
      DefPtr( void,             VertexPositions,                      verticesPosBegin,    verticesPosByteStride )
      DefPtr( void,             VertexNormals,                        verticesNormalBegin, verticesNormalByteStride )
      DefPtr( void,             Indices,                              indicesBegin,        indicesByteStride )
      DefPtr( void,             ParentIndices,                        parentIndicesBegin,  parentIndicesByteStride )

      DefCnt(                   Vertex,                          numVerticesPtr )
      DefCnt(                   Index,                           numIndicesPtr )
      DefCnt(                   ParentIndex,                     numParentIndicesPtr )
      DefCntX( MeshDataDirtyBufferFlags, DirtyBufferFlags,            dirtyBufferFlagsPtr,  )


      DefP0(  unsigned,         MaxVertexCount,                       maxVertices )
      DefP0(  unsigned,         MaxIndexCount,                        maxIndices )
      DefP0(  unsigned,         MaxParentIndexCount,                  maxParentIndices )

      DefPc(  MeshDataFlags,    Flags,                         NxU32, flags )
  };

//=============================+=====================================+=
                                EndNamespace
