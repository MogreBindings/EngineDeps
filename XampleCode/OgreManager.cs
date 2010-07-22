using System;
using System.Collections.Generic;
using System.IO;

using Mogre;

using MyGame.Engine.Graphics.Ogre;
using MyGame.Engine.Objects;
using MyGame.Shared.Datatypes;

namespace MyGame.Engine.Graphics
{
  /************************************************************************/
  /* ogre manager                                                         */
  /************************************************************************/
  public class OgreManager
  {
    //////////////////////////////////////////////////////////////////////////
    private EngineLibrary mLib;
    private Root mRoot;
    private IntPtr mExternalWindowHandle;
    private RenderWindow mWindow;
    private IntPtr mWindowPtr;
    private IntPtr mWindowHandle;
    private IntPtr mD3DDevice;
    private SceneManager mSceneMgr;
    private IntPtr mSceneMgrPtr;
    private Camera mCamera;
    private Viewport mViewport;
    private bool mRenderingActive;

    // reference to system window handle /////////////////////////////////////
    internal IntPtr WindowHnd
    {
      get { return mWindowHandle; }
    }

    // reference to renderwindow native pointer //////////////////////////////
    internal IntPtr WindowPtr
    {
      get { return mWindowPtr; }
    }

    // reference to direct 3D device native pointer //////////////////////////
    internal IntPtr D3DDevice
    {
      get { return mD3DDevice; }
    }

    // reference to scene manager native pointer /////////////////////////////
    internal IntPtr SceneMgrPtr
    {
      get { return mSceneMgrPtr; }
    }

    // check if using external window or ogre managed window /////////////////
    internal bool IsUsingExternalWindow
    {
      get { return mExternalWindowHandle != IntPtr.Zero; }
    }

    // reference to camera ///////////////////////////////////////////////////
    public Camera Camera
    {
      get { return mCamera; }
    }

    // events raised when direct 3D device is lost or restored ///////////////
    public event EventHandler<OgreEventArgs> DeviceLost;
    public event EventHandler<OgreEventArgs> DeviceRestored;

    /************************************************************************/
    /* constructor                                                          */
    /************************************************************************/
    internal OgreManager( EngineLibrary _lib )
    {
      mLib = _lib;
      mRoot = null;
      mExternalWindowHandle = IntPtr.Zero;
      mWindow = null;
      mWindowPtr = IntPtr.Zero;
      mWindowHandle = IntPtr.Zero;
      mD3DDevice = IntPtr.Zero;
      mSceneMgr = null;
      mSceneMgrPtr = IntPtr.Zero;
      mCamera = null;
      mViewport = null;
      mRenderingActive = false;
    }

