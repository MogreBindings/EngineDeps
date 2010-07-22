//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "SoftBodyMesh.h"
#include                       "Physics.h"
#include                       "PhysicsCollection.h"
#include                       "nxstreamrw.h"

//=============================+=====================================+=
                                SoftBodyMesh::SoftBodyMesh(Physics^ Physics, NxSoftBodyMesh* data):
                                  giNxProxy( data )
  {
    Register( Physics );
  }

//=============================+=====================================+=
                                SoftBodyMesh::~SoftBodyMesh()
  {
    if( !data ) return;

    NxPhysicsSDK* physicsptr = Owner->ptr;
    Owner->softbodymeshes->Remove( IntPtr( data ) );

    Unregister();

    if( !physicsptr ) return; // physics is disposing, no need to release explicitly
    if( this->ReferenceCount != 0 ) throw gcnew Exception();

    physicsptr->releaseSoftBodyMesh( *data );
  }

//=============================+=====================================+=
SoftBodyMesh^                   Physics::CreateSoftBodyMesh(Stream^ CookedStream)
  {
    giNxStream str( CookedStream );

    NxSoftBodyMesh* m = ptr->createSoftBodyMesh( str );
    if( !m ) return nullptr;
    
    SoftBodyMesh^ result = gcnew SoftBodyMesh( this, m );

    softbodymeshes->Add( IntPtr( m ), result );
    return result;
  }

//=============================+=====================================+=
SoftBodyMesh^                   Physics::WrapOrGet(const NxSoftBodyMesh& mesh)
  {
    NxSoftBodyMesh* ptr = const_cast<NxSoftBodyMesh*>( &mesh );

    SoftBodyMesh^ result;

    if( !softbodymeshes->TryGetValue( IntPtr( ptr ), result ) )
      softbodymeshes->Add( IntPtr( ptr ), result = gcnew SoftBodyMesh( this, ptr ) );

    return result;
  }


//=============================+=====================================+=
DefPinUnpinImplS( void,         VertexMasses,                         vertexMasses, vertexMassStrideBytes,  SoftBodyMeshDesc )
DefPinUnpinImplS( void,         VertexFlags,                          vertexFlags,  vertexFlagStrideBytes,  SoftBodyMeshDesc )
DefPinUnpinImplS( void,         Vertices,                             vertices,     vertexStrideBytes,      SoftBodyMeshDesc )
DefPinUnpinImplS( void,         Tetrahedra,                           tetrahedra,   tetrahedronStrideBytes, SoftBodyMeshDesc )

//=============================+=====================================+=
void                            SoftBodyMeshDesc::UnpinPinned()
  {
    DefPinFree( VertexMasses, vertexMasses )
    DefPinFree( VertexFlags,  vertexFlags  )
    DefPinFree( Vertices,     vertices     )
    DefPinFree( Tetrahedra,   tetrahedra   )
  }

//=============================+=====================================+=
void                            SoftBodyMeshDesc::CopyCustom(SoftBodyMeshDesc^ other)
  {
    UnpinPinned();
    //
    DefPinCopy( VertexMasses, vertexMasses )
    DefPinCopy( VertexFlags,  vertexFlags  )
    DefPinCopy( Vertices,     vertices     )
    DefPinCopy( Tetrahedra,   tetrahedra   )
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddSoftBodyMesh(SoftBodyMesh^ SoftBodyMesh, String^ SoftBodyMeshID)
  {
    const char* id = ToNx( SoftBodyMeshID );
    
    bool Result = NXU::addSoftBodyMesh( *this->ptr, *SoftBodyMesh->GetNx(), id );
    
    delete[] id;
    return Result;
  }
