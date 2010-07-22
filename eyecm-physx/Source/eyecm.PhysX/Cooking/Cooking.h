//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"
#include                       "errorstream.h"
#include                       "nxstreamrw.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref struct                      CookingParams;
ref struct                      TriangleMeshDesc;
ref struct                      ConvexMeshDesc;
ref struct                      ClothMeshDesc;
ref struct                      SoftBodyMeshDesc;

//=============================+=====================================+=
public ref class                CookingInterface
  {
    internal:
      typedef                   ThisNamespace::CookingParams          giCookingParams;

      static
      NxCookingInterface*       ptr;

      static CookingParams^     params;
      static giNxErrorStream*   errorstr;

    private:
      static CookingInterface();

    public:
      static bool               InitCooking()                         { return ptr->NxInitCooking( 0, errorstr ); }
      static void               CloseCooking()                        { return ptr->NxCloseCooking(); }
      static void               ReportCooking()                       { ptr->NxReportCooking(); }

      static bool               CookTriangleMesh(TriangleMeshDesc^ Desc, System::IO::Stream^ Stream);
      static bool               CookTriangleMesh(array<float>^ Vertices, array<unsigned>^ Triangles, System::IO::Stream^ Stream);

      static bool               CookConvexMesh(ConvexMeshDesc^ Desc, System::IO::Stream^ Stream);

      static bool               ScaleCookedConvexMesh(Stream^ Source, float Scale, Stream^ Destination)
        {
          giNxStream src( Source );
          giNxStream dst( Destination );

          return ptr->NxScaleCookedConvexMesh( src, Scale, dst );
        }

      static bool               CookClothMesh(ClothMeshDesc^ Desc, System::IO::Stream^ Stream);
      static bool               CookSoftBodyMesh(SoftBodyMeshDesc^ Desc, System::IO::Stream^ Stream);

    public:
      static property
      giCookingParams^          CookingParams
        {
          giCookingParams^      get()                                 { return params; }
        }

      static property bool      IsPlatformMismatch
        {
          bool                  get()                                 { return ptr->NxPlatformMismatch(); }
        }
  };

//=============================+=====================================+=
public ref struct               CookingParams:                        public giNxData<NxCookingParams>
  {
    internal:
      CookingParams() {}

    public:
      property float            SkinWidth
        {
          float                 get()                                 { *data = CookingInterface::ptr->NxGetCookingParams();return data->skinWidth; }
          void                  set(float v)                          { data->skinWidth = v; CookingInterface::ptr->NxSetCookingParams( *data ); }
        }

      property bool             HintCollisionSpeed
        {
          bool                  get()                                 { *data = CookingInterface::ptr->NxGetCookingParams(); return data->hintCollisionSpeed; }
          void                  set(bool v)                           { data->hintCollisionSpeed = v; CookingInterface::ptr->NxSetCookingParams( *data ); }
        }

      property Platforms        TargetPlatform
        {
          Platforms             get()                                 { *data = CookingInterface::ptr->NxGetCookingParams(); return static_cast<Platforms>( data->targetPlatform ); }
          void                  set(Platforms v)                      { data->targetPlatform = static_cast<NxPlatform>( v ); CookingInterface::ptr->NxSetCookingParams( *data ); }
        }
  };

//=============================+=====================================+=
inline                   static CookingInterface::CookingInterface()
  {
    ptr      = NxGetCookingLib( NX_PHYSICS_SDK_VERSION );
    params   = gcnew giCookingParams();
    errorstr = new giNxErrorStream( gcnew ErrorStream() );
  }

//=============================+=====================================+=
                                EndNamespace

