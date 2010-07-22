//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Scene.h"
#include                       "Actor.h"
#include                       "Shape.h"
#include                       "Material.h"
#include                       "Physics.h"
#include                       "PhysicsCollection.h"

//=============================+=====================================+=
                                Scene::Scene(giPhysics^ Physics, SceneDesc^ Desc, NxScene* ptr):
                                  giNxObject( ptr )
  {
    Register( Physics );

    NxMaterial* defaultmaterial = ptr->getMaterialFromIndex( 0 );
    if( Material::CastOrNull( defaultmaterial ) == nullptr ) gcnew Material( this, defaultmaterial );

    InitLists();
    InitPairs();
    InitReports( Desc );

    limits = gcnew ProxyLimits( ptr );
    timing = gcnew ProxyTiming( ptr );
  }

//=============================+=====================================+=
                                Scene::~Scene()
  {
    if( !ptr ) return;

    DeInitReports();

    NxScene* ptr = this->ptr;
    this->ptr = 0;

    while( First )
      delete First;

    DeInitLists();
    DeInitPairs();

    delete limits; limits = nullptr;
    delete timing; timing = nullptr;
    
    DefProxyDestroy( ForceFieldScale )

    NxPhysicsSDK* sdk = Owner->ptr;

    Unregister();

    if( !sdk ) return;  // sdk is disposing, no need to release explicitly
    sdk->releaseScene( *ptr );
  }

//=============================+=====================================+=
                                Scene::!Scene()
  {
  }
//=============================+=====================================+=
Scene^                          Physics::CreateScene(SceneDesc^ Desc)
  {
    NxScene* sceneptr = ptr->createScene( *Desc->data );
    return sceneptr ? gcnew Scene( this, Desc, sceneptr ) : nullptr;
  }



//=============================+=====================================+=
ContactPairFlags                Scene::ProxyActorPairFlags::default::get(Actor^ a, Actor^ b)
  {
    return static_cast<ContactPairFlags>( data->getActorPairFlags( *a->ptr, *b->ptr ) );
  }

//=============================+=====================================+=
void                            Scene::ProxyActorPairFlags::default::set(Actor^ a, Actor^ b, ContactPairFlags v)
  {
    data->setActorPairFlags( *a->ptr, *b->ptr, static_cast<NxU32>( v ) );
  }

//=============================+=====================================+=
ContactPairFlags                Scene::ProxyShapePairFlags::default::get(Shape^ a, Shape^ b)
  {
    return static_cast<ContactPairFlags>( data->getShapePairFlags( *a->ptr, *b->ptr ) );
  }

//=============================+=====================================+=
void                            Scene::ProxyShapePairFlags::default::set(Shape^ a, Shape^ b, ContactPairFlags v)
  {
    data->setShapePairFlags( *a->ptr, *b->ptr, static_cast<NxU32>( v ) );
  }

//=============================+=====================================+=
bool                            Scene::ProxyGroupCollisionFlags::default::get(unsigned a, unsigned b)
  {
    return data->getGroupCollisionFlag( static_cast<NxCollisionGroup>( a ), static_cast<NxCollisionGroup>( b ) );
  }

//=============================+=====================================+=
void                            Scene::ProxyGroupCollisionFlags::default::set(unsigned a, unsigned b, bool v)
  {
    data->setGroupCollisionFlag( static_cast<NxCollisionGroup>( a ), static_cast<NxCollisionGroup>( b ), v );
  }

//=============================+=====================================+=
ContactPairFlags                Scene::ProxyActorGroupPairFlags::default::get(unsigned a, unsigned b)
  {
    return static_cast<ContactPairFlags>( data->getActorGroupPairFlags( static_cast<NxActorGroup>( a ), static_cast<NxActorGroup>( b ) ) );
  }

//=============================+=====================================+=
void                            Scene::ProxyActorGroupPairFlags::default::set(unsigned a, unsigned b, ContactPairFlags v)
  {
    data->setActorGroupPairFlags( static_cast<NxActorGroup>( a ), static_cast<NxActorGroup>( b ), static_cast<NxU32>( v ) );
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddScene(Scene^ Object, UserPropertiesType UserProperties, String^ ID)
  {
    const char* id    = ToNx( ID );
    const char* props = ToChar( UserProperties );

    bool Result = addScene( *this->ptr, *Object->ptr, props, id );
    
    delete[] props;
    delete[] id;
    return Result;
  }
