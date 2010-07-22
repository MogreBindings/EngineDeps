//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "ConvexMesh.h"
#include                       "Physics.h"
#include                       "nxstreamrw.h"
#include                       "Shape.h"
#include                       "ShapeDesc.h"
#include                       "Actor.h"
#include                       "Scene.h"
#include                       "ForceFieldShapeDesc.h"
#include                       "PhysicsCollection.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public ref class                ConvexMesh:                         public giNxProxy<NxConvexMesh, giNxRegisteredObject<Physics> >
  {
    internal:
      ConvexMesh(Physics^ Physics, NxConvexMesh* data):
        giNxProxy( data )
        {
          Register( Physics );
        }

    public:
      ~ConvexMesh()
        {
          if( !data ) return;

          NxPhysicsSDK* physicsptr = Owner->ptr;

          Owner->convexmeshes->Remove( IntPtr( data ) );
          Unregister();

          if( !physicsptr ) return; // physics is disposing, no need to release explicitly
          if( this->ReferenceCount != 0 ) throw gcnew Exception();

          physicsptr->releaseConvexMesh( *data );
        }

    public:
      value struct              ProxySubmesh
        {
          internal:
            NxConvexMesh*       ptr;
            NxSubmeshIndex      idx;
            NxInternalArray     internalarray;

            ProxySubmesh(NxConvexMesh* ptr, NxSubmeshIndex idx, InternalArrays internalarray):
              ptr( ptr ), idx( idx ), internalarray( static_cast<NxInternalArray>( internalarray ) )
              {}

          public:
            property unsigned   SubmeshIndex
              {
                unsigned        get()                                 { return idx; }
              }

            property
            InternalArrays      InternalArray
              {
                InternalArrays  get()                                 { return static_cast<InternalArrays>( internalarray ); }
              }

            property unsigned   Count
              {
                unsigned        get()                                 { return ptr->getCount( idx, internalarray ); }
              }

            property
            InternalFormats     Format
              {
                InternalFormats get()                                 { return static_cast<InternalFormats>( ptr->getFormat( idx, internalarray ) ); }
              }

            property IntPtr     Base
              {
                IntPtr          get()                                 { return IntPtr( const_cast<void*>( ptr->getBase( idx, internalarray ) ) ); }
              }

            property unsigned   Stride
              {
                unsigned        get()                                 { return ptr->getStride( idx, internalarray ); }
              }
        };

      value struct              ProxySubmeshes // TODO: IEnumerable<ProxySubmesh>
        {
          internal:
            NxConvexMesh*     ptr;

            ProxySubmeshes(NxConvexMesh* ptr): ptr ( ptr ) { }

          public:
            property unsigned   Count
              {
                unsigned        get()                                 { return ptr->getSubmeshCount(); }
              }

            property
            ProxySubmesh        default[int, InternalArrays]
              {
                ProxySubmesh    get(int SubmeshIndex, InternalArrays InternalArray)
                  {
                    return ProxySubmesh( ptr, SubmeshIndex, InternalArray );
                  }
              }
        };

      property ProxySubmeshes   Submeshes
        {
          ProxySubmeshes        get()                                 { return ProxySubmeshes( data ); }
        }

      property unsigned         ReferenceCount
        {
          unsigned              get()                                 { return data->getReferenceCount(); }
        }

      value struct              ProxyMassInformation
        {
          internal:
            float               m;
            Matrix3x3           li;
            Vector3             lcom;

            ProxyMassInformation(NxConvexMesh* ptr)
              {
                float m; NxMat33 li; NxVec3 lcom;

                ptr->getMassInformation( m, li, lcom );
                this->m = m; this->li = FromNx( li ); this->lcom = FromNx( lcom );
              }

          public:
            property float      Mass
              {
                float           get()                                 { return m; }
              }

            property Matrix3x3  LocalInertia
              {
                Matrix3x3       get()                                 { return li; }
              }

            property Vector3    LocalCenterOfMass
              {
                Vector3         get()                                 { return lcom; }
              }
        };

      property
      ProxyMassInformation      MassInformation
        {
          ProxyMassInformation  get()                                 { return ProxyMassInformation( data ); }
        }

    public:
      bool                      Load(Stream^ CookedStream)
        {
          giNxStream str( CookedStream );
          return data->load( str );
        }

    public:
                                DefSaveToDescX( ConvexMeshDesc, data )
  };

//=============================+=====================================+=
NxConvexMesh*                   GetNxConvexMesh(ConvexMesh^ v)
  {
    return v != nullptr ? v->data : 0;
  }

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
void                            ConvexShapeDesc::Init(giPhysics^ physics)
  {
    convexmesh = physics->WrapOrGet( *data->meshData );
  }

//=============================+=====================================+=
Physics^                        ConvexShapeDesc::Physics::get()       { return ConvexMesh ? ConvexMesh->Owner : nullptr; }

//=============================+=====================================+=
ConvexShape::giConvexMesh^      ConvexShape::ConvexMesh::get()
  {
    return this->Actor->Scene->Physics->WrapOrGet( ptr->getConvexMesh() );
  }

//=============================+=====================================+=
ConvexMesh^                     Physics::CreateConvexMesh(Stream^ CookedStream)
  {
    giNxStream str( CookedStream );

    NxConvexMesh* m = ptr->createConvexMesh( str );
    if( !m ) return nullptr;
    
    ConvexMesh^ result = gcnew ConvexMesh( this, m );

    convexmeshes->Add( IntPtr( m ), result );
    return result;
  }

//=============================+=====================================+=
ConvexMesh^                     Physics::WrapOrGet(const NxConvexMesh& mesh)
  {
    NxConvexMesh* ptr = const_cast<NxConvexMesh*>( &mesh );

    ConvexMesh^ result;

    if( !convexmeshes->TryGetValue( IntPtr( ptr ), result ) )
      convexmeshes->Add( IntPtr( ptr ), result = gcnew ConvexMesh( this, ptr ) );

    return result;
  }



//=============================+=====================================+=
DefPinUnpinImplS( void,         Points,                               points,    pointStrideBytes,    ConvexMeshDesc )
DefPinUnpinImplS( void,         Triangles,                            triangles, triangleStrideBytes, ConvexMeshDesc )


//=============================+=====================================+=
void                            ConvexMeshDesc::UnpinPinned()
  {
    DefPinFree( Points,    points    )
    DefPinFree( Triangles, triangles )
  }

//=============================+=====================================+=
void                            ConvexMeshDesc::CopyCustom(ConvexMeshDesc^ other)
  {
    UnpinPinned();
    //
    DefPinCopy( Points,    points    )
    DefPinCopy( Triangles, triangles )
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddConvexMesh(ConvexMesh^ Object, UserPropertiesType UserProperties, String^ ID)
  {
    const char* id    = ToNx( ID );
    const char* props = ToChar( UserProperties );

    bool Result = addConvexMesh( *this->ptr, *Object->data, props, id );
    
    delete[] props;
    delete[] id;
    return Result;
  }
