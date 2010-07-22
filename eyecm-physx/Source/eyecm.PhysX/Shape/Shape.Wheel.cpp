//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Shape.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public interface class          IUserWheelContactModify
  {
      bool                      OnWheelContact(

                                  WheelShape^ Wheel,
                                  Vector3%    ContactPoint,
                                  Vector3%    ContactNormal,
                                  float%      ContactPosition,
                                  float%      NormalForce,
                                  Shape^      OtherShape,
                                  unsigned%   OtherShapeMaterialIndex,
                                  unsigned    OtherShapeFeatureIndex
                                );
  };

//=============================+=====================================+=
class                           giNxUserWheelContactModify:           public NxUserWheelContactModify
  {
    public:
      gcroot<IUserWheelContactModify^> iface;

      giNxUserWheelContactModify(IUserWheelContactModify^ iface) { this->iface = iface; }

    private:
      bool                      onWheelContact(NxWheelShape* wheelShape, NxVec3& contactPoint, NxVec3& contactNormal, NxReal& contactPosition, NxReal& normalForce, NxShape* otherShape, NxMaterialIndex& otherShapeMaterialIndex, NxU32 otherShapeFeatureIndex)
        {
          WheelShape^ Wheel         = static_cast<WheelShape^>( WheelShape::Cast( wheelShape ) );
          Vector3     ContactPoint  = FromNx( contactPoint );
          Vector3     ContactNormal = FromNx( contactNormal );
          Shape^      OtherShape    = Shape::CastAny( otherShape );
          unsigned    MaterialIndex = otherShapeMaterialIndex;

          bool result = iface->OnWheelContact( Wheel, ContactPoint, ContactNormal, contactPosition, normalForce, OtherShape, MaterialIndex, otherShapeFeatureIndex );

          otherShapeMaterialIndex = static_cast<NxMaterialIndex>( MaterialIndex );
          contactNormal           = ToNx( ContactNormal );
          contactPoint            = ToNx( ContactPoint );

          return result;
        }
  };

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
void                            WheelShape::Init(WheelShapeDesc^ Desc)
  {
    callback = 0;
    //
    if( Desc != nullptr ) this->WheelContactModify = Desc->WheelContactModify;
  }

//=============================+=====================================+=
                                WheelShape::~WheelShape()
  {
    DefProxyDestroy( Suspension                  )
    DefProxyDestroy( LongitudalTireForceFunction )
    DefProxyDestroy( LateralTireForceFunction    )
    //
    this->!WheelShape();
  }

//=============================+=====================================+=
                                WheelShape::!WheelShape()
  {
    delete callback; callback = 0;
  }

//=============================+=====================================+=
IUserWheelContactModify^        WheelShape::WheelContactModify::get()
  {
    return callback ? callback->iface : nullptr;
  }

//=============================+=====================================+=
void                            WheelShape::WheelContactModify::set(IUserWheelContactModify^ Callback)
  {
    if( !Callback ) { delete callback; callback = 0; return; }
    //
    if( callback ) { callback->iface = Callback; return; }
    //
    callback = new giNxUserWheelContactModify( Callback );
  }

//=============================+=====================================+=
IUserWheelContactModify^        WheelShapeDesc::WheelContactModify::get()
  {
    return !data->wheelContactModify ? nullptr : static_cast<giNxUserWheelContactModify*>( data->wheelContactModify )->iface;
  }

//=============================+=====================================+=
void                            WheelShapeDesc::WheelContactModify::set(IUserWheelContactModify^ Callback)
  {
    if( !Callback ) { delete static_cast<giNxUserWheelContactModify*>( data->wheelContactModify ); data->wheelContactModify = 0; return; }
    if( data->wheelContactModify ) { static_cast<giNxUserWheelContactModify*>( data->wheelContactModify )->iface = Callback; return; }
    //
    data->wheelContactModify = new giNxUserWheelContactModify( Callback );
  }

//=============================+=====================================+=
                                WheelShapeDesc::!WheelShapeDesc()
  {
    delete static_cast<giNxUserWheelContactModify*>( data->wheelContactModify ); data->wheelContactModify = 0;
  }
