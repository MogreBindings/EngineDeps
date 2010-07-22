//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Physics.h"
#include                       "Actor.h"
#include                       "Scene.h"
#include                       "Shape.h"
#include                       "RaycastObjects.h"
#include                       "Controller.h"

//=============================+=====================================+=
#pragma                         unmanaged                             // these are unmanaged on purpose, else compiler warns about unmanaged compilation of virtuals

//=============================+=====================================+=
inline NxController*            GetController(NxControllerManager* mng, int idx)  { return mng->getController( idx ); }
inline int                      GetControllerCount(NxControllerManager* mng)      { return static_cast<int>( mng->getNbControllers() ); }

//=============================+=====================================+=
#pragma                         managed

//=============================+=====================================+=
                                BeginNamespace
                                
//=============================+=====================================+=
public ref class                ControllerShapeHit:                   public giNxProxy<NxControllerShapeHit>
	{
	  internal:
	    ControllerShapeHit(const NxControllerShapeHit& hit) : BaseType( &const_cast<NxControllerShapeHit&>( hit ) ) { }
	    
	    typedef                   ThisNamespace::Controller             giController;
	    typedef                   ThisNamespace::Shape                  giShape;
	    
	  public:
      property giController^    Controller                            { giController^ get() { return giController::Cast( GetNx()->controller ); } }
      //
      property giShape^         Shape                                 { giShape^ get() { NxShape* shape = GetNx()->shape; return shape ? giShape::CastSafe( *shape ) : nullptr; } }
      //
      DefVec3ExtR(              WorldPosition,                        worldPos    )
	    DefRx( Vector3,           WorldNormal,                          worldNormal )
	    DefR0( unsigned,          ID,                                   id          )
	    DefRx( Vector3,           Direction,                            dir         )
	    DefR0( float,             Length,                               length      )
	};
	
//=============================+=====================================+=
public ref class                ControllersHit:                       public giNxProxy<NxControllersHit>
  {
    internal:
      ControllersHit(const NxControllersHit& hit): BaseType( &const_cast<NxControllersHit&>( hit ) ) { }
      
	    typedef                   ThisNamespace::Controller             giController;

    public:
      property giController^    Controller                            { giController^ get() { return giController::Cast( GetNx()->controller ); } }
      property giController^    Other                                 { giController^ get() { return giController::Cast( GetNx()->other ); } }
  };
  
//=============================+=====================================+=
class                           giNxUserControllerHitReport:          public NxUserControllerHitReport
  {
    public:
      gcroot<
        IUserControllerHitReport^
      >                         iface;
    
    public:
      giNxUserControllerHitReport(IUserControllerHitReport^ iface): iface( iface ) { }
      //
    private:    
	    NxControllerAction        onShapeHit(const NxControllerShapeHit& hit)
	      {
	        ControllerShapeHit^ Hit    = gcnew ControllerShapeHit( hit );
	        NxControllerAction  result = static_cast<NxControllerAction>( iface->OnShapeHit( Hit ) );
	        //
	        delete Hit; Hit = nullptr;
	        //
	        return result;
	      }
	    
	    NxControllerAction        onControllerHit(const NxControllersHit& hit)
	      {
	        ControllersHit^    Hit    = gcnew ControllersHit( hit );
	        NxControllerAction result = static_cast<NxControllerAction>( iface->OnControllerHit( Hit ) );
	        //
	        delete Hit; Hit = nullptr;
	        //
	        return result;
	      }
  };

//=============================+=====================================+=
template<typename T>
inline void                     SetCallbackGeneric(IUserControllerHitReport^ iface, T^ desc)
  {
    giNxUserControllerHitReport* report = static_cast<giNxUserControllerHitReport*>( desc->GetNx()->callback );
    //
    // TODO: check if gcroot from interface wrapper DESC gets duplicated when OBJECT is created from DESC
    //
    if( !report )
    {
      if( !iface ) return;
      //
      desc->GetNx()->callback = new giNxUserControllerHitReport( iface );
      //
      return;
    }
    //
    if( !iface )
    {
      desc->GetNx()->callback = 0;
      //
      delete report;
      //
      return;
    }
    //
    report->iface = iface;
  }

//=============================+=====================================+=
void                            BoxControllerDesc::Callback::set(IUserControllerHitReport^ iface)     { SetCallbackGeneric( iface, this ); }
void                            CapsuleControllerDesc::Callback::set(IUserControllerHitReport^ iface) { SetCallbackGeneric( iface, this ); }

//=============================+=====================================+=
IUserControllerHitReport^       BoxControllerDesc::Callback::get()
  {
    giNxUserControllerHitReport* report = static_cast<giNxUserControllerHitReport*>( GetNx()->callback );
    //
    return report ? report->iface : nullptr;
  }
  
//=============================+=====================================+=
IUserControllerHitReport^       CapsuleControllerDesc::Callback::get()
  {
    giNxUserControllerHitReport* report = static_cast<giNxUserControllerHitReport*>( GetNx()->callback );
    //
    return report ? report->iface : nullptr;
  }
  
//=============================+=====================================+=
typedef                         giNxReadOnlyList<
                                  ControllerManager, ThisNamespace::Controller,
                                  GetController, GetControllerCount
                                >                                     ControllerCollection;

//=============================+=====================================+=
                                ControllerManager::ControllerManager(Physics^):
                                  BaseType( NxCreateControllerManager( Physics::userAllocator ) )
  {
    controllerList = gcnew ControllerCollection( this );
  }


