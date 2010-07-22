//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "ForceFieldShapeDesc.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       ForceFieldShapeGroup;

//=============================+=====================================+=
public ref class                ForceFieldShape:                      public giNxNamedObject<NxForceFieldShape, ForceFieldShape, giNxRegisteredObject<ForceFieldShapeGroup> >
  {
    internal:
      typedef                   ThisNamespace::ForceFieldShapeGroup   giForceFieldShapeGroup;
      
    internal:
      ForceFieldShape(NxType* ptr);
      
      static ForceFieldShape^   Wrap(NxType*);
      
    public:
      ~ForceFieldShape();
      
    public:
      property 
      giForceFieldShapeGroup^   ShapeGroup                            { giForceFieldShapeGroup^ get(); }
      
      Defmc( ShapeTypes,        Type,                                 Type )
  };

//=============================+=====================================+=
                                EndNamespace
