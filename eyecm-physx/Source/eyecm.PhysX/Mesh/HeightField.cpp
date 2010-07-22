//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Physics.h"
#include                       "HeightField.h"
#include                       "Shape.h"
#include                       "Actor.h"
#include                       "Scene.h"
#include                       "PhysicsCollection.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public ref class                HeightField:                          public giNxProxy<NxHeightField, giNxRegisteredObject<Physics> >
  {
    internal:
      HeightField(Physics^ physics, NxHeightField* ptr);

    public:
      ~HeightField();

    public:
      DefR0( unsigned,          RowCount,                             getNbRows() )
      DefR0( unsigned,          ColumnCount,                          getNbColumns() )
      DefRc(
        HeightFieldFormats,     Format,
        NxHeightFieldFormat,    getFormat()
      )
      DefR0( unsigned,          SampleByteStride,                     getSampleStride() )
      DefR0( float,             Thickness,                            getThickness() )
      DefR0( float,             ConvexEdgeThreshold,                  getConvexEdgeThreshold() )
      DefRc( HeightFieldFlags,  Flags,            NxHeightFieldFlags, getFlags() )
      DefR0( unsigned,          ReferenceCount,                       getReferenceCount() )

      property IntPtr           Cells
        {
          IntPtr                get()                                 { return IntPtr( const_cast<void*>( data->getCells() ) ); }
        }

    public:
      float                     GetHeight(float X, float Z)           { return data->getHeight( X, Z ); }

    public:
                                DefLoadSaveToDescX( HeightFieldDesc, data )

    // TODO: save cells
  };

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
void                            HeightFieldShapeDesc::Init(giPhysics^ physics)
  {
    hfield = physics->WrapOrGet( *data->heightField );
  }

//=============================+=====================================+=
void                            HeightFieldShapeDesc::HeightField::set(giHeightField^ v)
  {
    hfield = v;
    data->heightField = v != nullptr ? v->data : 0;
  }

//=============================+=====================================+=
Physics^                        HeightFieldShapeDesc::Physics::get()  { return HeightField ? HeightField->Owner : nullptr; }

//=============================+=====================================+=
HeightField^                    HeightFieldShape::HeightField::get()
  {
    return this->Actor->Scene->Physics->WrapOrGet( ptr->getHeightField() );
  }

//=============================+=====================================+=
unsigned                        HeightFieldShape::GetTriangle([Out] Triangle% Result, [Out] array<Triangle>^% Edges, [Out] array<TriangleFlags>^% Flags, unsigned TriangleIndex, bool WorldSpaceTranslation, bool WorldSpaceRotation)
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
bool                            HeightFieldShape::OverlapAABBTriangles(AxisAlignedBox AABox, QueryFlags Flags, IUserEntityReport<unsigned>^ Report)
  {
    giUserEntityReport<giValueWrapper<unsigned>> report( Report );

    return ptr->overlapAABBTriangles( ToNx( AABox ), static_cast<NxU32>( Flags ), &report );
  }

//=============================+=====================================+=
                                HeightField::HeightField(Physics^ physics, NxHeightField* ptr): giNxProxy( ptr )
  {
    Register( physics );
  }

//=============================+=====================================+=
                                HeightField::~HeightField()
  {
    if( !data ) return;

    NxPhysicsSDK* sdk = this->Owner->ptr;

    Owner->hfields->Remove( IntPtr( data ) );
    Unregister();

    if( !sdk ) return; // sdk is disposing, no need to release explicitly
    if( this->ReferenceCount != 0 ) throw gcnew Exception();

    sdk->releaseHeightField( *data );
  }

//=============================+=====================================+=
HeightField^                    Physics::CreateHeightField(HeightFieldDesc^ Desc)
  {
    NxHeightField* hfieldptr = ptr->createHeightField( *Desc->data );
    if( !hfieldptr ) return nullptr;
    
    HeightField^ result = gcnew HeightField( this, hfieldptr );

    hfields->Add( IntPtr( hfieldptr ), result );
    return result;
  }

//=============================+=====================================+=
HeightField^                    Physics::CreateHeightField(HeightFieldDesc^ Desc, array<HeightFieldSample>^ Samples)
  {
    pin_ptr<HeightFieldSample> p = &Samples[0];

    Desc->data->samples = p;
    return CreateHeightField( Desc );
  }

//=============================+=====================================+=
HeightField^                    Physics::CreateHeightField(HeightFieldDesc^ Desc, array<HeightFieldSample, 2>^ Samples)
  {
    pin_ptr<HeightFieldSample> p = &Samples[0, 0];

    Desc->data->samples = p;
    return CreateHeightField( Desc );
  }

//=============================+=====================================+=
HeightField^                    Physics::WrapOrGet(const NxHeightField& hfield)
  {
    NxHeightField* hfieldptr = const_cast<NxHeightField*>( &hfield );
    HeightField^   result;

    if( !hfields->TryGetValue( IntPtr( hfieldptr ), result ) )
      hfields->Add( IntPtr( hfieldptr ), result = gcnew HeightField( this, hfieldptr ) );

    return result;
  }





//=============================+=====================================+=
DefPinUnpinImplS( void,         Samples,                              samples, sampleStride, HeightFieldDesc )
DefPinImplX( void,              Samples,                              samples, sampleStride, HeightFieldDesc, generic<typename T>, T, DefArrayTypeTwoDimensional )

//=============================+=====================================+=
void                            HeightFieldDesc::UnpinPinned()
  {
    DefPinFree( Samples, samples )
  }

//=============================+=====================================+=
void                            HeightFieldDesc::CopyCustom(HeightFieldDesc^ other)
  {
    UnpinPinned();
    //
    DefPinCopy( Samples, samples )
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddHeightField(HeightField^ Object, UserPropertiesType UserProperties, String^ ID)
  {
    const char* id    = ToNx( ID );
    const char* props = ToChar( UserProperties );

    bool Result = addHeightField( *this->ptr, *Object->data, props, id );
    
    delete[] props;
    delete[] id;
    return Result;
  }
