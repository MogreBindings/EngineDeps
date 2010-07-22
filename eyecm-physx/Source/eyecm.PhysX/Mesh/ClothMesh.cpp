//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "ClothMesh.h"
#include                       "Physics.h"
#include                       "PhysicsCollection.h"
#include                       "nxstreamrw.h"

//=============================+=====================================+=
                                ClothMesh::ClothMesh(Physics^ Physics, NxClothMesh* data):
                                  giNxProxy( data )
  {
    Register( Physics );
  }

//=============================+=====================================+=
                                ClothMesh::~ClothMesh()
  {
    if( !data ) return;

    NxPhysicsSDK* physicsptr = Owner->ptr;
    Owner->clothmeshes->Remove( IntPtr( data ) );

    Unregister();

    if( !physicsptr ) return; // physics is disposing, no need to release explicitly
    if( this->ReferenceCount != 0 ) throw gcnew Exception();

    physicsptr->releaseClothMesh( *data );
  }

//=============================+=====================================+=
ClothMesh^                      Physics::CreateClothMesh(Stream^ CookedStream)
  {
    giNxStream str( CookedStream );

    NxClothMesh* m = ptr->createClothMesh( str );
    if( !m ) return nullptr;
    
    ClothMesh^ result = gcnew ClothMesh( this, m );

    clothmeshes->Add( IntPtr( m ), result );
    return result;
  }

//=============================+=====================================+=
ClothMesh^                      Physics::WrapOrGet(const NxClothMesh& mesh)
  {
    NxClothMesh* ptr = const_cast<NxClothMesh*>( &mesh );

    ClothMesh^ result;

    if( !clothmeshes->TryGetValue( IntPtr( ptr ), result ) )
      clothmeshes->Add( IntPtr( ptr ), result = gcnew ClothMesh( this, ptr ) );

    return result;
  }


//=============================+=====================================+=
DefPinUnpinImplS( void,         VertexMasses,                         vertexMasses, vertexMassStrideBytes, ClothMeshDesc )
DefPinUnpinImplS( void,         VertexFlags,                          vertexFlags,  vertexFlagStrideBytes, ClothMeshDesc )


//=============================+=====================================+=
void                            ClothMeshDesc::UnpinPinned()
  {
    SimpleTriangleMesh::UnpinPinned();

    DefPinFree( VertexMasses, vertexMasses )
    DefPinFree( VertexFlags,  vertexFlags  )
  }

//=============================+=====================================+=
void                            ClothMeshDesc::CopyCustom(ClothMeshDesc^ other)
  {
    UnpinPinned();
    //
    SimpleTriangleMesh::CopyCustom( other );
    //
    DefPinCopy( VertexMasses, vertexMasses )
    DefPinCopy( VertexFlags,  vertexFlags  )
  }

//=============================+=====================================+=
void                            ClothMeshDesc::PostSet()
  {
    SimpleTriangleMesh::PostSet();
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddClothMesh(ClothMesh^ ClothMesh, String^ ClothMeshID)
  {
    const char* id = ToNx( ClothMeshID );
    
    bool Result = NXU::addClothMesh( *this->ptr, *ClothMesh->GetNx(), id );
    
    delete[] id;
    return Result;
  }
