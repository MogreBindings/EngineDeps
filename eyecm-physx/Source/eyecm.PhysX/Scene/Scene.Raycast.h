//=============================+=====================================+=
//public ref class                Scene:                                public giNxObject<NxScene, Scene, giNxRegisteredObject<Physics> >
//  {

    public:

      //-------------------------------------------------------------
      //-------------------------------------------------------------
      //-------------------------------------------------------------

      bool                      RaycastAnyBounds(Line Ray, ShapesTypes Which)
        {
          return RaycastAnyBounds( Ray, Which, 0xFFFFFFFF, NX_MAX_F32 );
        }

      bool                      RaycastAnyBounds(Line Ray, ShapesTypes Which, unsigned Groups)
        {
          return RaycastAnyBounds( Ray, Which, Groups, NX_MAX_F32 );
        }

      bool                      RaycastAnyBounds(Line Ray, ShapesTypes Which, unsigned Groups, float MaxDistance);


      //-------------------------------------------------------------
      //-------------------------------------------------------------
      //-------------------------------------------------------------

      bool                      RaycastAnyShape(Line Ray, ShapesTypes Which)
        {
          return RaycastAnyShape( Ray, Which, 0xFFFFFFFF, NX_MAX_F32 );
        }

      bool                      RaycastAnyShape(Line Ray, ShapesTypes Which, unsigned Groups)
        {
          return RaycastAnyShape( Ray, Which, Groups, NX_MAX_F32 );
        }

      bool                      RaycastAnyShape(Line Ray, ShapesTypes Which, unsigned Groups, float MaxDistance);


      //-------------------------------------------------------------
      //-------------------------------------------------------------
      //-------------------------------------------------------------

      Shape^                    RaycastClosestShape(Line Ray, ShapesTypes Which, [Out] RaycastHit% Hit)
        {
          return RaycastClosestShape( Ray, Which, Hit, 0xFFFFFFFF, NX_MAX_F32 );
        }

      Shape^                    RaycastClosestShape(Line Ray, ShapesTypes Which, [Out] RaycastHit% Hit, unsigned Groups)
        {
          return RaycastClosestShape( Ray, Which, Hit, Groups, NX_MAX_F32 );
        }

      Shape^                    RaycastClosestShape(Line Ray, ShapesTypes Which, [Out] RaycastHit% Hit, unsigned Groups, float MaxDistance);


      //-------------------------------------------------------------
      //-------------------------------------------------------------
      //-------------------------------------------------------------

      Shape^                    RaycastClosestBounds(Line Ray, ShapesTypes Which, [Out] RaycastHit% Hit)
        {
          return RaycastClosestBounds( Ray, Which, Hit, 0xFFFFFFFF, NX_MAX_F32 );
        }

      Shape^                    RaycastClosestBounds(Line Ray, ShapesTypes Which, [Out] RaycastHit% Hit, unsigned Groups)
        {
          return RaycastClosestBounds( Ray, Which, Hit, Groups, NX_MAX_F32 );
        }

      Shape^                    RaycastClosestBounds(Line Ray, ShapesTypes Which, [Out] RaycastHit% Hit, unsigned Groups, float MaxDistance);

      //-------------------------------------------------------------
      //-------------------------------------------------------------
      //-------------------------------------------------------------

      unsigned                  RaycastAllShapes(Line Ray, IRaycastReport^ Report, ShapesTypes Which)
        {
          return RaycastAllShapes( Ray, Report, Which, 0xFFFFFFFF, NX_MAX_F32, RaycastBits::All );
        }

      unsigned                  RaycastAllShapes(Line Ray, IRaycastReport^ Report, ShapesTypes Which, unsigned Groups)
        {
          return RaycastAllShapes( Ray, Report, Which, Groups, NX_MAX_F32, RaycastBits::All );
        }

      unsigned                  RaycastAllShapes(Line Ray, IRaycastReport^ Report, ShapesTypes Which, unsigned Groups, float MaxDistance)
        {
          return RaycastAllShapes( Ray, Report, Which, Groups, MaxDistance, RaycastBits::All );
        }

      unsigned                  RaycastAllShapes(Line Ray, IRaycastReport^ Report, ShapesTypes Which, unsigned Groups, float MaxDistance, RaycastBits Flags);


      //-------------------------------------------------------------
      //-------------------------------------------------------------
      //-------------------------------------------------------------

      unsigned                  RaycastAllBounds(Line Ray, IRaycastReport^ Report, ShapesTypes Which)
        {
          return RaycastAllShapes( Ray, Report, Which, 0xFFFFFFFF, NX_MAX_F32, RaycastBits::All );
        }

      unsigned                  RaycastAllBounds(Line Ray, IRaycastReport^ Report, ShapesTypes Which, unsigned Groups)
        {
          return RaycastAllShapes( Ray, Report, Which, Groups, NX_MAX_F32, RaycastBits::All );
        }

      unsigned                  RaycastAllBounds(Line Ray, IRaycastReport^ Report, ShapesTypes Which, unsigned Groups, float MaxDistance)
        {
          return RaycastAllShapes( Ray, Report, Which, Groups, MaxDistance, RaycastBits::All );
        }

      unsigned                  RaycastAllBounds(Line Ray, IRaycastReport^ Report, ShapesTypes Which, unsigned Groups, float MaxDistance, RaycastBits Flags);
//  };

//=============================+=====================================+=
