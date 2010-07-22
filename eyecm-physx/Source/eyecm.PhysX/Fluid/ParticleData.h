//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+= // TODO: has name
public ref struct               ParticleData:                         public DefCBProxyBase<NxParticleData>
  {
    internal:
      DefCBProxyConstructorsPin( ParticleData )

    public:
      ParticleData() { AutoManageCounts = true; }
      ParticleData(bool AutoManageCounts) { this->AutoManageCounts = AutoManageCounts; }

      ~ParticleData() { DeinitManaged();   }
      !ParticleData() { DeinitUnmanaged(); }

    internal:
      DefPinCntFuncs( ParticleData, unsigned )

    public:
        DefPtr( NxF32,          Positions,                            bufferPos,             bufferPosByteStride )
        DefPtr( NxF32,          Velocities,                           bufferVel,             bufferVelByteStride )
        DefPtr( NxF32,          Lives,                                bufferLife,            bufferLifeByteStride )
        DefPtr( NxF32,          Densities,                            bufferDensity,         bufferDensityByteStride )
        DefPtr( NxU32,          IDs,                                  bufferId,              bufferIdByteStride )
        DefPtr( NxU32,          Flags,                                bufferFlag,            bufferFlagByteStride )
        DefPtr( NxF32,          CollisionNormals,                     bufferCollisionNormal, bufferCollisionNormalByteStride )

        DefCntSet(              Particle,                             numParticlesPtr )
  };

//=============================+=====================================+= // TODO: has name
public ref struct               ParticleIDData:                       public DefCBProxyBase<NxParticleIdData>
  {
    internal:
      DefCBProxyConstructorsPin( ParticleIDData )

    public:
      ParticleIDData() { AutoManageCounts = true; }
      ParticleIDData(bool AutoManageCounts) { this->AutoManageCounts = AutoManageCounts; }

      ~ParticleIDData() { DeinitManaged();   }
      !ParticleIDData() { DeinitUnmanaged(); }

    internal:
      DefPinCntFuncs( ParticleIDData, unsigned )

    public:
      DefPtr( NxU32,            IDs,                                  bufferId, bufferIdByteStride )

      DefCnt(                   ParticleID,                           numIdsPtr )
  };

//=============================+=====================================+= // TODO: has name
public ref struct               ParticleUpdateData:                   public giNxData<NxParticleUpdateData>
  {
    internal:
      DefDataConstructorsPin( ParticleUpdateData );

    public:
      ParticleUpdateData() { }

      ~ParticleUpdateData() { UnpinPinned(); }

    internal:
      DefPinFuncs( ParticleUpdateData )

    public:
      DefPtr( NxF32,            Forces,                               bufferForce, bufferForceByteStride )
      DefPtr( NxU32,            Flags,                                bufferFlag,  bufferFlagByteStride  )
      DefPtr( NxU32,            IDs,                                  bufferId,    bufferIdByteStride    )

      DefP0( unsigned,          UpdateCount,                          numUpdates )
      DefPc( ForceModes,        ForceMode,               NxForceMode, forceMode )
  };

//=============================+=====================================+=
[                 StructLayout( LayoutKind::Explicit )                ]
//=============================+=====================================+=
public value struct             FluidPacket
  {
    internal:
      typedef                   NxFluidPacket                         NxType;

    internal:
      [                         FieldOffsetAttribute( 0 )             ]
      unsigned char             first;

      [                         FieldOffsetAttribute( sizeof( NxFluidPacket ) - 1 )]
      unsigned char             last;

      inline void               PostSet()                           { }

    public:
      property AxisAlignedBox   AABB
        {
          AxisAlignedBox        get()                                 { pin_ptr<void> p = &first; return FromNx( static_cast<NxType*>( p )->aabb ); }
          void                  set(AxisAlignedBox v)                 { pin_ptr<void> p = &first; static_cast<NxType*>( p )->aabb = ToNx( v ); }
        }

      #define                   TempDef(name, token) \
        property unsigned       name \
          { \
            unsigned            get()                                 { pin_ptr<void> p = &first; return static_cast<NxType*>( p )->token; } \
            void                set(unsigned v)                       { pin_ptr<void> p = &first; static_cast<NxType*>( p )->token = v; } \
          }

        TempDef(                FirstParticleIndex,                   firstParticleIndex )
        TempDef(                ParticleCount,                        numParticles )
        TempDef(                PacketID,                             packetID )

      #undef                    TempDef
  };

//=============================+=====================================+= // TODO: has name
public ref struct               FluidPacketData:                      public DefCBProxyBase<NxFluidPacketData>
  {
    internal:
      DefCBProxyConstructorsPin( FluidPacketData )

    public:
      FluidPacketData() { AutoManageCounts = true; }
      FluidPacketData(bool AutoManageCounts) { this->AutoManageCounts = AutoManageCounts; }

      ~FluidPacketData() { DeinitManaged();   }
      !FluidPacketData() { DeinitUnmanaged(); }

    internal:
      DefPinCntFuncs( FluidPacketData, unsigned )

    public:
      DefPtrNS( NxFluidPacket,  FluidPackets,                         bufferFluidPackets, FluidPacket )

      DefCnt(                   FluidPacket,                          numFluidPacketsPtr )
  };


//=============================+=====================================+=
                                EndNamespace
