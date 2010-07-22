//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "RaycastObjects.h"
#include                       "nxenumerable.h"
#include                       "ForceFieldDesc.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Scene;
ref class                       Actor;
ref class                       ForceFieldKernel;

//=============================+=====================================+=
public ref class                ForceField:                           giNxNamedObject<NxForceField, ForceField, giNxRegisteredObject<Scene> >
  {
    internal:
      typedef                   ThisNamespace::Scene                  giScene;
      typedef                   ThisNamespace::Actor                  giActor;
      typedef                   ThisNamespace::GroupsMask             giGroupsMask;
      typedef                   ThisNamespace::ForceFieldKernel       giForceFieldKernel;
      
    internal:
      ForceField(NxType* ptr);
      
      inline static ForceField^ Wrap(NxType* ptr)                     { return gcnew ForceField( ptr ); }
      
      void                      OnGroupsMaskChanged(NxGroupsMask* data) { GetNx()->setGroupsMask( *data ); }

    public:
      ~ForceField();
      
      DefSaveToDesc( ForceField )
      
    public:
      property giScene^         Scene
        {
          giScene^              get()                                 { return Owner; }
        }
        
      property giActor^         Actor                                 { giActor^ get(); void set(giActor^); }

      property 
      giForceFieldKernel^       ForceFieldKernel                      { giForceFieldKernel^ get(); void set(giForceFieldKernel^); }
        
    public:
      DefMx( Matrix4x4,         Pose,                                 Pose )
      DefMc( unsigned,          Group,              NxCollisionGroup, Group )
      DefMc( 
        ForceFieldCoordinates,  Coordinates,
        NxForceFieldCoordinates, Coordinates
      )
      DefMc( ForceFieldTypes,   FluidType,          NxForceFieldType, FluidType )
      DefMc( ForceFieldTypes,   ClothType,          NxForceFieldType, ClothType )
      DefMc( ForceFieldTypes,   SoftBodyType,       NxForceFieldType, SoftBodyType )
      DefMc( ForceFieldTypes,   RigidBodyType,      NxForceFieldType, RigidBodyType )
      DefMc( ForceFieldFlags,   Flags,             NxForceFieldFlags, Flags )
      DefMc( unsigned,          ForceFieldVariety, NxForceFieldVariety, ForceFieldVariety )
      
      DefProxyGetSetm( ForceField, giGroupsMask, GroupsMask )
      
    public:
      property 
        IEnumerableWithCount<
          ForceFieldShapeGroup^
        >^                      ShapeGroups                           { IEnumerableWithCount<ForceFieldShapeGroup^>^ get(); }
                
    public:
      void                      AddShapeGroup(ForceFieldShapeGroup^ ShapeGroup);
      void                      RemoveShapeGroup(ForceFieldShapeGroup^ ShapeGroup);

      void                      SamplePoints(array<float>^ Points, array<float>^ Velocities, [Out] array<float>^% Forces, [Out] array<float>^% Torques)
        {
          const int cnt = Velocities == nullptr ? Points->Length : System::Math::Min( Points->Length, Velocities->Length );
          
          Forces  = gcnew array<float>( cnt );
          Torques = gcnew array<float>( cnt );
          
          pin_ptr<float> pts  = &Points[0];
          pin_ptr<float> vels = Velocities == nullptr ? nullptr : &Velocities[0];
          pin_ptr<float> fs   = &Forces[0];
          pin_ptr<float> ts   = &Torques[0];
          
          GetNx()->samplePoints( cnt / 3, reinterpret_cast<const NxVec3*>( pts ), reinterpret_cast<const NxVec3*>( vels ), reinterpret_cast<NxVec3*>( fs ), reinterpret_cast<NxVec3*>( ts ) );
        }
  };
  
//=============================+=====================================+=
                                EndNamespace
