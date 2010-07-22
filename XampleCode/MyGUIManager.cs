using System;
using System.IO;

using MyGUI.Managed;

namespace MyGame.Engine.Graphics
{
  /************************************************************************/
  /* mygui manager                                                        */
  /************************************************************************/
  public class MyGUIManager
  {
    //////////////////////////////////////////////////////////////////////////
    private EngineLibrary mLib;
    private Gui mMyGUI;

    /************************************************************************/
    /* constructor                                                          */
    /************************************************************************/
    internal MyGUIManager( EngineLibrary _lib )
    {
      mLib = _lib;
      mMyGUI = null;
    }

    /************************************************************************/
    /* start up mygui manager                                               */
    /************************************************************************/
    internal bool Startup()
    {
      // initialize resource group for mygui
      mLib.ResourceMgr.InitGroup( mLib.EngineCfg.MyGUIResourceGroup );

      // preload resources of mygui resource group
      mLib.ResourceMgr.LoadGroup( mLib.EngineCfg.MyGUIResourceGroup );

      // create and initialize mygui
      string logFileName = Path.Combine( mLib.SharedLib.Paths.SavePath, mLib.EngineCfg.MyGUILogFile );
      Gui.Initialise( mLib.OgreMgr.WindowPtr, mLib.OgreMgr.SceneMgrPtr,
        mLib.EngineCfg.MyGUIConfigFile, mLib.EngineCfg.MyGUIResourceGroup, logFileName );

      // get reference to mygui manager
      mMyGUI = Gui.Instance;
      if( mMyGUI == null )
        return false;

      // by default, mouse pointer is not visible
      mMyGUI.PointerVisible = false;

      // OK
      return true;
    }

    /************************************************************************/
    /* shut down mygui manager                                              */
    /************************************************************************/
    internal void Shutdown()
    {
      // unload resources of mygui resource group
      mLib.ResourceMgr.UnloadGroup( mLib.EngineCfg.MyGUIResourceGroup );

      // shutdown mygui manager
      if( mMyGUI != null )
        Gui.Shutdown();
      mMyGUI = null;
    }

    /************************************************************************/
    /* update mygui manager                                                 */
    /************************************************************************/
    internal void Update( long _frameTime )
    {
      // side note: the gui is updated automatically every frame from an
      // internal ogre frame listener, if manual updating is necessary
      // this behavior needs to be changed in the mygui dependency
    }

    /************************************************************************/
    /* an external rendering window got resized                             */
    /************************************************************************/
    internal void ExternalWindowResized( int _width, int _height )
    {
      // update new size in mygui systems
      mMyGUI.ResizeWindow( _width, _height );
    }

  } // class

} // namespace
