//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "ShapeDesc.h"
#include                       "userentityreport.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Actor;
ref class                       CCDSkeleton;
value struct                    RaycastHit;

class                           giNxUserWheelContactModify;

//=============================+=====================================+=
public ref class                Shape:                                public giNxNamedObject<NxShape, Shape, giNxRegisteredObject<Actor> >
  {
    internal:
      typedef                   ThisNamespace::Actor                  giActor;
      typedef                   ThisNamespace::CCDSkeleton            giCCDSkeleton;
      typedef                   ThisNamespace::Sphere                 giSphere;
      typedef                   ThisNamespace::OrientedBox            giOBB;
      typedef                   ThisNamespace::AxisAlignedBox         giAABB;
      typedef                   ThisNamespace::Capsule                giCaps;

      Shape(Actor^, NxShape*);

    public:
      ~Shape();

    internal:
      static Shape^             Wrap(giActor^, NxShape*, ShapeDesc^);
      static Shape^             CastAny(NxShape* ptr);
      static Shape^             CastSafe(NxShape& nx);

    public:
      DefMc( unsigned,          Group,              NxCollisionGroup, Group )
      DefMc( unsigned,          MaterialIndex,       NxMaterialIndex, Material )
      DefM0( float,             SkinWidth,                            SkinWidth )

      DefMc( CompartmentTypes,  NonInteractingCompartmentTypes, NxU32, NonInteractingCompartmentTypes )

      DefMx( Matrix4x4,         LocalPose,                            LocalPose )
      DefMx( Matrix3x3,         LocalOrientation,                     LocalOrientation )
      DefMx( Vector3,           LocalPosition,                        LocalPosition )
      DefMx( Matrix4x4,         GlobalPose,                           GlobalPose )
      DefMx( Matrix3x3,         GlobalOrientation,                    GlobalOrientation )
      DefMx( Vector3,           GlobalPosition,                       GlobalPosition )

      property ShapeTypes       Type
        {
          ShapeTypes            get()                                 { return static_cast<ShapeTypes>( ptr->getType() ); }
        }

      property giActor^         Actor
        {
          giActor^              get()                                 { return Owner; }
        }

      property giCCDSkeleton^   CCDSkeleton                           { giCCDSkeleton^ get(); void set(giCCDSkeleton^); }

      Shape^                    Is(ShapeTypes Type);

      #include                 "Shape.Flags.h"

    public:
      bool                      CheckOverlapSphere(giSphere Sphere)   { return ptr->checkOverlapSphere( ToNx( Sphere ) ); }
      bool                      CheckOverlapOBB(giOBB Box)            { return ptr->checkOverlapOBB( ToNx( Box ) ); }
      bool                      CheckOverlapOBB(giAABB AABox)         { return ptr->checkOverlapAABB( ToNx( AABox ) ); }
      bool                      CheckOverlapCapsule(giCaps Capsule)   { return ptr->checkOverlapCapsule( ToNx( Capsule ) ); }

      bool                      Raycast(Line Ray, float MaxDistance, RaycastBits HintFlags, [Out] RaycastHit% Hit, bool FirstHit);
  };

