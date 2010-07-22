//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Actor;

//=============================+=====================================+= // TODO: has name
public ref struct               EffectorDesc:                         public giNxProxyData<NxEffectorDesc>
  {
    internal:
      EffectorDesc(NxType* subclassptr): BaseType( subclassptr ) { }
      
    public:
      ~EffectorDesc() { }

    public:
      property EffectorTypes    Type
        {
          EffectorTypes         get()                                 { return static_cast<EffectorTypes>( data->getType() ); }
        }
  };

//=============================+=====================================+= 
public ref struct               SpringAndDamperEffectorDesc:          public EffectorDesc
  {
    internal:
      DefRecastData( NxSpringAndDamperEffectorDesc, EffectorDesc )
      
    private:
      SpringAndDamperEffectorDesc(NxSpringAndDamperEffectorDesc& desc): EffectorDesc( &desc ) { }
    
    internal:
      inline static 
      SpringAndDamperEffectorDesc^ Wrap(NxSpringAndDamperEffectorDesc& desc) { return gcnew SpringAndDamperEffectorDesc( desc ); }      
      
    public:
      SpringAndDamperEffectorDesc(): EffectorDesc( new NxSpringAndDamperEffectorDesc ) { }      
      ~SpringAndDamperEffectorDesc() { }
      
    public:
      property Actor^           Body1                                 { Actor^ get(); void set(Actor^); }
      property Actor^           Body2                                 { Actor^ get(); void set(Actor^); }
      
      DefPx( Vector3,           Position1,                            pos1 )
      DefPx( Vector3,           Position2,                            pos2 )
      DefP0( float,             SpringDistanceCompressSaturate,       springDistCompressSaturate )
      DefP0( float,             SpringDistanceRelaxed,                springDistRelaxed )
      DefP0( float,             SpringMaxCompressForce,               springMaxCompressForce )
      DefP0( float,             SpringMaxStretchForce,                springMaxStretchForce )
      DefP0( float,             DamperVelocityCompressSaturate,       damperVelCompressSaturate )
      DefP0( float,             DamperVelocityStretchSaturate,        damperVelStretchSaturate )
      DefP0( float,             DamperMaxCompressForce,               damperMaxCompressForce )
      DefP0( float,             DamperMaxStretchForce,                damperMaxStretchForce )      
  };

//=============================+=====================================+=
                                EndNamespace
  