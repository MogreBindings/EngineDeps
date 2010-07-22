//=============================+=====================================+=
//                              Eye Candy Machine customization file
//=============================+=====================================+=
#pragma                         once

//=============================+=====================================+=
#define                         RootNamespace                         eyecm

//=============================+=====================================+=
#define                         UserVector3                           gi::Mathematics::Vector3
#define                         UserMatrix3x3                         gi::Mathematics::Matrix3x3
#define                         UserMatrix4x4                         gi::Mathematics::Matrix4x4
#define                         UserQuaternion                        gi::Mathematics::Quaternion

//=============================+=====================================+=
#define                         UserAxisAlignedBox                    gi::Mathematics::Geometry::AxisAlignedBox
#define                         UserOrientedBox                       gi::Mathematics::Geometry::OrientedBox
#define                         UserSphere                            gi::Mathematics::Geometry::Sphere
#define                         UserLine                              gi::Mathematics::Geometry::Line
#define                         UserPlane                             gi::Mathematics::Geometry::Plane
#define                         UserCapsule                           gi::Mathematics::Geometry::Capsule
#define                         UserTriangle                          gi::Mathematics::Geometry::Triangle

//=============================+=====================================+=
#define                         ActorUserDataType                     gi::Scene::Node^ // don't forget the ^
#define                         ActorUserDataName                     Node

//=============================+=====================================+=
#define UserConversionFile     "convert.eyecm.h"

//=============================+=====================================+=
#using                         <gi.Base.dll>
#using                         <gi.Scene.dll>
