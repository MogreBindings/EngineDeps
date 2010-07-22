//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
// TODO: Value versus Reference math types
// TODO: possible ambiguities between lines, segments, rays depending on user types

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
typedef                         UserVector3                           Vector3;
typedef                         UserMatrix3x3                         Matrix3x3;
typedef                         UserMatrix4x4                         Matrix4x4;
typedef                         UserQuaternion                        Quaternion;

//=============================+=====================================+=
typedef                         UserAxisAlignedBox                    AxisAlignedBox;
typedef                         UserOrientedBox                       OrientedBox;
typedef                         UserSphere                            Sphere;
typedef                         UserLine                              Line;
typedef                         UserPlane                             Plane;
typedef                         UserCapsule                           Capsule;
typedef                         UserTriangle                          Triangle;

//=============================+=====================================+=
inline unsigned                 ARGBToABGR(unsigned col)              { return ((col >> 16) & 0xFF) | ((col & 0xFF) << 16) | (col & 0xFF00FF00); }

//=============================+=====================================+=
inline NX_BOOL                  ToNx(bool v)                          { return v ? NX_TRUE : NX_FALSE; }
inline bool                     FromNx(NX_BOOL v)                     { return v != NX_FALSE; }

//=============================+=====================================+=
inline String^                  FromNx(const char* v)
  {
    return gcnew String( v );
  }

//=============================+=====================================+=
inline char*                    ToNx(String^ v)
  {
    if( v == nullptr ) return 0;

    IntPtr      srcptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi( v );
    const char* src    = static_cast<const char*>( srcptr.ToPointer() );
    int         len    = strlen( src ) + 1;

    char* result = new char[len];
    strcpy_s( result, len, src );

    System::Runtime::InteropServices::Marshal::FreeHGlobal( srcptr );
    return result;
  }

//=============================+=====================================+=
#include                        UserConversionFile

//=============================+=====================================+=
template<typename T>
struct                          InstanceEquals
  {
      bool                      operator()(T a, T b)                  { return a == b; }
  };

//=============================+=====================================+=
                                EndNamespace

