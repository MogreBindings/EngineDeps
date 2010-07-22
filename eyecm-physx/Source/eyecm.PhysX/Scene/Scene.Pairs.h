//=============================+=====================================+=
//public ref class                Scene:                                public giNxObject<NxScene, Scene, giNxRegisteredObject<Physics> >
//  {

    public:
      //-------------------------------------------------------------
      //---------------------== Pair Flags ==------------------------
      //-------------------------------------------------------------

      #define                   DefPair( name, obj, param ) \
        \
        ref class               Proxy##name:                          public giNxProxy<NxScene> \
          { \
            \
            internal: \
              Proxy##name(NxScene* data): giNxProxy( data ) { } \
              \
            public: \
              property param    default[obj, obj]                     { param get(obj a, obj b); void set(obj a, obj b, param v); } \
          }; \
          \
      private: \
        Proxy##name^            pairs##name; \
        \
      public: \
        \
        property Proxy##name^   name \
          { \
            Proxy##name^        get()                                 { return pairs##name; } \
          } \

        DefPair               ( ActorPairFlags, Actor^, ContactPairFlags )
        DefPair               ( ShapePairFlags, Shape^, ContactPairFlags )
        DefPair               ( GroupCollisionFlags, unsigned, bool )
        DefPair               ( ActorGroupPairFlags, unsigned, ContactPairFlags )

      #undef                    DefPair

      void                      InitPairs()
        {
          pairsActorPairFlags      = gcnew ProxyActorPairFlags( ptr );
          pairsShapePairFlags      = gcnew ProxyShapePairFlags( ptr );
          pairsGroupCollisionFlags = gcnew ProxyGroupCollisionFlags( ptr );
          pairsActorGroupPairFlags = gcnew ProxyActorGroupPairFlags( ptr );
        }

      void                      DeInitPairs()
        {
          delete pairsActorPairFlags;      pairsActorPairFlags      = nullptr;
          delete pairsShapePairFlags;      pairsShapePairFlags      = nullptr;
          delete pairsGroupCollisionFlags; pairsGroupCollisionFlags = nullptr;
          delete pairsActorGroupPairFlags; pairsActorGroupPairFlags = nullptr;
        }

//  };

//=============================+=====================================+=
