//=============================+=====================================+=
//                              xna customization file
//=============================+=====================================+=
#pragma                         once

//=============================+=====================================+=
#define                         RootNamespace                         eyecm

//=============================+=====================================+=
#define                         UserVector3                           Microsoft::Xna::Framework::Vector3
#define                         UserMatrix3x3                         Microsoft::Xna::Framework::Matrix3
#define                         UserMatrix4x4                         Microsoft::Xna::Framework::Matrix
#define                         UserQuaternion                        Microsoft::Xna::Framework::Quaternion

//=============================+=====================================+=
#define                         UserAxisAlignedBox                    Microsoft::Xna::Framework::BoundingBox
#define                         UserOrientedBox                       Microsoft::Xna::Framework::OrientedBoundingBox
#define                         UserSphere                            Microsoft::Xna::Framework::BoundingSphere
#define                         UserLine                              Microsoft::Xna::Framework::Ray
#define                         UserPlane                             Microsoft::Xna::Framework::Plane
#define                         UserCapsule                           Microsoft::Xna::Framework::Capsule
#define                         UserTriangle                          Microsoft::Xna::Framework::Triangle

//=============================+=====================================+=
//#define                         ActorUserDataType                     gi::Scene::Node^ // don't forget the ^
//#define                         ActorUserDataName                     Node

//=============================+=====================================+=
#define UserConversionFile     "convert.xna.h"

//=============================+=====================================+=
#using                         <Microsoft.Xna.Framework.dll>

//=============================+=====================================+=
namespace Microsoft { namespace Xna { namespace Framework {

//=============================+=====================================+=
public value struct             Matrix3
  {
    public:
      float M11, M12, M13;
      float M21, M22, M23;
      float M31, M32, M33;
  };

//=============================+=====================================+=
public value struct             Triangle
  {
    public:
      Vector3 a, b, c;

    public:
      Triangle(Vector3 a, Vector3 b, Vector3 c) { this->a = a; this->b = b; this->c = c; }
  };

//=============================+=====================================+=
public value struct             Capsule
  {
    public:
      Vector3 a, b;
      float Radius;

    public:
      Capsule(Vector3 a, Vector3 b, float radius) { this->a = a; this->b = b; this->Radius = radius; }
  };

//=============================+=====================================+=
public value struct             OrientedBoundingBox
  {
    public:
      Matrix3 Orientation;
      Vector3 Center, Dimension;

      public:
       OrientedBoundingBox(Matrix3 ori, Vector3 center, Vector3 dim) { this->Orientation = ori; this->Center = center; this->Dimension = dim; }
  };

//=============================+=====================================+=
}}}

