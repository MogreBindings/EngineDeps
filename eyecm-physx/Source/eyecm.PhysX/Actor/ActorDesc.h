//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "ShapeDesc.h"
#include                       "nxarraylist.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref struct                      ShapeDesc;
ref class                       Physics;

//=============================+=====================================+=
public ref struct               ActorDesc:                            public giNxProxyData<NxActorDesc>
  {
    private:
      ActorDesc(Physics^ physics, NxActorDesc& desc): BaseType( desc ) { Init( physics ); }

    internal:
      static ActorDesc^         Wrap(Physics^, NxActorDesc& desc);

    private:
      BodyDesc^                 bodydesc;
      String^                   name;
      ActorUserDataType         user;

      void                      Init(Physics^ ph)
        {
          InitShapes( ph );
          flags  = gcnew ProxyActorFlags( data );
        }

    public:
      ActorDesc() { Init( nullptr ); }

      ActorDesc(ShapeDesc^ Shape)
        {
          Init( nullptr );

          Shapes->Add( Shape );
        }

      ActorDesc(String^ Name)
        {
          Init( nullptr );

          this->Name = Name;
        }

      ActorDesc(String^ Name, ShapeDesc^ Shape)
        {
          Init( nullptr );

          this->Name = Name;

          Shapes->Add( Shape );
        }

      ActorDesc(BodyDesc^ Body)
        {
          Init( nullptr );

          this->Body = Body;
        }

      ActorDesc(BodyDesc^ Body, ShapeDesc^ Shape)
        {
          Init( nullptr );

          this->Body = Body;

          Shapes->Add( Shape );
        }

      ActorDesc(BodyDesc^ Body, float Density)
        {
          Init( nullptr );

          this->Body    = Body;
          this->Density = Density;
        }

      ActorDesc(BodyDesc^ Body, float Density, ShapeDesc^ Shape)
        {
          Init( nullptr );

          this->Body    = Body;
          this->Density = Density;

          Shapes->Add( Shape );
        }

      ~ActorDesc()
        {
          DeinitShapes();

          flags    = nullptr;
          bodydesc = nullptr;
          name     = nullptr;
          user     = nullptr;
        }

      DefArrayListParam( ShapeDesc, Shapes, &data->shapes, Physics );

    public:
      property
      ActorUserDataType         ActorUserDataName
        {
          ActorUserDataType     get()                                 { return user; }
          void                  set(ActorUserDataType v)              { user = v; }
        }

    public:
      property Matrix4x4        GlobalPose
        {
          Matrix4x4             get()                                 { return FromNx( data->globalPose ); }
          void                  set(Matrix4x4 v)                      { data->globalPose = ToNx( v ); }
        }

      property Matrix3x3        GlobalOrientation
        {
          Matrix3x3             get()                                 { return FromNx( data->globalPose.M ); }
          void                  set(Matrix3x3 v)                      { data->globalPose.M = ToNx( v ); }
        }

      property Vector3          GlobalPosition
        {
          Vector3               get()                                 { return FromNx( data->globalPose.t ); }
          void                  set(Vector3 v)                        { data->globalPose.t = ToNx( v ); }
        }

      property BodyDesc^        Body
        {
          BodyDesc^             get()                                 { return bodydesc; }
          void                  set(BodyDesc^ v)                      { bodydesc = v; data->body = v == nullptr ? 0 : v->data; }
        }

      property float            Density
        {
          float                 get()                                 { return data->density; }
          void                  set(float v)                          { data->density = v; }
        }

      property unsigned         Group
        {
          unsigned              get()                                 { return static_cast<unsigned>( data->group ); }
          void                  set(unsigned v)                       { data->group = static_cast<NxActorGroup>( v ); }
        }

      property unsigned         DominanceGroup
        {
          unsigned              get()                                 { return static_cast<unsigned>( data->dominanceGroup ); }
          void                  set(unsigned v)                       { data->dominanceGroup = static_cast<NxDominanceGroup>( v ); }
        }

      property ContactPairFlags ContactReportFlags
        {
          ContactPairFlags      get()                                 { return static_cast<ContactPairFlags>( data->contactReportFlags ); }
          void                  set(ContactPairFlags v)               { data->contactReportFlags = static_cast<NxU32>( v ); }
        }

      property unsigned         ForceFieldMaterial
        {
          unsigned              get()                                 { return data->forceFieldMaterial; }
          void                  set(unsigned v)                       { data->forceFieldMaterial = static_cast<NxU16>( v ); }
        }

      property String^          Name
        {
          String^               get()                                 { return name; }
          void                  set(String^ v)                        { name = v; }
        }

    public:
      //-------------------------------------------------------------
      //---------------------== ProxyActorFlags ==-------------------
      //-------------------------------------------------------------

    public:
      ref class                 ProxyActorFlags
        {
          private:
            NxActorDesc*        data;

          internal:
            ProxyActorFlags(NxActorDesc* data) { this->data = data; }

          public:

          #define               DefFlag( name, token ) \
            virtual \
            property bool       name \
              { \
                bool            get()                                 { return (data->flags & token) == token; } \
                void            set(bool v)                           { if( v ) data->flags |= token; else data->flags &= ~token; } \
              } \

            DefFlag           ( DisableCollision                      , NX_AF_DISABLE_COLLISION )
            DefFlag           ( DisableResponse                       , NX_AF_DISABLE_RESPONSE )
            DefFlag           ( LockCom                               , NX_AF_LOCK_COM )
            DefFlag           ( FluidDisableCollision                 , NX_AF_FLUID_DISABLE_COLLISION )
            DefFlag           ( ContactModification                   , NX_AF_CONTACT_MODIFICATION )
            DefFlag           ( ForceConeFriction                     , NX_AF_FORCE_CONE_FRICTION )
            DefFlag           ( UserActorPairFiltering                , NX_AF_USER_ACTOR_PAIR_FILTERING )

          #undef                DefFlag
        };

    private:
      ProxyActorFlags^          flags;

    public:
      property ProxyActorFlags^ Flags
        {
          ProxyActorFlags^      get()                                 { return flags; }
        }

    public:
                                DefValidDefaultX( listShapes->Clear(); data->setToDefault(); PostSet(); )
  };

//=============================+=====================================+=
                                EndNamespace

