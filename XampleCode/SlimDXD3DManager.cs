using System;

using SlimDX.Direct3D9;

namespace MyGame.Engine.Graphics
{
  /************************************************************************/
  /* slimdx direct 3D manager                                             */
  /************************************************************************/
  public class SlimDXD3DManager
  {
    //////////////////////////////////////////////////////////////////////////
    private EngineLibrary mLib;
    private Device mD3D;

    /************************************************************************/
    /* constructor                                                          */
    /************************************************************************/
    internal SlimDXD3DManager( EngineLibrary _lib )
    {
      mLib = _lib;
      mD3D = null;
    }

    /************************************************************************/
    /* start up direct 3D manager                                           */
    /************************************************************************/
    internal bool Startup()
    {
      // create reference to external D3D device from ogre
      mD3D = Device.FromPointer( mLib.OgreMgr.D3DDevice );
      if( mD3D == null )
        return false;

      // OK
      return true;
    }

    /************************************************************************/
    /* shut down direct 3D manager                                          */
    /************************************************************************/
    internal void Shutdown()
    {
      // remove reference to external device from ogre
      if( mD3D != null )
        mD3D.Dispose();
      mD3D = null;
    }

    /************************************************************************/
    /* update direct 3D manager                                             */
    /************************************************************************/
    internal void Update( long _frameTime )
    {
    }

  } // class

} // namespace
