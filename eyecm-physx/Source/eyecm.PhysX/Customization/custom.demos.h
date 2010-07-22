//=============================+=====================================+=
//                              PhysX Candy Wrapper Demos customization file
//=============================+=====================================+=
#pragma                         once

//=============================+=====================================+=
#define                         RootNamespace                         eyecm

//=============================+=====================================+=
#define                         UserVector3                           eyecm::PhysX::Demos::Vec3
#define                         UserMatrix3x3                         eyecm::PhysX::Demos::Mat33
#define                         UserMatrix4x4                         eyecm::PhysX::Demos::Mat44
#define                         UserQuaternion                        eyecm::PhysX::Demos::Quat

//=============================+=====================================+=
#define                         UserAxisAlignedBox                    eyecm::PhysX::Demos::AABB
#define                         UserOrientedBox                       eyecm::PhysX::Demos::OBB
#define                         UserSphere                            eyecm::PhysX::Demos::Sphere
#define                         UserLine                              eyecm::PhysX::Demos::Line
#define                         UserPlane                             eyecm::PhysX::Demos::Plane
#define                         UserCapsule                           eyecm::PhysX::Demos::Capsule
#define                         UserTriangle                          eyecm::PhysX::Demos::Triangle

//=============================+=====================================+=
//#define                         ActorUserDataType                     gi::Scene::Node^ // don't forget the ^
//#define                         ActorUserDataName                     Node

//=============================+=====================================+=
#define UserConversionFile     "convert.demos.h"

//=============================+=====================================+=
#using                         <eyecm.PhysX.Demos.Math/eyecm.PhysX.Demos.Math.dll>
