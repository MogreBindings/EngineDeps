//=============================+=====================================+=
//                              example conversion file (see also 'custom.example.h')
//=============================+=====================================+=
//
// All functions converting
//
// TO   the PhysX unmanaged classes
// FROM your custom managed math classes
//
// look like: 'NxType ToNx(ManagedType v)'
//
//=============================+=====================================+=
//
// All functions converting
//
// FROM the PhysX unmanaged classes
// TO   your custom managed math classes
//
// look like: 'ManagedType FromNx(const NxType& v)'
//
//=============================+=====================================+=
//
//                              IMPORTANT:
//
// Don't worry about the fact that names of types in this file are named Vector3, Matrix3x3, etc.
// which are probably different names from the names of your math classes you've specified in custom.*.h.
// These are only typedef-ed aliases of those classes and you will see them as your classes in the compiled lib.
// This is to ensure that the source code looks consistent throughout the project.
//
//=============================+=====================================+=

//=============================+=====================================+=
//                              Vector3
//=============================+=====================================+=
inline NxVec3                   ToNx(Vector3 v)
  {
    return NxVec3( &v.X );
  }

//=============================+=====================================+=
inline Vector3                  FromNx(const NxVec3& v)
  {
    Vector3 result;
    v.get( &result.X );
    return result;
  }

//=============================+=====================================+=
inline void                     ToNx(Vector3 v, float& x, float& y, float& z)
  {
    x = v.X; y = v.Y; z = v.Z;
  }

//=============================+=====================================+=
//                              AxisAlignedBox
//=============================+=====================================+=
inline NxBounds3                ToNx(AxisAlignedBox v)
  {
    NxBounds3 result;
    result.set( v.Lower.X, v.Lower.Y, v.Lower.Z, v.Upper.X, v.Upper.Y, v.Upper.Z );
    return result;
  }

//=============================+=====================================+=
inline AxisAlignedBox           FromNx(NxBounds3& v)
  {
    return AxisAlignedBox( FromNx( v.min ), FromNx( v.max ) );
  }


//=============================+=====================================+=
//                              Matrix4x4
//=============================+=====================================+=
inline NxMat34                  ToNx(Matrix4x4 m)
  {
    NxMat34 result( false );
    result.setColumnMajor44( &m._11 );
    return result;
  }

//=============================+=====================================+=
inline Matrix4x4                FromNx(const NxMat34& m)
  {
    Matrix4x4 result;
    m.getColumnMajor44( &result._11 );
    return result;
  }


//=============================+=====================================+=
//                              Matrix3x3
//=============================+=====================================+=
inline NxMat33                  ToNx(Matrix3x3 m)
  {
    NxMat33 result;
    result.setColumnMajor( &m._11 );
    return result;
  }

//=============================+=====================================+=
inline Matrix3x3                FromNx(const NxMat33& m)
  {
    Matrix3x3 result;
    m.getColumnMajor( &result._11 );
    return result;
  }


//=============================+=====================================+=
//                              Quaternion
//=============================+=====================================+=
inline NxQuat                   ToNx(Quaternion q)
  {
    NxQuat result;
    result.setXYZW( &q.qx );
    return result;
  }

//=============================+=====================================+=
inline Quaternion               FromNx(const NxQuat& q)
  {
    Quaternion result;
    q.getXYZW( &result.qx );
    return result;
  }


//=============================+=====================================+=
//                              OrientedBox
//=============================+=====================================+=
inline NxBox                    ToNx(OrientedBox v)
  {
    return NxBox( ToNx( v.Center ), ToNx( v.Size ) / 2.0, ToNx( v.Orientation ) );
  }

//=============================+=====================================+=
inline OrientedBox              FromNx(const NxBox& v)
  {
    OrientedBox result;

    result.Orientation = FromNx( v.rot );
    result.Center = FromNx( v.center );
    result.Size = FromNx( v.extents * 2 );

    return result;
  }


//=============================+=====================================+=
//                              Sphere
//=============================+=====================================+=
inline NxSphere                 ToNx(Sphere v)
  {
    return NxSphere( ToNx( v.Center ), v.Radius );
  }

//=============================+=====================================+=
inline Sphere                   FromNx(const NxSphere& v)
  {
    return Sphere( FromNx( v.center ), v.radius );
  }


//=============================+=====================================+=
//                              Plane
//=============================+=====================================+=
inline Plane                    FromNx(const NxPlane& v)
  {
    return Plane( FromNx( v.normal ), v.d );
  }

//=============================+=====================================+=
inline NxPlane                  ToNx(Plane v)
  {
    return NxPlane( ToNx( v.Normal ), v.d );
  }


//=============================+=====================================+=
//                              Line
//=============================+=====================================+=
inline NxRay                    ToNx(Line v)
  {
    return NxRay( ToNx( v.Origin ), ToNx( v.Direction.Normalized ) );
  }

//=============================+=====================================+=
inline Line                     FromNx(const NxRay& v)
  {
    return Line( FromNx( v.orig ), FromNx( v.dir ) );
  }


//=============================+=====================================+=
//                              Capsule
//=============================+=====================================+=
inline NxCapsule                ToNx(Capsule v)
  {
    return NxCapsule( NxSegment( ToNx( v.Segment.Origin ), ToNx( v.Segment.End ) ), v.Radius );
  }

//=============================+=====================================+=
inline Capsule                  FromNx(const NxCapsule& v)
  {
    return Capsule( Line::FromPoints( FromNx( v.p0 ), FromNx( v.p1 ) ), v.radius );
  }


//=============================+=====================================+=
//                              Triangle
//=============================+=====================================+=
inline NxTriangle               ToNx(Triangle v)
  {
    return NxTriangle( ToNx( v.p0 ), ToNx( v.p1 ), ToNx( v.p2 ) );
  }

//=============================+=====================================+=
inline Triangle                 FromNx(const NxTriangle& v)
  {
    return Triangle( FromNx( v.verts[0] ), FromNx( v.verts[1] ), FromNx( v.verts[2] ) );
  }
