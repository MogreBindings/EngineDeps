//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "MeshData.h"

//=============================+=====================================+=
                                BeginNamespace

/*//=============================+=====================================+=
static unsigned                 GetMaxCount(int typesize, int count, int byteoffset, int& bytestride)
  {
    int srcbsize = count * typesize;
    if( bytestride == 0 ) bytestride = typesize;
    if( byteoffset + typesize > srcbsize || byteoffset < 0 ) throw gcnew IndexOutOfRangeException();
    return ( srcbsize - byteoffset + bytestride - typesize ) / bytestride;
  }
*/
//=============================+=====================================+=
                                EndNamespace
/*
//=============================+=====================================+=
#define                         DefUnpin(which, token, maxcounttoken) \
    if( pin##which.IsAllocated ) { \
      \
      data->token##Begin      = 0; \
      data->token##ByteStride = 0; \
      data->maxcounttoken     = 0; \
      \
      pin##which.Free(); \
    }

//=============================+=====================================+=
#define                         DefPinUnpinX( type, which, token, maxcounttoken ) \
generic<typename T> IntPtr      type::Pin##which(array<T>^ Source, int ByteOffset, int ByteStride) \
  { \
    DefUnpin( which, token, maxcounttoken ) \
    \
    if( Source == nullptr ) { PostSet(); return IntPtr::Zero; } \
    \
    unsigned maxcount = GetMaxCount( sizeof( T ), Source->Length, ByteOffset, ByteStride ); \
    \
    pin##which = GCHandle::Alloc( Source, GCHandleType::Pinned ); \
    \
    IntPtr p = pin##which.AddrOfPinnedObject(); \
    data->token##Begin      = reinterpret_cast<void*>( p.ToInt64() + ByteOffset ); \
    data->token##ByteStride = ByteStride; \
    data->maxcounttoken     = maxcount; \
    \
    PostSet(); \
    \
    return which##Begin; \
  } \
\
void                            type::Unpin##which() \
  { \
    DefUnpin( which, token, maxcounttoken ) \
    PostSet(); \
  } \
\
Object^                         type::which##PinnedObject::get() \
  {  \
    return pin##which.IsAllocated ? pin##which.Target : nullptr; \
  } \
\
void                            type::which##PinnedObject::set(Object^ v) \
  { \
    if( v == which##PinnedObject ) return; \
    if( pin##which.IsAllocated ) { pin##which.Free(); data->token##Begin = 0; } \
    if( v != nullptr ) { \
      \
      pin##which         = GCHandle::Alloc( v, GCHandleType::Pinned ); \
      data->token##Begin = pin##which.AddrOfPinnedObject().ToPointer(); \
    } \
    PostSet(); \
  } \

//=============================+=====================================+=
#define                         DefPinUnpin(which, token, count)      DefPinUnpinX( MeshData, which, token, count )

//=============================+=====================================+=
DefPinUnpin(                    VertexPositions,                      verticesPos, maxVertices )
DefPinUnpin(                    VertexNormals,                        verticesNormal, maxVertices )
DefPinUnpin(                    Indices,                              indices, maxIndices )
DefPinUnpin(                    ParentIndices,                        parentIndices, maxParentIndices )

//=============================+=====================================+=
void                            MeshData::UnpinPinned()
  {
    DefUnpin( VertexPositions, verticesPos,    maxVertices      )
    DefUnpin( VertexNormals,   verticesNormal, maxVertices      )
    DefUnpin( Indices,         indices,        maxIndices       )
    DefUnpin( ParentIndices,   parentIndices,  maxParentIndices )
  }

//=============================+=====================================+=
void                            MeshData::UnpinAll()
  {
    UnpinPinned();
    PostSet();
  }

//=============================+=====================================+=
generic<typename T> void        MeshData::PinVertices(array<T>^ Source, int PositionsByteOffset, int NormalsByteOffset, int ByteStride)
  {
    if( ByteStride == 0 ) ByteStride = sizeof( T ) * 2;

    PinVertexPositions( Source, PositionsByteOffset, ByteStride );
    PinVertexNormals( Source, NormalsByteOffset, ByteStride );
  }

//=============================+=====================================+=
void                            MeshData::UnpinVertices()
  {
    UnpinVertexPositions();
    UnpinVertexNormals();
  }

//=============================+=====================================+=
void                            MeshData::DeleteCounts()
  {
    data->numVerticesPtr      = 0;
    data->numIndicesPtr       = 0;
    data->numParentIndicesPtr = 0;
    data->dirtyBufferFlagsPtr = 0;

    delete counts; counts = 0;
  }

//=============================+=====================================+=
void                            MeshData::AutoManageCounts::set(bool v)
  {
    if( counts ) {

      if( v ) return;
      DeleteCounts();

    } else {

      if( !v ) return;
      counts = new giMeshDataCounts;
    }

    PostSet();
  }

//=============================+=====================================+=
void                            MeshData::PostSet()
  {
    if( counts ) {

      data->numVerticesPtr      = data->verticesNormalBegin || data->verticesPosBegin ? &counts->VertexCount      : 0;
      data->numIndicesPtr       = data->indicesBegin                                  ? &counts->IndexCount       : 0;
      data->numParentIndicesPtr = data->parentIndicesBegin                            ? &counts->ParentIndexCount : 0;
      data->dirtyBufferFlagsPtr =                                                       &counts->DirtyBufferFlags;
    }

    BaseType::PostSet();
  }

//=============================+=====================================+=
void                            MeshData::CopyCustom(MeshData^ other)
  {
    UnpinPinned();

    if( other->pinVertexPositions.IsAllocated ) pinVertexPositions = GCHandle::Alloc( other->pinVertexPositions.Target, GCHandleType::Pinned );
    if( other->pinVertexNormals.IsAllocated ) pinVertexNormals = GCHandle::Alloc( other->pinVertexNormals.Target, GCHandleType::Pinned );
    if( other->pinIndices.IsAllocated ) pinIndices = GCHandle::Alloc( other->pinIndices.Target, GCHandleType::Pinned );
    if( other->pinParentIndices.IsAllocated ) pinParentIndices = GCHandle::Alloc( other->pinVertexPositions.Target, GCHandleType::Pinned );

    if( other->counts && !counts ) counts = new giMeshDataCounts;
    else if( !other->counts && counts ) DeleteCounts();
  }
*/

