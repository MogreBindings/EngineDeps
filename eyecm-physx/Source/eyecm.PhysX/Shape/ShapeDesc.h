//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "MiscDesc.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Physics;
ref class                       TriangleMesh;
ref class                       ConvexMesh;
interface class                 IUserWheelContactModify;
ref class                       HeightField;
ref class                       CCDSkeleton;

NxConvexMesh*                   GetNxConvexMesh(ConvexMesh^ v);

//=============================+=====================================+=
public ref struct               ShapeDesc:                            giNxProxyData<NxShapeDesc>
  {
    private:
      typedef                   ThisNamespace::ShapeFlags             giShapeFlags;

    internal:
      ShapeDesc(NxShapeDesc& data): BaseType( data ) { }

    internal:
      static ShapeDesc^         Wrap(Physics^, NxShapeDesc& data);

    internal:
      ShapeDesc(NxShapeDesc* data): BaseType( data ) { }

      ShapeDesc(NxShapeDesc* data, Vector3 LocalPosition):
        BaseType( data )
        {
          this->LocalPosition = LocalPosition;
        }
        
    public:
      ShapeDesc^                Clone();

    public:
      property ShapeTypes       Type
        {
          ShapeTypes            get()                                 { return static_cast<ShapeTypes>( data->getType() ); }
        }

      property Matrix4x4        LocalPose
        {
          Matrix4x4             get()                                 { return FromNx( data->localPose ); }
          void                  set(Matrix4x4 v)                      { data->localPose = ToNx( v ); }
        }

      property Matrix3x3        LocalOrientation
        {
          Matrix3x3             get()                                 { return FromNx( data->localPose.M ); }
          void                  set(Matrix3x3 v)                      { data->localPose.M = ToNx( v ); }
        }

      property Vector3          LocalPosition
        {
          Vector3               get()                                 { return FromNx( data->localPose.t ); }
          void                  set(Vector3 v)                        { data->localPose.t = ToNx( v ); }
        }

      property unsigned         MaterialIndex
        {
          unsigned              get()                                 { return data->materialIndex; }
          void                  set(unsigned v)                       { data->materialIndex = static_cast<NxMaterialIndex>( v ); }
        }

      property giShapeFlags     ShapeFlags
        {
          giShapeFlags          get()                                 { return static_cast<giShapeFlags>( data->shapeFlags ); }
          void                  set(giShapeFlags v)                   { data->shapeFlags = static_cast<NxU32>( v ); }
        }

      property unsigned         Group
        {
          unsigned              get()                                 { return data->group; }
          void                  set(unsigned v)                       { data->group = static_cast<NxCollisionGroup>( v ); }
        }

      property float            Mass
        {
          float                 get()                                 { return data->mass; }
          void                  set(float mass)                       { data->mass = mass; }
        }

      property float            Density
        {
          float                 get()                                 { return data->density; }
          void                  set(float density)                    { data->density = density; }
        }

      property float            SkinWidth
        {
          float                 get()                                 { return data->skinWidth; }
          void                  set(float skinwidth)                  { data->skinWidth = skinwidth; }
        }
        
      typedef                   ThisNamespace::CCDSkeleton            giCCDSkeleton;
      //
      property giCCDSkeleton^   CCDSkeleton                           { giCCDSkeleton^ get(); void set(giCCDSkeleton^); }
      //
internal:
      giCCDSkeleton^            skelptr;
        
      void                      CopyCustom(ShapeDesc^ other)          { skelptr = other->skelptr; }
  };

