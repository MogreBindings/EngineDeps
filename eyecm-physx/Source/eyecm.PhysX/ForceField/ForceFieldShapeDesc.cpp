//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "ForceFieldShapeDesc.h"
#include                       "Physics.h"

//=============================+=====================================+=
                                ConvexForceFieldShapeDesc::ConvexForceFieldShapeDesc(Physics^ physics, NxConvexForceFieldShapeDesc& data): 
                                  ForceFieldShapeDesc( data ) 
  { 
    this->convexmesh = data.meshData ? physics->WrapOrGet( *data.meshData ) : nullptr; 
  }

//=============================+=====================================+=
ForceFieldShapeDesc^            ForceFieldShapeDesc::Wrap(Physics^ physics, NxForceFieldShapeDesc& data)
  {
    switch( data.getType() ) {
    
      case NX_SHAPE_BOX:     return BoxForceFieldShapeDesc    ::Wrap( physics, static_cast<NxBoxForceFieldShapeDesc&>    ( data ) );
      case NX_SHAPE_CAPSULE: return CapsuleForceFieldShapeDesc::Wrap( physics, static_cast<NxCapsuleForceFieldShapeDesc&>( data ) );
      case NX_SHAPE_CONVEX:  return ConvexForceFieldShapeDesc ::Wrap( physics, static_cast<NxConvexForceFieldShapeDesc&> ( data ) );
      case NX_SHAPE_SPHERE:  return SphereForceFieldShapeDesc ::Wrap( physics, static_cast<NxSphereForceFieldShapeDesc&> ( data ) );
    }
    
    return gcnew ForceFieldShapeDesc( data );
  }

