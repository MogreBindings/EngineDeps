//=============================+=====================================+=
//
//                              Copyright (c) 2008 Gregor Popovic
//=============================+=====================================+=
#pragma                         once

//=============================+=====================================+=
#if                   !defined( UserCustomization )

#error You must read 'readme.txt'! You must define UserCustomization macro that contains the filename of the customization include file. (Use /D "UserCustomization=\"custom.mycompany.h\"" ). See 'custom.example.h'.

#endif

//=============================+=====================================+=
#include                        UserCustomization

//=============================+=====================================+=
#if                   !defined( UserVector3        ) || \
                      !defined( UserMatrix3x3      ) || \
                      !defined( UserMatrix4x4      ) || \
                      !defined( UserQuaternion     ) || \
                      !defined( UserAxisAlignedBox ) || \
                      !defined( UserOrientedBox    ) || \
                      !defined( UserSphere         ) || \
                      !defined( UserLine           ) || \
                      !defined( UserPlane          ) || \
                      !defined( UserCapsule        )

#error You must define all user math types. See 'custom.example.h' for an example.

#endif                       /* user math types defined */

//=============================+=====================================+=
#if                   !defined( UserConversionFile )

#error You must provide conversions to and from your math classes. Define the filename as 'UserConversionFile' macro. See 'convert.example.h' for an example

#endif                       /* UserConversionFile */

//=============================+=====================================+=
#ifndef                         RootNamespace
#define                         RootNamespace                         eyecm
#endif                       /* RootNamespace */

//=============================+=====================================+=
#define                         ThisNamespace                         RootNamespace::PhysX

//=============================+=====================================+=
#ifndef                         ActorUserDataType                     // don't forget the ^
#define                         ActorUserDataType                     Object^
#endif                       /* ActorUserDataType */

//=============================+=====================================+=
#ifndef                         ActorUserDataName
#define                         ActorUserDataName                     UserData
#endif                       /* ActorUserDataName */


//=============================+=====================================+=
#define                         BeginNamespace \
namespace                       RootNamespace                         { \
namespace                       PhysX                                 { \

//=============================+=====================================+=
#define                         EndNamespace \
}}                           /* RootNamespace::PhysX namespace */

//=============================+=====================================+=
                                BeginNamespace
                                EndNamespace

//=============================+=====================================+=
using namespace                 System;
using namespace                 System::Collections::Generic;
using namespace                 System::Collections::ObjectModel;
using namespace                 System::Runtime::InteropServices;

//=============================+=====================================+=
using namespace                 ThisNamespace;

//=============================+=====================================+=
#include                       "convert.h"
#include                       "macros.h"
#include                       "Enums.h"
#include                       "Interfaces.h"

