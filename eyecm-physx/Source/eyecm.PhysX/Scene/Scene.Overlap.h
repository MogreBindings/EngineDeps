//=============================+=====================================+=
//public ref class                Scene:                                public giNxObject<NxScene, Scene, giNxRegisteredObject<Physics> >
//  {

    private:
      typedef                   ThisNamespace::Sphere                 giSphere;
      typedef                   ThisNamespace::Capsule                giCapsule;

    public:
      unsigned                  OverlapSphereShapes(giSphere Sphere, ShapesTypes Types, IUserEntityReport<Shape^>^ Report)
        {
          return OverlapSphereShapes( Sphere, Types, Report, 0xFFFFFFFF );
        }

      unsigned                  OverlapSphereShapes(giSphere Sphere, ShapesTypes Types, IUserEntityReport<Shape^>^ Report, unsigned ActiveGroups);


      unsigned                  OverlapAABBShapes(AxisAlignedBox AABox, ShapesTypes Types, IUserEntityReport<Shape^>^ Report)
        {
          return OverlapAABBShapes( AABox, Types, Report, 0xFFFFFFFF );
        }

      unsigned                  OverlapAABBShapes(AxisAlignedBox AABox, ShapesTypes Types, IUserEntityReport<Shape^>^ Report, unsigned ActiveGroups);


      unsigned                  OverlapOBBShapes(OrientedBox Box, ShapesTypes Types, IUserEntityReport<Shape^>^ Report)
        {
          return OverlapOBBShapes( Box, Types, Report, 0xFFFFFFFF );
        }

      unsigned                  OverlapOBBShapes(OrientedBox Box, ShapesTypes Types, IUserEntityReport<Shape^>^ Report, unsigned ActiveGroups);


      unsigned                  OverlapCapsuleShapes(giCapsule Capsule, ShapesTypes Types, IUserEntityReport<Shape^>^ Report)
        {
          return OverlapCapsuleShapes( Capsule, Types, Report, 0xFFFFFFFF );
        }

      unsigned                  OverlapCapsuleShapes(giCapsule Capsule, ShapesTypes Types, IUserEntityReport<Shape^>^ Report, unsigned ActiveGroups);

    public:
      bool                      CheckOverlapSphere(giSphere Sphere)
        {
          return CheckOverlapSphere( Sphere, ShapesTypes::All, 0xFFFFFFFF );
        }

      bool                      CheckOverlapSphere(giSphere Sphere, ShapesTypes Types)
        {
          return CheckOverlapSphere( Sphere, Types, 0xFFFFFFFF );
        }

      bool                      CheckOverlapSphere(giSphere Sphere, ShapesTypes Types, unsigned ActiveGroups)
        {
          return ptr->checkOverlapSphere( ToNx( Sphere ), static_cast<NxShapesType>( Types ), ActiveGroups );
        }


      bool                      CheckOverlapAABB(AxisAlignedBox AABox)
        {
          return CheckOverlapAABB( AABox, ShapesTypes::All, 0xFFFFFFFF );
        }

      bool                      CheckOverlapAABB(AxisAlignedBox AABox, ShapesTypes Types)
        {
          return CheckOverlapAABB( AABox, Types, 0xFFFFFFFF );
        }

      bool                      CheckOverlapAABB(AxisAlignedBox AABox, ShapesTypes Types, unsigned ActiveGroups)
        {
          return ptr->checkOverlapAABB( ToNx( AABox ), static_cast<NxShapesType>( Types ), ActiveGroups );
        }


      bool                      CheckOverlapOBB(OrientedBox Box)
        {
          return CheckOverlapOBB( Box, ShapesTypes::All, 0xFFFFFFFF );
        }

      bool                      CheckOverlapOBB(OrientedBox Box, ShapesTypes Types)
        {
          return CheckOverlapOBB( Box, Types, 0xFFFFFFFF );
        }

      bool                      CheckOverlapOBB(OrientedBox Box, ShapesTypes Types, unsigned ActiveGroups)
        {
          return ptr->checkOverlapOBB( ToNx( Box ), static_cast<NxShapesType>( Types ), ActiveGroups );
        }


      bool                      CheckOverlapCapsule(giCapsule Capsule)
        {
          return CheckOverlapCapsule( Capsule, ShapesTypes::All, 0xFFFFFFFF );
        }

      bool                      CheckOverlapCapsule(giCapsule Capsule, ShapesTypes Types)
        {
          return CheckOverlapCapsule( Capsule, Types, 0xFFFFFFFF );
        }

      bool                      CheckOverlapCapsule(giCapsule Capsule, ShapesTypes Types, unsigned ActiveGroups)
        {
          return ptr->checkOverlapCapsule( ToNx( Capsule ), static_cast<NxShapesType>( Types ), ActiveGroups );
        }

//  };

//=============================+=====================================+=