    /************************************************************************/
    /* start up ogre manager                                                */
    /************************************************************************/
    internal bool Startup( IntPtr _windowHnd )
    {
      // check if already initialized
      if( mRoot != null )
        return false;

      // create ogre root
      string logFileName = Path.Combine( mLib.SharedLib.Paths.SavePath, mLib.EngineCfg.OgreLogFile );
      mRoot = new Root( "ogreplugins.cfg", "ogresettings.cfg", logFileName );

      // load ogre plugins
      if( !LoadPlugins() )
        return false;

      // set directx render system
      RenderSystem renderSys = mRoot.GetRenderSystemByName( "Direct3D9 Rendering Subsystem" );
      mRoot.RenderSystem = renderSys;

      // register event to get notified when application lost or regained focus
      mRoot.RenderSystem.EventOccurred += OnRenderSystemEventOccurred;

      // initialize engine
      mRoot.Initialise( false );

      // optional parameters
      NameValuePairList parm = new NameValuePairList();
      parm[ "vsync" ] = "true";

      mExternalWindowHandle = _windowHnd;
      if( mExternalWindowHandle != IntPtr.Zero )
      {
        parm[ "externalWindowHandle" ] = mExternalWindowHandle.ToString();
        //parm[ "parentWindowHandle" ] = mExternalWindowHandle.ToString();
      }

#if REFERENCE_OGRE_1_7_1
      parm[ "left" ] = "int";
      parm[ "top" ] = "int";
      parm[ "title" ] = "string";
      parm[ "parentWindowHandle" ] = "handle";
      parm[ "externalWindowHandle" ] = "handle";
      parm[ "vsync" ] = "bool";
      parm[ "vsyncInterval" ] = "uint (0 = default)";
      parm[ "displayFrequency" ] = "uint (0 = default)";
      parm[ "colourDepth" ] = "uint";
      parm[ "depthBuffer" ] = "bool";
      parm[ "FSAA" ] = "(D3DMULTISAMPLE_TYPE) uint";
      parm[ "FSAAHint" ] = "string (Quality|Speed)";
      parm[ "border" ] = "string (none|fixed|default)";
      parm[ "outerDimensions" ] = "bool";
      parm[ "useNVPerfHUD" ] = "bool";
      parm[ "gamma" ] = "bool";
      parm[ "monitorIndex" ] = "int (-1 = autodetect)";
#endif

      // create window
      if( mExternalWindowHandle == IntPtr.Zero )
        mWindow = mRoot.CreateRenderWindow( "My Game Engine", 1600, 900, false, parm );
      else
        mWindow = mRoot.CreateRenderWindow( "My Game Engine (Ext)", 0, 0, false, parm );
      mWindow.GetCustomAttribute( "WINDOW", out mWindowHandle );
      mWindow.GetCustomAttribute( "D3DDEVICE", out mD3DDevice );

      // get reference to unmanager renderwindow
      unsafe
      {
        mWindowPtr = new IntPtr( mWindow.NativePtr );
      }

      // create scene manager
      mSceneMgr = mRoot.CreateSceneManager( SceneType.ST_GENERIC, "DefaultSceneManager" );

      // get reference to unmanaged scene manager
      unsafe
      {
        mSceneMgrPtr = new IntPtr( mSceneMgr.NativePtr );
      }

      // create default camera
      mCamera = mSceneMgr.CreateCamera( "DefaultCamera" );
      mCamera.AutoAspectRatio = true;
      mCamera.NearClipDistance = 0.5f;
      mCamera.FarClipDistance = 100.0f;

      // create default viewport
      mViewport = mWindow.AddViewport( mCamera );

      // set rendering active flag
      mRenderingActive = true;

      /*DEBUG*/
      //TODO: remove asap
      mSceneMgr.AmbientLight = new ColourValue( 0.1f, 0.1f, 0.1f );
      mCamera.Position = new Vector3( 5.0f, 10.0f, 20.0f );
      mCamera.LookAt( new Vector3() );
      Light light;
      light = mSceneMgr.CreateLight( "***LIGHT1***" );
      light.Type = Light.LightTypes.LT_POINT;
      light.DiffuseColour = new ColourValue( 1.0f, 0.975f, 0.85f );
      light.Position = new Vector3( -7.5f, 15.0f, 25.0f );
      mSceneMgr.RootSceneNode.AttachObject( light );
      light = mSceneMgr.CreateLight( "***LIGHT2***" );
      light.Type = Light.LightTypes.LT_POINT;
      light.DiffuseColour = new ColourValue( 0.1f, 0.15f, 0.3f );
      light.Position = new Vector3( 15.0f, 10.0f, -40.0f );
      mSceneMgr.RootSceneNode.AttachObject( light );

      // OK
      return true;
    }

    /************************************************************************/
    /* shut down ogre manager                                               */
    /************************************************************************/
    internal void Shutdown()
    {
      // shutdown ogre root
      if( mRoot != null )
      {
        // deregister event to get notified when application lost or regained focus
        mRoot.RenderSystem.EventOccurred -= OnRenderSystemEventOccurred;

        // shutdown ogre
        mRoot.Dispose();
      }
      mRoot = null;

      // forget other references to ogre systems
      mExternalWindowHandle = IntPtr.Zero;
      mWindow = null;
      mWindowPtr = IntPtr.Zero;
      mWindowHandle = IntPtr.Zero;
      mD3DDevice = IntPtr.Zero;
      mSceneMgr = null;
      mSceneMgrPtr = IntPtr.Zero;
      mCamera = null;
      mViewport = null;
      mRenderingActive = false;
    }

    /************************************************************************/
    /* update ogre manager, also processes the systems event queue          */
    /************************************************************************/
    internal void Update( long _frameTime )
    {
      // check if ogre manager is initialized
      if( mRoot == null )
        return;

      // process windows event queue (only if no external window is used)
      if( mExternalWindowHandle == IntPtr.Zero )
        WindowEventUtilities.MessagePump();

      // render next frame
      if( mRenderingActive )
        mRoot.RenderOneFrame();
    }

