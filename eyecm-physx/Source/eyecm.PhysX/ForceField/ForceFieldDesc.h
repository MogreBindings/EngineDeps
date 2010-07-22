//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "RaycastObjects.h"
#include                       "ForceFieldShapeGroup.h"
#include                       "nxarraylist.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Actor;
ref class                       ForceFieldKernel;

//=============================+=====================================+= // TODO: has name
public ref struct               ForceFieldDesc:                       public giNxProxyData<NxForceFieldDesc>
  {
    internal: 
      typedef                   ThisNamespace::Actor                  giActor;
      typedef                   ThisNamespace::GroupsMask             giGroupsMask;
      typedef                   ThisNamespace::ForceFieldKernel       giForceFieldKernel;
      
    private:
      ForceFieldDesc(Physics^ physics, NxType& desc): BaseType( desc ) { InitIncludeGroupShapes( physics ); InitShapeGroups( physics ); }

    internal:
      inline static 
      ForceFieldDesc^           Wrap(Physics^ physics, NxType& desc) { return gcnew ForceFieldDesc( physics, desc ); }
      
    public:
      ForceFieldDesc() { InitIncludeGroupShapes( nullptr ); InitShapeGroups( nullptr ); }        
      ~ForceFieldDesc() 
      { 
        DeinitIncludeGroupShapes(); 
        DeinitShapeGroups(); 
        //
        DefProxyDestroy( GroupsMask );
      }
    
      DefValidDefault
          
    public:
      DefArrayListParam( ForceFieldShapeDesc, IncludeGroupShapes, &data->includeGroupShapes, Physics )
      DefArrayListParam( ForceFieldShapeGroup, ShapeGroups, &data->shapeGroups, Physics )
      
      DefProxyGetSet( giGroupsMask, GroupsMask, groupsMask )
      
      property giActor^         Actor                                 { giActor^ get(); void set(giActor^); }
      
      property 
      giForceFieldKernel^       ForceFieldKernel                      { giForceFieldKernel^ get(); void set(giForceFieldKernel^); }

    public:
      DefPx( Matrix4x4,         Pose,                                 pose )
      DefPc( 
        ForceFieldCoordinates,  Coordinates,
        NxForceFieldCoordinates, coordinates
      )
      DefPc( unsigned,          Group,              NxCollisionGroup, group )
      DefPc( unsigned,          ForceFieldVariety, NxForceFieldVariety, forceFieldVariety )
      DefPc( ForceFieldTypes,   FluidType,          NxForceFieldType, fluidType )
      DefPc( ForceFieldTypes,   ClothType,          NxForceFieldType, clothType )
      DefPc( ForceFieldTypes,   SoftBodyType,       NxForceFieldType, softBodyType )
      DefPc( ForceFieldTypes,   RigidBodyType,      NxForceFieldType, rigidBodyType )      
      DefPc( ForceFieldFlags,   Flags,             NxForceFieldFlags, flags )      
  };

//=============================+=====================================+=
                                EndNamespace
