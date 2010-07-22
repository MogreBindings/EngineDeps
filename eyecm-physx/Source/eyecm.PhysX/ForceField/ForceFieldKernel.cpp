//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "ForceFieldKernel.h"
#include                       "ForceField.h"
#include                       "Scene.h"

//=============================+=====================================+=
                                ForceFieldLinearKernel::ForceFieldLinearKernel(NxForceFieldLinearKernel* ptr):
                                  ForceFieldKernel( ptr )
  {
    giScene^ scene = giScene::Cast( &ptr->getScene() );
    
    Register( scene );
  }
  
//=============================+=====================================+=
                                ForceFieldLinearKernel::~ForceFieldLinearKernel()
  {
    if( !GetNx() ) return;
    
    NxScene* sceneptr = Owner->GetNx();
    
    Unregister();
    
    if( !sceneptr ) return; // scene is disposing, no need to release explicitly
    
    sceneptr->releaseForceFieldLinearKernel( *ptr );
  }

//=============================+=====================================+=
ForceFieldKernel^               ForceField::ForceFieldKernel::get()                      { return giForceFieldKernel::CastOrNull( ptr->getForceFieldKernel() ); }
void                            ForceField::ForceFieldKernel::set(giForceFieldKernel^ v) { ptr->setForceFieldKernel( v == nullptr ? 0 : v->ptr ); }

//=============================+=====================================+=
ForceFieldKernel^               ForceFieldDesc::ForceFieldKernel::get()                      { return giForceFieldKernel::CastOrNull( data->kernel ); }
void                            ForceFieldDesc::ForceFieldKernel::set(giForceFieldKernel^ v) { data->kernel = v == nullptr ? 0 : v->ptr; }

//=============================+=====================================+=
ForceFieldLinearKernel^         Scene::CreateForceFieldLinearKernel(ForceFieldLinearKernelDesc^ Desc)
  {
    NxForceFieldLinearKernel* lkptr = ptr->createForceFieldLinearKernel( *Desc->data );
    return lkptr ? gcnew ForceFieldLinearKernel( lkptr ) : nullptr;
  }
