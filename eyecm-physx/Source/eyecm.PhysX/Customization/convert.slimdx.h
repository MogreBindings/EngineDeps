//=============================+=====================================+=
//                              xna conversion file
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
    result.set( v.Minimum.X, v.Minimum.Y, v.Minimum.Z, v.Maximum.X, v.Maximum.Y, v.Maximum.Z );
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
    result.setColumnMajor44( &m.M11 );
    return result;
  }

//=============================+=====================================+=
inline Matrix4x4                FromNx(const NxMat34& m)
  {
    Matrix4x4 result;
    m.getColumnMajor44( &result.M11 );
    return result;
  }


//=============================+=====================================+=
//                              Matrix3x3
//=============================+=====================================+=
inline NxMat33                  ToNx(Matrix3x3 m)
  {
    NxMat33 result;
    result.setColumnMajor( &m.M11 );
    return result;
  }

//=============================+=====================================+=
inline Matrix3x3                FromNx(const NxMat33& m)
  {
    Matrix3x3 result;
    m.getColumnMajor( &result.M11 );
    return result;
  }


//=============================+=====================================+=
//                              Quaternion
//=============================+=====================================+=
inline NxQuat                   ToNx(Quaternion q)
  {
    NxQuat result;
    //
    result.setWXYZ( q.W, q.X, q.Y, q.Z );
    //
    return result;
  }

//=============================+=====================================+=
inline Quaternion               FromNx(const NxQuat& q)
  {
    Quaternion result;
    //
    result.X = q.x;
    result.Y = q.y;
    result.Z = q.z;
    result.W = q.w;
    //
    return result;
  }

//=============================+=====================================+=
//                              OrientedBox
//=============================+=====================================+=
inline NxBox                    ToNx(OrientedBox v)
  {
    return NxBox( ToNx( v.Center ), ToNx( v.Dimension ) / 2.0, ToNx( v.Orientation ) );
  }

//=============================+=====================================+=
inline OrientedBox              FromNx(const NxBox& v)
  {
    OrientedBox result;

    result.Orientation = FromNx( v.rot );
    result.Center      = FromNx( v.center );
    result.Dimension   = FromNx( v.extents * 2 );

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
    return NxPlane( ToNx( v.Normal ), v.D );
  }


//=============================+=====================================+=
//                              Line
//=============================+=====================================+=
inline NxRay                    ToNx(Line v)
  {
    NxVec3 dn = ToNx( v.Direction );
    dn.normalize();
    return NxRay( ToNx( v.Position ), dn );
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
    return NxCapsule( NxSegment( ToNx( v.a ), ToNx( v.b ) ), v.Radius );
  }

//=============================+=====================================+=
inline Capsule                  FromNx(const NxCapsule& v)
  {
    return Capsule( FromNx( v.p0 ), FromNx( v.p1 ), v.radius );
  }


//=============================+=====================================+=
//                              Triangle
//=============================+=====================================+=
inline NxTriangle               ToNx(Triangle v)
  {
    return NxTriangle( ToNx( v.a ), ToNx( v.b ), ToNx( v.c ) );
  }

//=============================+=====================================+=
inline Triangle                 FromNx(const NxTriangle& v)
  {
    return Triangle( FromNx( v.verts[0] ), FromNx( v.verts[1] ), FromNx( v.verts[2] ) );
  }
