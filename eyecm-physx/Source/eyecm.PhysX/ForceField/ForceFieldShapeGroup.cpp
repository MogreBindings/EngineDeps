//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "ForceFieldDesc.h"
#include                       "ForceFieldShapeGroup.h"
#include                       "ForceFieldShape.h"
#include                       "Scene.h"

//=============================+=====================================+=
                                BeginNamespace
                                
//=============================+=====================================+=
#pragma                         unmanaged

inline NxForceFieldShape*       GetNextShape(NxForceFieldShapeGroup* ptr)  { return ptr->getNextShape(); }
inline void                     ResetShapes(NxForceFieldShapeGroup* ptr)   { return ptr->resetShapesIterator(); }
inline int                      GetShapeCount(NxForceFieldShapeGroup* ptr) { return ptr->getNbShapes(); }

//=============================+=====================================+=
#pragma                         managed

//=============================+=====================================+=
                                EndNamespace



//=============================+=====================================+=
                                ForceFieldShapeGroup::ForceFieldShapeGroup(NxForceFieldShapeGroup* ptr):
                                  BaseType( ptr )
  {
    giScene^ scene = giScene::Cast( &ptr->getScene() );
    
    Register( scene );
  }
  
//=============================+=====================================+=
                                ForceFieldShapeGroup::~ForceFieldShapeGroup()
  {
    if( !ptr ) return;
    
    NxScene* sceneptr = Owner->ptr;
    NxType* ptr = this->ptr;
    this->ptr = 0;
    
    while( First )
      delete First;
    
    Unregister();
    
    if( !sceneptr ) return; // scene is disposing, no need to delete explicitly
    sceneptr->releaseForceFieldShapeGroup( *ptr );
  }
                                
//=============================+=====================================+=
IEnumerableWithCount<
  ForceFieldShape^
>^                              ForceFieldShapeGroup::Shapes::get()
  {
    typedef giNxEnumerable<ForceFieldShapeGroup, ForceFieldShape, GetNextShape, ResetShapes, GetShapeCount> EnumerableType;
    return EnumerableType::Create( this );
  }

//=============================+=====================================+=
ForceFieldShapeGroup^           Scene::CreateForceFieldShapeGroup(ForceFieldShapeGroupDesc^ Desc)
  {
    NxForceFieldShapeGroup* groupptr = ptr->createForceFieldShapeGroup( *Desc->GetNx() );
    return groupptr ? gcnew ForceFieldShapeGroup( groupptr ) : nullptr;
  }