//=============================+=====================================+=
#define                         DefShapeX( type, init ) \
    internal: \
                                DefRecastPtr( Nx##type##Shape, Shape ) \
    private: \
      type##Shape(giActor^ actor, Nx##type##Shape* ptr, type##ShapeDesc^ Desc): Shape( actor, ptr ) { Desc; init } \
    internal: \
      inline static Shape^      Wrap(giActor^ actor, Nx##type##Shape* shape, type##ShapeDesc^ Desc) { return gcnew type##Shape( actor, shape, Desc ); } \
    public: \
                                DefSaveToDesc( type##Shape )


//=============================+=====================================+=
#define                         DefShape( name )                      DefShapeX( name, {} )
#define                         DefShapeI( name )                     DefShapeX( name, Init( Desc ); )

//=============================+=====================================+=
public ref class                BoxShape:                             public Shape
  {
      DefShape(                 Box )

    public:
      DefMx( Vector3,           Dimensions,                           Dimensions )

      property OrientedBox      WorldOBB
        {
          OrientedBox           get()                                 { NxBox box; ptr->getWorldOBB( box ); return FromNx( box ); }
        }
  };

//=============================+=====================================+=
public ref class                SphereShape:                          public Shape
  {
      DefShape(                 Sphere )

    public:
      DefM0( float,             Radius,                               Radius )

      property Sphere           WorldSphere
        {
          Sphere                get()                                 { NxSphere sphere; ptr->getWorldSphere( sphere ); return FromNx( sphere ); }
        }
  };

//=============================+=====================================+=
public ref class                CapsuleShape:                         public Shape
  {
      DefShape(                 Capsule )

    public:
      DefM0( float,             Radius,                               Radius )
      DefM0( float,             Height,                               Height )

    public:
      void                      SetDimensions(float Radius, float Height) { ptr->setDimensions( Radius, Height ); }
  };

//=============================+=====================================+=
public ref class                PlaneShape:                           public Shape
  {
      DefShape(                 Plane )

      typedef                   ThisNamespace::Plane                  giPlane;

    public:
       property Vector3         Normal
        {
          Vector3               get()                                 { return FromNx( ptr->getPlane().normal ); }
          void                  set(Vector3 n)                        { ptr->setPlane( ToNx( n ), ptr->getPlane().d ); }
        }

      property float            Distance
        {
          float                 get()                                 { return ptr->getPlane().d; }
          void                  set(float d)                          { ptr->setPlane( ptr->getPlane().normal, d ); }
        }

      property giPlane          Plane
        {
          giPlane               get()                                 { return FromNx( ptr->getPlane() ); }
          void                  set(giPlane v)                        { NxPlane plane = ToNx( v ); ptr->setPlane( plane.normal, plane.d ); }
        }
  };

//=============================+=====================================+=
public ref struct               TriangleMeshShape:                    public Shape
  {
      DefShape(                 TriangleMesh )

    internal:
      typedef                   ThisNamespace::TriangleMesh           giTriangleMesh;

    public:
      property giTriangleMesh^  TriangleMesh
        {
          giTriangleMesh^       get();
        }

    public:
      unsigned                  GetTriangle([Out] Triangle% Result, [Out] array<Triangle>^% Edges, [Out] array<TriangleFlags>^% Flags, unsigned TriangleIndex, bool WorldSpaceTranslation, bool WorldSpaceRotation);
      bool                      OverlapAABBTriangles(AxisAlignedBox AABox, QueryFlags Flags, IUserEntityReport<unsigned>^ Report);
  };

//=============================+=====================================+=
public ref struct               ConvexShape:                          public Shape
  {
      DefShape(                 Convex )

    internal:
      typedef                   ThisNamespace::ConvexMesh             giConvexMesh;

    public:
      property giConvexMesh^    ConvexMesh
        {
          giConvexMesh^         get();
        }
  };

//=============================+=====================================+=
public ref struct               HeightFieldShape:                     public Shape
  {
      DefShape(                 HeightField )

    internal:
      typedef                   ThisNamespace::HeightField            giHeightField;

    public:
      property giHeightField^   HeightField
        {
          giHeightField^        get();
        }

      DefM0( float,             HeightScale,                          HeightScale )
      DefM0( float,             RowScale,                             RowScale )
      DefM0( float,             ColumnScale,                          ColumnScale )

      unsigned                  GetTriangle([Out] Triangle% Result, [Out] array<Triangle>^% Edges, [Out] array<TriangleFlags>^% Flags, unsigned TriangleIndex, bool WorldSpaceTranslation, bool WorldSpaceRotation);
      bool                      OverlapAABBTriangles(AxisAlignedBox AABox, QueryFlags Flags, IUserEntityReport<unsigned>^ Report);

      bool                      IsShapePointOnHeightField(float X, float Z )  { return ptr->isShapePointOnHeightField( X, Z ); }
      float                     GetHeightAtShapePoint(float X, float Z)       { return ptr->getHeightAtShapePoint( X, Z ); }
      unsigned                  GetMaterialAtShapePoint(float X, float Z)     { return ptr->getMaterialAtShapePoint( X, Z ); }
      Vector3                   GetNormalAtShapePoint(float X, float Z)       { return FromNx( ptr->getNormalAtShapePoint( X, Z ) ); }
      Vector3                   GetSmoothNormalAtShapePoint(float X, float Z) { return FromNx( ptr->getSmoothNormalAtShapePoint( X, Z ) ); }
  };

//=============================+=====================================+=
public ref class                WheelShape:                           public Shape
  {
      DefShapeI(                Wheel )

    private:
      //SpringDesc^               suspension;
      void                      OnSuspensionChanged(NxSpringDesc* data)       { ptr->setSuspension( *data ); }

      //TireFunctionDesc^         longitudal;
      void                      OnLongitudalTireForceFunctionChanged(NxTireFunctionDesc* data) { ptr->setLongitudalTireForceFunction( *data ); }

      //TireFunctionDesc^         lateral;
      void                      OnLateralTireForceFunctionChanged(NxTireFunctionDesc* data)    { ptr->setLateralTireForceFunction( *data ); }

      giNxUserWheelContactModify* callback;

      void                      Init(WheelShapeDesc^);

    public:
      ~WheelShape();
      !WheelShape();

    public:
                                //DefProxyGetSetm( TireFunctionDesc, LongitudalTireForceFunction, longitudal )
                                //DefProxyGetSetm( TireFunctionDesc, LateralTireForceFunction, lateral )
                                //DefProxyGetSetm( SpringDesc, Suspension, suspension )
                                DefProxyGetSetm( WheelShape, TireFunctionDesc, LongitudalTireForceFunction )
                                DefProxyGetSetm( WheelShape, TireFunctionDesc, LateralTireForceFunction )
                                DefProxyGetSetm( WheelShape, SpringDesc, Suspension )

        DefM0( float,           Radius,                               Radius )
        DefM0( float,           SuspensionTravel,                     SuspensionTravel )
        DefM0( float,           InverseWheelMass,                     InverseWheelMass )
        DefM0( float,           MotorTorque,                          MotorTorque )
        DefM0( float,           BrakeTorque,                          BrakeTorque )
        DefM0( float,           SteerAngle,                           SteerAngle )
        DefM0( float,           AxleSpeed,                            AxleSpeed )
        DefMc( WheelShapeFlags, WheelFlags,                    NxU32, WheelFlags )

      property
      IUserWheelContactModify^  WheelContactModify                    { IUserWheelContactModify^  get(); void set(IUserWheelContactModify^ ); }
  };

//=============================+=====================================+=
                                EndNamespace

