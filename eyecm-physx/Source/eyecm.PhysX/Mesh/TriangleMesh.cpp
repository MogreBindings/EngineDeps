//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "TriangleMesh.h"
#include                       "Physics.h"
#include                       "Actor.h"
#include                       "Scene.h"
#include                       "Shape.h"
#include                       "nxstreamrw.h"
#include                       "PhysicsCollection.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public ref class                TriangleMesh:                         public giNxProxy<NxTriangleMesh, giNxRegisteredObject<Physics> >
  {
    internal:
      TriangleMesh(Physics^ Physics, NxTriangleMesh* data):
        giNxProxy( data )
        {
          Register( Physics );
        }

    public:
      ~TriangleMesh()
        {
          if( !data ) return;

          NxPhysicsSDK* physicsptr = Owner->ptr;

          Owner->trimeshes->Remove( IntPtr( data ) );
          Unregister();

          if( !physicsptr ) return; // physics is disposing, no need to release explicitly
          if( this->ReferenceCount != 0 ) throw gcnew Exception();

          physicsptr->releaseTriangleMesh( *data );
        }

    public:
      value struct              ProxySubmesh
        {
          internal:
            NxTriangleMesh*     ptr;
            NxSubmeshIndex      idx;
            NxInternalArray    internalarray;

            ProxySubmesh(NxTriangleMesh* ptr, NxSubmeshIndex idx, InternalArrays internalarray):
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
            NxTriangleMesh*     ptr;

            ProxySubmeshes(NxTriangleMesh* ptr): ptr ( ptr ) { }

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

            ProxyMassInformation(NxTriangleMesh* ptr)
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

      unsigned                  GetTriangleMaterial(unsigned TriangleID) { return data->getTriangleMaterial( static_cast<NxTriangleID>( TriangleID ) ); }

    public:
                                DefSaveToDescX( TriangleMeshDesc, data )

  };

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
void                            TriangleMeshShapeDesc::Init(giPhysics^ physics)
  {
    trimesh = physics->WrapOrGet( *data->meshData );
  }

//=============================+=====================================+=
void                            TriangleMeshShapeDesc::TriangleMesh::set(giTriangleMesh^ v)
  {
    trimesh = v;
    data->meshData = v != nullptr ? v->data : 0;
  }

//=============================+=====================================+=
Physics^                        TriangleMeshShapeDesc::Physics::get()  { return TriangleMesh ? TriangleMesh->Owner : nullptr; }

//=============================+=====================================+=
TriangleMesh^                   TriangleMeshShape::TriangleMesh::get()
  {
    return this->Actor->Scene->Physics->WrapOrGet( ptr->getTriangleMesh() );
  }

//=============================+=====================================+=
unsigned                        TriangleMeshShape::GetTriangle([Out] Triangle% Result, [Out] array<Triangle>^% Edges, [Out] array<TriangleFlags>^% Flags, unsigned TriangleIndex, bool WorldSpaceTranslation, bool WorldSpaceRotation)
  {
    NxTriangle triangle;
    NxTriangle edges[3];
    NxU32      flags[3];

    unsigned result = ptr->getTriangle( triangle, edges, flags, TriangleIndex, WorldSpaceTranslation, WorldSpaceRotation );

    Result = FromNx( triangle );

    Edges = gcnew array<Triangle>( 3 );
    Flags = gcnew array<TriangleFlags>( 3 );

    for(int i = 0; i < 3; i++ ) {

      Edges[i] = FromNx( edges[i] );
      Flags[i] = static_cast<TriangleFlags>( flags[i] );
    }

    return result;
  }

//=============================+=====================================+=
bool                            TriangleMeshShape::OverlapAABBTriangles(AxisAlignedBox AABox, QueryFlags Flags, IUserEntityReport<unsigned>^ Report)
  {
    giUserEntityReport<giValueWrapper<unsigned>> report( Report );

    return ptr->overlapAABBTriangles( ToNx( AABox ), static_cast<NxU32>( Flags ), &report );
  }

//=============================+=====================================+=
TriangleMesh^                   Physics::CreateTriangleMesh(Stream^ CookedStream)
  {
    giNxStream str( CookedStream );

    NxTriangleMesh* m = ptr->createTriangleMesh( str );
    if( !m ) return nullptr;
    
    TriangleMesh^ result = gcnew TriangleMesh( this, m );

    trimeshes->Add( IntPtr( m ), result );
    return result;
  }

//=============================+=====================================+=
TriangleMesh^                   Physics::WrapOrGet(const NxTriangleMesh& mesh)
  {
    NxTriangleMesh* ptr = const_cast<NxTriangleMesh*>( &mesh );

    TriangleMesh^ result;

    if( !trimeshes->TryGetValue( IntPtr( ptr ), result ) )
      trimeshes->Add( IntPtr( ptr ), result = gcnew TriangleMesh( this, ptr ) );

    return result;
  }




//=============================+=====================================+=
DefPinUnpinImplS( void,         MaterialIndices,                      materialIndices, materialIndexStride, TriangleMeshDesc )

//=============================+=====================================+=
void                            TriangleMeshDesc::UnpinPinned()
  {
    DefPinFree( MaterialIndices, materialIndices )
    //
    SimpleTriangleMesh::UnpinPinned();
  }

//=============================+=====================================+=
void                            TriangleMeshDesc::CopyCustom(TriangleMeshDesc^ other)
  {
    UnpinPinned();
    //
    SimpleTriangleMesh::CopyCustom( other );
    //
    DefPinCopy( MaterialIndices, materialIndices )
  }

//=============================+=====================================+=
void                            TriangleMeshDesc::PostSet()
  {
    SimpleTriangleMesh::PostSet();
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddTriangleMesh(TriangleMesh^ Object, UserPropertiesType UserProperties, String^ ID)
  {
    const char* id    = ToNx( ID );
    const char* props = ToChar( UserProperties );

    bool Result = addTriangleMesh( *this->ptr, *Object->data, props, id );
    
    delete[] props;
    delete[] id;
    return Result;
  }
