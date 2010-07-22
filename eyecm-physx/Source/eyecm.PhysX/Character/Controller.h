//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "ControllerManager.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       ControllerShapeHit;
ref class                       ControllersHit;
ref struct                      GroupsMask;

class                           giNxUserControllerHitReport;

//=============================+=====================================+=
public interface class          IUserControllerHitReport
  {
    public:
      virtual
      ControllerActions         OnShapeHit(ControllerShapeHit^) = 0;
      virtual 
      ControllerActions         OnControllerHit(ControllersHit^) = 0;
  };
  
//=============================+=====================================+=
#define                         DefVec3ExtIgnore(tokens)
#define                         DefVec3ExtVerbatim(tokens) tokens
#define                         DefVec3ExtDescSet(token, val) data->token = val;
#define                         DefVec3ExtMethodSet(token, val) data->set##token( val );
#define                         DefVec3ExtDescGet(token) data->token
#define                         DefVec3ExtMethodGet(token) data->get##token()
//
#define                         DefVec3ExtX( name, token, getmacro, setmacro, getfilter, setfilter ) \
      property Vector3          name \
        { \
          getfilter( Vector3    get() \
            { \
              NxExtendedVec3 res = getmacro( token ); \
              \
              return FromNx( NxVec3( static_cast<NxF32>( res.x ), static_cast<NxF32>( res.y ), static_cast<NxF32>( res.z ) ) ); \
            } ) \
          \
          setfilter( void       set(Vector3 vec) \
          { \
            NxVec3 nxvec = ToNx( vec ); \
            \
            setmacro( token, NxExtendedVec3( nxvec.x, nxvec.y, nxvec.z ) ) \
          } ) \
        } \
      property array<double>^   name##Extended \
        { \
          getfilter( array<double>^ get() \
            { \
              array<double>^ res = gcnew array<double>( 3 ); \
              NxExtendedVec3 src = getmacro( token ); \
              \
              res[0] = src.x; \
              res[1] = src.y; \
              res[2] = src.z; \
              \
              return res; \
            } ) \
          \
          setfilter( void       set(array<double>^ val) \
            { \
              setmacro( token, NxExtendedVec3( val[0], val[1], val[2] ) ); \
            } ) \
        } \

//=============================+=====================================+=
#define                         DefVec3Ext(name, token)               DefVec3ExtX( name, token, DefVec3ExtDescGet,   DefVec3ExtDescSet,   DefVec3ExtVerbatim, DefVec3ExtVerbatim )
#define                         DefVec3ExtR(name, token)              DefVec3ExtX( name, token, DefVec3ExtDescGet,   DefVec3ExtDescSet,   DefVec3ExtVerbatim, DefVec3ExtIgnore   )
#define                         DefVec3ExtM(name, token)              DefVec3ExtX( name, token, DefVec3ExtMethodGet, DefVec3ExtMethodSet, DefVec3ExtVerbatim, DefVec3ExtVerbatim )
#define                         DefVec3Extm(name, token)              DefVec3ExtX( name, token, DefVec3ExtMethodGet, DefVec3ExtMethodSet, DefVec3ExtVerbatim, DefVec3ExtIgnore   )
#define                         DefVec3ExtS(name, token)              DefVec3ExtX( name, token, DefVec3ExtMethodGet, DefVec3ExtMethodSet, DefVec3ExtIgnore,   DefVec3ExtVerbatim )

//=============================+=====================================+=
#define                         DefControllerBaseProps \
	    Defm0( unsigned,          Version,                              Version     ) \
	    Defmc( ControllerTypes,   Type,                                 Type        ) \
	    DefPc( HeightFieldAxes,   UpDirection,       NxHeightFieldAxis, upDirection ) \
			DefP0( float,             SlopeLimit,                           slopeLimit  ) \
      DefP0( float,             SkinWidth,                            skinWidth   ) \
      DefP0( float,             StepOffset,                           stepOffset  ) \
      \
      DefPc( CCTInteractionFlags, InteractionFlags, NxCCTInteractionFlag, interactionFlag ) \
      DefVec3Ext(               Position,                             position ) \
      \
      property IUserControllerHitReport^ Callback                     { IUserControllerHitReport^ get(); void set(IUserControllerHitReport^); } \
      property Object^          UserData                              { Object^ get() { return userData; } void set(Object^ val) { userData = val; } }
	
