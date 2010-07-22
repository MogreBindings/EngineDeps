//=============================+=====================================+=
//                              tv3d customization file
//=============================+=====================================+=
#pragma                         once

//=============================+=====================================+=
#define                         RootNamespace                         MTV3D65

//=============================+=====================================+=
#define                         UserVector3                           MTV3D65::TV_3DVECTOR
#define                         UserMatrix3x3                         MTV3D65::TVX_MATRIX3
#define                         UserMatrix4x4                         MTV3D65::TV_3DMATRIX
#define                         UserQuaternion                        MTV3D65::TV_3DQUATERNION

//=============================+=====================================+=
#define                         UserAxisAlignedBox                    MTV3D65::TVX_AABB
#define                         UserOrientedBox                       MTV3D65::TVX_OBB
#define                         UserSphere                            MTV3D65::TVX_SPHERE
#define                         UserLine                              MTV3D65::TVX_RAY
#define                         UserPlane                             MTV3D65::TV_PLANE
#define                         UserCapsule                           MTV3D65::TVX_CAPSULE
#define                         UserTriangle                          MTV3D65::TVX_TRIANGLE

//=============================+=====================================+=
//#define                         ActorUserDataType                     gi::Scene::Node^ // don't forget the ^
//#define                         ActorUserDataName                     Node

//=============================+=====================================+=
#define UserConversionFile     "convert.tv3d.h"

//=============================+=====================================+=
#using                         <MTV3D65.dll>


//=============================+=====================================+=
namespace MTV3D65 {

//=============================+=====================================+=
public value struct             TVX_MATRIX3
  {
    public:
      float m11, m12, m13;
      float m21, m22, m23;
      float m31, m32, m33;
  };

//=============================+=====================================+=
public value struct             TVX_TRIANGLE
  {
    public:
      TV_3DVECTOR a, b, c;

    public:
      TVX_TRIANGLE(TV_3DVECTOR a, TV_3DVECTOR b, TV_3DVECTOR c) { this->a = a; this->b = b; this->c = c; }
  };

//=============================+=====================================+=
public value struct             TVX_CAPSULE
  {
    public:
      TV_3DVECTOR a, b;
      float Radius;

    public:
      TVX_CAPSULE(TV_3DVECTOR a, TV_3DVECTOR b, float radius) { this->a = a; this->b = b; this->Radius = radius; }
  };

//=============================+=====================================+=
public value struct             TVX_AABB
  {
    public: 
      TV_3DVECTOR Lower, Upper;

    public:
      void Reset()
        {
          const float bigfloat = 10e7;
          //
          Lower = TV_3DVECTOR(  bigfloat,  bigfloat,  bigfloat );
          Upper = TV_3DVECTOR( -bigfloat, -bigfloat, -bigfloat );
        }

      //TVX_AABB(const TVX_AABB &box) { Lower = box.Lower; Upper = box.Upper; }

      TVX_AABB(TV_3DVECTOR a, TV_3DVECTOR b)
        {
          if ( a.x > b.x ) { Lower.x = b.x; Upper.x = a.x; } else { Lower.x = a.x; Upper.x = b.x; }
          if ( a.y > b.y ) { Lower.y = b.y; Upper.y = a.y; } else { Lower.y = a.y; Upper.y = b.y; }
          if ( a.z > b.z ) { Lower.z = b.z; Upper.z = a.z; } else { Lower.z = a.z; Upper.z = b.z; }
        }
  };

//=============================+=====================================+=
public value struct             TVX_OBB
  {
    public:
      TVX_MATRIX3 Orientation;
      TV_3DVECTOR Center, Dimension;

    public:
      TVX_OBB(TVX_MATRIX3 ori, TV_3DVECTOR center, TV_3DVECTOR dim) { this->Orientation = ori; this->Center = center; this->Dimension = dim; }
  };

//=============================+=====================================+=
public value struct             TVX_RAY
  {
    public:
      TV_3DVECTOR Origin;
      TV_3DVECTOR Direction;

    public:
      TVX_RAY(TV_3DVECTOR org, TV_3DVECTOR dir) { this->Origin = org; this->Direction = dir; }
  };

//=============================+=====================================+=
public value struct             TVX_SPHERE
  {
    public:
      TV_3DVECTOR Center;
      float Radius;

    public:
      TVX_SPHERE(TV_3DVECTOR center, float r) { this->Center = center; this->Radius = r; }
  };

//=============================+=====================================+=
}

