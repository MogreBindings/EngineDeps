//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Scene.h"
#include                       "SceneDesc.h"

//=============================+=====================================+=
void                            Scene::InitReports(SceneDesc^ Desc)
  {
    if( Desc != nullptr ) {

      this->UserNotify             = Desc->UserNotify;
      this->FluidUserNotify        = Desc->FluidUserNotify;
      this->UserContactModify      = Desc->UserContactModify;
      this->UserTriggerReport      = Desc->UserTriggerReport;
      this->UserContactReport      = Desc->UserContactReport;
      this->UserActorPairFiltering = Desc->UserActorPairFiltering;
    }
  }

//=============================+=====================================+=
void                            Scene::DeInitReports()
  {
    this->UserNotify             = nullptr;
    this->FluidUserNotify        = nullptr;
    this->UserContactModify      = nullptr;
    this->UserTriggerReport      = nullptr;
    this->UserContactReport      = nullptr;
    this->UserActorPairFiltering = nullptr;
  }
