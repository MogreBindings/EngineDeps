//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Material.h"
#include                       "Scene.h"
#include                       "PhysicsCollection.h"

//=============================+=====================================+=
                                Material::Material(giScene^ Scene, NxMaterial* ptr):
                                  giNxObject( ptr )
  {
    Register( Scene );
  }

//=============================+=====================================+=
                                Material::~Material()
  {
    if( !ptr ) return;

    NxScene* scene = Owner->ptr;

    Unregister();

    if( !scene ) return; // scene is disposing, no need to release explicitly

    scene->releaseMaterial( *ptr );
  }

//=============================+=====================================+=
Material^                       Material::CastOrWrap(NxMaterial* ptr)
  {
    return gcnew Material( giScene::Cast( &ptr->getScene() ), ptr );
  }

//=============================+=====================================+=
Material^                       Scene::CreateMaterial(MaterialDesc^ Desc)
  {
    NxMaterial* materialptr = ptr->createMaterial( *Desc->data );
    return materialptr ? gcnew Material( this, materialptr ) : nullptr;
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddMaterial(Material^ Object, UserPropertiesType UserProperties, String^ ID)
  {
    const char* id    = ToNx( ID );
    const char* props = ToChar( UserProperties );
    
    bool Result = addMaterial( *this->ptr, *Object->ptr, props, id );
    
    delete[] props;
    delete[] id;
    return Result;
  }
