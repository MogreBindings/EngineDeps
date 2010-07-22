//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "ForceFieldDesc.h"
#include                       "ForceFieldShape.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public ref class                BoxForceFieldShape:                   public ForceFieldShape
  {
    internal:
      DefRecastPtr( NxBoxForceFieldShape, ForceFieldShape )
      
    internal:
      BoxForceFieldShape(NxForceFieldShape* ptr): ForceFieldShape( ptr ) { }
      
    public:
      ~BoxForceFieldShape() { }
      
      DefSaveToDesc( BoxForceFieldShape )
      
    public:
      DefMx( Vector3,           Dimensions,                           Dimensions )
  };

//=============================+=====================================+=
public ref class                CapsuleForceFieldShape:               public ForceFieldShape
  {
    internal:
      DefRecastPtr( NxCapsuleForceFieldShape, ForceFieldShape )
      
    internal:
      CapsuleForceFieldShape(NxForceFieldShape* ptr): ForceFieldShape( ptr ) { }
      
    public:
      ~CapsuleForceFieldShape() { }
      
      DefSaveToDesc( CapsuleForceFieldShape )
      
    public:
      DefM0( float,             Radius,                               Radius )
      DefM0( float,             Height,                               Height )
      
    public:
      void                      SetDimensions(float Radius, float Height) { ptr->setDimensions( Radius, Height ); }
  };

//=============================+=====================================+=
public ref class                ConvexForceFieldShape:                public ForceFieldShape
  {
    internal:
      DefRecastPtr( NxConvexForceFieldShape, ForceFieldShape )
      
    internal:
      ConvexForceFieldShape(NxForceFieldShape* ptr): ForceFieldShape( ptr ) { }
      
    public:
      ~ConvexForceFieldShape() { }
      
      DefSaveToDesc( ConvexForceFieldShape )      
  };

//=============================+=====================================+=
public ref class                SphereForceFieldShape:                public ForceFieldShape
  {
    internal:
      DefRecastPtr( NxSphereForceFieldShape, ForceFieldShape )
      
    internal:
      SphereForceFieldShape(NxForceFieldShape* ptr): ForceFieldShape( ptr ) { }
      
    public:
      ~SphereForceFieldShape() { }
      
      DefSaveToDesc( SphereForceFieldShape )
      
    public:
      DefM0( float,             Radius,                               Radius )
  };

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
                                ForceFieldShape::ForceFieldShape(NxType *ptr):
                                  BaseType( ptr )
  {
    giForceFieldShapeGroup^ Group = ForceFieldShapeGroup::Cast( &ptr->getShapeGroup() );
    
    Register( Group );
  }
                                
//=============================+=====================================+=
                                ForceFieldShape::~ForceFieldShape()
  {
    if( !ptr ) return;
    
    NxForceFieldShapeGroup* groupptr = Owner->GetNx();
    
    // TODO: investigate includegroup disposal
    Unregister();
    
    if( !groupptr ) return; // shapegroup is disposing, no need to release explicitly
    groupptr->releaseShape( *GetNx() );
  }

//=============================+=====================================+=
ForceFieldShape^                ForceFieldShape::Wrap(NxType* shapeptr)
  {
    #define DefWrap(type) if( Nx##type##ForceFieldShape* ptr = shapeptr->is##type() ) { return gcnew type##ForceFieldShape( ptr ); }

    DefWrap( Box )
    DefWrap( Capsule )
    DefWrap( Convex )
    DefWrap( Sphere )
    
    return gcnew ForceFieldShape( shapeptr );
  }

//=============================+=====================================+=
ForceFieldShape^                ForceFieldShapeGroup::CreateShape(ForceFieldShapeDesc^ Desc)
  {
    NxForceFieldShape* shapeptr = GetNx()->createShape( *Desc->GetNx() );
    return shapeptr ? ForceFieldShape::Wrap( shapeptr ) : nullptr;
  }

//=============================+=====================================+=
ForceFieldShapeGroup^           ForceFieldShape::ShapeGroup::get()    { return ForceFieldShapeGroup::Cast( &GetNx()->getShapeGroup() ); }
