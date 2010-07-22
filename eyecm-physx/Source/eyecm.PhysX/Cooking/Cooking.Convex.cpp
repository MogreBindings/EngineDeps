//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Cooking.h"
#include                       "ConvexMesh.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
bool                            CookingInterface::CookConvexMesh(ConvexMeshDesc^ Desc, System::IO::Stream^ Stream)
  {
    giNxStream str( Stream );
    return ptr->NxCookConvexMesh( *Desc->data, str );
  }

//=============================+=====================================+=
                                EndNamespace

