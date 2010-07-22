//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Physics.h"
#include                       "Scene.h"
#include                       "SoftBodyMesh.h"
#include                       "ClothMesh.h"
#include                       "nxlist.h"

//=============================+=====================================+=
#pragma                         unmanaged

int                             GetSceneCount(NxPhysicsSDK* ptr)                  { return static_cast<int>( ptr->getNbScenes() ); }
NxScene*                        GetSceneByIdx(NxPhysicsSDK* ptr, int idx)         { return ptr->getScene( static_cast<unsigned>( idx ) ); }

//=============================+=====================================+=
#pragma                         managed

//=============================+=====================================+=
typedef                         giNxReadOnlyList<
                                  Physics, Scene,
                                  GetSceneByIdx, GetSceneCount
                                >                                     SceneCollection;


//=============================+=====================================+=
void                            Physics::InitLists()
  {
    listscenes = gcnew SceneCollection( this );
  }

//=============================+=====================================+=
void                            Physics::DeInitLists()
  {
    delete static_cast<SceneCollection^>( listscenes ); listscenes = nullptr;
  }
