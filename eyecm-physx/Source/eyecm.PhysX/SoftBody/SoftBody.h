//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "SoftBodyDesc.h"
#include                       "nxlist.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Scene;
ref class                       Shape;
ref class                       SoftBodyMesh;

//=============================+=====================================+=
public ref class                SoftBody:                             public giNxNamedObject<NxSoftBody, SoftBody, giNxRegisteredObject<Scene> >
  {
    internal:
      typedef                   ThisNamespace::SoftBodyMesh           giSoftBodyMesh;
      typedef                   ThisNamespace::GroupsMask             giGroupsMask;
      typedef                   ThisNamespace::MeshData               giMeshData;
      typedef                   ThisNamespace::Scene                  giScene;
      typedef                   ThisNamespace::Shape                  giShape;

    internal:
      SoftBody(Scene^, NxSoftBody* ptr, SoftBodyDesc^);

      static SoftBody^          Wrap(NxSoftBody* ptr);

      void                      OnGroupsMaskChanged(NxGroupsMask* data)               { ptr->setGroupsMask( *data ); }
      void                      OnMeshDataChanged(NxMeshData* data)                   { ptr->setMeshData( *data ); }
      void                      OnSplitPairDataChanged(NxSoftBodySplitPairData* data) { ptr->setSplitPairData( *data ); }

    public:
      ~SoftBody();
      !SoftBody();

    public:
                                DefSaveToDesc( SoftBody )
    public:
      property giSoftBodyMesh^  SoftBodyMesh                          { giSoftBodyMesh^ get(); }

      property giScene^         Scene
        {
          giScene^              get()                                 { return Owner; }
        }

    public:
      DefM0( float,             VolumeStiffness,                      VolumeStiffness )
      DefM0( float,             StretchingStiffness,                  StretchingStiffness )
      DefM0( float,             DampingCoefficient,                   DampingCoefficient )
      DefM0( float,             Friction,                             Friction )
      DefM0( float,             TearFactor,                           TearFactor )
      DefM0( float,             AttachmentTearFactor,                 AttachmentTearFactor )
      DefM0( float,             ParticleRadius,                       ParticleRadius )
      DefM0( unsigned,          SolverIterationCount,                 SolverIterations )
      DefMc( unsigned,          Group,              NxCollisionGroup, Group )
      DefM0( float,             CollisionResponseCoefficient,         CollisionResponseCoefficient )
      DefM0( float,             AttachmentResponseCoefficient,        AttachmentResponseCoefficient )
      DefM0( float,             ToFluidResponseCoefficient,           ToFluidResponseCoefficient )
      DefM0( float,             FromFluidResponseCoefficient,         FromFluidResponseCoefficient )
      DefM0( float,             MinAdhereVelocity,                    MinAdhereVelocity )
      DefMx( Vector3,           ExternalAcceleration,                 ExternalAcceleration )
      DefM0( float,             SleepLinearVelocity,                  SleepLinearVelocity )
      DefMc( SoftBodyFlags,     Flags,                         NxU32, Flags )
      DefMc( unsigned,          ForceFieldMaterial, NxForceFieldMaterial, ForceFieldMaterial )

      Defm0( float,             Density,                              Density )
      Defm0( float,             RelativeGridSpacing,                  RelativeGridSpacing )

      property AxisAlignedBox   WorldBounds
        {
          AxisAlignedBox        get()                                 { NxBounds3 b; ptr->getWorldBounds( b ); return FromNx( b ); }
        }

      property AxisAlignedBox   ValidBounds
        {
          AxisAlignedBox        get()                                 { NxBounds3 b; ptr->getValidBounds( b ); return FromNx( b ); }
          void                  set(AxisAlignedBox v)                 { ptr->setValidBounds( ToNx( v ) ); }
        }

      property bool             IsSleeping
        {
          bool                  get()                                 { return ptr->isSleeping(); }
        }

      property unsigned         StateByteSize
        {
          unsigned              get()                                 { return ptr->getStateByteSize(); }
        }

      DefProxyGetSetm(    SoftBody, giGroupsMask,          GroupsMask );
      DefProxyGetSetm(    SoftBody, giMeshData,            MeshData);
      DefProxyGetSetmPin( SoftBody, SoftBodySplitPairData, SplitPairData);

    public:
      void                      WakeUp()                              { WakeUp( NX_SLEEP_INTERVAL ); }
      void                      WakeUp(float WakeCounterValue)
        {
          ptr->wakeUp( WakeCounterValue );
        }

      void                      PutToSleep()
        {
          ptr->putToSleep();
        }

      void                      SaveStateToStream(System::IO::Stream^ Stream) { SaveStateToStream( Stream, false ); }
      void                      SaveStateToStream(System::IO::Stream^ Stream, bool Permute);
      void                      LoadStateFromStream(System::IO::Stream^ Stream);

    public:
      void                      AddForceAtVertex(Vector3 Force, unsigned VertexID)  { AddForceAtVertex( Force, VertexID, ForceModes::Force ); }
      void                      AddForceAtVertex(Vector3 Force, unsigned VertexID, ForceModes Mode)
        {
          ptr->addForceAtVertex( ToNx( Force ), VertexID, static_cast<NxForceMode>( Mode ) );
        }

      void                      AddForceAtPos(Vector3 Position, float Magnitude, float Radius) { AddForceAtPos( Position, Magnitude, Radius, ForceModes::Force ); }
      void                      AddForceAtPos(Vector3 Position, float Magnitude, float Radius, ForceModes Mode)
        {
          ptr->addForceAtPos( ToNx( Position ), Magnitude, Radius, static_cast<NxForceMode>( Mode ) );
        }

      bool                      Raycast(Line WorldRay, [Out] Vector3% Hit, [Out] unsigned% VertexID)
        {
          NxVec3   hit;
          unsigned vid;

          bool result = ptr->raycast( ToNx( WorldRay ), hit, vid );

          Hit      = FromNx( hit );
          VertexID = vid;

          return result;
        }

      bool                      OverlapAABBTetrahedra (AxisAlignedBox Bounds, [Out] array<unsigned>^% Indices)
        {
          NxU32        cnt;
          const NxU32* indices;

          bool result = ptr->overlapAABBTetrahedra ( ToNx( Bounds ), cnt, indices);

          Indices = gcnew array<unsigned>( cnt );
          pin_ptr<unsigned> p = &Indices[0];
          memcpy_s( p, sizeof( NxU32 ) * cnt, indices, sizeof( NxU32 ) * cnt );

          return result;
        }

    public:
      void                      AttachToShape(giShape^ Shape, SoftBodyAttachmentFlags Flags)
        {
          ptr->attachToShape( Shape->ptr, static_cast<NxSoftBodyAttachmentFlag>( Flags ) );
        }

      void                      AttachToCollidingShapes(SoftBodyAttachmentFlags Flags)
        {
          ptr->attachToCollidingShapes( static_cast<NxSoftBodyAttachmentFlag>( Flags ) );
        }

      void                      DetachFromShape(giShape^ Shape)
        {
          ptr->detachFromShape( Shape->ptr );
        }

      void                      AttachVertexToShape(unsigned VertexID, giShape^ Shape, Vector3 LocalPosition, SoftBodyAttachmentFlags Flags)
        {
          ptr->attachVertexToShape( VertexID, Shape->ptr, ToNx( LocalPosition ), static_cast<NxSoftBodyAttachmentFlag>( Flags ) );
        }

      void                      AttachVertexToGlobalPosition(unsigned VertexID, Vector3 GlobalPosition)
        {
          ptr->attachVertexToGlobalPosition( VertexID, ToNx( GlobalPosition ) );
        }

      void                      FreeVertex(unsigned VertexID)
        {
          ptr->freeVertex( VertexID );
        }

      void                      TearVertex(unsigned VertexID, Vector3 Normal)
        {
          ptr->tearVertex( VertexID, ToNx( Normal ) );
        }


      //-------------------------------------------------------------
      //---------------------== Positions ==-------------------------
      //-------------------------------------------------------------

      void                      SetPosition(Vector3 Position, unsigned VertexID)
        {
          ptr->setPosition( ToNx( Position ), VertexID );
        }

      Vector3                   GetPosition(unsigned VertexID)
        {
          return FromNx( ptr->getPosition( VertexID ) );
        }

      void                      GetPositions(IntPtr Target)           { GetPositions( Target, sizeof( NxVec3 ) ); }
      void                      GetPositions(IntPtr Target, unsigned ByteStride)
        {
          ptr->getPositions( Target.ToPointer(), ByteStride );
        }

      void                      SetPositions(IntPtr Source)           { SetPositions( Source, sizeof( NxVec3 ) ); }
      void                      SetPositions(IntPtr Source, unsigned ByteStride)
        {
          ptr->setPositions( Source.ToPointer(), ByteStride );
        }

      property unsigned         ParticleCount
        {
          unsigned              get()                                 { return ptr->getNumberOfParticles(); }
        }


      //-------------------------------------------------------------
      //---------------------== Velocities ==------------------------
      //-------------------------------------------------------------

      void                      SetVelocity(Vector3 Velocity, unsigned VertexID)
        {
          ptr->setVelocity( ToNx( Velocity ), VertexID );
        }

      Vector3                   GetVelocity(unsigned VertexID)
        {
          return FromNx( ptr->getVelocity( VertexID ) );
        }

      void                      GetVelocities(IntPtr Target)          { GetVelocities( Target, sizeof( NxVec3 ) ); }
      void                      GetVelocities(IntPtr Target, unsigned ByteStride)
        {
          ptr->getVelocities( Target.ToPointer(), ByteStride );
        }

      void                      SetVelocities(IntPtr Source)          { SetVelocities( Source, sizeof( NxVec3 ) ); }
      void                      SetVelocities(IntPtr Source, unsigned ByteStride)
        {
          ptr->setVelocities( Source.ToPointer(), ByteStride );
        }


      //-------------------------------------------------------------
      //---------------------== Shapes ==----------------------------
      //-------------------------------------------------------------

      typedef                   giNxStaticList<
                                  giShape, NxShape*, giShape^,
                                  true
                                >                                     ShapeCollection;

      void                      GetShapes([Out] ReadOnlyCollection<giShape^>^% Shapes)
        {
          const unsigned cnt    = ptr->queryShapePointers();
          NxShape**      shapes = new NxShape*[cnt];

          ptr->getShapePointers( shapes, 0 );

          Shapes = gcnew ShapeCollection( shapes, cnt );
        }

      void                      GetShapes([Out] ReadOnlyCollection<giShape^>^% Shapes, [Out] array<ClothAttachmentFlags>^% Flags)
        {
          const unsigned cnt    = ptr->queryShapePointers();
          NxShape**      shapes = new NxShape*[cnt];

          Flags = gcnew array<ClothAttachmentFlags>( cnt );

          pin_ptr<ClothAttachmentFlags> pflags = &Flags[0];
          NxU32*                        p      = static_cast<NxU32*>( static_cast<void*>( pflags ) );

          ptr->getShapePointers( shapes, p );

          Shapes = gcnew ShapeCollection( shapes, cnt );
        }

      void                      SetShapes(array<giShape^>^ Shapes);
      void                      SetShapes(IList<giShape^>^ Shapes);

      /*virtual NxCompartment *  getCompartment () const =0 */
  };

//=============================+=====================================+=
                                EndNamespace
