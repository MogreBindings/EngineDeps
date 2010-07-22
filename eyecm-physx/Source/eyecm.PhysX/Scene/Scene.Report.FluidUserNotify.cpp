//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Fluid.h"
#include                       "FluidEmitter.h"
#include                       "Scene.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public interface class          IFluidUserNotify
  {
    bool                        OnEmitterEvent(FluidEmitter^ Emitter, FluidEmitterEventTypes EventType);
    bool                        OnEvent(Fluid^ Fluid, FluidEventTypes EventType);
  };

//=============================+=====================================+=
class                           giNxFluidUserNotify:                  public NxFluidUserNotify
  {
    public:
      gcroot<IFluidUserNotify^> iface;

    public:
      giNxFluidUserNotify(IFluidUserNotify^ iface) { this->iface = iface; }
      ~giNxFluidUserNotify() { this->iface = nullptr; }

    private:
      bool                      onEmitterEvent(NxFluidEmitter& emitter, NxFluidEmitterEventType eventType)
        {
          return iface->OnEmitterEvent( FluidEmitter::Cast( &emitter ), static_cast<FluidEmitterEventTypes>( eventType ) );
        }

      bool                      onEvent(NxFluid& fluid, NxFluidEventType eventType)
        {
          return iface->OnEvent( Fluid::Cast( &fluid ), static_cast<FluidEventTypes>( eventType ) );
        }
  };

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
DefSceneReportGetSet(           FluidUserNotify )