//=============================+=====================================+=
                                ControllerManager::~ControllerManager() 
  { 
    NxControllerManager* data = this->data;
    //
    if( !data ) return;
    this->data = 0;
    
    while( First )
      delete First;
      
    delete controllerList; controllerList = nullptr;
      
    NxReleaseControllerManager( data );
    this->!ControllerManager(); 
  }
  
//=============================+=====================================+=
                                ControllerManager::!ControllerManager()
  {
    NxControllerManager* data = this->data;
    //
    if( data ) NxReleaseControllerManager( data );
  }
  
//=============================+=====================================+=
void                            ControllerManager::PurgeControllers()
  {
    while( First )
      delete First;
      
    GetNx()->purgeControllers();
  }

//=============================+=====================================+=
template<typename TDesc, typename TCtrl>
TCtrl^                          CreateControllerGeneric(ControllerManager^ mng, Scene^ scene, TDesc^ Desc)
  {
    TCtrl^ ctrl = nullptr;

    // TODO: check for memory leaks if create methods throw in errorstream    
    gcroot<Controller^>* root = new gcroot<Controller^>( 0 );
    //
    Desc->GetNx()->userData = root; // the only way to set user data on the controller is before it's created, this is needed to hold the gcroot that'll point to the wrapping object

    giNxUserControllerHitReport* descreport = static_cast<giNxUserControllerHitReport*>( Desc->GetNx()->callback );
    giNxUserControllerHitReport* copyreport = 0;
    //
    if( descreport ) // make a temp copy of the iface holder to pass to controller, else it'd get deleted when desc is finalized
      Desc->GetNx()->callback = copyreport = new giNxUserControllerHitReport( descreport->iface ); 

    try
    {
      NxController* ctrlptr = mng->GetNx()->createController( scene->GetNx(), *Desc->GetNx() );
      //
      ctrl  = gcnew TCtrl( mng, scene, ctrlptr );
      //
      *root = ctrl;
      //
      ctrl->rootptr     = root; // store rootptr so finalizer can delete it
      ctrl->callbackptr = copyreport; // store hitreport pointer, so finalizer can delete it
      ctrl->userData    = Desc->userData;
      //
      NxActor* actor = ctrlptr->getActor();
      NxShape* shape = actor->getShapes()[0];
      void*    nxud  = shape->userData; // this is probably used by char.controller (it's not null upon creation)
      //
      shape->userData = 0; // set it to null temporarily, so wrapping works
      //
      Actor::Wrap( actor );
      //
      actor->setName( static_cast<char*>( shape->userData ) ); // HACK: store the shape wrapper pointer as actor's name
      //
      shape->userData = nxud; // restore the original userData
      // NOTE: Shapes property on Controller's Actor won't work as expected
    }
    catch(...)
    {
      delete copyreport;
      delete root;
      //
      throw;
    }
    finally
    {
      if( descreport ) Desc->GetNx()->callback = descreport; // restore desc's callback to the original iface holder
    }
    //    
    return ctrl;
  }
  
//=============================+=====================================+=
BoxController^                  ControllerManager::CreateController(Scene^ scene, BoxControllerDesc^ Desc)
  {
    return CreateControllerGeneric<BoxControllerDesc, BoxController>( this, scene, Desc );
  }

//=============================+=====================================+=
CapsuleController^              ControllerManager::CreateController(Scene^ scene, CapsuleControllerDesc^ Desc)
  {
    return CreateControllerGeneric<CapsuleControllerDesc, CapsuleController>( this, scene, Desc );
  }

//=============================+=====================================+=
                                Controller::Controller(ControllerManager^ mng, Scene^, NxType *ptr):
                                  BaseType( ptr )
  {
    Register( mng );
    //
    callbackptr = 0;
  }

//=============================+=====================================+=
                                Controller::~Controller()
  {
    NxControllerManager* mng = Owner->GetNx();
    
    Unregister();
    
    // TODO: maybe make finalizers for all objects that store unmanaged heap pointers
    if( mng ) mng->releaseController( *GetNx() ); // if !mng, controller manager is disposing, no need to release explicitly

    this->!Controller();
  }

//=============================+=====================================+=
                                Controller::!Controller()
  {
    delete callbackptr; callbackptr = 0;
    delete rootptr;     rootptr     = 0;
  }

//=============================+=====================================+=
Controller^                     Controller::Cast(NxType *ptr)
  {
    gcroot<Controller^>* root = static_cast<gcroot<Controller^>*>( ptr->getUserData() );
    //
    return *root;
  }

//=============================+=====================================+=
Actor^                          Controller::Actor::get()
  {
    NxActor* actorptr = GetNx()->getActor();
    //
    return giActor::Cast( actorptr );
  }
    
//=============================+=====================================+=
void                            Controller::Move(Vector3 Displacement, unsigned ActiveGroups, float MinDistance, [Out] ControllerFlags% CollisionFlags, float Sharpness, GroupsMask^ GroupsMask)
  {
    NxU32         collisionFlags = static_cast<NxU32>( CollisionFlags );
    NxGroupsMask* grpmsk         = GroupsMask == nullptr ? 0 : GroupsMask->GetNx();
    //
    GetNx()->move( ToNx( Displacement ), ActiveGroups, MinDistance, collisionFlags, Sharpness, grpmsk );
    //
    CollisionFlags = static_cast<ControllerFlags>( collisionFlags );
  }
    
//=============================+=====================================+=
                                EndNamespace

// TODO: redesign recasting from base to subclass maybe