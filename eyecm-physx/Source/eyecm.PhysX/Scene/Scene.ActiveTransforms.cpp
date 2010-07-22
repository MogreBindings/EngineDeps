//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Scene.h"
#include                       "Actor.h"
#include                       "nxlist.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public value struct             ActiveTransform
  {
    internal:
      typedef                   ThisNamespace::Actor                  giActor;
      typedef                   NxActiveTransform                     NxType;

      NxActiveTransform*        data;

    internal:
      ActiveTransform(NxActiveTransform* data): data( data ) { }

    public:
      property giActor^         Actor
        {
          giActor^              get()                                 { return giActor::CastUserData( data->userData ); }
        }

      property Matrix4x4        Actor2World
        {
          Matrix4x4             get()                                 { return FromNx( data->actor2World ); }
        }

    internal:
      static ActiveTransform    Cast(NxType* ptr)                     { return ActiveTransform( ptr ); }
  };

//=============================+=====================================+=
template<>
struct                          InstanceEquals<ActiveTransform>
  {
    bool                        operator()(ActiveTransform, ActiveTransform) { return false; }
  };


//=============================+=====================================+=
public ref class                ActiveTransforms:                     public giNxStaticList<ActiveTransform, NxActiveTransform, ActiveTransform>
  {
    internal:
      ActiveTransforms(NxActiveTransform* ats, NxU32 atc): giNxStaticList( ats, atc ) { }

    public:
      ~ActiveTransforms() {}
  };

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
ActiveTransforms^               Scene::GetActiveTransforms()
  {
    NxU32              atc;
    NxActiveTransform* ats = ptr->getActiveTransforms( atc );

    return gcnew ActiveTransforms( ats, atc );
  }

