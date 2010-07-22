//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "Shape.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public value struct             SweepQueryHit
  {
    internal:
      typedef                   NxSweepQueryHit                       NxType;

      NxSweepQueryHit*          data;

      SweepQueryHit(NxSweepQueryHit* data): data( data ) { }

    public:
      property Shape^           HitShape
        {
          Shape^                get()                                 { return Shape::Cast( data->hitShape ); }
        }

      property Shape^           SweepShape
        {
          Shape^                get()                                 { return Shape::CastOrNull( data->sweepShape ); }
        }

      property Object^          UserData
        {
          Object^               get()
            {
              if( !data->userData ) return nullptr;
              return *static_cast<gcroot<Object^>*>( data->userData );
            }
        }

      DefR0( float,             Distance,                             t )
      DefR0( unsigned,          InternalFaceID,                       internalFaceID )
      DefR0( unsigned,          FaceID,                               faceID )
      DefRx( Vector3,           Point,                                point )
      DefRx( Vector3,           Normal,                               normal )

    internal:
      inline static
      SweepQueryHit             Cast(NxSweepQueryHit* ptr)            { return SweepQueryHit( ptr ); }
  };

//=============================+=====================================+=
template<> struct               InstanceEquals<SweepQueryHit>         { bool operator()(SweepQueryHit a, SweepQueryHit b) { return a.data == b.data; } };

//=============================+=====================================+=
public ref struct               GroupsMask:                           public DefCBProxyBase<NxGroupsMask> // TODO: move this to another place
  {
    internal:
      DefCBProxyConstructorsX( GroupsMask, DefNothing )

    public:
      GroupsMask() { }

    public:
      DefP0( unsigned,          Bits0,                                bits0 )
      DefP0( unsigned,          Bits1,                                bits1 )
      DefP0( unsigned,          Bits2,                                bits2 )
      DefP0( unsigned,          Bits3,                                bits3 )
  };

//=============================+=====================================+=
public value struct             RaycastHit
  {
    internal:
      typedef                   ThisNamespace::Shape                  giShape;
      typedef                   const NxRaycastHit                    NxType;

    internal:
      RaycastHit(const NxRaycastHit& data)
        {
          Shape           = giShape::CastOrNull( data.shape );
          WorldImpact     = FromNx( data.worldImpact );
          WorldNormal     = FromNx( data.worldNormal );
          FaceID          = data.faceID;
          InternalFaceID  = static_cast<unsigned>( data.internalFaceID );
          Distance        = data.distance;
          U               = data.u;
          V               = data.v;
          MaterialIndex   = static_cast<unsigned>( data.materialIndex );
          Flags           = static_cast<RaycastBits>( data.flags );
        }

    public:
      giShape^                  Shape;
      Vector3                   WorldImpact;
      Vector3                   WorldNormal;
      unsigned                  FaceID;
      unsigned                  InternalFaceID;
      float                     Distance;
      float                     U;
      float                     V;
      unsigned                  MaterialIndex;
      RaycastBits               Flags;

    internal:
      inline static RaycastHit  Cast(const NxRaycastHit* ptr)         { return RaycastHit( *ptr ); }
  };

//=============================+=====================================+=
template<>
struct                          InstanceEquals<RaycastHit>
  {
      bool                      operator()(RaycastHit, RaycastHit)    { return false; }
  };

//=============================+=====================================+=
                                EndNamespace
