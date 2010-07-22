//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref struct                      JointDesc;
ref class                       Scene;
ref class                       Actor;

//=============================+=====================================+=
public ref class                Joint:                                giNxNamedObject<NxJoint, Joint, giNxRegisteredObject<Scene> >
  {
    internal:
      typedef                   ThisNamespace::Plane                  giPlane;
      typedef                   ThisNamespace::Scene                  giScene;

    internal:
      Joint(giScene^ Scene, NxJoint* ptr, JointDesc^ Desc);

    public:
      ~Joint();

    public:
      property giScene^         Scene
        {
          giScene^              get()                                 { return Owner; }
        }

      property Actor^           ActorFirst                            { Actor^ get(); }
      property Actor^           ActorSecond                           { Actor^ get(); }

      property JointStates      State
        {
          JointStates           get()                                 { return static_cast<JointStates>( ptr->getState() ); }
        }

      property JointTypes       Type
        {
          JointTypes            get()                                 { return static_cast<JointTypes>( ptr->getType() ); }
        }

      property float            MaxForce
        {
          float                 get()                                 { float mf, mt; ptr->getBreakable( mf, mt ); return mf; }
          void                  set(float v)                          { float mf, mt; ptr->getBreakable( mf, mt ); ptr->setBreakable( v, mt ); }
        }

      property float            MaxTorque
        {
          float                 get()                                 { float mf, mt; ptr->getBreakable( mf, mt ); return mt; }
          void                  set(float v)                          { float mf, mt; ptr->getBreakable( mf, mt ); ptr->setBreakable( mf, v ); }
        }

      property float            SolverExtrapolationFactor
        {
          float                 get()                                 { return ptr->getSolverExtrapolationFactor(); }
          void                  set(float v)                          { ptr->setSolverExtrapolationFactor( v ); }
        }

      property bool             UseAccelerationSpring
        {
          bool                  get()                                 { return ptr->getUseAccelerationSpring(); }
          void                  set(bool v)                           { ptr->setUseAccelerationSpring( v ); }
        }

      void                      SetBreakable(float MaxForce, float MaxTorque)
        {
          ptr->setBreakable( MaxForce, MaxTorque );
        }

      void                      GetBreakable([System::Runtime::InteropServices::Out] float% MaxForce, [System::Runtime::InteropServices::Out] float% MaxTorque)
        {
          float mf, mt;
          ptr->getBreakable( mf, mt );
          MaxForce  = mf;
          MaxTorque = mt;
        }

      DefMx( Vector3,           GlobalAnchor,                         GlobalAnchor )
      DefMx( Vector3,           GlobalAxis,                           GlobalAxis )

      property Vector3          LimitPoint
        {
          Vector3               get()                                 { NxVec3 v; ptr->getLimitPoint( v ); return FromNx( v ); }
          void                  set(Vector3 v)                        { ptr->setLimitPoint( ToNx( v ) );  }
        }

      property bool             IsLimitPointOnSecondActor
        {
          bool                  get()                                 { NxVec3 v; return ptr->getLimitPoint( v ); }
        }

      property Vector3          LimitPointOnFirstActor
        {
          void                  set(Vector3 v)                        { ptr->setLimitPoint( ToNx( v ), false );  }
        }

    public:
      value struct              LimitPlane
        {
          private:
            Vector3             normal;
            float               distance, restitution;

          internal:
            LimitPlane( NxVec3 normal, float distance, float restitution)
              {
                this->normal      = FromNx( normal );
                this->distance    = distance;
                this->restitution = restitution;
              }

          public:
            property giPlane    Plane
              {
                giPlane         get()                                 { return FromNx( NxPlane( ToNx( normal ), distance ) ); }
              }

            property Vector3    Normal
              {
                Vector3         get()                                 { return normal; }
              }

            property float      Distance
              {
                float           get()                                 { return distance; }
              }

            property float      Restitution
              {
                float           get()                                 { return restitution; }
              }
        };

      ref struct                ProxyLimitPlanes:                     public giNxProxy<NxJoint>, IEnumerable<LimitPlane>
        {
          internal:
            ProxyLimitPlanes(NxJoint* data): giNxProxy( data ) { }

          public:
            bool                Add(Vector3 Normal, Vector3 PointInPlane, float Restitution)
              {
                return data->addLimitPlane( ToNx( Normal ), ToNx( PointInPlane ), Restitution );
              }

            void                Purge()
              {
                data->purgeLimitPlanes();
              }

          internal:
            virtual System::Collections::
            IEnumerator^        GetEnumeratorIEnumerable() = System::Collections::IEnumerable::GetEnumerator { return gcnew Enumerator( data ); }

          public:
            virtual IEnumerator<
              LimitPlane
            >^                  GetEnumerator()                       { return gcnew Enumerator( data ); }

            ref struct          Enumerator:                           public giNxProxy<NxJoint>, IEnumerator<LimitPlane>
              {
                private:
                  LimitPlane current;

                internal:
                  Enumerator(NxJoint* data): giNxProxy( data ) { Reset(); }

                public:
                  virtual bool  MoveNext()
                    {
                      if( !data->hasMoreLimitPlanes() ) return false;

                      NxVec3 n; float d, r;
                      data->getNextLimitPlane( n, d, &r );
                      current = LimitPlane( n, d, r );
                      return true;
                    }

                  virtual void  Reset()
                    {
                      data->resetLimitPlaneIterator();
                    }

                  virtual
                  property
                  Object^       OldCurrent
                    {
                      Object^   get() = System::Collections::IEnumerator::Current::get { return current; }
                    }

                  virtual
                  property
                  LimitPlane    Current
                    {
                      LimitPlane get() { return current; }
                    }
              };
        };

    private:
      ProxyLimitPlanes^         limitplanes;

    public:
      property
      ProxyLimitPlanes^         LimitPlanes
        {
          ProxyLimitPlanes^     get()                                 { return limitplanes; }
        }

     internal:
      static Joint^             Wrap(giScene^ Scene, NxJoint* ptr, JointDesc^ Desc);
      static Joint^             Wrap(NxJoint* ptr);
  };

//=============================+=====================================+=
                                EndNamespace

