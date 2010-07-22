//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public ref class                RemoteDebugger:                       public giNxProxy<NxRemoteDebugger>
  {
    internal:
      typedef                   ThisNamespace::Physics                giPhysics;

    internal:
      RemoteDebugger(NxRemoteDebugger *ptr): giNxProxy( ptr )
        {
        }

    public:
      bool                      Connect(String ^Host)                 { return Connect( Host, NX_DBG_DEFAULT_PORT ); }
      bool                      Connect(String ^Host, int Port)       { return Connect( Host, Port, DebuggerEventMasks::Everything ); }
      bool                      Connect(String ^Host, int Port, DebuggerEventMasks mask)
        {
          const char* host = ToNx( Host );
          //
          data->connect( host, Port, (NxU32)mask );
          //
          delete[] host;
          //
          return IsConnected;
        }

      void                      Disconnect()                          { data->disconnect(); }
      
      property bool             IsConnected
        {
          bool                  get()                                 { return data->isConnected(); }
        }

  };

//=============================+=====================================+=
                                EndNamespace

