//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public ref struct               JointLimitDesc:                       public DefCBProxyBase<NxJointLimitDesc>
  {
    internal:
      DefCBProxyConstructors( JointLimitDesc )

    public:
      JointLimitDesc() { }
      JointLimitDesc(float Value) { this->Value = Value; }
      JointLimitDesc(float Value, float Restitution) { this->Value = Value; this->Restitution = Restitution; }
      JointLimitDesc(float Value, float Restitution, float Hardness) { this->Value = Value; this->Restitution = Restitution; this->Hardness = Hardness; }

    public:
      DefP0( float,             Value,                                value )
      DefP0( float,             Restitution,                          restitution )
      DefP0( float,             Hardness,                             hardness )
  };

//=============================+=====================================+=
public ref struct               JointLimitPairDesc:                   public DefCBProxyBase<NxJointLimitPairDesc>
  {
    internal:
      DefCBProxyConstructors( JointLimitPairDesc )

      void                      OnLowChanged(NxJointLimitDesc*)       { PostSet(); }
      void                      OnHighChanged(NxJointLimitDesc*)      { PostSet(); }

    public:
      JointLimitPairDesc() { }

      ~JointLimitPairDesc()
        {
          DefProxyDestroy( Low );
          DefProxyDestroy( High );
        }
      !JointLimitPairDesc()
        {
        }

    public:
      DefProxyGetSetX( JointLimitDesc, Low,  , gcnew JointLimitDesc::ChangedDelegate( this, &JointLimitPairDesc::OnLowChanged  ) DefPrefixComma( data->low  ) )
      DefProxyGetSetX( JointLimitDesc, High, , gcnew JointLimitDesc::ChangedDelegate( this, &JointLimitPairDesc::OnHighChanged ) DefPrefixComma( data->high ) )
  };

//=============================+=====================================+=
public ref struct               SpringDesc:                           public DefCBProxyBase<NxSpringDesc>
  {
    internal:
      DefCBProxyConstructors( SpringDesc )

    public:
      SpringDesc() { }
      SpringDesc(float Spring) { this->Spring = Spring; }
      SpringDesc(float Spring, float Damper) { this->Spring = Spring; this->Damper = Damper; }
      SpringDesc(float Spring, float Damper, float TargetValue) { this->Spring = Spring; this->Damper = Damper; this->TargetValue = TargetValue; }

    public:
      DefP0( float,             Spring,                               spring )
      DefP0( float,             Damper,                               damper )
      DefP0( float,             TargetValue,                          targetValue )
  };

//=============================+=====================================+=
public ref struct               MotorDesc:                            public DefCBProxyBase<NxMotorDesc>
  {
    internal:
      DefCBProxyConstructors( MotorDesc )

    public:
      MotorDesc() { }
      MotorDesc(float VelTarget) { this->VelTarget = VelTarget; }
      MotorDesc(float VelTarget, float MaxForce) { this->VelTarget = VelTarget; this->MaxForce = MaxForce; }
      MotorDesc(float VelTarget, float MaxForce, bool FreeSpin) { this->VelTarget = VelTarget; this->MaxForce = MaxForce; this->FreeSpin = FreeSpin; }

    public:
      DefP0( float,             VelTarget,                            velTarget )
      DefP0( float,             MaxForce,                             maxForce )
      DefPx( bool,              FreeSpin,                             freeSpin )
  };

//=============================+=====================================+=
public ref struct               JointLimitSoftDesc:                   public DefProxyBase<NxJointLimitSoftDesc>
  {
    internal:
      DefProxyConstructors( JointLimitSoftDesc )

    public:
      JointLimitSoftDesc() { }
      JointLimitSoftDesc(float Value) { this->Value = Value; }
      JointLimitSoftDesc(float Value, float Restitution) { this->Value = Value; this->Restitution = Restitution; }
      JointLimitSoftDesc(float Value, float Restitution, float Spring) { this->Value = Value; this->Restitution = Restitution; this->Spring = Spring; }
      JointLimitSoftDesc(float Value, float Restitution, float Spring, float Damping) { this->Value = Value; this->Restitution = Restitution; this->Spring = Spring; this->Damping = Damping; }

    public:
      DefP0( float,             Value,                                value )
      DefP0( float,             Restitution,                          restitution )
      DefP0( float,             Spring,                               spring )
      DefP0( float,             Damping,                              damping )
  };

//=============================+=====================================+=
public ref struct               JointLimitSoftPairDesc:               public DefProxyBase<NxJointLimitSoftPairDesc>
  {
    internal:
      DefProxyConstructors( JointLimitSoftPairDesc )

    public:
      JointLimitSoftPairDesc() { }

      ~JointLimitSoftPairDesc()
        {
          DefProxyDestroy( Low );
          DefProxyDestroy( High );
        }
      !JointLimitSoftPairDesc()
        {
        }

    public:
      DefProxyGetSet( JointLimitSoftDesc, Low,  low  )
      DefProxyGetSet( JointLimitSoftDesc, High, high )
  };

//=============================+=====================================+=
public ref struct               JointDriveDesc:                       public DefProxyBase<NxJointDriveDesc>
  {
    internal:
      DefProxyConstructorsX( JointDriveDesc, DefNothing )

    public:
      JointDriveDesc() { }
      JointDriveDesc(float Spring) { this->Spring = Spring; }
      JointDriveDesc(float Spring, float Damping) { this->Spring = Spring; this->Damping = Damping; }
      JointDriveDesc(float Spring, float Damping, float ForceLimit) { this->Spring = Spring; this->Damping = Damping; this->ForceLimit = ForceLimit; }
      JointDriveDesc(float Spring, float Damping, float ForceLimit, D6JointDriveTypes DriveType) { this->Spring = Spring; this->Damping = Damping; this->ForceLimit = ForceLimit; this->DriveType = DriveType; }

    public:
      DefP0( float,             Spring,                               spring )
      DefP0( float,             Damping,                              damping )
      DefP0( float,             ForceLimit,                           forceLimit )
      DefPc( D6JointDriveTypes, DriveType,       NxBitField::IntType, driveType.bitField )
  };

//=============================+=====================================+=
public ref struct               TireFunctionDesc:                     public DefCBProxyBase<NxTireFunctionDesc>
  {
    internal:
      DefCBProxyConstructors( TireFunctionDesc )

    public:
      TireFunctionDesc() { }

    public:
      DefP0( float,             ExtremumSlip,                         extremumSlip )
      DefP0( float,             ExtremumValue,                        extremumValue )
      DefP0( float,             AsymptoteSlip,                        asymptoteSlip )
      DefP0( float,             AsymptoteValue,                       asymptoteValue )
      DefP0( float,             StiffnessFactor,                      stiffnessFactor )

    public:
      float                     HermiteEval(float t)                  { return data->hermiteEval( t ); }
  };

//=============================+=====================================+=
                                EndNamespace

