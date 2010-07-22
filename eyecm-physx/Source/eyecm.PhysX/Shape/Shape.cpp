//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Shape.h"
#include                       "Actor.h"
#include                       "RaycastObjects.h"

//=============================+=====================================+=
                                Shape::Shape(giActor^ Actor, NxShape* ptr):
                                  giNxNamedObject( ptr )
  {
    Register( Actor );

    flags = gcnew ProxyFlags( ptr );
  }

//=============================+=====================================+=
                                Shape::~Shape()
  {
    NxActor* actor = Owner->ptr;

    delete flags; flags = nullptr;

    Unregister();

    if( !actor ) return;  // actor is disposing, no need to release explicitly

    actor->releaseShape( *ptr );
  }

//=============================+=====================================+=
Shape^                          Shape::Wrap(giActor^ actor, NxShape* ptr, ShapeDesc^ Desc)
  {
    #define DefShapeWrap( type ) if( Nx##type##Shape* shape = ptr->is##type() )  return type##Shape::Wrap( actor, shape, static_cast<type##ShapeDesc^>( Desc ) );

    DefShapeWrap(               Box )
    DefShapeWrap(               Sphere )
    DefShapeWrap(               Capsule )
    DefShapeWrap(               Plane )
    DefShapeWrap(               TriangleMesh )
    DefShapeWrap(               HeightField )
    DefShapeWrap(               Wheel )

    if( NxConvexShape* convex = ptr->isConvexMesh() ) return ConvexShape::Wrap( actor, convex, static_cast<ConvexShapeDesc^>( Desc ) );

    return gcnew Shape( actor, ptr );
  }

//=============================+=====================================+=
Shape^                          Shape::CastSafe(NxShape& nx)
  {
    try
    {
      return Shape::CastUserDataOrNull( nx.userData );
    }
    catch( ... )
    {
    }
    
    // NxShape's user data is invalid  

    // probably a character controller' actor shape
    NxActor&  ac = nx.getActor();
    void*     ud = const_cast<char*>( ac.getName() );
    //
    try
    {
      return Shape::CastUserDataOrNull( ud );
    }
    catch( ... )
    {
      System::Diagnostics::Debug::WriteLine( "Don't give names to character controller's actors!" );
    }
    //
    return nullptr;
  }

//=============================+=====================================+=
Shape^                          Shape::CastAny(NxShape* ptr)
  {
    if( !ptr ) return nullptr;

    if( NxBoxShape*          box     = ptr->isBox()          )  return BoxShape::Cast         ( box     );
    if( NxSphereShape*       sphere  = ptr->isSphere()       )  return SphereShape::Cast      ( sphere  );
    if( NxCapsuleShape*      capsule = ptr->isCapsule()      )  return CapsuleShape::Cast     ( capsule );
    if( NxPlaneShape*        plane   = ptr->isPlane()        )  return PlaneShape::Cast       ( plane   );
    if( NxTriangleMeshShape* mesh    = ptr->isTriangleMesh() )  return TriangleMeshShape::Cast( mesh    );
    if( NxConvexShape*       convex  = ptr->isConvexMesh()   )  return ConvexShape::Cast      ( convex  );
    if( NxHeightFieldShape*  hfield  = ptr->isHeightField()  )  return HeightFieldShape::Cast ( hfield  );
    if( NxWheelShape*        wheel   = ptr->isWheel()        )  return WheelShape::Cast       ( wheel   );

    return Shape::Cast( ptr );
  }

//=============================+=====================================+=
Shape^                          Shape::Is(ShapeTypes Type)
  {
    void* res = ptr->is( static_cast<NxShapeType>( Type ) );
    return res == 0 ? nullptr : Cast( static_cast<NxShape*>( res ) );
  }

//=============================+=====================================+=
bool                            Shape::Raycast(Line Ray, float MaxDistance, RaycastBits HintFlags, [Out] RaycastHit% Hit, bool FirstHit)
  {
    NxRaycastHit hit;
    bool         result = ptr->raycast( ToNx( Ray ), MaxDistance, static_cast<NxU32>( HintFlags ), hit, FirstHit );

    Hit = RaycastHit( hit );
    return result;
  }


//=============================+=====================================+=
Shape^                          Actor::CreateShape(ShapeDesc^ Desc)
  {
    NxShape* shapeptr = ptr->createShape( *Desc->data );
    if( !shapeptr ) return nullptr;

    return Shape::Wrap( this, shapeptr, Desc );
  }
