using System;
using System.Collections.Generic;

using Mogre;

using MyGame.Shared.Datatypes;
using MyGame.Shared.GameObjects.Renderer;

namespace MyGame.Engine.Objects
{
  /************************************************************************/
  /* engine object manager                                                */
  /************************************************************************/
  public class ObjectManager
  {
    //////////////////////////////////////////////////////////////////////////
    private EngineLibrary mLib;
    private Dictionary<string, BaseObject> mObjects;
    private ulong mObjectCounter;

    //////////////////////////////////////////////////////////////////////////
    private Vector3 mStartRelativePos;
    private Vector3 mStartAbsolutePos;
    private Vector3D mStartEntityPos;
    private Vector3 mLastAbsolutePos;
    private Vector3 mLastGrabPos;
    private Vector3 mLastGridPos;
    private Plane mMovePlaneXY;
    private Plane mMovePlaneXZ;

    // reference to engine library ///////////////////////////////////////////
    internal EngineLibrary EngineLib
    {
      get { return mLib; }
    }

    /************************************************************************/
    /* constructor                                                          */
    /************************************************************************/
    internal ObjectManager( EngineLibrary _lib )
    {
      mLib = _lib;
      mObjects = null;
      mObjectCounter = 0;
    }

    /************************************************************************/
    /* start up                                                             */
    /************************************************************************/
    internal bool Startup()
    {
      // check if initialized before
      if( mObjectCounter != 0 )
        return false;

      // create lookup table for objects
      mObjects = new Dictionary<string, BaseObject>();

      // start object counter for unique name generator with 1
      mObjectCounter = 1;

      // OK
      return true;
    }

    /************************************************************************/
    /* shut down                                                            */
    /************************************************************************/
    internal void Shutdown()
    {
      // get list of all objects
      BaseObject[] objects = new BaseObject[ mObjects.Count ];
      mObjects.Values.CopyTo( objects, 0 );

      // iterate list of objects
      foreach( BaseObject obj in objects )
      {
        // clean up object
        obj.Cleanup();
      }

      // clear object table
      mObjects.Clear();
      mObjects = null;

      // reset object counter
      mObjectCounter = 0;
    }

    /************************************************************************/
    /* update                                                               */
    /************************************************************************/
    internal void Update( long _frameTime )
    {
    }

    //////////////////////////////////////////////////////////////////////////
    // internal function /////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /************************************************************************/
    /* generate unique object name                                          */
    /************************************************************************/
    private string GenerateUniqueName( string _baseName )
    {
      // create unique name
      string name = _baseName + "." + mObjectCounter.ToString();
      ++mObjectCounter;
      return name;
    }

    /************************************************************************/
    /* add object to object table                                           */
    /************************************************************************/
    private bool AddObject( string _name, BaseObject _obj )
    {
      // store object name
      _obj.Name = _name;

      // add object to object table
      mObjects.Add( _name, _obj );

      // OK
      return true;
    }

    /************************************************************************/
    /* create a new, empty 3D object                                        */
    /************************************************************************/
    private Object3D CreateObject3D( string _baseName, GORenderer _renderer )
    {
      // create new object
      Object3D obj = new Object3D( this );

      // create unique name for the object
      string name = GenerateUniqueName( _baseName );

      // add object to object table, this will also create a unique name from basename
      if( !AddObject( name, obj ) )
        return null;

      // return the created object
      return obj;
    }

    //////////////////////////////////////////////////////////////////////////
    // public functions //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /************************************************************************/
    /* get object by name                                                   */
    /************************************************************************/
    public T GetObject<T>( string _name )
      where T : BaseObject
    {
      BaseObject obj;

      // if object was found, return it
      if( mObjects.TryGetValue( _name, out obj ) )
        return obj as T;

      // object with this name was not found
      return null;
    }

    /************************************************************************/
    /* destroy object                                                       */
    /************************************************************************/
    public bool DestroyObject( BaseObject _obj )
    {
      // check if object is in object table
      BaseObject obj = GetObject<BaseObject>( _obj.Name );

      // check if object is valid
      if( obj == null || obj != _obj )
        return false;

      // clean up object
      _obj.Cleanup();

      // remove object from table
      mObjects.Remove( _obj.Name );

      //OK
      return true;
    }

    /************************************************************************/
    /* get list of 3D objects at a relative mouse position                  */
    /************************************************************************/
    public List<PickInfo> Get3DObjectsAt( Vector2D _pos )
    {
      // let the ogre manager do the work
      return mLib.OgreMgr.QueryMousePosition( _pos );
    }

    //////////////////////////////////////////////////////////////////////////
    // editor support functions //////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /************************************************************************/
    /* start moving the object with mouse                                   */
    /************************************************************************/
    public bool StartMouseMove( Object3D _obj, bool _isEntity, Vector2D _pos )
    {
      // object needs to be provided
      if( _obj == null || _obj.Node == null )
        return false;

      // get ray from mouse position
      Ray mouseRay = mLib.OgreMgr.GetMouseRay( _pos );

      // get object position, relative and absolute
      mStartRelativePos = _obj.Node.Position;
      mStartAbsolutePos = _obj.Node._getDerivedPosition();

      // if object is an entity, store entity start position
      if( _isEntity )
        mStartEntityPos = _obj.Entity.Position;

      // store absolute position in move and grid handling positions
      mLastAbsolutePos = mStartAbsolutePos;
      mLastGridPos = mStartAbsolutePos;

      // create XY plane for moving up/down parallel to view from camera
      Vector3 camRight = mLib.OgreMgr.Camera.DerivedRight;
      mMovePlaneXY.Redefine( mLastAbsolutePos, mLastAbsolutePos + Vector3.UNIT_Y, mLastAbsolutePos + camRight );

      // get mouse position on XY plane
      Pair<bool, float> rayHitXY = mouseRay.Intersects( mMovePlaneXY );

      // just to be safe, check if mouse position intersects with XY plane
      if( !rayHitXY.first )
        return false;

      // get XZ plane for moving forward/backward/left/right
      mLastGrabPos = mouseRay.GetPoint( rayHitXY.second );
      mMovePlaneXZ.Redefine( mLastGrabPos, mLastGrabPos - Vector3.UNIT_Z, mLastGrabPos + Vector3.UNIT_X );

      // moving is possible
      return true;
    }

