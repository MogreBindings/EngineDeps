//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxobject.h"

//=============================+=====================================+=
class                           NXU::NxuPhysicsCollection;

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
ref class                       Physics;
ref class                       Scene;
ref struct                      SimpleTriangleMesh;
ref class                       Actor;
ref class                       Material;
ref class                       Joint;
ref class                       ForceField;
ref class                       Effector;
ref class                       Fluid;
ref class                       Cloth;
ref class                       SoftBody;
ref struct                      SoftBodyDesc;
ref struct                      SoftBodyMeshDesc;
ref class                       TriangleMesh;
ref class                       ConvexMesh;
ref class                       CCDSkeleton;
ref class                       HeightField;
ref class                       ClothMesh;
ref class                       SoftBodyMesh;

ref class                       NxuNotify;
class                           giNxuNotify;

//=============================+=====================================+=
typedef                         Dictionary<String^, String^>^         UserPropertiesType;

const char*                     ToChar(UserPropertiesType UserProperties);

//=============================+=====================================+=
public ref class                PhysicsCollection
  {
    internal:
      typedef                   ThisNamespace::Scene                  giScene;
      typedef                   NXU::NxuPhysicsCollection             NxType;

    private:
      NxType*                   ptr;

    internal:
      PhysicsCollection(NxType* ptr);
      PhysicsCollection(String^ CollectionID, Dictionary<String^, String^>^ UserProperties);

    public:      
      ~PhysicsCollection();
      !PhysicsCollection();

    public:
      bool                      Instantiate(Physics^ Physics, giScene^ Scene, Matrix4x4 Transform, NxuNotify^ Notify);
      bool                      Instantiate(String^ SceneName, Physics^ Physics, giScene^ Scene, Matrix4x4 Transform, NxuNotify^ Notify);

      bool                      Save(String^ Filename, NXUFileTypes Type)                     { return Save( Filename, Type, true ); }
      bool                      Save(String^ Filename, NXUFileTypes Type, bool SaveDefaults)  { return Save( Filename, Type, SaveDefaults, false ); }
      bool                      Save(String^ Filename, NXUFileTypes Type, bool SaveDefaults, bool Cook);

      IntPtr                    SaveToMemory(String^ CollectionID, NXUFileTypes Type, bool SaveDefaults, bool Cook, IntPtr Memory, int MemoryByteSize, [Out] int% WrittenByteSize );
      void                      ReleaseMemory(IntPtr Memory);
      
      bool                      AddParameter(Parameters Parameter, float Value);
      bool                      AddPhysics(Physics^ Physics);

      bool                      AddScene(Scene^ Scene)                                    { return AddScene( Scene, nullptr ); }
      bool                      AddScene(Scene^ Scene, UserPropertiesType UserProperties) { return AddScene( Scene, UserProperties, nullptr ); }
      bool                      AddScene(Scene^ Scene, UserPropertiesType UserProperties, String^ SceneID);

      bool                      AddEntireScene(Scene^ Scene)                                                      { return AddEntireScene( Scene, nullptr ); }
      bool                      AddEntireScene(Scene^ Scene, UserPropertiesType UserProperties)                   { return AddEntireScene( Scene, UserProperties, nullptr ); }
      bool                      AddEntireScene(Scene^ Scene, UserPropertiesType UserProperties, String^ SceneID)  { return AddEntireScene( Scene, UserProperties, SceneID, nullptr ); }
      bool                      AddEntireScene(Scene^ Scene, UserPropertiesType UserProperties, String^ SceneID, NxuNotify^ Notify);

      bool                      AddActor(Actor^ Actor)                                    { return AddActor( Actor, nullptr ); }
      bool                      AddActor(Actor^ Actor, UserPropertiesType UserProperties) { return AddActor( Actor, UserProperties, nullptr ); }
      bool                      AddActor(Actor^ Actor, UserPropertiesType UserProperties, String^ ActorID);

      bool                      AddJoint(Joint^ Joint)                                    { return AddJoint( Joint, nullptr ); }
      bool                      AddJoint(Joint^ Joint, UserPropertiesType UserProperties) { return AddJoint( Joint, UserProperties, nullptr ); }
      bool                      AddJoint(Joint^ Joint, UserPropertiesType UserProperties, String^ JointID);

      bool                      AddCloth(Cloth^ Cloth)                                    { return AddCloth( Cloth, nullptr ); }
      bool                      AddCloth(Cloth^ Cloth, UserPropertiesType UserProperties) { return AddCloth( Cloth, UserProperties, nullptr ); }
      bool                      AddCloth(Cloth^ Cloth, UserPropertiesType UserProperties, String^ ClothID);

      bool                      AddSoftBody(SoftBody^ SoftBody)                                    { return AddSoftBody( SoftBody, nullptr ); }
      bool                      AddSoftBody(SoftBody^ SoftBody, UserPropertiesType UserProperties) { return AddSoftBody( SoftBody, UserProperties, nullptr ); }
      bool                      AddSoftBody(SoftBody^ SoftBody, UserPropertiesType UserProperties, String^ SoftBodyID);

      bool                      AddSoftBody(SoftBodyDesc^ SoftBodyDesc, SoftBodyMeshDesc^ SoftBodyMeshDesc)                                    { return AddSoftBody( SoftBodyDesc, SoftBodyMeshDesc, nullptr ); }
      bool                      AddSoftBody(SoftBodyDesc^ SoftBodyDesc, SoftBodyMeshDesc^ SoftBodyMeshDesc, UserPropertiesType UserProperties) { return AddSoftBody( SoftBodyDesc, SoftBodyMeshDesc, UserProperties, nullptr ); }
      bool                      AddSoftBody(SoftBodyDesc^ SoftBodyDesc, SoftBodyMeshDesc^ SoftBodyMeshDesc, UserPropertiesType UserProperties, String^ SoftBodyID);

      bool                      AddFluid(Fluid^ Fluid)                                    { return AddFluid( Fluid, nullptr ); }
      bool                      AddFluid(Fluid^ Fluid, UserPropertiesType UserProperties) { return AddFluid( Fluid, UserProperties, nullptr ); }
      bool                      AddFluid(Fluid^ Fluid, UserPropertiesType UserProperties, String^ FluidID);

      bool                      AddMaterial(Material^ Material)                                    { return AddMaterial( Material, nullptr ); }
      bool                      AddMaterial(Material^ Material, UserPropertiesType UserProperties) { return AddMaterial( Material, UserProperties, nullptr ); }
      bool                      AddMaterial(Material^ Material, UserPropertiesType UserProperties, String^ MaterialID);

      bool                      AddConvexMesh(ConvexMesh^ ConvexMesh)                                    { return AddConvexMesh( ConvexMesh, nullptr ); }
      bool                      AddConvexMesh(ConvexMesh^ ConvexMesh, UserPropertiesType UserProperties) { return AddConvexMesh( ConvexMesh, UserProperties, nullptr ); }
      bool                      AddConvexMesh(ConvexMesh^ ConvexMesh, UserPropertiesType UserProperties, String^ ConvexMeshID);

      bool                      AddTriangleMesh(TriangleMesh^ TriangleMesh)                                    { return AddTriangleMesh( TriangleMesh, nullptr ); }
      bool                      AddTriangleMesh(TriangleMesh^ TriangleMesh, UserPropertiesType UserProperties) { return AddTriangleMesh( TriangleMesh, UserProperties, nullptr ); }
      bool                      AddTriangleMesh(TriangleMesh^ TriangleMesh, UserPropertiesType UserProperties, String^ TriangleMeshID);

      bool                      AddHeightField(HeightField^ HeightField)                                    { return AddHeightField( HeightField, nullptr ); }
      bool                      AddHeightField(HeightField^ HeightField, UserPropertiesType UserProperties) { return AddHeightField( HeightField, UserProperties, nullptr ); }
      bool                      AddHeightField(HeightField^ HeightField, UserPropertiesType UserProperties, String^ HeightFieldID);

      bool                      AddCCDSkeleton(CCDSkeleton^ CCDSkeleton)                                    { return AddCCDSkeleton( CCDSkeleton, nullptr ); }
      bool                      AddCCDSkeleton(CCDSkeleton^ CCDSkeleton, UserPropertiesType UserProperties) { return AddCCDSkeleton( CCDSkeleton, UserProperties, nullptr ); }
      bool                      AddCCDSkeleton(CCDSkeleton^ CCDSkeleton, UserPropertiesType UserProperties, String^ CCDSkeletonID);

      bool                      AddEffector(Effector^ Effector)                                    { return AddEffector( Effector, nullptr ); }
      bool                      AddEffector(Effector^ Effector, UserPropertiesType UserProperties) { return AddEffector( Effector, UserProperties, nullptr ); }
      bool                      AddEffector(Effector^ Effector, UserPropertiesType UserProperties, String^ EffectorID);

      bool                      AddForceField(ForceField^ ForceField)                                    { return AddForceField( ForceField, nullptr ); }
      bool                      AddForceField(ForceField^ ForceField, UserPropertiesType UserProperties) { return AddForceField( ForceField, UserProperties, nullptr ); }
      bool                      AddForceField(ForceField^ ForceField, UserPropertiesType UserProperties, String^ ForceFieldID);

      bool                      AddSceneInstance(String^ InstanceID, String^ SceneName, Matrix4x4 RootNode)                   { return AddSceneInstance( InstanceID, SceneName, RootNode, false ); }
      bool                      AddSceneInstance(String^ InstanceID, String^ SceneName, Matrix4x4 RootNode, bool IgnorePlane) { return AddSceneInstance( InstanceID, SceneName, RootNode, IgnorePlane, nullptr ); }
      bool                      AddSceneInstance(String^ InstanceID, String^ SceneName, Matrix4x4 RootNode, bool IgnorePlane, UserPropertiesType UserProperties);

      bool                      AddToCurrentSceneInstance(String^ InstanceID, String^ SceneName, Matrix4x4 RootNode)                   { return AddToCurrentSceneInstance( InstanceID, SceneName, RootNode, false ); }
      bool                      AddToCurrentSceneInstance(String^ InstanceID, String^ SceneName, Matrix4x4 RootNode, bool IgnorePlane) { return AddToCurrentSceneInstance( InstanceID, SceneName, RootNode, IgnorePlane, nullptr ); }
      bool                      AddToCurrentSceneInstance(String^ InstanceID, String^ SceneName, Matrix4x4 RootNode, bool IgnorePlane, UserPropertiesType UserProperties);

      bool                      CloseCurrentSceneInstance()           { return closeCurrentSceneInstance( *this->ptr ); }
      
      property unsigned         SceneCount
        {
          unsigned              get()                                 { return getSceneCount( *this->ptr ); }
        }
        
      property String^          Name
        {
          String^               get()                                 { return FromNx( getCollectionName( *this->ptr ) ); }
        }
        
      String^                   GetSceneName(unsigned Index)          { return FromNx( getSceneName( *this->ptr, Index ) ); }

      property unsigned         SceneInstanceCount
        {
          unsigned              get()                                 { return getSceneInstanceCount( *this->ptr ); }
        }

      String^                   GetSceneInstanceName(unsigned Index)  { return FromNx( getSceneInstanceName( *this->ptr, Index ) ); }

      String^                   GetSceneInstanceSceneName(unsigned Index)  { return FromNx( getSceneInstanceSceneName( *this->ptr, Index ) ); }
      
      unsigned                  CreateCCDSkeletons()                            { return CreateCCDSkeletons( 0.9f ); }
      unsigned                  CreateCCDSkeletons(float Shrink)                { return CreateCCDSkeletons( Shrink, 16 ); }
      unsigned                  CreateCCDSkeletons(float Shrink, unsigned MaxV) { return createCCDSkeletons( *this->ptr, Shrink, MaxV ); }

      bool                      AutoGenerateCCDSkeletons(Actor^ Actor)                { return AutoGenerateCCDSkeletons( Actor, 0.9f ); }
      bool                      AutoGenerateCCDSkeletons(Actor^ Actor, float Shrink)  { return AutoGenerateCCDSkeletons( Actor, Shrink, 16 ); }
      bool                      AutoGenerateCCDSkeletons(Actor^ Actor, float Shrink, unsigned MaxV);

      void                      SetAutoGenerateCCDSkeletons(bool State, float Shrink, unsigned MaxV) { NXU::setAutoGenerateCCDSkeletons( State, Shrink, MaxV ); }
      
      property bool             UseClothActiveState
        {
          void                  set(bool v)                           { NXU::setUseClothActiveState( v ); }
        }

      property bool             UseSoftBodyActiveState
        {
          void                  set(bool v)                           { NXU::setUseSoftBodyActiveState( v ); }
        }
        
      bool                      AddClothMesh(ClothMesh^ ClothMesh)    { return AddClothMesh( ClothMesh, nullptr ); }
      bool                      AddClothMesh(ClothMesh^ ClothMesh, String^ ClothMeshID);
      
      bool                      AddSoftBodyMesh(SoftBodyMesh^ SoftBodyMesh) { return AddSoftBodyMesh( SoftBodyMesh, nullptr ); }
      bool                      AddSoftBodyMesh(SoftBodyMesh^ SoftBodyMesh, String^ SoftBodyMeshID);
      
      bool                      AddGroupCollisionFlag(unsigned Group1, unsigned Group2, bool Enable) { return addGroupCollisionFlag( *this->ptr, Group1, Group2, Enable); }

      bool                      AddActorGroupFlag(unsigned Group1, unsigned Group2, ContactPairFlags Flags) { return addActorGroupFlag( *this->ptr, Group1, Group2, static_cast<NxU32>( Flags ) ); }

      /*
bool  addPairFlag (NxuPhysicsCollection &c, NxPairFlag &f, const char *userProperties=0, const char *pairFlagID=0) 
bool  setFilterOps (NxuPhysicsCollection &c, bool active,::NxFilterOp filterOp0,::NxFilterOp filterOp1,::NxFilterOp filterOp2, const ::NxGroupsMask &filterConstant0, const ::NxGroupsMask &filterConstant1) 
bool  addCompartment (NxuPhysicsCollection &c, NxCompartment &cmp, const char *compartmentID=0) 
      */
      
      property String^          ID                                    { String^ get(); void set(String^ v); }
      
    public:
      static PhysicsCollection^ Load(String^ Filename, NXUFileTypes FileType);

      static PhysicsCollection^ Create()                              { return Create( nullptr ); }
      static PhysicsCollection^ Create(String^ CollectionID)          { return Create( CollectionID, nullptr ); }
      static PhysicsCollection^ Create(String^ CollectionID, Dictionary<String^, String^>^ UserProperties);
  };

//=============================+=====================================+=
                                EndNamespace

