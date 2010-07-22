//=============================+=====================================+=
//                              example customization file (see also 'convert.example.h')
//=============================+=====================================+=
#pragma                         once

//=============================+=====================================+=
// Define the root namespace you want your customized library to reside in.
// All the compiled classes can be found in RootNamespace::PhysX.
//=============================+=====================================+=
#define                         RootNamespace                         mycompany

//=============================+=====================================+=
// Define the names of your pre-defined math types.
// They will be integrated directly into the library's interface.
// It is necessary that type definitions contain fully qualified names. Add ^ for ref types.
// Use array<float>^ for any classes you don't already have, and write some sort of conversion (see below).
//=============================+=====================================+=
#define                         UserVector3                           mycompany::Mathematics::MyVec3
#define                         UserMatrix3x3                         mycompany::Mathematics::MyMat33
#define                         UserMatrix4x4                         mycompany::Mathematics::MyMat44
#define                         UserQuaternion                        mycompany::Mathematics::MyQuat
#define                         UserAxisAlignedBox                    mycompany::Mathematics::MyAxisAlignedBox
#define                         UserOrientedBox                       mycompany::Mathematics::MyOrientedBox
#define                         UserSphere                            mycompany::Mathematics::MySphere
#define                         UserLine                              mycompany::Mathematics::MyLine
#define                         UserPlane                             mycompany::Mathematics::MyPlane
#define                         UserCapsule                           mycompany::Mathematics::MyCapsule
#define                         UserTriangle                          mycompany::Mathematics::MyTriangle

//=============================+=====================================+=
// Define types for storing custom user data directly on PhysX objects, or leave them at 'Object^'.
// You can also specify each user data property's name, or leave them at 'UserData'
// It is necessary that type definitions contain fully qualified names. Add ^ for ref types.
// OPTIONAL: comment out if not needed
//=============================+=====================================+=
#define                         ActorUserDataType                     mycompany::SceneGraph::Node^ // don't forget the ^ on ref types
#define                         ActorUserDataName                     Node // it would be named 'UserData' if this weren't specified

//=============================+=====================================+=
// Specify the name of the include file that contains conversion functions
// between your managed math and PhysX unmanaged types.
// See convert.example.h for an, er, example.
//=============================+=====================================+=
#define                         UserConversionFile                   "convert.mycompany.h"

//=============================+=====================================+=
// Specify any additional assemblies you are using.
// They should contain definitions of you math and user data classes.
//=============================+=====================================+=
#using                         <mycompany.Mathematics.dll>
#using                         <mycompany.Scene.dll>
