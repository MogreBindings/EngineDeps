//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "nxlist.h"
#include                       "userentityreport.h"
#include                       "Scene.h"
#include                       "Shape.h"

//=============================+=====================================+=
unsigned                        Scene::OverlapSphereShapes(Scene::giSphere Sphere, ShapesTypes Types, IUserEntityReport<Shape^>^ Report, unsigned ActiveGroups)
  {
    giUserEntityReport<Shape, NxShape*> report( Report );
    return ptr->overlapSphereShapes( ToNx( Sphere ), static_cast<NxShapesType>( Types ), 0, 0, &report, ActiveGroups );
  }

//=============================+=====================================+=
unsigned                        Scene::OverlapAABBShapes(AxisAlignedBox AABox, ShapesTypes Types, IUserEntityReport<Shape^>^ Report, unsigned ActiveGroups)
  {
    giUserEntityReport<Shape, NxShape*> report( Report );
    return ptr->overlapAABBShapes( ToNx( AABox ), static_cast<NxShapesType>( Types ), 0, 0, &report, ActiveGroups );
  }

//=============================+=====================================+=
unsigned                        Scene::OverlapOBBShapes(OrientedBox Box, ShapesTypes Types, IUserEntityReport<Shape^>^ Report, unsigned ActiveGroups)
  {
    giUserEntityReport<Shape, NxShape*> report( Report );
    return ptr->overlapOBBShapes( ToNx( Box ), static_cast<NxShapesType>( Types ), 0, 0, &report, ActiveGroups );
  }

//=============================+=====================================+=
unsigned                        Scene::OverlapCapsuleShapes(giCapsule Capsule, ShapesTypes Types, IUserEntityReport<Shape^>^ Report, unsigned ActiveGroups)
  {
    giUserEntityReport<Shape, NxShape*> report( Report );
    return ptr->overlapCapsuleShapes( ToNx( Capsule ), static_cast<NxShapesType>( Types ), 0, 0, &report, ActiveGroups );
  }
