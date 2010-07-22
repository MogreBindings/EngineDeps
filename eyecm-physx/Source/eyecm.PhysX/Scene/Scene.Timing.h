//=============================+=====================================+=
//public ref class                Scene:                                public giNxObject<NxScene, Scene, giNxRegisteredObject<Physics> >
//  {

    public:
      //-------------------------------------------------------------
      //---------------------== Timing ==----------------------------
      //-------------------------------------------------------------

      ref class                 ProxyTiming:                          public giNxProxy<NxScene>
        {
          internal:
            ProxyTiming(NxScene* data): giNxProxy( data ) {}

          public:
            property float      MaxTimestep
              {
                float           get()                                 { float t; NxU32 i; NxTimeStepMethod m; data->getTiming( t, i, m ); return t; }
                void            set(float v)                          { float t; NxU32 i; NxTimeStepMethod m; data->getTiming( t, i, m ); data->setTiming( v, i, m ); }
              }

            property unsigned   MaxIterationCount
              {
                unsigned        get()                                 { float t; NxU32 i; NxTimeStepMethod m; data->getTiming( t, i, m ); return i; }
                void            set(unsigned v)                       { float t; NxU32 i; NxTimeStepMethod m; data->getTiming( t, i, m ); data->setTiming( t, v, m ); }
              }

            property
            TimeStepMethods     Method
              {
                TimeStepMethods get()                                 { float t; NxU32 i; NxTimeStepMethod m; data->getTiming( t, i, m ); return static_cast<TimeStepMethods>( m ); }
                void            set(TimeStepMethods v)                { float t; NxU32 i; NxTimeStepMethod m; data->getTiming( t, i, m ); data->setTiming( t, i, static_cast<NxTimeStepMethod>( v ) ); }
              }

            property unsigned   SubStepCount
              {
                unsigned        get()                                 { float t; NxU32 i; NxTimeStepMethod m; NxU32 s; data->getTiming( t, i, m, &s ); return s; }
              }

            void                Set(float MaxTimeStep, unsigned MaxIterationCount, TimeStepMethods Method)
              {
                data->setTiming( MaxTimeStep, MaxIterationCount, static_cast<NxTimeStepMethod>( Method ) );
              }
        };

    private:
      ProxyTiming^              timing;

    public:
      property ProxyTiming^     Timing
        {
          ProxyTiming^          get()                                 { return timing; }
        }

//  };

//=============================+=====================================+=