//=============================+=====================================+=
public ref class                BoxControllerDesc:                    public giNxProxyData<NxBoxControllerDesc>
  {
    internal:
      property NxType*          ptr                                   { NxType* get() { return GetNx(); } }
      
      Object^                   userData;
      
    public:
      BoxControllerDesc() { }
      
    public:
      DefPx( Vector3,           Extents,                              extents )
      //
      DefControllerBaseProps
      DefValidDefault
  };

//=============================+=====================================+=
public ref class                CapsuleControllerDesc:                public giNxProxyData<NxCapsuleControllerDesc>
  {
    internal:
      property NxType*          ptr                                   { NxType* get() { return GetNx(); } }
      
      Object^                   userData;
      
    public:
      CapsuleControllerDesc() { }
      
    public:
      DefP0( float,             Radius,                               radius )
      DefP0( float,             Height,                               height )
      //
      DefPc( CapsuleClimbingModes, ClimbingMode, NxCapsuleClimbingMode, climbingMode )
      //
      DefControllerBaseProps      
      DefValidDefault
  };

//=============================+=====================================+=
public ref class                Controller:                           public giNxProxy<NxController, giNxRegisteredObject<ControllerManager> >
  {
    internal:
      Controller(ControllerManager^, Scene^, NxType *ptr);
      
    internal:
      static Controller^        Cast(NxType*);
      
      Object^                   userData;
      //
      giNxUserControllerHitReport* callbackptr;
      //
      gcroot<Controller^>*      rootptr;
      
      typedef                   ThisNamespace::Actor                  giActor;
      
    public:
      ~Controller();
      !Controller();
      
    public:
      DefVec3ExtM(              Position,                             Position         )
      DefVec3Extm(              FilteredPosition,                     FilteredPosition )
      DefVec3Extm(              DebugPosition,                        DebugPosition    )
      //
      Defs0( float,             StepOffset,                           StepOffset       )
      Defs0( bool,              Collision,                            Collision        )
      Defmc( ControllerTypes,   Type,                                 Type             )
      DefMc( 
        CCTInteractionFlags,    Interaction,    NxCCTInteractionFlag, Interaction      )
        
      property Object^          UserData                              { Object^ get() { return userData; } }
      property giActor^         Actor                                 { giActor^ get(); }

    public:      
      void                      Move(Vector3 Displacement, unsigned ActiveGroups, float MinDistance, [Out] ControllerFlags% CollisionFlags)                  { Move( Displacement, ActiveGroups, MinDistance, CollisionFlags, 1,         nullptr ); }
      void                      Move(Vector3 Displacement, unsigned ActiveGroups, float MinDistance, [Out] ControllerFlags% CollisionFlags, float Sharpness) { Move( Displacement, ActiveGroups, MinDistance, CollisionFlags, Sharpness, nullptr ); }
      void                      Move(Vector3 Displacement, unsigned ActiveGroups, float MinDistance, [Out] ControllerFlags% CollisionFlags, float Sharpness, GroupsMask^ GroupsMask);
      //
      void                      ReportSceneChanged()                  { GetNx()->reportSceneChanged(); }
  };

//=============================+=====================================+=
public ref class                BoxController:                        public Controller
  {
      DefRecastData(            NxBoxController,                      Controller );
      
    internal:
      BoxController(ControllerManager^ mng, Scene^ scene, NxType* data): Controller( mng, scene, data ) { }
      
    public:
      DefMx( Vector3,           Extents,                              Extents )
  };

//=============================+=====================================+=
public ref class                CapsuleController:                    public Controller
  {
      DefRecastData(            NxCapsuleController,                  Controller );
      
    internal:
      CapsuleController(ControllerManager^ mng, Scene^ scene, NxType* data): Controller( mng, scene, data ) { }
      
    public:
      DefM0( float,             Radius,                               Radius )
      DefM0( float,             Height,                               Height )
      DefMc( 
        CapsuleClimbingModes,   ClimbingMode,  NxCapsuleClimbingMode, ClimbingMode )
  };
  
//=============================+=====================================+=
                                EndNamespace

