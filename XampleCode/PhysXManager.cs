using System;

using Mogre;
using Mogre.PhysX;

namespace MyGame.Engine.Physic
{
  /************************************************************************/
  /* physx manager                                                        */
  /************************************************************************/
  public class PhysXManager
  {
    //////////////////////////////////////////////////////////////////////////
    private EngineLibrary mLib;
    private Physics mPhysX;
    private Scene mScene;

    /************************************************************************/
    /* constructor                                                          */
    /************************************************************************/
    internal PhysXManager( EngineLibrary _lib )
    {
      mLib = _lib;
      mPhysX = null;
      mScene = null;
    }

    /************************************************************************/
    /* start up physx manager                                               */
    /************************************************************************/
    internal bool Startup()
    {
      // create and init physx wrapper
      mPhysX = Physics.Create();
      if( mPhysX == null )
        return false;

      // create default scene
      if( !CreateDefaultScene() )
        return false;

      // OK
      return true;
    }

    /************************************************************************/
    /* shut down physx manager                                              */
    /************************************************************************/
    internal void Shutdown()
    {
      // destroy default scene
      RemoveDefaultScene();

      // shutdown physx wrapper
      if( mPhysX != null )
        mPhysX.Dispose();
      mPhysX = null;
    }

    /************************************************************************/
    /* update physx manager                                                 */
    /************************************************************************/
    internal void Update( long _frameTime )
    {
      // simulate next physics step
      mScene.Simulate( (double) _frameTime / 1000.0 );
      mScene.FlushStream();
      mScene.FetchResults( SimulationStatuses.AllFinished, true );
    }

    /************************************************************************/
    /* create default physx scene with default parameters                   */
    /************************************************************************/
    private bool CreateDefaultScene()
    {
      // setup default scene description
      SceneDesc desc = new SceneDesc();
      desc.Gravity = new Vector3( 0.0f, -9.81f, 0.0f );
      desc.MaxBounds = new AxisAlignedBox( -1000.0f, -1000.0f, -1000.0f, 1000.0f, 1000.0f, 1000.0f );
      desc.UpAxis = 1;
      desc.TimeStepMethod = TimeStepMethods.Fixed;
      desc.MaxTimeStep = 0.01f;
      desc.MaxIterationCount = 10;

      // create default scene
      mScene = mPhysX.CreateScene( desc );
      if( mScene == null )
        return false;

      // OK
      return true;
    }

    /************************************************************************/
    /* remove default physx scene                                           */
    /************************************************************************/
    private void RemoveDefaultScene()
    {
      // destroy default scene
      if( mScene != null )
        mScene.Dispose();
      mScene = null;
    }

  } // class

} // namespace
