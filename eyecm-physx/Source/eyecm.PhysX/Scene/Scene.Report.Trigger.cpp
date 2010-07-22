//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Scene.h"
#include                       "Shape.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public interface class          IUserTriggerReport
  {
    void                        OnTrigger(Shape^ TriggerShape, Shape^ OtherShape, TriggerFlags Status);
  };

//=============================+=====================================+=
class                           giNxUserTriggerReport:                public NxUserTriggerReport
  {
    public:
      gcroot<IUserTriggerReport^> iface;

    public:
      giNxUserTriggerReport(IUserTriggerReport^ iface) { this->iface = iface; }
      ~giNxUserTriggerReport() { this->iface = nullptr; }

    public:
      void                      onTrigger(NxShape& triggerShape, NxShape& otherShape, NxTriggerFlag status)
        {
          IUserTriggerReport^ iface = this->iface;
          if( iface == nullptr ) return;

          //iface->OnTrigger( Shape::CastOrNull( &triggerShape ), Shape::CastOrNull( &otherShape ), static_cast<TriggerFlags>( status ) );
          iface->OnTrigger( Shape::CastSafe( triggerShape ), Shape::CastSafe( otherShape ), static_cast<TriggerFlags>( status ) );
        }
  };

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
DefSceneReportGetSet(           UserTriggerReport )
