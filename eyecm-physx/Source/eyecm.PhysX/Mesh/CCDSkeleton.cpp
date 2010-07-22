//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Physics.h"
#include                       "Shape.h"
#include                       "Actor.h"
#include                       "Scene.h"
#include                       "SimpleTriangleMesh.h"
#include                       "PhysicsCollection.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public ref class                CCDSkeleton:                          public giNxProxy<NxCCDSkeleton, giNxRegisteredObject<Physics> >
  {
    internal:
      CCDSkeleton(Physics^ Physics, NxCCDSkeleton* data):
        giNxProxy( data )
        {
          Register( Physics );
        }

    public:
      ~CCDSkeleton()
        {
          if( !data ) return;

          NxPhysicsSDK* physicsptr = Owner->ptr;

          Owner->ccdskels->Remove( IntPtr( data ) );
          Unregister();

          if( !physicsptr ) return; // physics is disposing, no need to release explicitly
          if( this->ReferenceCount != 0 ) throw gcnew Exception();

          physicsptr->releaseCCDSkeleton( *data );
        }

    public:
      property unsigned         ReferenceCount
        {
          unsigned              get()                                 { return data->getReferenceCount(); }
        }

    public:
      unsigned                  Save([Out] array<unsigned char>^% Buffer)
        {
          Buffer = gcnew array<unsigned char>( data->getDataSize() );
          pin_ptr<unsigned char> p = &Buffer[0];
          return data->save( p, Buffer->Length );
        }

    public:
                                DefSaveToDescX( SimpleTriangleMesh, data )
  };

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
ThisNamespace::CCDSkeleton^     ShapeDesc::CCDSkeleton::get()
{
  return skelptr;
}

//=============================+=====================================+=
void                            ShapeDesc::CCDSkeleton::set(ThisNamespace::CCDSkeleton^ skel)
{
  data->ccdSkeleton = skel == nullptr ? 0 : skel->GetNx();
  //
  skelptr = skel;
}

//=============================+=====================================+=
CCDSkeleton^                    Shape::CCDSkeleton::get()
  {
    NxCCDSkeleton* nxskel = ptr->getCCDSkeleton();
    //
    if( !nxskel ) return nullptr;
    
    Physics ^p = Owner->Owner->Owner;
    //
    return p->WrapOrGet( *nxskel );
  }

//=============================+=====================================+=
void                            Shape::CCDSkeleton::set(ThisNamespace::CCDSkeleton^ v)
  {
    ptr->setCCDSkeleton( v == nullptr ? 0 : v->data );
  }

//=============================+=====================================+=
CCDSkeleton^                    Physics::WrapOrGet(const NxCCDSkeleton& skeleton)
  {
    NxCCDSkeleton* ptr = const_cast<NxCCDSkeleton*>( &skeleton );

    CCDSkeleton^ result;

    if( !ccdskels->TryGetValue( IntPtr( ptr ), result ) )
      ccdskels->Add( IntPtr( ptr ), result = gcnew CCDSkeleton( this, ptr ) );

    return result;
  }

//=============================+=====================================+=
CCDSkeleton^                    Physics::CreateCCDSkeleton(SimpleTriangleMesh^ Mesh)
  {
    NxCCDSkeleton* s = ptr->createCCDSkeleton( *Mesh->data );
    //
    if( !s ) return nullptr;
    
    CCDSkeleton^ result = gcnew CCDSkeleton( this, s );
    //
    ccdskels->Add( IntPtr( s ), result );
    //
    return result;
  }

//=============================+=====================================+=
CCDSkeleton^                    Physics::CreateCCDSkeleton(array<unsigned char>^ Buffer)
  {
    pin_ptr<unsigned char> p      = &Buffer[0];
    NxCCDSkeleton*         s      = ptr->createCCDSkeleton( p, Buffer->Length );
    if( !s ) return nullptr;
    
    CCDSkeleton^ result = gcnew CCDSkeleton( this, s );

    ccdskels->Add( IntPtr( s ), result );
    return result;
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddCCDSkeleton(CCDSkeleton^ Object, UserPropertiesType UserProperties, String^ ID)
  {
    const char* id    = ToNx( ID );
    const char* props = ToChar( UserProperties );

    bool Result = addCCDSkeleton( *this->ptr, *Object->data, props, id );
    
    delete[] props;
    delete[] id;
    return Result;
  }
