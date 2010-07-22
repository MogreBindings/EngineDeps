//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Cloth.h"
#include                       "ClothMesh.h"
#include                       "Scene.h"
#include                       "Shape.h"
#include                       "Actor.h"
#include                       "Physics.h"
#include                       "nxstreamrw.h"
#include                       "PhysicsCollection.h"

//=============================+=====================================+=
ClothMesh^                      ClothDesc::ClothMesh::get()
  {
    return clothmesh;
  }

//=============================+=====================================+=
void                            ClothDesc::ClothMesh::set(giClothMesh^ v)
  {
    clothmesh = v;
    data->clothMesh = v == nullptr ? 0 : v->data;
  }

//=============================+=====================================+=
                                Cloth::Cloth(giScene^ scene, NxCloth* ptr, ClothDesc^ Desc):
                                  giNxNamedObject( ptr )
  {
    Register( scene );

    DefProxyCopyFast( MeshData );
    //MeshData->Copy( Desc->MeshData );
  }

//=============================+=====================================+=
                                Cloth::~Cloth()
  {
    if( !ptr ) return;

    NxScene* sceneptr = Owner->ptr;

    Unregister();

    DefProxyDestroy( GroupsMask )
    DefProxyDestroy( MeshData   )

    if( !sceneptr ) return; // scene is disposing, no need to release explicitly
    sceneptr->releaseCloth( *ptr );
  }

//=============================+=====================================+=
                                Cloth::!Cloth()
  {
  }

//=============================+=====================================+=
Cloth^                          Cloth::Wrap(NxCloth* ptr)
  {
    giScene^ scene = giScene::Cast( &ptr->getScene() );

    return gcnew Cloth( scene, ptr, nullptr );
  }

//=============================+=====================================+=
Cloth^                          Scene::CreateCloth(ClothDesc^ Desc)
  {
    NxCloth* clothptr = ptr->createCloth( *Desc->data );
    return clothptr ? gcnew Cloth( this, clothptr, Desc ) : nullptr;
  }

//=============================+=====================================+=
void                            Cloth::AttachToShape(giShape^ Shape, ClothAttachmentFlags Flags)
  {
    ptr->attachToShape( Shape->ptr, static_cast<NxU32>( Flags ) );
  }

//=============================+=====================================+=
void                            Cloth::DetachFromShape(giShape^ Shape)
  {
    ptr->detachFromShape( Shape->ptr );
  }

//=============================+=====================================+=
void                            Cloth::AttachVertexToShape(unsigned VertexID, giShape^ Shape, Vector3 LocalPosition, ClothAttachmentFlags Flags)
  {
    ptr->attachVertexToShape(VertexID, Shape->ptr, ToNx( LocalPosition ), static_cast<NxU32>( Flags ) );
  }

//=============================+=====================================+=
Shape^                          Cloth::GetVertexAttachmentShape(unsigned VertexID)
  {
    return giShape::CastOrNull( ptr->getVertexAttachmentShape( VertexID ) );
  }

//=============================+=====================================+=
void                            Cloth::AttachToCore(Actor^ Actor, float ImpulseThreshold, float PenetrationDepth, float MaxDeformationDistance)
  {
    ptr->attachToCore( Actor->ptr, ImpulseThreshold, PenetrationDepth, MaxDeformationDistance );
  }


//=============================+=====================================+=
void                            Cloth::SaveStateToStream(System::IO::Stream^ Stream, bool Permute)
  {
    giNxStream str( Stream );
    ptr->queryShapePointers();
    ptr->saveStateToStream( str, Permute );
  }

//=============================+=====================================+=
void                            Cloth::LoadStateFromStream(System::IO::Stream^ Stream)
  {
    giNxStream str( Stream );
    ptr->loadStateFromStream( str );
  }

//=============================+=====================================+=
void                            Cloth::SetShapes(array<giShape^>^ Shapes)
  {
    const unsigned Count = Shapes->Length;
    NxShape** shapes = new NxShape*[Count];

    for( unsigned i = 0; i < Count; i++ )
      shapes[i] = Shapes[i]->ptr;

    ptr->setShapePointers( shapes, Count );
    delete[] shapes;
  }

//=============================+=====================================+=
void                            Cloth::SetShapes(IList<giShape^>^ Shapes)
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
ClothMesh^                      Cloth::ClothMesh::get()
  {
    return Scene->Physics->WrapOrGet( *ptr->getClothMesh() );
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddCloth(Cloth^ Object, UserPropertiesType UserProperties, String^ ID)
  {
    const char* id    = ToNx( ID );
    const char* props = ToChar( UserProperties );
    
    bool Result = addCloth( *this->ptr, *Object->ptr, props, id );
    
    delete[] props;
    delete[] id;
    return Result;
  }
