//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "SimpleTriangleMesh.h"

//=============================+=====================================+=
DefPinUnpinImplS( void,         Points,                               points,    pointStrideBytes,    SimpleTriangleMesh )
DefPinUnpinImplS( void,         Triangles,                            triangles, triangleStrideBytes, SimpleTriangleMesh )


//=============================+=====================================+=
void                            SimpleTriangleMesh::UnpinPinned()
  {
    DefPinFree( Points,    points    )
    DefPinFree( Triangles, triangles )
  }

//=============================+=====================================+=
void                            SimpleTriangleMesh::CopyCustom(SimpleTriangleMesh^ other)
  {
    UnpinPinned();
    //
    DefPinCopy( Points,    points    )
    DefPinCopy( Triangles, triangles )
  }
