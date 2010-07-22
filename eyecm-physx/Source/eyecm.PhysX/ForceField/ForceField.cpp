//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "ForceField.h"
#include                       "Scene.h"
#include                       "Actor.h"
#include                       "PhysicsCollection.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
#pragma                         unmanaged

inline NxForceFieldShapeGroup*  GetNextGroup(NxForceField* ptr)       { return ptr->getNextShapeGroup(); }
inline void                     ResetGroups(NxForceField* ptr)        { return ptr->resetShapeGroupsIterator(); }
inline int                      GetGroupCount(NxForceField* ptr)      { return ptr->getNbShapeGroups(); }

//=============================+=====================================+=
#pragma                         managed

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
                                ForceField::ForceField(NxType* ptr):
                                  BaseType( ptr )
  {
    giScene^ scene = giScene::Cast( &GetNx()->getScene() );
    
    Register( scene );
  }

//=============================+=====================================+=
                                ForceField::~ForceField()
  {
    if( !GetNx() ) return;
    
    NxScene* sceneptr = Owner->GetNx();
    
    DefProxyDestroy( GroupsMask )
    // TODO: includegroup disposal
    Unregister();
    
    if( !sceneptr ) return; // scene is disposing, no need to dispose explicitly
    sceneptr->releaseForceField( *GetNx() );
  }

//=============================+=====================================+=
Actor^                          ForceField::Actor::get()              { return giActor::Cast( GetNx()->getActor() ); }
void                            ForceField::Actor::set(giActor^ v)    { GetNx()->setActor( v == nullptr ? 0 : v->GetNx() ); }

//=============================+=====================================+=
Actor^                          ForceFieldDesc::Actor::get()            { return giActor::Cast( GetNx()->actor ); }
void                            ForceFieldDesc::Actor::set(giActor^ v)  { GetNx()->actor = v == nullptr ? 0 : v->GetNx(); }

//=============================+=====================================+=
IEnumerableWithCount<
  ForceFieldShapeGroup^
>^                              ForceField::ShapeGroups::get()
  {
    typedef giNxEnumerable<ForceField, ForceFieldShapeGroup, GetNextGroup, ResetGroups, GetGroupCount> EnumerableType;
    return EnumerableType::Create( this );    
  }
  
//=============================+=====================================+=
void                            ForceField::AddShapeGroup(ForceFieldShapeGroup^ ShapeGroup)
  {
    GetNx()->addShapeGroup( *ShapeGroup->GetNx() );    
  }
  
//=============================+=====================================+=
void                            ForceField::RemoveShapeGroup(ForceFieldShapeGroup^ ShapeGroup)
  {
    GetNx()->removeShapeGroup( *ShapeGroup->GetNx() );
  }

//=============================+=====================================+=
ForceField^                     Scene::CreateForceField(ForceFieldDesc^ Desc)
  {
    NxForceField* ffptr = GetNx()->createForceField( *Desc->GetNx() );
    return ffptr ? gcnew ForceField( ffptr ) : nullptr;
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddForceField(ForceField^ Object, UserPropertiesType UserProperties, String^ ID)
  {
    const char* id    = ToNx( ID );
    const char* props = ToChar( UserProperties );
    
    bool Result = addForceField( *this->ptr, *Object->ptr, props, id );
    
    delete[] props;
    delete[] id;
    return Result;
  }
