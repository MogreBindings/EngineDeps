//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Cooking.h"
#include                       "TriangleMesh.h"

//=============================+=====================================+=
bool                            CookingInterface::CookTriangleMesh(TriangleMeshDesc^ Desc, System::IO::Stream^ Stream)
  {
    giNxStream str( Stream );
    return ptr->NxCookTriangleMesh( *Desc->data, str );
  }

//=============================+=====================================+=
bool                            CookingInterface::CookTriangleMesh(array<float>^ Vertices, array<unsigned>^ Triangles, System::IO::Stream^ Stream)
  {
    giNxStream        str( Stream );

    pin_ptr<float>    pv = &Vertices[0] ;
    pin_ptr<unsigned> pt = &Triangles[0];

    TriangleMeshDesc^ desc = gcnew TriangleMeshDesc( IntPtr( pv ), IntPtr( pt ) );

    desc->PointsByteStride    = 12;
    desc->TrianglesByteStride = 12;
    desc->VertexCount         = Vertices->Length / 3;
    desc->TriangleCount       = Triangles->Length / 3;

    bool result = ptr->NxCookTriangleMesh( *desc->data, str );

    delete desc;
    return result;
  }
