//=============================+=====================================+=
//public ref class                Scene:                                public giNxObject<NxScene, Scene, giNxRegisteredObject<Physics> >
//  {

    public:
      ref class                 ProxyLimits:                          public giNxData<NxSceneLimits>
        {
          internal:
            ProxyLimits(NxScene* ptr) { ptr->getLimits( *data ); }

          public:
            property unsigned   ActorCount
              {
                unsigned        get()                                 { return data->maxNbActors; }
              }

            property unsigned   BodyCount
              {
                unsigned        get()                                 { return data->maxNbBodies; }
              }

            property unsigned   StaticShapeCount
              {
                unsigned        get()                                 { return data->maxNbStaticShapes; }
              }

            property unsigned   DynamicShapeCount
              {
                unsigned        get()                                 { return data->maxNbDynamicShapes; }
              }

            property unsigned   JointCount
              {
                unsigned        get()                                 { return data->maxNbJoints; }
              }
        };

    private:
      ProxyLimits^              limits;

    public:
      property ProxyLimits^     Limits
        {
          ProxyLimits^          get()                                 { return limits; }
        }

//  };

//=============================+=====================================+=
