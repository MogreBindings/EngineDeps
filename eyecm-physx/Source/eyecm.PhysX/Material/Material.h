//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Scene;

//=============================+=====================================+=
public ref struct               MaterialDesc:                         public giNxProxyData<NxMaterialDesc>
  {
    private:
      MaterialDesc(NxMaterialDesc& desc): BaseType( desc ) { }

    internal:
      inline static
      MaterialDesc^             Wrap(NxMaterialDesc& desc)            { return gcnew MaterialDesc( desc ); }

      DefDataConstructors( MaterialDesc )

    public:
      MaterialDesc() { }

      MaterialDesc(float StaticFriction, float DynamicFriction, float Restitution)
        {
          this->StaticFriction  = StaticFriction;
          this->DynamicFriction = DynamicFriction;
          this->Restitution     = Restitution;
        }

      MaterialDesc(float StaticFriction, float DynamicFriction, CombineModes FrictionCombineMode, float Restitution, CombineModes RestitutionCombineMode)
        {
          this->StaticFriction         = StaticFriction;
          this->DynamicFriction        = DynamicFriction;
          this->FrictionCombineMode    = FrictionCombineMode;
          this->Restitution            = Restitution;
          this->RestitutionCombineMode = RestitutionCombineMode;
        }

    public:
      property float            DynamicFriction
        {
          float                 get()                                 { return data->dynamicFriction; }
          void                  set(float v)                          { data->dynamicFriction = v; }
        }

      property float            StaticFriction
        {
          float                 get()                                 { return data->staticFriction; }
          void                  set(float v)                          { data->staticFriction = v; }
        }

      property float            Restitution
        {
          float                 get()                                 { return data->restitution; }
          void                  set(float v)                          { data->restitution = v; }
        }

      property float            DynamicFrictionV
        {
          float                 get()                                 { return data->dynamicFrictionV; }
          void                  set(float v)                          { data->dynamicFrictionV = v; }
        }

      property float            StaticFrictionV
        {
          float                 get()                                 { return data->staticFrictionV; }
          void                  set(float v)                          { data->staticFrictionV = v; }
        }

      property Vector3          DirectionOfAnisotropy
        {
          Vector3               get()                                 { return FromNx( data->dirOfAnisotropy ); }
          void                  set(Vector3 v)                        { data->dirOfAnisotropy = ToNx ( v ); }
        }

      property MaterialFlags    Flags
        {
          MaterialFlags         get()                                 { return static_cast<MaterialFlags>( data->flags ); }
          void                  set(MaterialFlags v)                  { data->flags = static_cast<NxU32>( v ); }
        }

      property CombineModes     FrictionCombineMode
        {
          CombineModes          get()                                 { return static_cast<CombineModes>( data->frictionCombineMode ); }
          void                  set(CombineModes v)                   { data->frictionCombineMode = static_cast<NxCombineMode>( v ); }
        }

      property CombineModes     RestitutionCombineMode
        {
          CombineModes          get()                                 { return static_cast<CombineModes>( data->restitutionCombineMode ); }
          void                  set(CombineModes v)                   { data->restitutionCombineMode = static_cast<NxCombineMode>( v ); }
        }
  };

//=============================+=====================================+=
public ref class                Material:                             public giNxObject<NxMaterial, Material, giNxRegisteredObject<Scene> >
  {
    internal:
      typedef                   ThisNamespace::Scene                  giScene;

      Material(giScene^ Scene, NxMaterial* ptr);
      ~Material();

      static Material^          CastOrWrap(NxMaterial* ptr);

    public:
      property giScene^         Scene
        {
          giScene^              get()                                 { return Owner; }
        }

      property unsigned         Index
        {
          unsigned              get()                                 { return ptr->getMaterialIndex(); }
        }

      property float            DynamicFriction
        {
          float                 get()                                 { return ptr->getDynamicFriction(); }
          void                  set(float v)                          { ptr->setDynamicFriction( v ); }
        }

      property float            StaticFriction
        {
          float                 get()                                 { return ptr->getStaticFriction(); }
          void                  set(float v)                          { ptr->setStaticFriction( v ); }
        }

      property float            Restitution
        {
          float                 get()                                 { return ptr->getRestitution(); }
          void                  set(float v)                          { ptr->setRestitution( v ); }
        }

      property float            DynamicFrictionV
        {
          float                 get()                                 { return ptr->getDynamicFrictionV(); }
          void                  set(float v)                          { ptr->setDynamicFrictionV( v ); }
        }

      property float            StaticFrictionV
        {
          float                 get()                                 { return ptr->getStaticFrictionV(); }
          void                  set(float v)                          { ptr->setStaticFrictionV( v ); }
        }

      property Vector3          DirectionOfAnisotropy
        {
          Vector3               get()                                 { return FromNx( ptr->getDirOfAnisotropy() ); }
          void                  set(Vector3 v)                        { ptr->setDirOfAnisotropy( ToNx( v ) ); }
        }

      property MaterialFlags    Flags
        {
          MaterialFlags         get()                                 { return static_cast<MaterialFlags>( ptr->getFlags() ); }
          void                  set(MaterialFlags v)                  { ptr->setFlags( static_cast<NxU32>( v ) ); }
        }

      property CombineModes     FrictionCombineMode
        {
          CombineModes          get()                                 { return static_cast<CombineModes>( ptr->getFrictionCombineMode() ); }
          void                  set(CombineModes v)                   { ptr->setFrictionCombineMode( static_cast<NxCombineMode>( v ) ); }
        }

      property CombineModes     RestitutionCombineMode
        {
          CombineModes          get()                                 { return static_cast<CombineModes>( ptr->getRestitutionCombineMode() ); }
          void                  set(CombineModes v)                   { ptr->setRestitutionCombineMode( static_cast<NxCombineMode>( v ) ); }
        }

    public:
                                DefSaveToDesc( Material )
  };

//=============================+=====================================+=
                                EndNamespace

