//=============================+=====================================+=
//                              mogre customization file
//=============================+=====================================+=
#pragma                         once

//=============================+=====================================+=
#define                         RootNamespace                         Mogre

//=============================+=====================================+=
#define                         UserVector3                           Mogre::Vector3
#define                         UserMatrix3x3                         Mogre::Matrix3^
#define                         UserMatrix4x4                         Mogre::Matrix4^
#define                         UserQuaternion                        Mogre::Quaternion

//=============================+=====================================+=
#define                         UserAxisAlignedBox                    Mogre::AxisAlignedBox^
#define                         UserOrientedBox                       Mogre::OrientedBox^
#define                         UserSphere                            Mogre::Sphere
#define                         UserLine                              Mogre::Ray
#define                         UserPlane                             Mogre::Plane
#define                         UserCapsule                           Mogre::Capsule
#define                         UserTriangle                          Mogre::Triangle

//=============================+=====================================+=
//#define                         ActorUserDataType                     gi::Scene::Node^ // don't forget the ^
//#define                         ActorUserDataName                     Node

//=============================+=====================================+=
#define UserConversionFile     "convert.mogre.h"

//=============================+=====================================+=
#using                         <Mogre.dll>


//=============================+=====================================+=
namespace Mogre {

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
public ref class              OrientedBox
  {
    public:
      Matrix3^ Orientation;
      Vector3  Center, Dimension;

    public:
      OrientedBox(Matrix3^ ori, Vector3 center, Vector3 dim) { this->Orientation = ori; this->Center = center; this->Dimension = dim; }
  };

//=============================+=====================================+=
}

