//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "SoftBody.h"
#include                       "SoftBodyMesh.h"
#include                       "Scene.h"
#include                       "Physics.h"
#include                       "nxstreamrw.h"
#include                       "PhysicsCollection.h"

//=============================+=====================================+=
SoftBodyMesh^                   SoftBodyDesc::SoftBodyMesh::get()
  {
    return softbodymesh;
  }

//=============================+=====================================+=
void                            SoftBodyDesc::SoftBodyMesh::set(giSoftBodyMesh^ v)
  {
    softbodymesh = v;
    data->softBodyMesh = v == nullptr ? 0 : v->data;
  }



//=============================+=====================================+=
                                SoftBody::SoftBody(giScene^ scene, NxSoftBody* ptr, SoftBodyDesc^ Desc):
                                  giNxNamedObject( ptr )
  {
    Register( scene );

    DefProxyCopyFast( MeshData )
    //MeshData->Copy( Desc->MeshData );
  }

//=============================+=====================================+=
                                SoftBody::~SoftBody()
  {
    if( !ptr ) return;

    NxScene* sceneptr = Owner->ptr;

    Unregister();

    DefProxyDestroy( GroupsMask    )
    DefProxyDestroy( MeshData      )
    DefProxyDestroy( SplitPairData )

    if( !sceneptr ) return; // scene is disposing, no need to release explicitly
    sceneptr->releaseSoftBody( *ptr );
  }

//=============================+=====================================+=
                                SoftBody::!SoftBody()
  {
  }

//=============================+=====================================+=
SoftBody^                       SoftBody::Wrap(NxSoftBody* ptr)
  {
    giScene^ scene = giScene::Cast( &ptr->getScene() );

    return gcnew SoftBody( scene, ptr, nullptr );
  }

//=============================+=====================================+=
SoftBody^                       Scene::CreateSoftBody(SoftBodyDesc^ Desc)
  {
    NxSoftBody* softbodyptr = ptr->createSoftBody( *Desc->data );
    return softbodyptr ? gcnew SoftBody( this, softbodyptr, Desc ) : nullptr;
  }

//=============================+=====================================+=
void                            SoftBody::SaveStateToStream(System::IO::Stream^ Stream, bool Permute)
  {
    giNxStream str( Stream );
    ptr->queryShapePointers();
    ptr->saveStateToStream( str, Permute );
  }

//=============================+=====================================+=
void                            SoftBody::LoadStateFromStream(System::IO::Stream^ Stream)
  {
    giNxStream str( Stream );
    ptr->loadStateFromStream( str );
  }

//=============================+=====================================+=
void                            SoftBody::SetShapes(array<giShape^>^ Shapes)
  {
    const unsigned Count = Shapes->Length;
    NxShape** shapes = new NxShape*[Count];

    for( unsigned i = 0; i < Count; i++ )
      shapes[i] = Shapes[i]->ptr;

    ptr->setShapePointers( shapes, Count );
    delete[] shapes;
  }

//=============================+=====================================+=
void                            SoftBody::SetShapes(IList<giShape^>^ Shapes)
  {
    ShapeCollection^ coll = safe_cast<ShapeCollection^>( Shapes );

    if( coll != nullptr ) {

      ptr->setShapePointers( coll->ptr->items, coll->ptr->count );
      return;
    }

    const unsigned Count = Shapes->Count;
    NxShape** shapes = new NxShape*[Count];

    for( unsigned i = 0; i < Count; i++ )
      shapes[i] = Shapes[i]->ptr;

    ptr->setShapePointers( shapes, Count );
    delete[] shapes;
  }

//=============================+=====================================+=
SoftBodyMesh^                   SoftBody::SoftBodyMesh::get()
  {
    return Scene->Physics->WrapOrGet( *ptr->getSoftBodyMesh() );
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddSoftBody(SoftBody^ Object, UserPropertiesType UserProperties, String^ ID)
  {
    const char* id    = ToNx( ID );
    const char* props = ToChar( UserProperties );

    bool Result = addSoftBody( *this->ptr, *Object->ptr, props, id );
    
    delete[] props;
    delete[] id;
    return Result;
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddSoftBody(SoftBodyDesc^ SoftBodyDesc, SoftBodyMeshDesc^ SoftBodyMeshDesc, UserPropertiesType UserProperties, String^ ID)
  {
    const char* id    = ToNx( ID );
    const char* props = ToChar( UserProperties );

    bool Result = addSoftBody( *this->ptr, *SoftBodyDesc->data, *SoftBodyMeshDesc->data, props, id );

    delete[] props;
    delete[] id;
    return Result;
  }