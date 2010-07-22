//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Scene.h"
#include                       "Joint.h"
#include                       "Actor.h"
#include                       "nxlist.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public interface class          IUserNotify
  {
    bool                        OnJointBreak(float BreakingImpulse, Joint^ Joint);
    void                        OnWake(ReadOnlyCollection<Actor^>^ Actors);
    void                        OnSleep(ReadOnlyCollection<Actor^>^ Actors);
  };

//=============================+=====================================+=
class                           giNxUserNotify:                       public NxUserNotify
  {
    public:
      gcroot<IUserNotify^>      iface;

    public:
      giNxUserNotify(IUserNotify^ iface) { this->iface = iface; }
      ~giNxUserNotify() { this->iface = nullptr; }

    private:
      bool                      onJointBreak(NxReal breakingImpulse, NxJoint& brokenJoint)
        {
          return iface->OnJointBreak( breakingImpulse, Joint::Cast( &brokenJoint ) );
        }

      void                      onWake(NxActor** actors, NxU32 count)
        {
          giNxStaticList<Actor, NxActor*>^ list = gcnew giNxStaticList<Actor, NxActor*>( actors, count );
          iface->OnWake( list );
          delete list;
        }

      void                      onSleep(NxActor** actors, NxU32 count)
        {
          giNxStaticList<Actor, NxActor*>^ list = gcnew giNxStaticList<Actor, NxActor*>( actors, count );
          iface->OnSleep( list );
          delete list;
        }
  };

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
DefSceneReportGetSet(           UserNotify )