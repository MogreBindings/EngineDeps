using System;
using System.Collections.Generic;

using SlimDX;
using SlimDX.DirectInput;

namespace MyGame.Engine.Input
{
  /************************************************************************/
  /* climdx direct input manager                                          */
  /************************************************************************/
  public class SlimDXDInputManager
  {
    //////////////////////////////////////////////////////////////////////////
    private EngineLibrary mLib;
    private DirectInput mDInput;
    private Keyboard mKeyboard;
    private Mouse mMouse;

    /************************************************************************/
    /* constructor                                                          */
    /************************************************************************/
    internal SlimDXDInputManager( EngineLibrary _lib )
    {
      mLib = _lib;
      mDInput = null;
      mKeyboard = null;
      mMouse = null;
    }

    /************************************************************************/
    /* start up input manager                                               */
    /************************************************************************/
    internal bool Startup()
    {
      // do not try to capture any device if engine is running in an external window (editor)
      if( mLib.OgreMgr.IsUsingExternalWindow )
        return true;

      // create direct input wrapper
      try
      {
        mDInput = new DirectInput();
      }
      catch
      {
        // failed to create direct input wrapper
        return false;
      }

      // devices are captured exclusively in foreground
      CooperativeLevel coopLvl = CooperativeLevel.Exclusive | CooperativeLevel.Foreground;

      try
      {
        // create and init keyboard device
        mKeyboard = new Keyboard( mDInput );

        // exclusive, foreground, windows keys are disabled
        mKeyboard.SetCooperativeLevel( mLib.OgreMgr.WindowHnd, coopLvl | CooperativeLevel.NoWinKey );
      }
      catch
      {
        // failed to create keyboard device
        return false;
      }

      try
      {
        // create and init mouse device
        mMouse = new Mouse( mDInput );

        // exclusive, foregorund
        mMouse.SetCooperativeLevel( mLib.OgreMgr.WindowHnd, coopLvl );
      }
      catch
      {
        // failed to create mouse device
        return false;
      }

      // set keyboard buffer size
      mKeyboard.Properties.BufferSize = 16;

      // try to acquire the keyboad device
      mKeyboard.Acquire();

      // set mouse buffer size
      mMouse.Properties.BufferSize = 16;

      // try to acquire the mouse device
      mMouse.Acquire();

      // OK
      return true;
    }

    /************************************************************************/
    /* shut down input manager                                              */
    /************************************************************************/
    internal void Shutdown()
    {
      // shutdown mouse device
      if( mMouse != null )
      {
        mMouse.Unacquire();
        mMouse.Dispose();
      }
      mMouse = null;

      // shutdown keyboard device
      if( mKeyboard != null )
      {
        mKeyboard.Unacquire();
        mKeyboard.Dispose();
      }
      mKeyboard = null;

      // shutdown direct input wrapper
      if( mDInput != null )
        mDInput.Dispose();
      mDInput = null;
    }

    /************************************************************************/
    /* update input manager                                                 */
    /************************************************************************/
    internal void Update( long _frameTime )
    {
      // (re)acquire devices if necessary and poll their states
      bool keyboardOK = mKeyboard != null && mKeyboard.Acquire().IsSuccess && mKeyboard.Poll().IsSuccess;
      bool mouseOK = mMouse != null && mMouse.Acquire().IsSuccess && mMouse.Poll().IsSuccess;

      // buffers for device events
      IList<KeyboardState> keyboardBuffer = null;
      IList<MouseState> mouseBuffer = null;

      // try to obtain buffered keyboard events
      if( keyboardOK )
        keyboardBuffer = mKeyboard.GetBufferedData();
      if( Result.Last.IsFailure )
        keyboardBuffer = null;

      // try to obtain buffered mouse events
      if( mouseOK )
        mouseBuffer = mMouse.GetBufferedData();
      if( Result.Last.IsFailure )
        mouseBuffer = null;

      // process input event buffers
      ProcessEventQueues( keyboardBuffer, mouseBuffer );
    }

    /************************************************************************/
    /* process input events                                                 */
    /************************************************************************/
    private void ProcessEventQueues( IList<KeyboardState> _keyboardBuffer, IList<MouseState> _mouseBuffer )
    {
      // create empty dummy list for keyboard events if none provided
      if( _keyboardBuffer == null )
        _keyboardBuffer = new List<KeyboardState>();

      // create empty dummy list for mouse events if none provided
      if( _mouseBuffer == null )
        _mouseBuffer = new List<MouseState>();

      KeyboardState keyboardState;
      MouseState mouseState;

      // process event lists
      int keyboardPos = 0;
      int mousePos = 0;

      // while there are either more mouse events or keyboard events process lists
      while( keyboardPos < _keyboardBuffer.Count || mousePos < _mouseBuffer.Count )
      {
        // get next events from lists
        keyboardState = ( keyboardPos < _keyboardBuffer.Count ) ? _keyboardBuffer[ keyboardPos ] : null;
        mouseState = ( mousePos < _mouseBuffer.Count ) ? _mouseBuffer[ mousePos ] : null;

        // process keyboard event
        if( keyboardState != null )
        {
          //TODO: processing

          // next event
          ++keyboardPos;
        }

        // process mouse event
        if( mouseState != null )
        {
          //TODO: processing

          // next event
          ++mousePos;
        }
      }
    }

  } // class

} // namespace
