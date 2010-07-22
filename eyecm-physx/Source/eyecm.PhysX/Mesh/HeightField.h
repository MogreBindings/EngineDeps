//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public value struct             HeightFieldSample
  {
    internal:
      NxU32                     value;

    public:
      HeightFieldSample(short Height) { this->Height = Height; }
      HeightFieldSample(short Height, unsigned char MaterialIndex0, unsigned char MaterialIndex1, bool TesselationFlag)
        {
          Set( Height, MaterialIndex0, MaterialIndex1, TesselationFlag );
        }

      void                      Set(short Height, unsigned char MaterialIndex0, unsigned char MaterialIndex1, bool TesselationFlag)
        {
          this->Height          = Height;
          this->MaterialIndex0  = MaterialIndex0;
          this->MaterialIndex1  = MaterialIndex1;
          this->TesselationFlag = TesselationFlag;
        }

    public:
      property short            Height
        {
          short                 get()                                 { return reinterpret_cast<NxHeightFieldSample&>( value ).height; }
          void                  set(short v)                          { reinterpret_cast<NxHeightFieldSample&>( value ).height = v; }
        }

      property unsigned char    MaterialIndex0
        {
          unsigned char         get()                                 { return reinterpret_cast<NxHeightFieldSample&>( value ).materialIndex0; }
          void                  set(unsigned char v)                  { reinterpret_cast<NxHeightFieldSample&>( value ).materialIndex0 = v; }
        }

      property unsigned char    MaterialIndex1
        {
          unsigned char         get()                                 { return reinterpret_cast<NxHeightFieldSample&>( value ).materialIndex1; }
          void                  set(unsigned char v)                  { reinterpret_cast<NxHeightFieldSample&>( value ).materialIndex1 = v; }
        }

      property bool             TesselationFlag
        {
          bool                  get()                                 { return reinterpret_cast<NxHeightFieldSample&>( value ).tessFlag != 0; }
          void                  set(bool v)                           { reinterpret_cast<NxHeightFieldSample&>( value ).tessFlag = v ? 1 : 0; }
        }
  };

//=============================+=====================================+=
public ref struct               HeightFieldDesc:                      public giNxProxyData<NxHeightFieldDesc>
  {
    private:
      HeightFieldDesc(NxHeightFieldDesc& data): BaseType( data ) { }

    internal:
      static inline
      HeightFieldDesc^          Wrap(NxHeightFieldDesc& data)         { return gcnew HeightFieldDesc( data ); }

    public:
      HeightFieldDesc() { }

      HeightFieldDesc(unsigned RowCount, unsigned ColumnCount, float Thickness, HeightFieldFlags Flags)
        {
          this->RowCount          = RowCount;
          this->ColumnCount       = ColumnCount;
          this->Thickness         = Thickness;
          this->Flags             = Flags;
          this->SamplesByteStride = 4;
        }

      ~HeightFieldDesc() { UnpinPinned(); }

    public:
      DefValidDefaultUnpin
      DefCloneCopy( HeightFieldDesc )
      DefPinFuncs( HeightFieldDesc )

      generic<typename T>
      void                      PinSamples(array<T, 2>^ Source, unsigned ByteOffset, unsigned ByteStride);

    public:
      DefPtr( void,             Samples,                              samples, sampleStride )

      DefP0( unsigned,          RowCount,                             nbRows )
      DefP0( unsigned,          ColumnCount,                          nbColumns )
      DefPc(
        HeightFieldFormats,     Format,
        NxHeightFieldFormat,    format
      )
      DefP0( float,             Thickness,                            thickness )
      DefP0( float,             ConvexEdgeThreshold,                  convexEdgeThreshold )
      DefPc( HeightFieldFlags,  Flags,                         NxU32, flags )


    public:
      array<HeightFieldSample>^ MakePinnedSampleArray(unsigned RowCount, unsigned ColumnCount)
        {
          data->nbRows    = RowCount;
          data->nbColumns = ColumnCount;

          array<HeightFieldSample>^ result = gcnew array<HeightFieldSample>( RowCount * ColumnCount );
          PinSamples( result, 0, 0 );
          return result;
        }

      array<
        HeightFieldSample, 2
      >^                        MakePinnedSampleArray2D(unsigned RowCount, unsigned ColumnCount)
      {
          data->nbRows    = RowCount;
          data->nbColumns = ColumnCount;

          array<HeightFieldSample, 2>^ result = gcnew array<HeightFieldSample, 2>( RowCount, ColumnCount );
          PinSamples( result, 0, 0 );
          return result;
      }
  };

//=============================+=====================================+=
                                EndNamespace

