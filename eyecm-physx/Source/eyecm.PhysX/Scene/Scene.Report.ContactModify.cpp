//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Scene.h"
#include                       "Shape.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public ref struct               ContactCallbackData:                  public giNxProxy<NxUserContactModify::NxContactCallbackData>
  {
    internal:
      ContactCallbackData(NxType& data): BaseType( data ) { }
      ~ContactCallbackData() { }

    public:
      DefP0( float,             MinImpulse,                           minImpulse )
      DefP0( float,             MaxImpulse,                           maxImpulse )
      DefPx( Vector3,           Error,                                error )
      DefPx( Vector3,           Target,                               target )
      DefPx( Vector3,           LocalPosition0,                       localpos0 )
      DefPx( Vector3,           LocalPosition1,                       localpos1 )
      DefPx( Quaternion,        LocalOrientation0,                    localorientation0 )
      DefPx( Quaternion,        LocalOrientation1,                    localorientation1 )
      DefP0( float,             StaticFriction0,                      staticFriction0 )
      DefP0( float,             StaticFriction1,                      staticFriction1 )
      DefP0( float,             DynamicFriction0,                     dynamicFriction0 )
      DefP0( float,             DynamicFriction1,                     dynamicFriction1 )
      DefP0( float,             Restitution,                          restitution )
  };

//=============================+=====================================+=
public interface class          IUserContactModify
  {
    bool                        OnContactConstraint(
                                  ContactConstrainChangeFlags% ChangeFlags,
                                  Shape^                       Shape0,
                                  Shape^                       Shape1,
                                  unsigned                     FeatureIndex0,
                                  unsigned                     FeatureIndex1,
                                  ContactCallbackData^         Data
                                );
  };

//=============================+=====================================+=
class                           giNxUserContactModify:                public NxUserContactModify
  {
    public:
      gcroot<IUserContactModify^> iface;

    public:
      giNxUserContactModify(IUserContactModify^ iface) { this->iface = iface; }
      ~giNxUserContactModify() { this->iface = nullptr; }

    private:
      bool                      onContactConstraint(
                                  NxU32&                 changeFlags,
                                  const NxShape*         shape0,
                                  const NxShape*         shape1,
                                  const NxU32            featureIndex0,
                                  const NxU32            featureIndex1,
                                  NxContactCallbackData& data
                                )
      {
        ContactConstrainChangeFlags Flags = static_cast<ContactConstrainChangeFlags>( changeFlags );
        ContactCallbackData^        Data  = gcnew ContactCallbackData( data );

        bool result = iface->OnContactConstraint(Flags, Shape::Cast( shape0 ), Shape::Cast( shape1 ), featureIndex0, featureIndex1, Data );

        delete Data;
        changeFlags = static_cast<NxU32>( Flags );
        return result;
      }
  };

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
DefSceneReportGetSet(           UserContactModify )