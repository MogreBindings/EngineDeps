//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Fluid.h"
#include                       "FluidDesc.h"
#include                       "FluidEmitter.h"
#include                       "Scene.h"
#include                       "Shape.h"
#include                       "nxlist.h"
#include                       "PhysicsCollection.h"

/*
Descs should be garbage collected, 
  check custom array implementations for references
  check if callback delegates hold references
*/

//=============================+=====================================+=
#pragma                         unmanaged

//=============================+=====================================+=
inline NxFluidEmitter*          GetEmitter(NxFluid* ptr, int idx)     { return ptr->getEmitters()[idx]; }
inline int                      GetEmitterCount(NxFluid* ptr)         { return ptr->getNbEmitters(); }

//=============================+=====================================+=
#pragma                         managed

typedef                         giNxReadOnlyList<
                                  Fluid, FluidEmitter,
                                  GetEmitter, GetEmitterCount
                                >                                     EmitterCollection;

//=============================+=====================================+=
Shape^                          FluidEmitterDesc::FrameShape::get()
  {
    return giShape::CastOrNull( data->frameShape );
  }

//=============================+=====================================+=
void                            FluidEmitterDesc::FrameShape::set(giShape^ v)
  {
    data->frameShape = v == nullptr ? 0 : v->ptr;
  }

//=============================+=====================================+=
                                Fluid::Fluid(giScene^ scene, NxFluid* ptr, FluidDesc ^Desc):
                                  BaseType( ptr )
  {
    Register( scene );

    emitterlist = gcnew EmitterCollection( this );

    DefProxyCopyFast( ParticleWriteData );
    DefProxyCopyFast( ParticleDeletionIDWriteData );
    DefProxyCopyFast( ParticleCreationIDWriteData );
    DefProxyCopyFast( FluidPacketData );
  }

//=============================+=====================================+=
                                Fluid::~Fluid()
  {
    if( !this->ptr ) return;

    NxScene* sceneptr = Owner->ptr;
    NxFluid* ptr      = this->ptr;
    this->ptr = 0;

    while( First )
      delete First;

    DefProxyDestroy( Flags )
    DefProxyDestroy( GroupsMask )

    delete emitterlist; emitterlist = nullptr;

    DefProxyDestroy( ParticleWriteData );
    DefProxyDestroy( ParticleDeletionIDWriteData );
    DefProxyDestroy( ParticleCreationIDWriteData );
    DefProxyDestroy( FluidPacketData );

    Unregister();

    if( !sceneptr ) return; // scene is disposing, no need to release explicitly

    sceneptr->releaseFluid( *ptr );
  }

//=============================+=====================================+=
                                Fluid::!Fluid()
  {
  }

//=============================+=====================================+=
Fluid^                          Fluid::Wrap(NxFluid* ptr, FluidDesc ^Desc)
  {
    giScene^ scene = giScene::Cast( &ptr->getScene() );   
    Fluid^   fluid = gcnew Fluid( scene, ptr, Desc );

    const unsigned   ecnt     = ptr->getNbEmitters();
    NxFluidEmitter** emitters = ptr->getEmitters();

    for( unsigned i = 0; i < ecnt; i++ )
      FluidEmitter::Wrap( emitters[i] );

    return fluid;
  }

//=============================+=====================================+=
Fluid^                          Scene::CreateFluid(FluidDesc^ Desc)
  {
    NxFluid* fluidptr = ptr->createFluid( *Desc->data );
    //
    if( fluidptr == 0 ) return nullptr;

    return Fluid::Wrap( fluidptr, Desc );
  }

//=============================+=====================================+=
FluidEmitter^                   Fluid::CreateEmitter(FluidEmitterDesc^ Desc)
  {
    NxFluidEmitter* emitterptr = ptr->createEmitter( *Desc->data );
    return emitterptr ? FluidEmitter::Wrap( emitterptr ) : nullptr;
  }

//=============================+=====================================+=
bool                            Fluid::SaveEmittersToFluidDesc([Out] FluidDesc^% Desc)
  {
    Desc = gcnew FluidDesc();

    bool result = ptr->saveEmittersToFluidDesc( *Desc->data );
    Desc->InitEmitters();
        
    return result;
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddFluid(Fluid^ Object, UserPropertiesType UserProperties, String^ ID)
  {
    const char* id    = ToNx( ID );
    const char* props = ToChar( UserProperties );
    
    bool Result = addFluid( *this->ptr, *Object->ptr, props, id );
    
    delete[] props;
    delete[] id;
    return Result;
  }
