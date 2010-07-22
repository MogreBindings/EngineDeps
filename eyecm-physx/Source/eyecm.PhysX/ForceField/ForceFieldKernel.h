//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Scene;

//=============================+=====================================+= // TODO: has name
public ref struct               ForceFieldLinearKernelDesc:           public giNxData<NxForceFieldLinearKernelDesc>
  {
    public:
      ForceFieldLinearKernelDesc() { }
      ~ForceFieldLinearKernelDesc() { }
      
      DefValidDefault

    public:
      DefPx( Vector3,           Constant,                             constant )
      DefPx( Matrix3x3,         PositionMultiplier,                   positionMultiplier )
      DefPx( Vector3,           PositionTarget,                       positionTarget )
      DefPx( Matrix3x3,         VelocityMultiplier,                   velocityMultiplier )
      DefPx( Vector3,           VelocityTarget,                       velocityTarget )
      DefP0( float,             TorusRadius,                          torusRadius )
      DefPx( Vector3,           FalloffLinear,                        falloffLinear )
      DefPx( Vector3,           FalloffQuadratic,                     falloffQuadratic )
      DefPx( Vector3,           Noise,                                noise )
  };
  
//=============================+=====================================+= // TODO: subclass has name
public ref class                ForceFieldKernel:                     public giNxObject<NxForceFieldKernel, ForceFieldKernel, giNxRegisteredObject<Scene> >
  {
    internal:
      ForceFieldKernel(NxType* ptr): BaseType( ptr ) { }

    public:
      ~ForceFieldKernel() { }
    
    public:
  };
  
//=============================+=====================================+=
public ref class                ForceFieldLinearKernel:               public ForceFieldKernel
  {
    internal:
      DefRecastPtr( NxForceFieldLinearKernel, ForceFieldKernel )
      
      typedef                   NxForceFieldLinearKernel              NxType;
      typedef                   ThisNamespace::Scene                  giScene;

    internal:      
      ForceFieldLinearKernel(NxForceFieldLinearKernel*);
      
      inline static
      ForceFieldLinearKernel^   CastOrNull(NxType* ptr)               { return static_cast<ForceFieldLinearKernel^>( ForceFieldKernel::CastOrNull( ptr ) ); }

    public:
      ~ForceFieldLinearKernel();

      DefSaveToDesc( ForceFieldLinearKernel )
          
    public:
      property giScene^         Scene
        {
          giScene^              get()                                 { return Owner; }
        }

    public:
      DefMx( Vector3,           Constant,                             Constant )
      DefMx( Matrix3x3,         PositionMultiplier,                   PositionMultiplier )
      DefMx( Vector3,           PositionTarget,                       PositionTarget )
      DefMx( Matrix3x3,         VelocityMultiplier,                   VelocityMultiplier )
      DefMx( Vector3,           VelocityTarget,                       VelocityTarget )
      DefM0( float,             TorusRadius,                          TorusRadius )
      DefMx( Vector3,           FalloffLinear,                        FalloffLinear )
      DefMx( Vector3,           FalloffQuadratic,                     FalloffQuadratic )
      DefMx( Vector3,           Noise,                                Noise )
  };

//=============================+=====================================+=
                                EndNamespace
