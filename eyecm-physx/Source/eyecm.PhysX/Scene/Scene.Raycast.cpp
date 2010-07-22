//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Scene.h"
#include                       "RaycastObjects.h"
#include                       "Shape.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public interface class          IRaycastReport
  {
      bool                      OnHit(RaycastHit Hit);
  };

//=============================+=====================================+=
class                           giUserRayCastReport:                  public NxUserRaycastReport
  {
    private:
      typedef                   IRaycastReport                        TReport;
      typedef                   gcroot<TReport^>                      TReportRef;

      TReportRef                report;

    public:
      giUserRayCastReport(TReport^ report): report( report ) {}
      ~giUserRayCastReport() { report = nullptr; }

      bool                      onHit(const NxRaycastHit& hits)       { return report->OnHit( RaycastHit( hits ) ); }
  };

//=============================+=====================================+=
                                EndNamespace


//=============================+=====================================+=
bool                            Scene::RaycastAnyBounds(Line Ray, ShapesTypes Which, unsigned Groups, float MaxDistance)
  {
    return ptr->raycastAnyShape( ToNx( Ray ), static_cast<NxShapesType>( Which ), Groups, MaxDistance );
  }

//=============================+=====================================+=
bool                            Scene::RaycastAnyShape(Line Ray, ShapesTypes Which, unsigned Groups, float MaxDistance)
  {
    return ptr->raycastAnyShape( ToNx( Ray ), static_cast<NxShapesType>( Which ), Groups, MaxDistance );
  }

//=============================+=====================================+=
Shape^                          Scene::RaycastClosestShape(Line Ray, ShapesTypes Which, [Out] RaycastHit% Hit, unsigned Groups, float MaxDistance)
  {
    NxRaycastHit hit;
    Shape^       result = Shape::CastOrNull( ptr->raycastClosestShape( ToNx( Ray ), static_cast<NxShapesType>( Which ), hit, Groups, MaxDistance ) );

    Hit = RaycastHit( hit );
    return result;
  }

//=============================+=====================================+=
Shape^                          Scene::RaycastClosestBounds(Line Ray, ShapesTypes Which, [Out] RaycastHit% Hit, unsigned Groups, float MaxDistance)
  {
    NxRaycastHit hit;
    Shape^       result = Shape::CastOrNull( ptr->raycastClosestBounds( ToNx( Ray ), static_cast<NxShapesType>( Which ), hit, Groups, MaxDistance  ) );

    Hit = RaycastHit( hit );
    return result;
  }

//=============================+=====================================+=
unsigned                        Scene::RaycastAllShapes(Line Ray, IRaycastReport^ Report, ShapesTypes Which, unsigned Groups, float MaxDistance, RaycastBits Flags)
  {
    giUserRayCastReport report( Report );
    return ptr->raycastAllShapes( ToNx( Ray ), report, static_cast<NxShapesType>( Which ), Groups, MaxDistance, static_cast<NxU32>( Flags ) );
  }

//=============================+=====================================+=
unsigned                        Scene::RaycastAllBounds(Line Ray, IRaycastReport^ Report, ShapesTypes Which, unsigned Groups, float MaxDistance, RaycastBits Flags)
  {
    giUserRayCastReport report( Report );
    return ptr->raycastAllBounds( ToNx( Ray ), report, static_cast<NxShapesType>( Which ), Groups, MaxDistance, static_cast<NxU32>( Flags ) );
  }

