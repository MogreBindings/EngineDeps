using System;

namespace MyGame.Engine.Objects
{
  /************************************************************************/
  /*                                                                      */
  /************************************************************************/
  public class PickInfo
  {
    //////////////////////////////////////////////////////////////////////////
    private Object3D mObject3D;
    private float mDistance;

    //////////////////////////////////////////////////////////////////////////
    public Object3D Object
    {
      get { return mObject3D; }
    }

    //////////////////////////////////////////////////////////////////////////
    public float Distance
    {
      get { return mDistance; }
    }

    /************************************************************************/
    /* constructor                                                          */
    /************************************************************************/
    public PickInfo(Object3D _obj, float _distance)
    {
      mObject3D = _obj;
      mDistance = _distance;
    }

  } // class

} // namespace
