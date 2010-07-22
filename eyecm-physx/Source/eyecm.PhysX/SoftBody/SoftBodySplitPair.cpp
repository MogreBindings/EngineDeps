//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "SoftBodySplitPair.h"

//=============================+=====================================+=
void                            SoftBodySplitPairData::UnpinPinned()
  {
    DefPinFree( SplitPairs, splitPairsBegin )
  }

//=============================+=====================================+=
void                            SoftBodySplitPairData::ClearCounts()
  {
    data->numSplitPairsPtr = 0;
  }

//=============================+=====================================+=
void                            SoftBodySplitPairData::CopyCustom(SoftBodySplitPairData^ other)
  {
    UnpinPinned();
    //
    DefPinCopy( SplitPairs, splitPairsBegin )
    //
    DefCntCopy( unsigned );
  }

//=============================+=====================================+=
void                            SoftBodySplitPairData::PostSet()
  {
    DefCntPostSet( numSplitPairsPtr, data->splitPairsBegin )
    //
    BaseType::PostSet();
  }

//=============================+=====================================+=
void                            SoftBodySplitPairData::PinSplitPairs(array<SoftBodySplitPair>^ Source)
  {
    UnpinPinned();

    pinSplitPairs         = GCHandle::Alloc( Source, GCHandleType::Pinned );
    data->splitPairsBegin = static_cast<NxSoftBodySplitPair*>( pinSplitPairs.AddrOfPinnedObject().ToPointer() );

    PostSet();
  }

//=============================+=====================================+=
void                            SoftBodySplitPairData::UnpinSplitPairs()
  {
    UnpinPinned();
    PostSet();
  }
