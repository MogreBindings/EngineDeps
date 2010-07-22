//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Cooking.h"
#include                       "ClothMesh.h"

//=============================+=====================================+=
bool                            CookingInterface::CookClothMesh(ClothMeshDesc^ Desc, System::IO::Stream^ Stream)
  {
    giNxStream str( Stream );
    return ptr->NxCookClothMesh( *Desc->data, str );
  }
