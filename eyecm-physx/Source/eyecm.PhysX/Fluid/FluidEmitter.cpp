//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Fluid.h"
#include                       "FluidDesc.h"
#include                       "FluidEmitter.h"
#include                       "Shape.h"

//=============================+=====================================+=
                                FluidEmitter::FluidEmitter(giFluid^ fluid, NxFluidEmitter* ptr):
                                  BaseType( ptr )
  {
    Register( fluid );
  }

//=============================+=====================================+=
                                FluidEmitter::~FluidEmitter()
  {
    if( !ptr ) return;

    NxFluid* fluidptr = Owner->ptr;

    DefProxyDestroy( Flags )

    Unregister();

    if( !fluidptr ) return; // fluid is disposing, no need to release explicitly

    fluidptr->releaseEmitter( *ptr );
  }

//=============================+=====================================+=
                                FluidEmitter::!FluidEmitter()
  {
  }

//=============================+=====================================+=
FluidEmitter^                   FluidEmitter::Wrap(NxFluidEmitter* ptr)
  {
    giFluid^ fluid = giFluid::Cast( &ptr->getFluid() );
    //
    return gcnew FluidEmitter( fluid, ptr );
  }

//=============================+=====================================+=
Shape^                          FluidEmitter::FrameShape::get()
  {
    return Shape::Cast( ptr->getFrameShape() );
  }

//=============================+=====================================+=
void                            FluidEmitter::FrameShape::set(Shape^ v)
  {
    ptr->setFrameShape( v->ptr );
  }