using System;

using MyGame.Shared.Datatypes;
using MyGame.Shared.GameObjects.Entity;
using MyGame.Shared.GameObjects.Renderer;

namespace MyGame.Engine.Objects
{
  /************************************************************************/
  /* base class for engine objects                                        */
  /************************************************************************/
  public abstract class BaseObject
  {
    //////////////////////////////////////////////////////////////////////////
    private ObjectManager mObjectMgr;
    private string mName;
    private GORenderer mRenderer;

    //////////////////////////////////////////////////////////////////////////
    public ObjectManager ObjectMgr
    {
      get { return mObjectMgr; }
    }

    //////////////////////////////////////////////////////////////////////////
    public string Name
    {
      get { return mName; }
      internal set { mName = value; }
    }

    //////////////////////////////////////////////////////////////////////////
    public GOEntity Entity
    {
      get { return IsInitialized ? mRenderer.Owner : null; }
    }

    //////////////////////////////////////////////////////////////////////////
    public GORenderer Renderer
    {
      get { return mRenderer; }
    }

    //////////////////////////////////////////////////////////////////////////
    public bool IsInitialized
    {
      get { return mRenderer != null; }
    }

    /************************************************************************/
    /* constructor                                                          */
    /************************************************************************/
    internal BaseObject( ObjectManager _mgr )
    {
      mObjectMgr = _mgr;
      mName = string.Empty;
      mRenderer = null;
    }

    /************************************************************************/
    /* init object                                                          */
    /************************************************************************/
    internal bool Init( GORenderer _renderer )
    {
      // renderer must be set
      if( _renderer == null )
        return false;

      // store reference to renderer
      mRenderer = _renderer;

      // OK
      return true;
    }

    /************************************************************************/
    /* clean up object                                                      */
    /************************************************************************/
    internal virtual void Cleanup()
    {
      mRenderer = null;
    }

    //////////////////////////////////////////////////////////////////////////
    // public functions //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /************************************************************************/
    /* destroy this object and remove it from object manager                */
    /************************************************************************/
    public void Destroy()
    {
      // call destroy function in object manager
      mObjectMgr.DestroyObject( this );
    }

    /************************************************************************/
    /* make object visible in scene                                         */
    /************************************************************************/
    public abstract bool AddToScene();

    /************************************************************************/
    /* attach object to another object                                      */
    /************************************************************************/
    public abstract bool AddToObject( BaseObject _other );

    /************************************************************************/
    /* make object invisible in scene                                       */
    /************************************************************************/
    public abstract void RemoveFromScene();

    /************************************************************************/
    /* move object to a new position                                        */
    /************************************************************************/
    public abstract void MoveTo( Vector3D _pos );

    /************************************************************************/
    /* turn object to a new orientation                                     */
    /************************************************************************/
    public abstract void TurnTo( Vector4D _ori );

    /************************************************************************/
    /* resize object to a new size                                          */
    /************************************************************************/
    public abstract void ResizeTo( Vector3D _size );

  } // class

} // namespace
