//=============================+=====================================+=
//                              mogre conversion file
//=============================+=====================================+=
//=============================+=====================================+=
//                              Vector3
//=============================+=====================================+=
inline NxVec3                   ToNx(Vector3 v)
  {
    return NxVec3( v.x, v.y, v.z );
  }

//=============================+=====================================+=
inline Vector3                  FromNx(const NxVec3& v)
  {
    Vector3 result;

    result.x = v.x;
    result.y = v.y;
    result.z = v.z;

    return result;
  }

//=============================+=====================================+=
inline void                     ToNx(Vector3 v, float& x, float& y, float& z)
  {
    x = v.x; y = v.y; z = v.z;
  }

//=============================+=====================================+=
//                              AxisAlignedBox
//=============================+=====================================+=
inline NxBounds3                ToNx(AxisAlignedBox v)
  {
    NxBounds3 result;

    result.set( v->Minimum.x, v->Minimum.y, v->Minimum.z, v->Maximum.x, v->Maximum.y, v->Maximum.z );

    return result;
  }

//=============================+=====================================+=
inline AxisAlignedBox           FromNx(NxBounds3& v)
  {
    return gcnew Mogre::AxisAlignedBox( FromNx( v.min ), FromNx( v.max ) );
  }

//=============================+=====================================+=
//                              Matrix4x4
//=============================+=====================================+=
inline NxMat34                  ToNx(Matrix4x4 m)
  {
    NxMat34 result( false );
                         
    result.M.setRow( 0, NxVec3( m->m00, m->m01, m->m02 ) );
    result.M.setRow( 1, NxVec3( m->m10, m->m11, m->m12 ) );
    result.M.setRow( 2, NxVec3( m->m20, m->m21, m->m22 ) );
    //
    result.t = NxVec3( m->m03, m->m13, m->m23 );

    return result;
  }

//=============================+=====================================+=
inline Matrix4x4                FromNx(const NxMat34& m)
  {
    NxVec3 c0 = m.M.getColumn( 0 );
    NxVec3 c1 = m.M.getColumn( 1 );
    NxVec3 c2 = m.M.getColumn( 2 );

    Matrix4x4 result = gcnew Mogre::Matrix4
    (
      c0.x, c1.x, c2.x, m.t.x,
      c0.y, c1.y, c2.y, m.t.y,
      c0.z, c1.z, c2.z, m.t.z,
         0,    0,    0,     1
    );

    return result;
  }


//=============================+=====================================+=
//                              Matrix3x3
//=============================+=====================================+=
inline NxMat33                  ToNx(Matrix3x3 m)
  {
    NxMat33 result;

    result.setRow( 0, NxVec3( m->m00, m->m01, m->m02 ) );
    result.setRow( 1, NxVec3( m->m10, m->m11, m->m12 ) );
    result.setRow( 2, NxVec3( m->m20, m->m21, m->m22 ) );

    return result;
  }

//=============================+=====================================+=
inline Matrix3x3                FromNx(const NxMat33& m)
  {
    NxVec3 c0 = m.getColumn( 0 );
    NxVec3 c1 = m.getColumn( 1 );
    NxVec3 c2 = m.getColumn( 2 );

    Matrix3x3 result = gcnew Mogre::Matrix3
    (
      c0.x, c1.x, c2.x,
      c0.y, c1.y, c2.y,
      c0.z, c1.z, c2.z
    );   

    return result;
  }


//=============================+=====================================+=
//                              Quaternion
//=============================+=====================================+=
inline NxQuat                   ToNx(Quaternion q)
  {
    NxQuat result;
    //
    result.setWXYZ( q.w, q.x, q.y, q.z );
    //
    return result;
  }

//=============================+=====================================+=
inline Quaternion               FromNx(const NxQuat& q)
  {
    Quaternion result;
    //
    result.x = q.x;
    result.y = q.y;
    result.z = q.z;
    result.w = q.w;
    //
    return result;
  }

//=============================+=====================================+=
//                              OrientedBox
//=============================+=====================================+=
inline NxBox                    ToNx(OrientedBox v)
  {
    return NxBox( ToNx( v->Center ), ToNx( v->Dimension ) / 2.0, ToNx( v->Orientation ) );
  }

//=============================+=====================================+=
inline OrientedBox              FromNx(const NxBox& v)
  {
    OrientedBox result = gcnew Mogre::OrientedBox
    (
      FromNx( v.rot ),
      FromNx( v.center ),
      FromNx( v.extents * 2 )
    );

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
inline NxPlane                  ToNx(Plane v)
  {
    return NxPlane( ToNx( v.normal ), v.d );
  }

//=============================+=====================================+=
inline Plane                    FromNx(const NxPlane& v)
  {
    return Plane( FromNx( v.normal ), v.d );
  }



//=============================+=====================================+=
//                              Line
//=============================+=====================================+=
inline NxRay                    ToNx(Line v)
  {
    NxVec3 dn = ToNx( v.Direction );
    dn.normalize();
    return NxRay( ToNx( v.Origin ), dn );
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
