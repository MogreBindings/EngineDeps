//=============================+=====================================+=
//public ref class                Shape:                                public giNxNamedObject<NxShape, Shape, giNxRegisteredObject<Actor> >
//  {
      ref class                 ProxyFlags:                           public giNxProxy<NxShape>
        {
          internal:
            ProxyFlags(NxShape* data): giNxProxy( data ) {}

          public:
            property bool       default[ShapeFlags]
              {
                bool            get(ShapeFlags f)                     { return FromNx( data->getFlag( static_cast<NxShapeFlag>( f ) ) ); }
                void            set(ShapeFlags f, bool v)             { data->setFlag( static_cast<NxShapeFlag>( f ), v ); }
              }

          #define               DefFlag( name, token ) \
            property bool       name \
              { \
                bool            get()                                 { return FromNx( data->getFlag( token ) ); } \
                void            set(bool v)                           { data->setFlag( token, v ); } \
              } \

            DefFlag(            TriggerOnEnter                      , NX_TRIGGER_ON_ENTER )
            DefFlag(            TriggerOnLeave                      , NX_TRIGGER_ON_LEAVE )
            DefFlag(            TriggerOnStay                       , NX_TRIGGER_ON_STAY )
            DefFlag(            TriggerEnable                       , NX_TRIGGER_ENABLE )
            DefFlag(            Visualization                       , NX_SF_VISUALIZATION )
            DefFlag(            DisableCollision                    , NX_SF_DISABLE_COLLISION )
            DefFlag(            FeatureIndices                      , NX_SF_FEATURE_INDICES )
            DefFlag(            DisableRaycasting                   , NX_SF_DISABLE_RAYCASTING )
            DefFlag(            PointContactForce                   , NX_SF_POINT_CONTACT_FORCE )
            DefFlag(            FluidDrain                          , NX_SF_FLUID_DRAIN )
            DefFlag(            FluidDisableCollision               , NX_SF_FLUID_DISABLE_COLLISION )
            DefFlag(            FluidTwoway                         , NX_SF_FLUID_TWOWAY )
            DefFlag(            DisableResponse                     , NX_SF_DISABLE_RESPONSE )
            DefFlag(            DynamicDynamicCCD                   , NX_SF_DYNAMIC_DYNAMIC_CCD )
            DefFlag(            DisableSceneQueries                 , NX_SF_DISABLE_SCENE_QUERIES )
            DefFlag(            ClothDrain                          , NX_SF_CLOTH_DRAIN )
            DefFlag(            ClothDisableCollision               , NX_SF_CLOTH_DISABLE_COLLISION )
            DefFlag(            ClothTwoway                         , NX_SF_CLOTH_TWOWAY )
            DefFlag(            SoftbodyDrain                       , NX_SF_SOFTBODY_DRAIN )
            DefFlag(            SoftbodyDisableCollision            , NX_SF_SOFTBODY_DISABLE_COLLISION )
            DefFlag(            SoftbodyTwoway                      , NX_SF_SOFTBODY_TWOWAY )

          #undef                DefFlag
        };

    private:
      ProxyFlags^               flags;

    public:
      property ProxyFlags^      Flags
        {
          ProxyFlags^           get()                                 { return flags; }
        }

//  };

//=============================+=====================================+=
//                                EndNamespace
//
