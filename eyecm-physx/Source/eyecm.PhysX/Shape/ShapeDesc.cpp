//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "ShapeDesc.h"

//=============================+=====================================+=
ShapeDesc^                      ShapeDesc::Wrap(Physics^ physics, NxShapeDesc& data)
  {
    switch( data.getType() ) {

      case NX_SHAPE_PLANE:        return PlaneShapeDesc::Wrap       ( data );
      case NX_SHAPE_SPHERE:       return SphereShapeDesc::Wrap      ( data );
      case NX_SHAPE_BOX:          return BoxShapeDesc::Wrap         ( data );
      case NX_SHAPE_CAPSULE:      return CapsuleShapeDesc::Wrap     ( data );
      case NX_SHAPE_MESH:         return TriangleMeshShapeDesc::Wrap( physics, data );
      case NX_SHAPE_CONVEX:       return ConvexShapeDesc::Wrap      ( physics, data );
      case NX_SHAPE_HEIGHTFIELD:  return HeightFieldShapeDesc::Wrap ( physics, data );
      case NX_SHAPE_WHEEL:        return WheelShapeDesc::Wrap       ( data );
    }
    return nullptr;
  }

//=============================+=====================================+=
ShapeDesc^                      ShapeDesc::Clone()
  {
    switch( data->getType() ) {

      case NX_SHAPE_PLANE:        return static_cast<PlaneShapeDesc^>       ( this )->Clone();
      case NX_SHAPE_SPHERE:       return static_cast<SphereShapeDesc^>      ( this )->Clone();
      case NX_SHAPE_BOX:          return static_cast<BoxShapeDesc^>         ( this )->Clone();
      case NX_SHAPE_CAPSULE:      return static_cast<CapsuleShapeDesc^>     ( this )->Clone();
      case NX_SHAPE_MESH:         return static_cast<TriangleMeshShapeDesc^>( this )->Clone();
      case NX_SHAPE_CONVEX:       return static_cast<ConvexShapeDesc^>      ( this )->Clone();
      case NX_SHAPE_HEIGHTFIELD:  return static_cast<HeightFieldShapeDesc^> ( this )->Clone();
      case NX_SHAPE_WHEEL:        return static_cast<WheelShapeDesc^>       ( this )->Clone();
    }
    throw gcnew Exception();
  }