    /************************************************************************/
    /* load ogre plugins, by code not by config file for                    */
    /************************************************************************/
    private bool LoadPlugins()
    {
#if DEBUG
      // load debug versions of plugins
      mRoot.LoadPlugin( "RenderSystem_Direct3D9_d" );
      mRoot.LoadPlugin( "Plugin_ParticleFX_d" );
      mRoot.LoadPlugin( "Plugin_OctreeSceneManager_d" );
      mRoot.LoadPlugin( "Plugin_CgProgramManager_d" );
#else
      // load release versions of plugins
      mRoot.LoadPlugin( "RenderSystem_Direct3D9" );
      mRoot.LoadPlugin( "Plugin_ParticleFX" );
      mRoot.LoadPlugin( "Plugin_OctreeSceneManager" );
      mRoot.LoadPlugin( "Plugin_CgProgramManager" );
#endif

      // OK
      return true;
    }

    /************************************************************************/
    /* change between fullscreen and windowed mode                          */
    /************************************************************************/
    internal void ChangeFullscreen( bool _fullScreen )
    {
      // can't switch to fullscreen when using an external window handle
      if( mExternalWindowHandle != IntPtr.Zero )
        return;

      //TODO:
    }

    /************************************************************************/
    /* handle device lost and device restored events                        */
    /************************************************************************/
    private void OnRenderSystemEventOccurred( string eventName, Const_NameValuePairList parameters )
    {
      EventHandler<OgreEventArgs> evt = null;
      OgreEventArgs args;

      // check which event occured
      switch( eventName )
      {
        // direct 3D device lost
        case "DeviceLost":
          // don't set mRenderingActive to false here, because ogre will try to restore the
          // device in the RenderOneFrame function and mRenderingActive needs to be set to true
          // for this function to be called

          // event to raise is device lost event
          evt = DeviceLost;

          // on device lost, create empty ogre event args
          args = new OgreEventArgs();
          break;

        // direct 3D device restored
        case "DeviceRestored":
          uint width;
          uint height;
          uint depth;

          // event to raise is device restored event
          evt = DeviceRestored;

          // get metrics for the render window size
          mWindow.GetMetrics( out width, out height, out depth );

          // on device restored, create ogre event args with new render window size
          args = new OgreEventArgs( (int) width, (int) height );
          break;

        default:
          return;
      }

      // raise event with provided event args
      if( evt != null )
        evt( this, args );
    }

    /************************************************************************/
    /* an external render window has resized                                */
    /************************************************************************/
    internal void ExternalWindowResized( int _width, int _height )
    {
      // check if external render window is used
      if( mExternalWindowHandle == IntPtr.Zero )
        return;

      if( _width < 1 || _height < 1 )
      {
        mRenderingActive = false;
        return;
      }
      else
        mRenderingActive = true;

      // update new size in ogre systems
      mWindow.Resize( (uint) _width, (uint) _height );
      mWindow.WindowMovedOrResized();
    }

    /************************************************************************/
    /* create a simple object just consisting of an empty scenenode         */
    /************************************************************************/
    internal SceneNode CreateEmptyObject( string _name )
    {
      // if scene manager already has an object with the requested name, fail to create it again
      if( mSceneMgr.HasSceneNode( _name ) )
        return null;

      // create entity and scenenode for the object
      SceneNode node = mSceneMgr.CreateSceneNode( _name );

      // return the created object
      return node;
    }

    /************************************************************************/
    /* create a simple object just consisting of a scenenode with a mesh    */
    /************************************************************************/
    internal SceneNode CreateSimpleObject( string _name, string _mesh )
    {
      // if scene manager already has an object with the requested name, fail to create it again
      if( mSceneMgr.HasEntity( _name ) || mSceneMgr.HasSceneNode( _name ) )
        return null;

      // create entity and scenenode for the object
      Entity entity;
      try
      {
        // try to create entity from mesh
        entity = mSceneMgr.CreateEntity( _name, _mesh );
      }
      catch
      {
        // failed to create entity
        return null;
      }

      // add entity to scenenode
      SceneNode node = mSceneMgr.CreateSceneNode( _name );

      // connect entity to the scenenode
      node.AttachObject( entity );

      // return the created object
      return node;
    }

    /************************************************************************/
    /* destroy an object                                                    */
    /************************************************************************/
    internal void DestroyObject( SceneNode _node )
    {
      // check if object has a parent node...
      if( _node.Parent != null )
      {
        // ...if so, remove it from its parent node first
        _node.Parent.RemoveChild( _node );
      }

      // first remove all child nodes (they are not destroyed here !)
      _node.RemoveAllChildren();

      // create a list of references to attached objects
      List<MovableObject> objList = new List<MovableObject>();

      // get number of attached objects
      ushort count = _node.NumAttachedObjects();

      // get all attached objects references
      for( ushort i = 0; i < count; ++i )
        objList.Add( _node.GetAttachedObject( i ) );

      // detach all objects from node
      _node.DetachAllObjects();

      // destroy all previously attached objects
      foreach( MovableObject obj in objList )
        mSceneMgr.DestroyMovableObject( obj );

      // destroy scene node
      mSceneMgr.DestroySceneNode( _node );
    }

