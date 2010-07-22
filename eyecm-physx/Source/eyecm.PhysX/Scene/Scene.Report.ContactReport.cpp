//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Scene.h"
#include                       "Actor.h"
#include                       "Shape.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public ref class                ContactStreamIterator:                public giNxData<NxContactStreamIterator>
  {
    private:
      typedef                   ThisNamespace::Shape                  giShape;
      typedef                   ThisNamespace::ShapeFlags             giShapeFlags;

    internal:
      ContactStreamIterator(NxConstContactStream stream): giNxData( new NxContactStreamIterator( stream ) ) { }

    public:
      bool                      NextPair()                            { return data->goNextPair(); }
      bool                      NextPatch()                           { return data->goNextPatch(); }
      bool                      NextPoint()                           { return data->goNextPoint(); }

    public:
      property unsigned         PairCount
        {
          unsigned              get()                                 { return data->getNumPairs(); }
        }

      property unsigned         PatchCount
        {
          unsigned              get()                                 { return data->getNumPatches(); }
        }

      property unsigned         PatchesRemaining
        {
          unsigned              get()                                 { return data->getNumPatchesRemaining(); }
        }

      property unsigned         PointCount
        {
          unsigned              get()                                 { return data->getNumPoints(); }
        }

      property unsigned         PointsRemaining
        {
          unsigned              get()                                 { return data->getNumPointsRemaining(); }
        }

      property unsigned         FeatureIndex0
        {
          unsigned              get()                                 { return data->getFeatureIndex0(); }
        }

      property unsigned         FeatureIndex1
        {
          unsigned              get()                                 { return data->getFeatureIndex1(); }
        }

      property giShape^         ShapeFirst
        {
          giShape^              get()                                 { return giShape::Cast( data->getShape( 0 ) ); }
        }

      property giShape^         ShapeSecond
        {
          giShape^              get()                                 { return giShape::Cast( data->getShape( 1 ) ); }
        }

      property giShapeFlags     ShapeFlags
        {
          giShapeFlags          get()                                 { return static_cast<giShapeFlags>( data->getShapeFlags() ); }
        }

      property Vector3          PatchNormal
        {
          Vector3               get()                                 { return FromNx( data->getPatchNormal() ); }
        }

      property Vector3          Point
        {
          Vector3               get()                                 { return FromNx( data->getPoint() ); }
        }

      property float            Separation
        {
          float                 get()                                 { return data->getSeparation(); }
        }

      property float            PointNormalForce
        {
          float                 get()                                 { return data->getPointNormalForce(); }
        }
  };

//=============================+=====================================+=
public ref class                ContactPair:                          public giNxProxy<NxContactPair>
  {
    internal:
      ContactPair(NxContactPair& pair): giNxProxy( pair ) { iterators = nullptr; }
      ~ContactPair()
        {
          if( iterators == nullptr ) return;

          for(int i = 0; i < iterators->Count; i++ )
            if( !iterators[i]->IsDisposed ) delete iterators[i];

          delete iterators; iterators = nullptr;
        }

    public:
      property Actor^           ActorFirst
        {
          Actor^                get()                                 { return Actor::Cast( data->actors[0] ); }
        }

      property Actor^           ActorSecond
        {
          Actor^                get()                                 { return Actor::Cast( data->actors[1] ); }
        }

      property Vector3          SumNormalForce
        {
          Vector3               get()                                 { return FromNx( data->sumNormalForce ); }
        }

      property Vector3          SumFrictionForce
        {
          Vector3               get()                                 { return FromNx( data->sumFrictionForce ); }
        }

      property bool             IsDeletedFirst
        {
          bool                  get()                                 { return data->isDeletedActor[0]; }
        }

      property bool             IsDeletedSecond
        {
          bool                  get()                                 { return data->isDeletedActor[1]; }
        }

    private:
      typedef                   List<ContactStreamIterator^>          IteratorsType;

      IteratorsType^            iterators;

    public:
      ContactStreamIterator^    CreateStreamIterator()
        {
          if( iterators == nullptr ) iterators = gcnew IteratorsType();

          ContactStreamIterator^ iterator = gcnew ContactStreamIterator( data->stream );
          iterators->Add( iterator );
          return iterator;
        }
  };

//=============================+=====================================+=
public interface class          IUserContactReport
  {
    void                        OnContactNotify(ContactPair^ Pair, ContactPairFlags Events);
  };

//=============================+=====================================+=
class                           giNxUserContactReport:                public NxUserContactReport
  {
    public:
      gcroot<IUserContactReport^> iface;

    public:
      giNxUserContactReport(IUserContactReport^ iface) { this->iface = iface; }
      ~giNxUserContactReport() { iface = nullptr; }

    private:
      void                      onContactNotify(NxContactPair& pair, NxU32 events)
        {
          IUserContactReport^ Report = this->iface;
          if( Report == nullptr ) return;

          ContactPair^ Pair = gcnew ContactPair( pair );

          Report->OnContactNotify( Pair, static_cast<ContactPairFlags>( events ) );

          delete Pair;
        }
  };

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
DefSceneReportGetSet(           UserContactReport )
