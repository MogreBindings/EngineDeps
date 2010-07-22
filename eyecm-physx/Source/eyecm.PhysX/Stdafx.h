//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       <vcclr.h>

//=============================+=====================================+=
//#pragma                         unmanaged
#pragma                         managed( push, off )
#pragma warning ( disable:      4100 4512 4245 4400 )

//=============================+=====================================+=
#pragma message (              "===============" )
#pragma message (              "PhysX by NVIDIA" )
#pragma message (              "===============" )

//=============================+=====================================+=
#include                       "NxPhysics.h"
#include                       "NxCooking.h"
#include                       "NxStream.h"
#include                       "NxuStream/nxu_helper.h"
#include                       "Character/NxCharacter/include/NxBoxController.h"
#include                       "Character/NxCharacter/include/NxCapsuleController.h"
#include                       "Character/NxCharacter/include/NxControllerManager.h"

//=============================+=====================================+=
#pragma warning( default:       4100 4512 4245 )
#pragma                         managed( pop )
//#pragma                         managed

//=============================+=====================================+=
#pragma warning ( disable:      4714 )                                // supresses loads of warnings about __forceinline failing in managed parts of the code
                                                                      
