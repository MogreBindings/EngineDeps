using System;

using Mogre;
using Mogre.PhysX;

using MyGame.Shared.Datatypes;
using MyGame.Shared.GameObjects.Entity;
using MyGame.Shared.GameObjects.Renderer;

namespace MyGame.Engine.Objects
{
  /************************************************************************/
  /* engine 3D object wrapper                                             */
  /************************************************************************/
  public class Object3D : BaseObject
  {
    //////////////////////////////////////////////////////////////////////////
    private SceneNode mNode;
    private Actor mActor;

    //////////////////////////////////////////////////////////////////////////
    internal SceneNode Node
    {
      get { return mNode; }
    }

    //////////////////////////////////////////////////////////////////////////
    internal Actor Actor
    {
      get { return mActor; }
    }

    //////////////////////////////////////////////////////////////////////////
    public Vector3D Position
    {
      get
      {
        // if node is valid
        if( Node != null )
        {
          // return position from node
          return new Vector3D( Node.Position.x, Node.Position.y, Node.Position.z );
        }

        // otherwise return empty position
        return new Vector3D();
      }
    }

    /************************************************************************/
    /* constructor                                                          */
    /************************************************************************/
    internal Object3D( ObjectManager _mgr )
      : base( _mgr )
    {
      mNode = null;
      mActor = null;
    }

    /************************************************************************/
    /* init object                                                          */
    /************************************************************************/
    internal bool Init( GORenderer _renderer, SceneNode _node, Actor _actor )
    {
      // try to initialize the base class first
      if( !base.Init( _renderer ) )
        return false;

      // store references to 3D object and actor
      mNode = _node;
      mActor = _actor;

      // create references to this 3D object in ogre objects
      UpdateReferences( mNode );

      // OK
      return true;
    }

    /************************************************************************/
    /* clean up object                                                      */
    /************************************************************************/
    internal override void Cleanup()
    {
      // in case object is visible, hide it
      RemoveFromScene();

      // remove references to scene node and actor
      mNode = null;
      mActor = null;

      // also clean up base class
      base.Cleanup();
    }

    //////////////////////////////////////////////////////////////////////////
    // internal functions ////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /************************************************************************/
    /* store reference to this 3D object in ogre objects (mouse picking)    */
    /************************************************************************/
    private void UpdateReferences( SceneNode _node )
    {
      // check if node is valid
      if( _node != null )
      {
        // store reference to this 3D object in ogre entities
        foreach( MovableObject obj in _node.GetAttachedObjectIterator() )
          obj.UserObject = this;

        // recursively update reference in all children
        foreach( SceneNode child in _node.GetChildIterator() )
          UpdateReferences( child );
      }
    }

    //////////////////////////////////////////////////////////////////////////
    // public functions //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /************************************************************************/
    /* make object visible                                                  */
    /************************************************************************/
    public override bool AddToScene()
    {
      // can't show object without a 3D object
      if( Node == null )
        return false;

      // add object to scene
      ObjectMgr.EngineLib.OgreMgr.AddObjectToScene( Node );

      // OK
      return true;
    }

    /************************************************************************/
    /* attach object to another object                                      */
    /************************************************************************/
    public override bool AddToObject( BaseObject _other )
    {
      // check if other object is a valid 3D object
      Object3D newParent = _other as Object3D;
      if( newParent == null )
        return false;

      // both objects need to have a valid scene node
      if( Node == null || newParent.Node == null )
        return false;

      // add object to other object
      ObjectMgr.EngineLib.OgreMgr.AddObjectToObject( Node, newParent.Node );

      // OK
      return true;
    }

    /************************************************************************/
    /* make object invisible                                                */
    /************************************************************************/
    public override void RemoveFromScene()
    {
      // remove object from scene
      if( Node != null )
        ObjectMgr.EngineLib.OgreMgr.RemoveObjectFromScene( Node );
    }

    /************************************************************************/
    /* move object to a new position                                        */
    /************************************************************************/
    public override void MoveTo( Vector3D _pos )
    {
      // change position in object
      if( Node != null )
        Node.Position = new Vector3( _pos.X, _pos.Y, _pos.Z );
    }

    /************************************************************************/
    /* turn object to a new orientation                                     */
    /************************************************************************/
    public override void TurnTo( Vector4D _ori )
    {
      // change orientation in object
      if( Node != null )
        Node.Orientation = new Quaternion( _ori.W, _ori.X, _ori.Y, _ori.Z );
    }

    /************************************************************************/
    /* resize object to a new size                                          */
    /************************************************************************/
    public override void ResizeTo( Vector3D _size )
    {
      // change size in object
      if( Node != null )
        Node.SetScale( _size.X, _size.Y, _size.Z );
    }

    /************************************************************************/
    /* check if object has a mesh attached                                  */
    /************************************************************************/
    public bool HasMesh( string _meshName )
    {
      // no node, so no mesh can be attached
      if( Node == null )
        return false;

      // iterate all objects attached to the node
      foreach( MovableObject obj in Node.GetAttachedObjectIterator() )
      {
        // only check attached entities
        if( !( obj is Entity ) )
          continue;

        // check if mesh with requested name is attached
        MeshPtr mesh = ( (Entity) obj ).GetMesh();
        if( mesh.Name == _meshName )
          return true;
      }

      // mesh with requested name not found
      return false;
    }

    /************************************************************************/
    /* replace mesh attached to scene node                                  */
    /************************************************************************/
    public void ReplaceMesh( string _meshName )
    {
      // no node, so no mesh can be attached
      if( Node == null )
        return;

      // replace the mesh in this 3D object
      ObjectMgr.EngineLib.OgreMgr.ReplaceMesh( Node, _meshName );

      // make sure the references to this 3D object are properly set in all attached meshes
      UpdateReferences( Node );
    }

  } // class

} // namespace
