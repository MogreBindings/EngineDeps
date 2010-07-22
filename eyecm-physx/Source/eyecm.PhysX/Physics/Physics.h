//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"
#include                       "nxlist.h"
#include                       "HeightField.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       ErrorStream;
ref class                       Scene;
ref struct                      SceneDesc;
ref class                       PhysicsCollection;
ref struct                      SimpleTriangleMesh;
ref class                       TriangleMesh;
ref class                       ConvexMesh;
ref class                       CCDSkeleton;
ref class                       HeightField;
ref class                       ClothMesh;
ref class                       SoftBodyMesh;
ref class                       NxuNotify;
ref class                       RemoteDebugger;
ref class                       ControllerManager;

//=============================+=====================================+=
public ref class                Physics
  {
    internal:
      typedef                   NxPhysicsSDK                          NxType;

      NxPhysicsSDK*             ptr;
      
      NxPhysicsSDK*             GetNx()                               { return ptr; }

      giNxRegisteredObject<Physics>^ First;

    private:
      static int                instancecount;

    private:
      Physics(NxPhysicsSDK* ptr);

      void                      InitLists();
      void                      DeInitLists();

    public:
      ~Physics();

    public:
      property bool             IsDisposed
        {
          bool                  get()                                 { return ptr == 0; }
        }

    public:
      //-------------------------------------------------------------
      //---------------------== Collection ==------------------------
      //-------------------------------------------------------------

      PhysicsCollection^        ExtractCollection()                      { return ExtractCollection( nullptr ); }
      PhysicsCollection^        ExtractCollection(String^ CollectionID)  { return ExtractCollection( CollectionID, nullptr ); }
      PhysicsCollection^        ExtractCollection(String^ CollectionID, NxuNotify^ Notify);

      bool                      CoreDump(String^ Filename, NXUFileTypes Type)                               { return CoreDump( Filename, Type, true ); }
      bool                      CoreDump(String^ Filename, NXUFileTypes Type, bool SaveDefaults)            { return CoreDump( Filename, Type, SaveDefaults, false ); }
      bool                      CoreDump(String^ Filename, NXUFileTypes Type, bool SaveDefaults, bool Cook) { return CoreDump( Filename, Type, SaveDefaults, Cook, nullptr ); }
      bool                      CoreDump(String^ Filename, NXUFileTypes Type, bool SaveDefaults, bool Cook, NxuNotify^ Notify);

    private:
      //-------------------------------------------------------------
      //---------------------== Scene ==-----------------------------
      //-------------------------------------------------------------

      typedef                   ReadOnlyCollection<Scene^>            ScenesList;
      ScenesList^               listscenes;

    public:
      Scene^                    CreateScene(SceneDesc^ Desc);

      property ScenesList^      Scenes
        {
          ScenesList^           get()                                 { return listscenes; }
        }

    internal:
      //-------------------------------------------------------------
      //---------------------== Triangle Mesh ==---------------------
      //-------------------------------------------------------------

      typedef                   Dictionary<IntPtr, TriangleMesh^>     TriMeshesDictionary;
      typedef                   TriMeshesDictionary::ValueCollection  TriangleMeshesList;

      TriMeshesDictionary^      trimeshes;

      TriangleMesh^             WrapOrGet(const NxTriangleMesh&);

    public:
      TriangleMesh^             CreateTriangleMesh(System::IO::Stream^ CookedStream);

      property
      TriangleMeshesList^       TriangleMeshes
        {
          TriangleMeshesList^   get()                                 { return trimeshes->Values; }
        }

    internal:
      //-------------------------------------------------------------
      //---------------------== Convex Mesh ==-----------------------
      //-------------------------------------------------------------

      typedef                   Dictionary<IntPtr, ConvexMesh^>       ConvexDictionary;
      typedef                   ConvexDictionary::ValueCollection     ConvexMeshesList;

      ConvexDictionary^         convexmeshes;

      ConvexMesh^               WrapOrGet(const NxConvexMesh&);

    public:
      ConvexMesh^               CreateConvexMesh(System::IO::Stream^ CookedStream);

      property
      ConvexMeshesList^         ConvexMeshes
        {
          ConvexMeshesList^     get()                                 { return convexmeshes->Values; }
        }

    internal:
      //-------------------------------------------------------------
      //---------------------== CCD Skeleton ==----------------------
      //-------------------------------------------------------------

      typedef                   Dictionary<IntPtr, CCDSkeleton^>      CCDSkelsDictionary;
      typedef                   CCDSkelsDictionary::ValueCollection   CCDSkeletonsList;

      CCDSkelsDictionary^       ccdskels;

      CCDSkeleton^              WrapOrGet(const NxCCDSkeleton&);

    public:
      CCDSkeleton^              CreateCCDSkeleton(SimpleTriangleMesh^ Mesh);
      CCDSkeleton^              CreateCCDSkeleton(array<unsigned char>^ Buffer);

      property
      CCDSkeletonsList^         CCDSkeletons
        {
          CCDSkeletonsList^     get()                                 { return ccdskels->Values; }
        }

    internal:
      //-------------------------------------------------------------
      //---------------------== Height Field ==----------------------
      //-------------------------------------------------------------

      typedef                   Dictionary<IntPtr, HeightField^>      HFieldsDictionary;
      typedef                   HFieldsDictionary::ValueCollection    HeightFieldsList;

      HFieldsDictionary^        hfields;

      HeightField^              WrapOrGet(const NxHeightField&);

    public:
      HeightField^              CreateHeightField(HeightFieldDesc^ Desc);
      HeightField^              CreateHeightField(HeightFieldDesc^ Desc, array<HeightFieldSample>^ Samples);
      HeightField^              CreateHeightField(HeightFieldDesc^ Desc, array<HeightFieldSample, 2>^ Samples);

      property
      HeightFieldsList^         HeightFields
        {
          HeightFieldsList^     get()                                 { return hfields->Values; }
        }

    internal:
      //-------------------------------------------------------------
      //---------------------== Cloth Mesh ==------------------------
      //-------------------------------------------------------------

      typedef                   Dictionary<IntPtr, ClothMesh^>        ClothMeshDictionary;
      typedef                   ClothMeshDictionary::ValueCollection  ClothMeshesList;

      ClothMeshDictionary^      clothmeshes;

      ClothMesh^                WrapOrGet(const NxClothMesh&);

    public:
      ClothMesh^                CreateClothMesh(System::IO::Stream^ CookedStream);

      property
      ClothMeshesList^          ClothMeshes
        {
          ClothMeshesList^      get()                                 { return clothmeshes->Values; }
        }

    internal:
      //-------------------------------------------------------------
      //---------------------== SoftBody Mesh ==---------------------
      //-------------------------------------------------------------

    public:
      typedef                   Dictionary<IntPtr, SoftBodyMesh^>        SoftBodyMeshDictionary;
      typedef                   SoftBodyMeshDictionary::ValueCollection  SoftBodyMeshesList;

    internal:
      SoftBodyMeshDictionary^   softbodymeshes;

      SoftBodyMesh^             WrapOrGet(const NxSoftBodyMesh&);

    public:
      SoftBodyMesh^             CreateSoftBodyMesh(System::IO::Stream^ CookedStream);

      property
      SoftBodyMeshesList^       SoftBodyMeshes
        {
          SoftBodyMeshesList^   get()                                 { return softbodymeshes->Values; }
        }

    public:
      static Physics^           Create(ErrorStream^ Stream);
      static Physics^           Create();
      
      #include                 "Physics.Parameters.h"

      value struct              ProxyInternalVersion
        {
          internal:
            unsigned            res, apiRev, descRev, branchID;

            ProxyInternalVersion(NxPhysicsSDK* ptr)
              {
                NxU32 apiRev, descRev, branchID;
                NxU32 res = ptr->getInternalVersion( apiRev, descRev, branchID );

                this->res      = res;
                this->apiRev   = apiRev;
                this->descRev  = descRev;
                this->branchID = branchID;
              }

          public:
            property unsigned   Version
              {
                unsigned        get()                                 { return res; }
              }

            property unsigned   API
              {
                unsigned        get()                                 { return apiRev; }
              }

            property unsigned   Desc
              {
                unsigned        get()                                 { return descRev; }
              }

            property unsigned   Branch
              {
                unsigned        get()                                 { return branchID; }
              }
        };

      property
      ProxyInternalVersion      InternalVersion
        {
          ProxyInternalVersion  get()                                 { return ProxyInternalVersion( ptr ); }
        }

    internal:
      //-------------------------------------------------------------
      //---------------------== Remote Debugger ==-------------------
      //-------------------------------------------------------------
      typedef                   ThisNamespace::RemoteDebugger         giRemoteDebugger;

      static giRemoteDebugger^  debugger;

    public:
      property
      giRemoteDebugger^         RemoteDebugger
        {
          giRemoteDebugger^     get()                                 { return debugger; }
        }

    internal:
      //-------------------------------------------------------------
      //---------------------== Controller Manager ==----------------
      //-------------------------------------------------------------
      typedef                   ThisNamespace::ControllerManager      giControllerManager;

      static NxUserAllocator*   userAllocator;
      static 
        giControllerManager^    controllerManager;

    public:
      property 
        giControllerManager^    ControllerManager                     { giControllerManager^ get() { return controllerManager; } }
  };

//=============================+=====================================+=
                                EndNamespace

