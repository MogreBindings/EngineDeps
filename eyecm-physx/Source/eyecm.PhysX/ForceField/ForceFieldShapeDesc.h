//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"
#include                       "nxarraylist.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Physics;
ref class                       ConvexMesh;

NxConvexMesh*                   GetNxConvexMesh(ConvexMesh^ v);

//=============================+=====================================+= // TODO: has name
public ref struct               ForceFieldShapeDesc:                  public giNxProxyData<NxForceFieldShapeDesc>
  {
    internal:
      ForceFieldShapeDesc(NxForceFieldShapeDesc& data): BaseType( data ) { }

    internal:
      static 
      ForceFieldShapeDesc^      Wrap(Physics^, NxForceFieldShapeDesc& data);

    public:
      ~ForceFieldShapeDesc() { }
      
      DefValidDefault
      
    internal:
      ForceFieldShapeDesc(NxForceFieldShapeDesc* subclassdata): BaseType( subclassdata ) { }

    public:
      DefPx( Matrix4x4,         Pose,                                 pose )
      property ShapeTypes       Type
        {
          ShapeTypes            get()                                 { return static_cast<ShapeTypes>( data->getType() ); }
        }
  };

//=============================+=====================================+=
#define                         DefForceFieldDesc( type ) \
    internal: \
      inline static \
      type##ForceFieldShapeDesc^ Wrap(Physics^ physics, Nx##type##ForceFieldShapeDesc& desc) { return gcnew type##ForceFieldShapeDesc( physics, desc ); } \
      \
      DefRecastData( Nx##type##ForceFieldShapeDesc, ForceFieldShapeDesc ) \
      \
    public: \
      type##ForceFieldShapeDesc(type##ForceFieldShapeDesc^ Original): \
        ForceFieldShapeDesc( Original->IsDisposed ? new Nx##type##ForceFieldShapeDesc : new Nx##type##ForceFieldShapeDesc( *Original->data ) ) \
        { \
          DefThrowOnDisposed( Original, type##ForceFieldShapeDesc, "clone" ) \
          CopyCustom( Original ); \
          PostSet(); \
        } \
      DefCloneCopyFuncsOnly( type##ForceFieldShapeDesc, DefNothing ) \
      DefValidDefaultNew

//=============================+=====================================+=
public ref struct               BoxForceFieldShapeDesc:               public ForceFieldShapeDesc
  {
    private: 
      BoxForceFieldShapeDesc(Physics^, NxBoxForceFieldShapeDesc& data): ForceFieldShapeDesc( data ) { }

    internal:
      DefForceFieldDesc(        Box )

    public:
      BoxForceFieldShapeDesc(): ForceFieldShapeDesc( new NxBoxForceFieldShapeDesc ) { }
      ~BoxForceFieldShapeDesc() { }
      
    public:
      DefPx( Vector3,           Dimensions,                           dimensions )
  };

//=============================+=====================================+=
public ref struct               CapsuleForceFieldShapeDesc:           public ForceFieldShapeDesc
  {
    private: 
      CapsuleForceFieldShapeDesc(Physics^, NxCapsuleForceFieldShapeDesc& data): ForceFieldShapeDesc( data ) { }

    internal:
      DefForceFieldDesc(        Capsule )
      
    public:
      CapsuleForceFieldShapeDesc(): ForceFieldShapeDesc( new NxCapsuleForceFieldShapeDesc ) { }
      ~CapsuleForceFieldShapeDesc() { }

    public:
      DefP0( float,             Radius,                               radius )
      DefP0( float,             Height,                               height )
  };

//=============================+=====================================+=
public ref struct               ConvexForceFieldShapeDesc:            public ForceFieldShapeDesc
  {
    private: 
      ConvexForceFieldShapeDesc(Physics^, NxConvexForceFieldShapeDesc&);

    internal:
      DefForceFieldDesc(        Convex )
      
      typedef                   ThisNamespace::ConvexMesh             giConvexMesh;
      
      giConvexMesh^             convexmesh;
      
      void                      CopyCustom(ConvexForceFieldShapeDesc^ other) { this->ConvexMesh = other->ConvexMesh; }
      
    public:
      ConvexForceFieldShapeDesc(): ForceFieldShapeDesc( new NxConvexForceFieldShapeDesc ) { }
      ~ConvexForceFieldShapeDesc() { convexmesh = nullptr; }

    public:
      property giConvexMesh^    ConvexMesh
        {
          giConvexMesh^         get()                                 { return convexmesh; }
          void                  set(giConvexMesh^ v)                  { data->meshData = GetNxConvexMesh( convexmesh = v ); }
        }
  };

//=============================+=====================================+=
public ref struct               SphereForceFieldShapeDesc:            public ForceFieldShapeDesc
  {
    private: 
      SphereForceFieldShapeDesc(Physics^, NxSphereForceFieldShapeDesc& data): ForceFieldShapeDesc( data ) { }

    internal:
      DefForceFieldDesc(        Sphere )
      
    public:
      SphereForceFieldShapeDesc(): ForceFieldShapeDesc( new NxSphereForceFieldShapeDesc ) { }
      ~SphereForceFieldShapeDesc() { }

    public:
      DefP0( float,             Radius,                               radius )
  };

//=============================+=====================================+=
                                EndNamespace

