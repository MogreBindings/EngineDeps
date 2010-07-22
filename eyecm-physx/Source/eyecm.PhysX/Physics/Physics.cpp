//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Physics.h"
#include                       "PhysicsCollection.h"
#include                       "Debugger.h"
#include                       "errorstream.h"
#include                       "ControllerManager.h"

//=============================+=====================================+=
//#pragma comment(lib,           "NxCharacter" )
//#pragma comment(lib,           "NxCooking"   )
#pragma comment(lib,           "PhysXLoader" )

//=============================+=====================================+=
void                            InitNxuErrorReport();
void                            DeInitNxuErrorReport();

//=============================+=====================================+=
                                Physics::Physics(NxPhysicsSDK* ptr)
  {
    this->ptr = ptr;

    if( ptr == 0 ) throw gcnew ArgumentNullException( "NxPhysXSDK object was not created successfully." );

    this->parameters   = gcnew ProxyParameters( ptr );

    this->trimeshes      = gcnew TriMeshesDictionary();
    this->convexmeshes   = gcnew ConvexDictionary();
    this->ccdskels       = gcnew CCDSkelsDictionary();
    this->hfields        = gcnew HFieldsDictionary();
    this->clothmeshes    = gcnew ClothMeshDictionary();
    this->softbodymeshes = gcnew SoftBodyMeshDictionary();

    if( instancecount == 0 )
    {
      this->debugger     = gcnew giRemoteDebugger( ptr->getFoundationSDK().getRemoteDebugger() );
      
      NxUserAllocator* GetUserAllocator();
      //
      this->userAllocator     = GetUserAllocator();      
      this->controllerManager = gcnew giControllerManager( this );
    }

    instancecount++;

    InitNxuErrorReport();
    InitLists();
  }

//=============================+=====================================+=
                                Physics::~Physics()
  {
    NxPhysicsSDK* ptr = this->ptr;
    this->ptr = 0;

    while( First )
      delete First;

    DeInitLists();

    delete parameters;        parameters        = nullptr;

    delete trimeshes;         trimeshes         = nullptr;
    delete convexmeshes;      convexmeshes      = nullptr;
    delete ccdskels;          ccdskels          = nullptr;
    delete hfields;           hfields           = nullptr;
    delete clothmeshes;       clothmeshes       = nullptr;
    delete softbodymeshes;    softbodymeshes    = nullptr;
    
    if( instancecount == 1 )
    {
      delete debugger;          debugger          = nullptr;
      
      delete controllerManager; controllerManager = nullptr;
      delete userAllocator;     userAllocator     = 0;
    }

    ptr->release();
    ptr = 0;

    if( --instancecount == 0 ) {

      NXU::releasePersistentMemory();
      DeInitNxuErrorReport();
    }
  }

//=============================+=====================================+=
Physics^                        Physics::Create(ErrorStream^ Stream)
  {
    static giNxErrorStream EStream( Stream );

    NxPhysicsSDK* ptr = NxCreatePhysicsSDK( NX_PHYSICS_SDK_VERSION, 0, &EStream );
    return gcnew Physics( ptr );
  }

//=============================+=====================================+=
Physics^                        Physics::Create()
  {
    return Create( gcnew ErrorStream() );
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddPhysics(Physics^ Physics)
  {
    return addPhysicsSDK( *this->ptr, *Physics->ptr );
  }
