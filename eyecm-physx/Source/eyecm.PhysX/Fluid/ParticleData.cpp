//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "ParticleData.h"

//=============================+=====================================+=
DefPinUnpinImpl( NxF32,         Positions,                            bufferPos             , ParticleData )
DefPinUnpinImpl( NxF32,         Velocities,                           bufferVel             , ParticleData )
DefPinUnpinImpl( NxF32,         Lives,                                bufferLife            , ParticleData )
DefPinUnpinImpl( NxF32,         Densities,                            bufferDensity         , ParticleData )
DefPinUnpinImpl( NxU32,         IDs,                                  bufferId              , ParticleData )
DefPinUnpinImpl( NxU32,         Flags,                                bufferFlag            , ParticleData )
DefPinUnpinImpl( NxF32,         CollisionNormals,                     bufferCollisionNormal , ParticleData )
//=============================+=====================================+=
DefPinUnpinImpl( NxU32,         IDs,                                  bufferId, ParticleIDData )
//=============================+=====================================+=
DefPinUnpinImpl( NxF32,         Forces,                               bufferForce, ParticleUpdateData )
DefPinUnpinImpl( NxU32,         Flags,                                bufferFlag,  ParticleUpdateData )
DefPinUnpinImpl( NxU32,         IDs,                                  bufferId,    ParticleUpdateData )

//=============================+=====================================+=
void                            ParticleData::UnpinPinned()
  {
    DefPinFree( Positions,        bufferPos             )
    DefPinFree( Velocities,       bufferVel             )
    DefPinFree( Lives,            bufferLife            )
    DefPinFree( Densities,        bufferDensity         )
    DefPinFree( IDs,              bufferId              )
    DefPinFree( Flags,            bufferFlag            )
    DefPinFree( CollisionNormals, bufferCollisionNormal )
  }

//=============================+=====================================+=
void                            ParticleData::ClearCounts()
  {
    data->numParticlesPtr = 0;
  }

//=============================+=====================================+=
void                            ParticleData::CopyCustom(ParticleData^ other)
  {
    // TODO: what happens after SetToDefault? Must unpin all
    UnpinPinned();
    //
    DefPinCopy( Positions,        bufferPos             )
    DefPinCopy( Velocities,       bufferVel             )
    DefPinCopy( Lives,            bufferLife            )
    DefPinCopy( Densities,        bufferDensity         )
    DefPinCopy( IDs,              bufferId              )
    DefPinCopy( Flags,            bufferFlag            )
    DefPinCopy( CollisionNormals, bufferCollisionNormal )
    //
    DefCntCopy( unsigned );
  }

//=============================+=====================================+=
void                            ParticleData::PostSet()
  {
    DefCntPostSet( numParticlesPtr, data->bufferPos || data->bufferVel || data->bufferLife || data->bufferDensity || data->bufferId || data->bufferFlag || data->bufferCollisionNormal )
    //
    BaseType::PostSet();
  }



//=============================+=====================================+=
void                            ParticleIDData::UnpinPinned()
  {
    DefPinFree( IDs, bufferId )
  }

//=============================+=====================================+=
void                            ParticleIDData::ClearCounts()
  {
    data->numIdsPtr = 0;
  }

//=============================+=====================================+=
void                            ParticleIDData::CopyCustom(ParticleIDData^ other)
  {
    UnpinPinned();
    //
    DefPinCopy( IDs, bufferId )
    //
    DefCntCopy( unsigned );
  }

//=============================+=====================================+=
void                            ParticleIDData::PostSet()
  {
    DefCntPostSet( numIdsPtr, data->bufferId )
    //
    BaseType::PostSet();
  }




//=============================+=====================================+=
void                            ParticleUpdateData::UnpinPinned()
  {
    DefPinFree( Forces, bufferForce )
    DefPinFree( Flags,  bufferFlag  )
    DefPinFree( IDs,    bufferId    )
  }

//=============================+=====================================+=
void                            ParticleUpdateData::CopyCustom(ParticleUpdateData^ other)
  {
    UnpinPinned();
    //
    DefPinCopy( Forces, bufferForce )
    DefPinCopy( Flags,  bufferFlag  )
    DefPinCopy( IDs,    bufferId    )
  }


//=============================+=====================================+=
void                            FluidPacketData::UnpinPinned()
  {
    DefPinFree( FluidPackets, bufferFluidPackets )
  }
//=============================+=====================================+=
void                            FluidPacketData::ClearCounts()
  {
    data->numFluidPacketsPtr = 0;
  }

//=============================+=====================================+=
void                            FluidPacketData::CopyCustom(FluidPacketData^ other)
  {
    UnpinPinned();
    //
    DefPinCopy( FluidPackets, bufferFluidPackets )
    //
    DefCntCopy( unsigned );
  }

//=============================+=====================================+=
void                            FluidPacketData::PostSet()
  {
    DefCntPostSet( numFluidPacketsPtr, data->bufferFluidPackets )
    //
    BaseType::PostSet();
  }

//=============================+=====================================+=
void                            FluidPacketData::PinFluidPackets(array<FluidPacket>^ Source)
  {
    UnpinPinned();

    pinFluidPackets          = GCHandle::Alloc( Source, GCHandleType::Pinned );
    data->bufferFluidPackets = static_cast<NxFluidPacket*>( pinFluidPackets.AddrOfPinnedObject().ToPointer() );

    PostSet();
  }

//=============================+=====================================+=
void                            FluidPacketData::UnpinFluidPackets()
  {
    UnpinPinned();
    PostSet();
  }
