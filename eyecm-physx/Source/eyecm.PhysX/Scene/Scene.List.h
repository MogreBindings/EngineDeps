//=============================+=====================================+=
//public ref class                Scene:                                public giNxObject<NxScene, Scene, giNxRegisteredObject<Physics> >
//  {

    private:
      void                      InitLists();
      void                      DeInitLists();

      #define                   DefList( type, name ) \
      \
      private: \
      typedef                   ReadOnlyCollection<type^>             type##sList; \
      \
      type##sList^              list##type##s; \
      \
    public: \
      property type##sList^     name \
        { \
          type##sList^          get()                                 { return list##type##s; } \
        } \

      DefList                 ( Material,   Materials )
      DefList                 ( Actor,      Actors )
      DefList                 ( Cloth,      Cloths )
      DefList                 ( Fluid,      Fluids )
      DefList                 ( SoftBody,   SoftBodies )
      DefList                 ( ForceField, ForceFields )

      #undef                    DefList

    #define                     DefEnumerable( type, name ) \
    private: \
      typedef                   IEnumerableWithCount<type^>          type##Enumerable; \
      type##Enumerable^         enum##type; \
    public: \
      property \
      type##Enumerable^         name \
        { \
          type##Enumerable^     get()                                 { return enum##type; } \
        } \
        
      DefEnumerable           ( Joint,                  Joints )
      DefEnumerable           ( ForceFieldShapeGroup,   ForceFieldShapeGroups )
      DefEnumerable           ( ForceFieldLinearKernel, ForceFieldLinearKernels )
//  };

//=============================+=====================================+=
