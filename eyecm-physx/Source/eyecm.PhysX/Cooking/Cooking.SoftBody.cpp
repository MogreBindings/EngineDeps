//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Cooking.h"
#include                       "SoftBodyMesh.h"

//=============================+=====================================+=
bool                            CookingInterface::CookSoftBodyMesh(SoftBodyMeshDesc^ Desc, System::IO::Stream^ Stream)
  {
    giNxStream str( Stream );
    return ptr->NxCookSoftBodyMesh( *Desc->data, str );
  }
