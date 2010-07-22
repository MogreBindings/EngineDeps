//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Effector.h"
#include                       "Scene.h"
#include                       "Actor.h"
#include                       "PhysicsCollection.h"

//=============================+=====================================+=
Actor^                          SpringAndDamperEffectorDesc::Body1::get()         { return Actor::CastOrNull( data->body1 ); }
void                            SpringAndDamperEffectorDesc::Body1::set(Actor^ v) { data->body1 = v == nullptr ? 0 : v->ptr; }
Actor^                          SpringAndDamperEffectorDesc::Body2::get()         { return Actor::CastOrNull( data->body2 ); }
void                            SpringAndDamperEffectorDesc::Body2::set(Actor^ v) { data->body2 = v == nullptr ? 0 : v->ptr; }

//=============================+=====================================+=
                                Effector::Effector(NxEffector* ptr):
                                  BaseType( ptr )
  {
    giScene^ scene = giScene::Cast( &ptr->getScene() );
    
    Register( scene );
  }

//=============================+=====================================+=
                                Effector::~Effector()
  {
    if( !ptr ) return;
    
    NxScene* sceneptr = Owner->ptr;
    
    Unregister();
    
    if( !sceneptr ) return; // scene is disposing, no need to release explicitly    
    sceneptr->releaseEffector( *ptr );
  }
                                
//=============================+=====================================+=
Effector^                       Effector::Wrap(NxEffector* effectorptr)
  {
    if( NxSpringAndDamperEffector* sde = effectorptr->isSpringAndDamperEffector() ) return SpringAndDamperEffector::Wrap( sde );
    
    return Effector::Wrap( effectorptr );
  }

//=============================+=====================================+=
Effector^                       Scene::CreateEffector(EffectorDesc^ Desc)
  {
    NxEffector* effectorptr = ptr->createEffector( *Desc->data );
    return effectorptr ? Effector::Wrap( effectorptr ) : nullptr;    
  }

//=============================+=====================================+=
                                SpringAndDamperEffector::SpringAndDamperEffector(NxSpringAndDamperEffector* ptr):
                                  Effector( ptr )
  {
  }

//=============================+=====================================+=
                                SpringAndDamperEffector::~SpringAndDamperEffector()
  {
  }

//=============================+=====================================+=
void                            SpringAndDamperEffector::SetBodies(Actor^ Body0, Vector3 Global1, Actor^ Body1, Vector3 Global2)
  {
    ptr->setBodies( Body0->ptr, ToNx( Global1 ), Body1->ptr, ToNx( Global2 ) );
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddEffector(Effector^ Object, UserPropertiesType UserProperties, String^ ID)
  {
    const char* id    = ToNx( ID );
    const char* props = ToChar( UserProperties );

    bool Result = addEffector( *this->ptr, *Object->ptr, props, id );
    
    delete[] props;
    delete[] id;
    return Result;
  }