    /************************************************************************/
    /* continue moving the object with mouse                                */
    /************************************************************************/
    public void ContinueMouseMove( Object3D _obj, bool _isEntity, Vector2D _pos, bool _upDown, float _gridSize )
    {
      // object needs to be provided
      if( _obj == null || _obj.Node == null )
        return;

      // get ray from mouse position
      Ray mouseRay = mLib.OgreMgr.GetMouseRay( _pos );

      Pair<bool, float> rayHit;
      Vector3 pos;

      // check if moving up and down (Y)
      if( _upDown )
      {
        // get new position of mouse on XY plane
        rayHit = mouseRay.Intersects( mMovePlaneXY );

        // check if valid intersection is found
        if( !rayHit.first )
          return;

        // update XZ plane
        pos = mouseRay.GetPoint( rayHit.second );
        mMovePlaneXZ.Redefine( pos, pos - Vector3.UNIT_Z, pos + Vector3.UNIT_X );
      }
      else // moving in any other direction (X, Z)
      {
        // get new position of mouse on XZ plane
        rayHit = mouseRay.Intersects( mMovePlaneXZ );

        // check if valid intersection is found
        if( !rayHit.first )
          return;

        // update XY plane
        pos = mouseRay.GetPoint( rayHit.second );
        Vector3 camRight = mLib.OgreMgr.Camera.DerivedRight;
        mMovePlaneXY.Redefine( pos, pos + Vector3.UNIT_Y, pos + camRight );
      }

      // update grab position and calculate move vector
      Vector3 moveDiff = pos - mLastGrabPos;
      mLastGrabPos += moveDiff;

      // make sure only movement on selected axis is possible
      if( _upDown )
        moveDiff.x = moveDiff.z = 0.0f;
      else
        moveDiff.y = 0.0f;

      // update absolute position after move
      mLastAbsolutePos += moveDiff;

      // check if grid is set
      if( _gridSize == 0.0f )
      {
        // grid size of 0 means grid is disabled
        mLastGridPos = mLastAbsolutePos;
      }
      else
      {
        // snap movement in grid size
        Vector3 gridDiff = mLastAbsolutePos - mLastGridPos;
        gridDiff += new Vector3( 0.5f * _gridSize );
        gridDiff.x = (float) Mogre.Math.IFloor( gridDiff.x / _gridSize ) * _gridSize;
        gridDiff.y = (float) Mogre.Math.IFloor( gridDiff.y / _gridSize ) * _gridSize;
        gridDiff.z = (float) Mogre.Math.IFloor( gridDiff.z / _gridSize ) * _gridSize;
        mLastGridPos += gridDiff;
      }

      if( _isEntity )
      {
        // calculate entity position difference
        Vector3 diff = mLastGridPos - mStartAbsolutePos;
        Vector3D entityDiff = new Vector3D( diff.x, diff.y, diff.z );

        // update entity position
        _obj.Entity.Position = mStartEntityPos + entityDiff;
      }
      else // object is not an entity, should be a render object
      {
        // update objects relative position
        _obj.Node.Position = mLastGridPos - mStartAbsolutePos + mStartRelativePos;
      }
    }

    //////////////////////////////////////////////////////////////////////////
    // create functions //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /************************************************************************/
    /* create a new 3D object with only a scene node                        */
    /************************************************************************/
    public Object3D Create3DObject( string _baseName, GORenderer _renderer )
    {
      // create new object
      Object3D obj = CreateObject3D( _baseName, _renderer );
      if( obj == null )
        return null;

      // create ogre 3D object
      SceneNode ogreObj = mLib.OgreMgr.CreateEmptyObject( obj.Name );

      // check if ogre object could be created
      if( ogreObj != null )
      {
        // init object with no physics actor attached and return it
        if( obj.Init( _renderer, ogreObj, null ) )
          return obj;
      }

      // object creation failed, so remove it from object table
      mObjects.Remove( obj.Name );

      // no object because creation failed
      return null;
    }

    /************************************************************************/
    /* create a new 3D object with a mesh                                   */
    /************************************************************************/
    public Object3D Create3DObject( string _baseName, GORenderer _renderer, string _mesh )
    {
      // create new object
      Object3D obj = CreateObject3D( _baseName, _renderer );
      if( obj == null )
        return null;

      // create ogre 3D object
      SceneNode ogreObj = mLib.OgreMgr.CreateSimpleObject( obj.Name, _mesh );

      // check if ogre object could be created
      if( ogreObj != null )
      {
        // init object with no physics actor attached and return it
        if( obj.Init( _renderer, ogreObj, null ) )
          return obj;
      }

      // object creation failed, so remove it from object table
      mObjects.Remove( obj.Name );

      // no object because creation failed
      return null;
    }

  } // class

} // namespace
