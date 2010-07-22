using System;
using MyGame.Engine.Graphics;
using MyGame.Engine.Input;
using MyGame.Engine.Objects;
using MyGame.Engine.Physic;

namespace MyGame.Engine.Core
{
  /************************************************************************/
  /* engine main system                                                   */
  /************************************************************************/
  public class MainSystem
  {
    //////////////////////////////////////////////////////////////////////////
    private EngineLibrary mLib;
    private MyGUIManager mMyGUIMgr;
    private SlimDXD3DManager mD3DMgr;
    private SlimDXDInputManager mDInputMgr;
    private PhysXManager mPhysicsMgr;
    private ObjectManager mObjectMgr;

    // reference to mygui manager ////////////////////////////////////////////
    internal MyGUIManager MyGUIMgr
    {
      get { return mMyGUIMgr; }
    }

    // reference to slimdx direct 3D manager /////////////////////////////////
    internal SlimDXD3DManager D3DMgr
    {
      get { return mD3DMgr; }
    }

    // reference to slimdx input manager /////////////////////////////////////
    internal SlimDXDInputManager DInputMgr
    {
      get { return mDInputMgr; }
    }

    // reference to physx manager ////////////////////////////////////////////
    internal PhysXManager PhysicsMgr
    {
      get { return mPhysicsMgr; }
    }

    // reference to object manager ///////////////////////////////////////////
    internal ObjectManager ObjectMgr
    {
      get { return mObjectMgr; }
    }

    /************************************************************************/
    /* constructor                                                          */
    /************************************************************************/
    internal MainSystem( EngineLibrary _lib )
    {
      mLib = _lib;
      mMyGUIMgr = null;
      mD3DMgr = null;
      mDInputMgr = null;
      mPhysicsMgr = null;
      mObjectMgr = null;
    }

    /************************************************************************/
    /* start up engine main system                                          */
    /************************************************************************/
    internal bool Startup()
    {
      // create and init mygui manager
      mMyGUIMgr = new MyGUIManager( mLib );
      if( !mMyGUIMgr.Startup() )
        return false;

      // create and init slimdx D3D manager
      mD3DMgr = new SlimDXD3DManager( mLib );
      if( !mD3DMgr.Startup() )
        return false;

      // create and init slimdx DInput manager
      mDInputMgr = new SlimDXDInputManager( mLib );
      if( !mDInputMgr.Startup() )
        return false;

      // create and init physics manager
      mPhysicsMgr = new PhysXManager( mLib );
      if( !mPhysicsMgr.Startup() )
        return false;

      // create and init object manager
      mObjectMgr = new ObjectManager( mLib );
      if( !mObjectMgr.Startup() )
        return false;

      // OK
      return true;
    }

    /************************************************************************/
    /* shut down engine main system                                         */
    /************************************************************************/
    internal void Shutdown()
    {
      // shutdown object manager
      if( mObjectMgr != null )
        mObjectMgr.Shutdown();
      mObjectMgr = null;

      // shutdown physics manager
      if( mPhysicsMgr != null )
        mPhysicsMgr.Shutdown();
      mPhysicsMgr = null;

      // shutdown slimdx DInput manager
      if( mDInputMgr != null )
        mDInputMgr.Shutdown();
      mDInputMgr = null;

      // shutdown slimdx D3D manager
      if( mD3DMgr != null )
        mD3DMgr.Shutdown();
      mD3DMgr = null;

      // shutdown mygui manager
      if( mMyGUIMgr != null )
        mMyGUIMgr.Shutdown();
      mMyGUIMgr = null;
    }

    /************************************************************************/
    /* update engine main system                                            */
    /************************************************************************/
    internal void Update( long _frameTime )
    {
      // update slimdx DInput manager
      mDInputMgr.Update( _frameTime );

      // update physics manager
      mPhysicsMgr.Update( _frameTime );

      // update slimdx D3D manager
      mD3DMgr.Update( _frameTime );

      // update mygui manager
      mMyGUIMgr.Update( _frameTime );

      // update object manager
      mObjectMgr.Update( _frameTime );
    }

  } // class

} // namespace
