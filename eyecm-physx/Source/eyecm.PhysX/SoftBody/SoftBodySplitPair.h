//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
[                 StructLayout( LayoutKind::Explicit )                ]
//=============================+=====================================+=
public value struct             SoftBodySplitPair
  {
    internal:
      typedef                   NxSoftBodySplitPair                   NxType;

    internal:
      [                         FieldOffsetAttribute( 0 )             ]
      unsigned char             first;

      [                         FieldOffsetAttribute( sizeof( NxSoftBodySplitPair ) - 1 )]
      unsigned char             last;

      inline void               PostSet()                           { }

    public:
      #define                   TempDef(ret, name, token) \
        property ret            name \
          { \
            ret                 get()                                 { pin_ptr<void> p = &first; return static_cast<NxType*>( p )->token; } \
            void                set(ret v)                            { pin_ptr<void> p = &first; static_cast<NxType*>( p )->token = v; } \
          }

        TempDef( unsigned,      TetrahedronIndex0,                    tetrahedronIndex0 )
        TempDef( unsigned,      TetrahedronIndex1,                    tetrahedronIndex1 )
        TempDef( unsigned char, FaceIndex0,                           faceIndex0 )
        TempDef( unsigned char, FaceIndex1,                           faceIndex1 )

      #undef                    TempDef
  };

//=============================+=====================================+= // TODO: has name
public ref struct               SoftBodySplitPairData:                public DefCBProxyBase<NxSoftBodySplitPairData>
  {
    internal:
      DefCBProxyConstructorsPin( SoftBodySplitPairData )

    public:
      SoftBodySplitPairData() { AutoManageCounts = true; }
      SoftBodySplitPairData(bool AutoManageCounts) { this->AutoManageCounts = AutoManageCounts; }

      ~SoftBodySplitPairData() { DeinitManaged();   }
      !SoftBodySplitPairData() { DeinitUnmanaged(); }

    internal:
      DefPinCntFuncs( SoftBodySplitPairData, unsigned )

    public:
      DefPtrA(
        NxSoftBodySplitPair,    SplitPairs,                           splitPairsBegin, splitPairsByteStride, SoftBodySplitPair )

      DefCnt(                   SplitPair,                            numSplitPairsPtr )
      DefP0( unsigned,          MaxSplitPairCount,                    maxSplitPairs )
  };

//=============================+=====================================+=
                                EndNamespace
