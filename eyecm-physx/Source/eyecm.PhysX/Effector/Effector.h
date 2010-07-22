//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "EffectorDesc.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Scene;

//=============================+=====================================+= // TODO: has name
public ref class                Effector:                             public giNxNamedObject<NxEffector, Effector, giNxRegisteredObject<Scene> >
  {
    internal:
      typedef                   ThisNamespace::Scene                  giScene;

    internal:
      Effector(NxEffector*);
      
      static Effector^          Wrap(NxEffector*);

    public:
      ~Effector();
      
    public:
      property giScene^         Scene
        {
          giScene^              get()                                 { return Owner; }
        }
        
      Defmc( EffectorTypes,     Type,                                 Type )
  };

//=============================+=====================================+=
public ref class                SpringAndDamperEffector:              public Effector
  {
      DefRecastPtr( NxSpringAndDamperEffector, Effector )

    private:
      SpringAndDamperEffector(NxSpringAndDamperEffector*);

    internal:
      inline static 
      SpringAndDamperEffector^  Wrap(NxSpringAndDamperEffector* effectorptr) { return gcnew SpringAndDamperEffector( effectorptr ); }
      
    public:
      ~SpringAndDamperEffector();
      
    public:
      DefSaveToDesc( SpringAndDamperEffector )
      
    public:
      void                      SetBodies(Actor^ Body0, Vector3 Global1, Actor^ Body1, Vector3 Global2);

      void                      SetLinearSpring(float DistCompressSaturate, float DistRelaxed, float DistStretchSaturate, float MaxCompressForce, float MaxStretchForce)
        {
          ptr->setLinearSpring( DistCompressSaturate, DistRelaxed, DistStretchSaturate, MaxCompressForce, MaxStretchForce);
        }

      void                      GetLinearSpring(float% DistCompressSaturate, float% DistRelaxed, float% DistStretchSaturate, float% MaxCompressForce, float% MaxStretchForce)
        {
          float _DistCompressSaturate, _DistRelaxed, _DistStretchSaturate, _MaxCompressForce, _MaxStretchForce;

          ptr->getLinearSpring( _DistCompressSaturate, _DistRelaxed, _DistStretchSaturate, _MaxCompressForce, _MaxStretchForce );

          DistCompressSaturate = _DistCompressSaturate;
          DistRelaxed          = _DistRelaxed;
          DistStretchSaturate  = _DistStretchSaturate;
          MaxCompressForce     = _MaxCompressForce;
          MaxStretchForce      = _MaxStretchForce;
        }

      void                      SetLinearDamper(float VelCompressSaturate, float VelStretchSaturate, float MaxCompressForce, float MaxStretchForce)
        {
          ptr->setLinearDamper( VelCompressSaturate, VelStretchSaturate, MaxCompressForce, MaxStretchForce );
        }

      void                      GetLinearDamper(float% VelCompressSaturate, float% VelStretchSaturate, float% MaxCompressForce, float% MaxStretchForce)
        {
          float _VelCompressSaturate, _VelStretchSaturate, _MaxCompressForce, _MaxStretchForce;

          ptr->getLinearDamper( _VelCompressSaturate, _VelStretchSaturate, _MaxCompressForce, _MaxStretchForce );
          
          VelCompressSaturate = _VelCompressSaturate;
          VelStretchSaturate  = _VelStretchSaturate;
          MaxCompressForce    = _MaxCompressForce;
          MaxStretchForce     = _MaxStretchForce;
        }
  };

//=============================+=====================================+=
                                EndNamespace
