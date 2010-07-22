//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "eyecmPhysX.h"

//=============================+=====================================+=
using namespace                 System::IO;

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
class                           giNxStream:                           public NxStream
  {
    private:
      gcroot<BinaryReader^>     rd;
      gcroot<BinaryWriter^>     wr;

    public:
      giNxStream(Stream^ str)
        {
          rd = gcnew BinaryReader( str );
          wr = gcnew BinaryWriter( str );
        }

      ~giNxStream()
        {
          BinaryReader^ trd; delete trd; rd = nullptr;
          BinaryWriter^ twr; delete twr; wr = nullptr;
        }

    private:
      NxU8                      readByte()                      const { return rd->ReadByte(); }
      NxU16                     readWord()                      const { return rd->ReadUInt16(); }
      NxU32                     readDword()                     const { return rd->ReadUInt32(); }
      NxF32                     readFloat()                     const { return rd->ReadSingle(); }
      NxF64                     readDouble()                    const { return rd->ReadDouble(); }

      void                      readBuffer(void* buffer, NxU32 size) const
        {
          const unsigned chunkcount = size / 8;
          NxU64*         p64        = static_cast<NxU64*>( buffer );

          for( unsigned i = 0; i < chunkcount; i++ )
            p64[i] = rd->ReadUInt64();

          NxU8* p8 = static_cast<NxU8*>( buffer );

          for( unsigned i = chunkcount * 8; i < size; i++ )
            p8[i] = rd->ReadByte();
        }

      NxStream&                  storeByte(NxU8 b)                     { wr->Write( b ); return *this; }
      NxStream&                  storeWord(NxU16 w)                    { wr->Write( w ); return *this; }
      NxStream&                  storeDword(NxU32 d)                   { wr->Write( d ); return *this; }
      NxStream&                  storeFloat(NxF32 f)                   { wr->Write( f ); return *this; }
      NxStream&                  storeDouble(NxF64 f)                  { wr->Write( f ); return *this; }

      NxStream&                  storeBuffer(const void* buffer, NxU32 size)
        {
          const unsigned chunkcount = size / 8;
          const NxU64*   p64        = static_cast<const NxU64*>( buffer );

          for( unsigned  i = 0; i < chunkcount; i++ )
            wr->Write( p64[i] );

          const NxU8* p8 = static_cast<const NxU8*>( buffer );

          for( unsigned  i = chunkcount * 8; i < size; i++ )
            wr->Write( p8[i] );

          return *this;
        }
  };

//=============================+=====================================+=
                                EndNamespace

