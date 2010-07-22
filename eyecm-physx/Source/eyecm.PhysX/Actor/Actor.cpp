//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Actor.h"
#include                       "Scene.h"
#include                       "ShapeDesc.h"
#include                       "Shape.h"
#include                       "nxlist.h"
#include                       "RaycastObjects.h"
#include                       "PhysicsCollection.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ActorDesc^                      ActorDesc::Wrap(Physics^ physics, NxActorDesc& desc)
  {
    ActorDesc^     result = gcnew ActorDesc( physics, desc );
    
    if( desc.name ) result->name = FromNx( desc.name );
    if( desc.body ) result->Body = BodyDesc::Wrap( desc.body );

    return result;
  }

//=============================+=====================================+=
#pragma                         unmanaged                             // these are unmanaged on purpose, else compiler warns about unmanaged compilation of virtuals

//=============================+=====================================+=
inline NxShape*                 GetShape(NxActor* actor, int idx)     { return actor->getShapes()[idx]; }
inline int                      GetShapeCount(NxActor* actor)         { return static_cast<int>( actor->getNbShapes() ); }

//=============================+=====================================+=
#pragma                         managed

//=============================+=====================================+=
typedef                         giNxReadOnlyList<
                                  Actor, Shape,
                                  GetShape, GetShapeCount
                                >                                     ShapeCollection;

//=============================+=====================================+=
                                Actor::Actor(giScene^ Scene, NxActor* ptr, ActorDesc^ Desc):
                                  giNxNamedObject( ptr )
  {
    Register( Scene );

    flags     = gcnew ProxyActorFlags( ptr );
    bodyflags = gcnew ProxyBodyFlags( ptr );
    shapelist = gcnew ShapeCollection( this );

    int             shapecount = ptr->getNbShapes();
    NxShape*const * shapes     = ptr->getShapes();

    if( Desc == nullptr )
      for( int i = 0; i < shapecount; i++ )      
        Shape::Wrap( this, shapes[i], nullptr );
    else
      for( int i = 0; i < shapecount; i++ )
        Shape::Wrap( this, shapes[i], Desc->Shapes[i] ); // Desc->Shapes is an array of ShapeDescs actually, but I'm following the API names here

    if( Desc == nullptr ) return;

    this->Name = Desc->Name == nullptr ? "Actor_" + (++counter).ToString() : Desc->Name;
  }

//=============================+=====================================+=
                                Actor::~Actor()
  {
    if( !ptr ) return;

    NxActor* ptr = this->ptr;
    this->ptr = 0;

    while( First )
      delete First;

    delete flags;     flags     = nullptr;
    delete bodyflags; bodyflags = nullptr;

    delete static_cast<ShapeCollection^>( shapelist ); shapelist = nullptr;

    NxScene* scene = Owner->ptr;

    Unregister();

    if( !scene ) return; // scene is disposing, no need to release explicitly

    scene->releaseActor( *ptr );
  }

//=============================+=====================================+=
Actor^                          Actor::Wrap(NxActor* ptr)
  {
    giScene^    scene  = giScene::Cast( &ptr->getScene() );
    const char* name   = ptr->getName();
    Actor^      result = gcnew Actor( scene, ptr, nullptr );

    if( name ) result->Name = FromNx( name );
    return result;
  }

//=============================+=====================================+=
Actor^                          Scene::CreateActor(ActorDesc^ Desc)
  {
    NxActor* actorptr = ptr->createActor( *Desc->data );
    return actorptr ? gcnew Actor( this, actorptr, Desc ) : nullptr;
  }

//=============================+=====================================+=
public ref class                SweepQueryHits:                       public giNxStaticList<SweepQueryHit, NxSweepQueryHit, SweepQueryHit>
  {
    internal:
      NxSweepQueryHit*          items;
      gcroot<Object^>*          userdata;

    internal:
      SweepQueryHits(Object^ UserData, int count): userdata( new gcroot<Object^>( UserData ) ), giNxStaticList( items = new NxSweepQueryHit[count], count ) { }
      ~SweepQueryHits() { this->!SweepQueryHits(); }
      !SweepQueryHits() { delete[] items; items = 0; delete userdata; userdata = 0; }

      void                      SetCount(unsigned count) { ptr->count = count; }
  };

//=============================+=====================================+=
unsigned                        Actor::LinearSweep(Vector3 Motion, SweepFlags Flags, Object^ UserData, unsigned MaxHits, [Out] SweepQueryHits^% Shapes, IUserEntityReport<SweepQueryHit>^ Report)
  {
    Shapes = gcnew SweepQueryHits( UserData, MaxHits );

    giUserEntityReport<SweepQueryHit, NxSweepQueryHit, SweepQueryHit>  repobj( false );
    NxUserEntityReport<NxSweepQueryHit>* rep = 0;
    if( Report != nullptr ) { repobj.iface = Report; rep = &repobj; }

    unsigned result = ptr->linearSweep( ToNx( Motion ), static_cast<NxSweepFlags>( Flags ), Shapes->userdata, MaxHits, Shapes->items, rep );
    Shapes->SetCount( result );
    return result;
  }

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
bool                            PhysicsCollection::AddActor(Actor^ Object, UserPropertiesType UserProperties, String^ ID)
  {
    const char* id    = ToNx( ID );
    const char* props = ToChar( UserProperties );
    
    bool Result = addActor( *this->ptr, *Object->ptr, props, id );
    
    delete[] props;
    delete[] id;
    return Result;
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AutoGenerateCCDSkeletons(Actor^ Actor, float Shrink, unsigned MaxV)
  {
    return NXU::autoGenerateCCDSkeletons( Actor->GetNx(), Shrink, MaxV );
  }
  