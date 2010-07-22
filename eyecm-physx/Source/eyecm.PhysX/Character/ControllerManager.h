//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "eyecmPhysX.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Controller;
ref class                       BoxControllerDesc;
ref class                       CapsuleControllerDesc;
ref class                       BoxController;
ref class                       CapsuleController;

//=============================+=====================================+=
public ref class                ControllerManager:                    public giNxProxy<NxControllerManager>
  {
    internal:
      ControllerManager(Physics^);
      ~ControllerManager();
      !ControllerManager();
      
    internal:
      giNxRegisteredObject<ControllerManager>^ First;

    private:
      typedef                   ReadOnlyCollection<Controller^>       ControllerList;
      //
      ControllerList^           controllerList;
      
    public:
      property ControllerList^  Controllers
        {
          ControllerList^       get()                                 { return controllerList; }
        }

      BoxController^            CreateController(Scene^ Scene, BoxControllerDesc^ Desc);
      CapsuleController^        CreateController(Scene^ Scene, CapsuleControllerDesc^ Desc);
      
      void                      UpdateControllers()                   { GetNx()->updateControllers(); }
      void                      PurgeControllers();
  };

//=============================+=====================================+=
                                EndNamespace

