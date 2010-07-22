//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "nxlist.h"
#include                       "Scene.h"
#include                       "Actor.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public value struct             ActorPairFilter
  {
    internal:
      typedef                   NxActorPairFilter                     NxType;
      NxActorPairFilter*        data;

      ActorPairFilter(NxActorPairFilter* data): data( data ) { }

    public:
      property Actor^           ActorFirst
        {
          Actor^                get()                                 { return Actor::Cast( data->actor[0] ); }
        }

      property Actor^           ActorSecond
        {
          Actor^                get()                                 { return Actor::Cast( data->actor[1] ); }
        }

      property bool             Filtered
        {
          bool                  get()                                 { return data->filtered; }
          void                  set(bool v)                           { data->filtered = v; }
        }

    internal:
      static ActorPairFilter    Cast(NxActorPairFilter* data)         { return ActorPairFilter( data ); }
  };

//=============================+=====================================+=
template<> struct               InstanceEquals<ActorPairFilter>       { bool operator()(ActorPairFilter a, ActorPairFilter b) { return a.data == b.data; } };

//=============================+=====================================+=
public interface class          IUserActorPairFiltering
  {
    void                        OnActorPairs(ReadOnlyCollection<ActorPairFilter>^ ActorPairFilters);
  };

//=============================+=====================================+=
class                           giNxUserActorPairFiltering:                 public NxUserActorPairFiltering
  {
    public:
      typedef                   giNxStaticList<
                                  ActorPairFilter,
                                  NxActorPairFilter,
                                  ActorPairFilter
                                >                                     ListType;

    public:
      gcroot<IUserActorPairFiltering^> iface;

    public:
      giNxUserActorPairFiltering(IUserActorPairFiltering^ iface) { this->iface = iface; }
      ~giNxUserActorPairFiltering() { this->iface = nullptr; }

    public:
      void                      onActorPairs(NxActorPairFilter* filterArray, NxU32 arraySize)
        {
          IUserActorPairFiltering^ Report = this->iface;
          if( Report == nullptr ) return;

          ListType^ list = gcnew ListType( filterArray, arraySize );
          Report->OnActorPairs( list );
          delete list;
        }
  };

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
DefSceneReportGetSet(           UserActorPairFiltering )