//=============================+=====================================+=
DefPinUnpinImplS( void,         VertexPositions,                      verticesPosBegin,    verticesPosByteStride,    MeshData )
DefPinUnpinImplS( void,         VertexNormals,                        verticesNormalBegin, verticesNormalByteStride, MeshData )
DefPinUnpinImplS( void,         Indices,                              indicesBegin,        indicesByteStride,        MeshData )
DefPinUnpinImplS( void,         ParentIndices,                        parentIndicesBegin,  parentIndicesByteStride,  MeshData )

//=============================+=====================================+=
void                            MeshData::UnpinPinned()
  {
    DefPinFree( VertexPositions, verticesPosBegin    )
    DefPinFree( VertexNormals,   verticesNormalBegin )
    DefPinFree( Indices,         indicesBegin        )
    DefPinFree( ParentIndices,   parentIndicesBegin  )
  }

//=============================+=====================================+=
void                            MeshData::ClearCounts()
  {
    data->numVerticesPtr      = 0;
    data->numIndicesPtr       = 0;
    data->numParentIndicesPtr = 0;
    data->dirtyBufferFlagsPtr = 0;
  }

//=============================+=====================================+=
void                            MeshData::CopyCustom(MeshData^ other)
  {
    UnpinPinned();
    //
    DefPinCopy( VertexPositions, verticesPosBegin    )
    DefPinCopy( VertexNormals,   verticesNormalBegin )
    DefPinCopy( Indices,         indicesBegin        )
    DefPinCopy( ParentIndices,   parentIndicesBegin  )
    //
    DefCntCopy( giMeshDataCounts )
  }

//=============================+=====================================+=
void                            MeshData::PostSet()
  {
    if( counts ) {

      data->numVerticesPtr      = data->verticesNormalBegin || data->verticesPosBegin ? &counts->VertexCount      : 0;
      data->numIndicesPtr       = data->indicesBegin                                  ? &counts->IndexCount       : 0;
      data->numParentIndicesPtr = data->parentIndicesBegin                            ? &counts->ParentIndexCount : 0;
      data->dirtyBufferFlagsPtr =                                                       &counts->DirtyBufferFlags;
    }

    BaseType::PostSet();
  }



//=============================+=====================================+=
generic<typename T> void        MeshData::PinVertices(array<T>^ Source, int PositionsByteOffset, int NormalsByteOffset, int ByteStride)
  {
    if( ByteStride == 0 ) ByteStride = sizeof( T ) * 2;

    PinVertexPositions( Source, PositionsByteOffset, ByteStride );
    PinVertexNormals( Source, NormalsByteOffset, ByteStride );
  }

//=============================+=====================================+=
void                            MeshData::UnpinVertices()
  {
    UnpinVertexPositions();
    UnpinVertexNormals();
  }