//=============================+=====================================+=
#define                         DefShapeDescX( type, init, firstparam, firstparampass ) \
    internal: \
                                DefRecastData( Nx##type##ShapeDesc, ShapeDesc ) \
    private: \
      type##ShapeDesc( firstparam firstparampass Nx##type##ShapeDesc& data): ShapeDesc( data ) { init } \
    internal: \
      inline static ShapeDesc^  Wrap( firstparam firstparampass NxShapeDesc& desc)   { return gcnew type##ShapeDesc( firstparampass static_cast<Nx##type##ShapeDesc&>( desc ) ); } \
      \
    public: \
      type##ShapeDesc(type##ShapeDesc^ Original): \
        ShapeDesc( Original->IsDisposed ? new Nx##type##ShapeDesc : new Nx##type##ShapeDesc( *Original->data ) ) \
        { \
          DefThrowOnDisposed( Original, type##ShapeDesc, "clone" ) \
          CopyCustom( Original ); \
          PostSet(); \
        } \
      type##ShapeDesc^          Copy(type##ShapeDesc^ From) \
        { \
          DefThrowOnDisposed( this, type##ShapeDesc, "copy to" ) \
          DefThrowOnDisposed( From, type##ShapeDesc, "copy from" ) \
          delete data; \
          BaseType::data = new Nx##type##ShapeDesc( *From->data ); \
          CopyCustom( From ); \
          PostSet(); \
          return this;  \
        } \
      type##ShapeDesc^          Clone() new { return gcnew type##ShapeDesc( this ); } \
                                DefValidDefault

//=============================+=====================================+=
#define                         DefPhysicsArg                         giPhysics^
#define                         DefPhysicsArgPass                     physics,
#define                         DefShapeDesc( type )                  DefShapeDescX( type, {}, , )

//=============================+=====================================+=
#define                         DefShapeDescPh( type ) \
    internal: \
      typedef                   ThisNamespace::Physics                giPhysics; \
      property giPhysics^       Physics                               { giPhysics^ get(); } \
                                DefShapeDescX( type, Init( physics );, DefPhysicsArg, DefPhysicsArgPass )

//=============================+=====================================+=
public ref struct               PlaneShapeDesc:                       public ShapeDesc
  {
      DefShapeDesc(             Plane )

    private:
      typedef                   ThisNamespace::Plane                  giPlane;

    public:
      PlaneShapeDesc(): ShapeDesc( new NxPlaneShapeDesc() ) {}

      PlaneShapeDesc(Vector3 Normal, float Distance):
        ShapeDesc( new NxPlaneShapeDesc() )
        {
          this->Normal   = Normal;
          this->Distance = Distance;
        }

      PlaneShapeDesc(Vector3 Normal, float Distance, Vector3 LocalPosition):
        ShapeDesc( new NxPlaneShapeDesc(), LocalPosition )
        {
          this->Normal   = Normal;
          this->Distance = Distance;
        }

      PlaneShapeDesc(giPlane Plane):
        ShapeDesc( new NxPlaneShapeDesc() )
        {
          this->Plane = Plane;
        }

      PlaneShapeDesc(giPlane Plane, Vector3 LocalPosition):
        ShapeDesc( new NxPlaneShapeDesc(), LocalPosition )
        {
          this->Plane = Plane;
        }

    public:
       property Vector3         Normal
        {
          Vector3               get()                                 { return FromNx( data->normal ); }
          void                  set(Vector3 n)                        { data->normal = ToNx( n ); }
        }

      property float            Distance
        {
          float                 get()                                 { return -data->d; }
          void                  set(float d)                          { data->d = -d; } // notice the -
        }

      property giPlane          Plane
        {
          giPlane               get()                                 { return FromNx( NxPlane( data->normal, Distance ) ); }
          void                  set(giPlane p)                        { NxPlane plane = ToNx( p ); data->normal = plane.normal; Distance = plane.d; }
        }
  };


//=============================+=====================================+=
public ref struct               BoxShapeDesc:                         public ShapeDesc
  {
      DefShapeDesc(             Box )

    public:
      BoxShapeDesc(): ShapeDesc( new NxBoxShapeDesc() ) {}

      BoxShapeDesc(Vector3 Dimensions):
        ShapeDesc( new NxBoxShapeDesc() )
        {
          this->Dimensions = Dimensions;
        }

      BoxShapeDesc(Vector3 Dimensions, Vector3 LocalPosition):
        ShapeDesc( new NxBoxShapeDesc(), LocalPosition )
        {
          this->Dimensions = Dimensions;
        }

    public:
       property Vector3         Dimensions
        {
          Vector3               get()                                 { return FromNx( data->dimensions ); }
          void                  set(Vector3 dim)                      { data->dimensions = ToNx( dim ); }
        }
  };

//=============================+=====================================+=
public ref struct               SphereShapeDesc:                      public ShapeDesc
  {
      DefShapeDesc(             Sphere )

    public:
      SphereShapeDesc(): ShapeDesc( new NxSphereShapeDesc() ) {}

      SphereShapeDesc(float Radius):
        ShapeDesc( new NxSphereShapeDesc() )
        {
          this->Radius = Radius;
        }

      SphereShapeDesc(float Radius, Vector3 LocalPosition):
        ShapeDesc( new NxSphereShapeDesc(), LocalPosition )
        {
          this->Radius = Radius;
        }

    public:
      property float            Radius
        {
          float                 get()                                 { return data->radius; }
          void                  set(float r)                          { data->radius = r; }
        }
  };

//=============================+=====================================+=
public ref struct               CapsuleShapeDesc:                     public ShapeDesc
  {
      DefShapeDesc(             Capsule )

    public:
      CapsuleShapeDesc(): ShapeDesc( new NxCapsuleShapeDesc() ) {}

      CapsuleShapeDesc(float Radius, float Height):
        ShapeDesc( new NxCapsuleShapeDesc() )
        {
          this->Radius = Radius;
          this->Height = Height;
        }

      CapsuleShapeDesc(float Radius, float Height, Vector3 LocalPosition):
        ShapeDesc( new NxCapsuleShapeDesc(), LocalPosition )
        {
          this->Radius = Radius;
          this->Height = Height;
        }

    public:
      property float            Radius
        {
          float                 get()                                 { return data->radius; }
          void                  set(float r)                          { data->radius = r; }
        }

      property float            Height
        {
          float                 get()                                 { return data->height; }
          void                  set(float h)                          { data->height = h; }
        }
  };

//=============================+=====================================+=
public ref struct               TriangleMeshShapeDesc:                public ShapeDesc
  {
      DefShapeDescPh(           TriangleMesh )

    internal:
      typedef                   ThisNamespace::TriangleMesh           giTriangleMesh;

      giTriangleMesh^           trimesh;

      void                      Init(giPhysics^ physics);

      void                      CopyCustom(TriangleMeshShapeDesc^ Original)
        {
          trimesh = Original->trimesh;
          //
          ShapeDesc::CopyCustom( Original );
        }

    public:
      TriangleMeshShapeDesc(): ShapeDesc( new NxTriangleMeshShapeDesc() ) {}

      TriangleMeshShapeDesc(giTriangleMesh^ TriangleMesh):
        ShapeDesc( new NxTriangleMeshShapeDesc() )
        {
          this->TriangleMesh = TriangleMesh;
        }

      TriangleMeshShapeDesc(giTriangleMesh^ TriangleMesh, MeshShapeFlags MeshFlags):
        ShapeDesc( new NxTriangleMeshShapeDesc() )
        {
          this->TriangleMesh = TriangleMesh;
          this->MeshFlags    = MeshFlags;
        }

    public:
      property giTriangleMesh^  TriangleMesh
        {
          giTriangleMesh^       get()                                 { return trimesh; }
          void                  set(giTriangleMesh^ v);
        }

      DefPc( MeshShapeFlags,    MeshFlags,           NxMeshShapeFlag, meshFlags )
  };

//=============================+=====================================+=
public ref struct               ConvexShapeDesc:                      public ShapeDesc
  {
      DefShapeDescPh(           Convex )

    internal:
      typedef                   ThisNamespace::ConvexMesh             giConvexMesh;

      giConvexMesh^             convexmesh;

      void                      Init(giPhysics^ physics);

      void                      CopyCustom(ConvexShapeDesc^ Original)
        {
          convexmesh = Original->convexmesh;
          //
          ShapeDesc::CopyCustom( Original );
        }

    public:
      ConvexShapeDesc(): ShapeDesc( new NxConvexShapeDesc() ) {}

      ConvexShapeDesc(giConvexMesh^ ConvexMesh):
        ShapeDesc( new NxConvexShapeDesc() )
        {
          this->ConvexMesh = ConvexMesh;
        }

      ConvexShapeDesc(giConvexMesh^ ConvexMesh, MeshShapeFlags MeshFlags):
        ShapeDesc( new NxConvexShapeDesc() )
        {
          this->ConvexMesh = ConvexMesh;
          this->MeshFlags  = MeshFlags;
        }

    public:
      property giConvexMesh^    ConvexMesh
        {
          giConvexMesh^         get()                                 { return convexmesh; }
          void                  set(giConvexMesh^ v)
            {              
              data->meshData = GetNxConvexMesh( convexmesh = v );
            }
        }

      DefPc( MeshShapeFlags,    MeshFlags,           NxMeshShapeFlag, meshFlags )
  };

//=============================+=====================================+=
public ref struct               HeightFieldShapeDesc:                 public ShapeDesc
  {
      DefShapeDescPh(           HeightField )

    internal:
      typedef                   ThisNamespace::HeightField            giHeightField;

      giHeightField^            hfield;

      void                      Init(giPhysics^ physics);

      void                      CopyCustom(HeightFieldShapeDesc^ Original)
        {
          hfield = Original->hfield;
          //
          ShapeDesc::CopyCustom( Original );
        }

    public:
      HeightFieldShapeDesc(): ShapeDesc( new NxHeightFieldShapeDesc ) { }

      HeightFieldShapeDesc(giHeightField^ HeightField): ShapeDesc( new NxHeightFieldShapeDesc ) { this->HeightField = HeightField; }
      HeightFieldShapeDesc(giHeightField^ HeightField, Vector3 Scale, unsigned MaterialIndexHighBits, unsigned HoleMaterial, MeshShapeFlags MeshFlags): ShapeDesc( new NxHeightFieldShapeDesc )
        {
          this->HeightField           = HeightField;
          this->MaterialIndexHighBits = MaterialIndexHighBits;
          this->HoleMaterial          = HoleMaterial;
          this->MeshFlags             = MeshFlags;

          float x, y, z;
          ToNx( Scale, x, y, z );

          this->RowScale    = x;
          this->HeightScale = y * 1.0f / 32768;
          this->ColumnScale = z;
        }

    public:
      property giHeightField^   HeightField
        {
          giHeightField^        get()                                 { return hfield; }
          void                  set(giHeightField^);
        }

      DefP0( float,             HeightScale,                          heightScale )
      DefP0( float,             RowScale,                             rowScale )
      DefP0( float,             ColumnScale,                          columnScale )
      DefPc(
        unsigned,               MaterialIndexHighBits,
        NxMaterialIndex,        materialIndexHighBits
      )
      DefPc( unsigned,          HoleMaterial,        NxMaterialIndex, holeMaterial )
      DefPc( MeshShapeFlags,    MeshFlags,           NxMeshShapeFlag, meshFlags )
  };

//=============================+=====================================+=
public ref struct               WheelShapeDesc:                       public ShapeDesc
  {
      DefShapeDesc(             Wheel )

    public:
      WheelShapeDesc(): ShapeDesc( new NxWheelShapeDesc ) { }

      ~WheelShapeDesc()
        {
          DefProxyDestroy( Suspension );
          //
          DefProxyDestroy( LongitudalTireForceFunction );
          DefProxyDestroy( LateralTireForceFunction );
          //
          this->!WheelShapeDesc();
        }

      !WheelShapeDesc();

    public:
                                DefProxyGetSet( SpringDesc, Suspension, suspension )

                                DefProxyGetSet( TireFunctionDesc, LongitudalTireForceFunction, longitudalTireForceFunction )
                                DefProxyGetSet( TireFunctionDesc, LateralTireForceFunction,    lateralTireForceFunction )

      property
      IUserWheelContactModify^  WheelContactModify
        {
          IUserWheelContactModify^ get();
          void                     set(IUserWheelContactModify^ v);
        }

        DefP0( float,           Radius,                               radius )
        DefP0( float,           SuspensionTravel,                     suspensionTravel )
        DefP0( float,           InverseWheelMass,                     inverseWheelMass )
        DefP0( float,           MotorTorque,                          motorTorque )
        DefP0( float,           BrakeTorque,                          brakeTorque )
        DefP0( float,           SteerAngle,                           steerAngle )
        DefPc( WheelShapeFlags, WheelFlags,                    NxU32, wheelFlags )
  };

//=============================+=====================================+=
                                EndNamespace