    /************************************************************************/
    /* replace mesh attached to a scene node                                */
    /************************************************************************/
    public void ReplaceMesh( SceneNode _node, string _mesh )
    {
      Entity entity = null;

      // iterate all objects attached to the node
      foreach( MovableObject obj in _node.GetAttachedObjectIterator() )
      {
        // only check attached entities
        if( obj is Entity )
        {
          // detach mesh from scene node
          _node.DetachObject( obj );

          // store reference to entity, so it can be destroyed and recreated with the changed mesh
          entity = (Entity) obj;

          // skip to recreation of mesh
          break;
        }
      }

      // default entity name to same as scene node name
      string name = _node.Name;

      // if an entity was attached before
      if( entity != null )
      {
        // store entity name to use it for the new mesh
        name = entity.Name;

        // destroy the old mesh
        mSceneMgr.DestroyEntity( entity );
        entity = null;
      }

      // create a new mesh
      try
      {
        // try to create entity from mesh
        entity = mSceneMgr.CreateEntity( name, _mesh );
      }
      catch
      {
        // failed to create entity
        return;
      }

      // attach the new mesh to the scene node
      _node.AttachObject( entity );
    }

    /************************************************************************/
    /* add an object to the scene                                           */
    /************************************************************************/
    internal void AddObjectToScene( SceneNode _node )
    {
      // check if object is already has a parent
      if( _node.Parent != null )
      {
        // check if object is in scene already, then we are done
        if( _node.Parent == mSceneMgr.RootSceneNode )
          return;

        // otherwise remove the object from its current parent
        _node.Parent.RemoveChild( _node );
      }

      // add object to scene
      mSceneMgr.RootSceneNode.AddChild( _node );
    }

    /************************************************************************/
    /* add an object to another object as child                             */
    /************************************************************************/
    internal void AddObjectToObject( SceneNode _node, SceneNode _newParent )
    {
      // check if object is already has a parent
      if( _node.Parent != null )
      {
        // check if object is in scene already, then we are done
        if( _node.Parent == _newParent )
          return;

        // otherwise remove the object from its current parent
        _node.Parent.RemoveChild( _node );
      }

      // add object to scene
      _newParent.AddChild( _node );
    }

    /************************************************************************/
    /* remove object from scene                                             */
    /************************************************************************/
    internal void RemoveObjectFromScene( SceneNode _node )
    {
      // if object is attached to a node
      if( _node.Parent != null )
      {
        // remove object from its parent
        _node.Parent.RemoveChild( _node );
      }
    }

    /************************************************************************/
    /* get ray in scene from camera and mouse position                      */
    /************************************************************************/
    public Ray GetMouseRay( Vector2D _pos )
    {
      // create a ray in the scene from relative mouse position
      return mCamera.GetCameraToViewportRay( _pos.X, _pos.Y );
    }

    /************************************************************************/
    /* query scene objects at a relative mouse position                     */
    /************************************************************************/
    public List<PickInfo> QueryMousePosition( Vector2D _pos )
    {
      // create result list
      List<PickInfo> pickList = new List<PickInfo>();

      // create a ray in the scene from relative mouse position
      Ray camRay = GetMouseRay( _pos );

      // create a ray query in the scene
      RaySceneQuery sceneQuery = mSceneMgr.CreateRayQuery( camRay );

      // execute the query
      RaySceneQueryResult resultList = sceneQuery.Execute();

      // first check if any results were found
      if( !resultList.IsEmpty )
      {
        // iterate query results
        foreach( RaySceneQueryResultEntry result in resultList )
        {
          // movable must be valid
          if( result.movable == null )
            continue;

          // we are only interested in objects that are managed by the object manager
          Object3D obj = result.movable.UserObject as Object3D;
          if( obj == null )
            continue;

          // add object to result pick list
          pickList.Add( new PickInfo( obj, result.distance ) );
        }
      }

      sceneQuery.ClearResults();
      mSceneMgr.DestroyQuery( sceneQuery );

      // return the list of objects found at the mouse position
      return pickList;
    }

  } // class

} // namespace
