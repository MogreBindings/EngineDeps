//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "ForceFieldShapeDesc.h"
#include                       "nxenumerable.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Physics;
ref class                       Scene;
ref class                       ForceFieldShape;

//=============================+=====================================+= // TODO: has name
public ref struct               ForceFieldShapeGroupDesc:             public giNxProxyData<NxForceFieldShapeGroupDesc>
  {
    private:
      ForceFieldShapeGroupDesc(Physics^ physics, NxType& desc): BaseType( desc ) { InitShapes( physics ); }
      
    internal:
      inline static ForceFieldShapeGroupDesc^ Wrap(Physics^ physics, NxType& desc) { return gcnew ForceFieldShapeGroupDesc( physics, desc ); }

    public:
      ForceFieldShapeGroupDesc() { InitShapes( nullptr ); }
      ~ForceFieldShapeGroupDesc() { DeinitShapes(); }
      
      DefValidDefault

    public:      
      DefArrayListParam( ForceFieldShapeDesc, Shapes, &data->shapes, Physics )
        
      DefPc( ForceFieldShapeGroupFlags, Flags,                 NxU32, flags )
  };

//=============================+=====================================+=
public ref class                ForceFieldShapeGroup:                 public giNxNamedObject<NxForceFieldShapeGroup, ForceFieldShapeGroup, giNxRegisteredObject<Scene> >
  {
    internal:
      typedef                   ThisNamespace::Scene                  giScene;
      
      inline static 
      ForceFieldShapeGroup^     Wrap(Physics^, NxType& ptr)           { return gcnew ForceFieldShapeGroup( &ptr ); }
  
    internal:
      ForceFieldShapeGroup(NxForceFieldShapeGroup*);
      
      giNxRegisteredObject<ForceFieldShapeGroup>^ First;
      
    public:
      ~ForceFieldShapeGroup();
      
      DefSaveToDesc( ForceFieldShapeGroup )
      
    public:
      property giScene^         Scene
        {
          giScene^              get()                                 { return Owner; }
        }
                
      property 
      IEnumerableWithCount<
        ForceFieldShape^
      >^                        Shapes                                { IEnumerableWithCount<ForceFieldShape^>^ get(); }
      
    public:
      Defmc( ForceFieldShapeGroupFlags, Flags,                        Flags )
      
    public:
      ForceFieldShape^          CreateShape(ForceFieldShapeDesc^ Desc);
  };
  
//=============================+=====================================+=
                                EndNamespace
                                