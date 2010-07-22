//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "PhysicsCollection.h"
#include                       "Physics.h"
#include                       "Scene.h"

//=============================+=====================================+=
using namespace                 NXU;
//=============================+=====================================+=
class                           NXU::NxuPhysicsCollection             {};

//=============================+=====================================+=
NXU_userNotify*                 CreateNxuNotify(NxuNotify^ iface, Physics^ physics);
void                            DeleteNxuNotify(NXU_userNotify*& n);

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
const char*                     ToChar(UserPropertiesType UserProperties)
  {
    if( UserProperties == nullptr ) return 0;
    
    int len = 0;
    
    List<String^>^ strings = gcnew List<String^>();
    
    Dictionary<String^, String^>::Enumerator^ enumerator = UserProperties->GetEnumerator();
    
    while( enumerator->MoveNext() ) {
    
      String^ key = enumerator->Current.Key->Trim();
      String^ val = enumerator->Current.Value->Trim();
      
      int keylen = key->Length;
      int vallen = val->Length;
      
      len += keylen + vallen + 2;
      
      strings->Add( key );
      strings->Add( val );
    }
    
    if( !len ) return 0;
    
    char* resultptr = new char[len + 1];
    
    char* result = resultptr;
    result[len] = 0;
    
    for( int i = 0; i < strings->Count; i += 2 ) {
    
      IntPtr      srcptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi( strings[i + 0] );
      const char* src    = static_cast<const char*>( srcptr.ToPointer() );
      int         srclen = strlen( src ) + 1;
      
      strcpy_s( result, srclen, src );
      result[srclen - 1] = '=';
      result += srclen;
      
      srcptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi( strings[i + 1] );
      src    = static_cast<const char*>( srcptr.ToPointer() );
      srclen = strlen( src ) + 1;
      
      strcpy_s( result, srclen, src );
      result[srclen - 1] = ',';
      result += srclen;
    }
    
    return resultptr;
  }

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
                                PhysicsCollection::PhysicsCollection(NxType* ptr):
                                  ptr( ptr )
  {
  }

//=============================+=====================================+=
                                PhysicsCollection::PhysicsCollection(String^ CollectionID, Dictionary<String^, String^>^ UserProperties):
                                  ptr( 0 )
  {
    const char* collid = ToNx( CollectionID );
    const char* up     = ToChar( UserProperties );
    
    ptr = NXU::createCollection( collid, up );
    
    delete[] collid;
    delete[] up;
  }

//=============================+=====================================+=
                                PhysicsCollection::~PhysicsCollection()
  {
    // TODO: if some of the objects fail to load, only wrappers may exist. In that case change all other IsDisposed tests.
    this->!PhysicsCollection();
  }

//=============================+=====================================+=
                                PhysicsCollection::!PhysicsCollection()
  {
    if( !ptr ) return; // collection was never created
    releaseCollection( ptr );
    ptr = 0;
  }

//=============================+=====================================+=
bool                            PhysicsCollection::Instantiate(Physics^ Physics, PhysicsCollection::giScene^ Scene, Matrix4x4 Transform, NxuNotify^ Notify)
  {
    NxMat34         transform = ToNx( Transform );
    NxScene*        sceneptr  = Scene == nullptr ? 0 : Scene->ptr;
    NXU_userNotify* unotptr   = CreateNxuNotify( Notify, Physics);

    bool result = instantiateCollection( ptr, *Physics->ptr, sceneptr, &transform, unotptr );

    DeleteNxuNotify( unotptr );
    return result;
  }

//=============================+=====================================+=
bool                            PhysicsCollection::Instantiate(String^ SceneName, Physics^ Physics, giScene^ Scene, Matrix4x4 Transform, NxuNotify^ Notify)
  {
    NxMat34         transform = ToNx( Transform );
    NxScene*        sceneptr  = Scene == nullptr ? 0 : Scene->ptr;
    NXU_userNotify* unotptr   = CreateNxuNotify( Notify, Physics );
    const char*     scenename = ToNx( SceneName );

    bool result = instantiateScene( ptr, scenename, *Physics->ptr, sceneptr, &transform, unotptr );

    DeleteNxuNotify( unotptr );
    delete[] scenename;
    return result;
  }

//=============================+=====================================+=
PhysicsCollection^              PhysicsCollection::Load(String^ Filename, NXUFileTypes FileType)
  {
    const char* filename = ToNx( Filename );

    NxuPhysicsCollection* collptr = loadCollection( filename, static_cast<NXU_FileType>( FileType ) );
    PhysicsCollection^    Result  = gcnew PhysicsCollection( collptr );
    
    delete[] filename;
    return Result;
  }

//=============================+=====================================+=
PhysicsCollection^              Scene::ExtractCollection(String^ CollectionID, String^ SceneID)
  {
    const char*  collid  = ToNx( CollectionID );
    const char*  sceneid = ToNx( SceneID );
    
    NxuPhysicsCollection* collptr = extractCollectionScene( this->GetNx(), collid, sceneid );
    PhysicsCollection^    Result  = gcnew PhysicsCollection( collptr );

    delete[] collid;
    delete[] sceneid;
    return Result;    
  }

//=============================+=====================================+=
PhysicsCollection^              PhysicsCollection::Create(String^ CollectionID, Dictionary<String^, String^>^ UserProperties)
  {
    return gcnew PhysicsCollection( CollectionID, UserProperties );
  }

//=============================+=====================================+=
bool                            PhysicsCollection::Save(String^ Filename, NXUFileTypes Type, bool SaveDefaults, bool Cook)
  {
    const char* filename = ToNx( Filename );

    bool Result = saveCollection( this->ptr, filename, static_cast<NXU_FileType>( Type ), SaveDefaults, Cook );
    
    delete[] filename;
    return Result;
  }

//=============================+=====================================+=
IntPtr                          PhysicsCollection::SaveToMemory(String^ CollectionID, NXUFileTypes Type, bool SaveDefaults, bool Cook, IntPtr Memory, int MemoryByteSize, [Out] int% WrittenByteSize )
  {
    const char* collid  = ToNx( CollectionID );
    int         written = 0;
    
    void* mem = saveCollectionToMemory( this->ptr, collid, static_cast<NXU_FileType>( Type ), SaveDefaults, Cook, Memory.ToPointer(), MemoryByteSize, written );
    
    WrittenByteSize = written;

    delete[] collid;
    return IntPtr( mem );
  }

//=============================+=====================================+=
void                            PhysicsCollection::ReleaseMemory(IntPtr Memory)
  {
    releaseCollectionMemory( Memory.ToPointer() );
  }

//=============================+=====================================+=
String^                         PhysicsCollection::ID::get()
  {
    return FromNx( getCollectionName( *this->ptr ) );
  }
  
//=============================+=====================================+=
void                            PhysicsCollection::ID::set(String^ v)
  {
    const char* collid = ToNx( v );
    
    setCollectionID( *this->ptr, collid );    

    delete[] collid;    
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddParameter(Parameters Parameter, float Value)
  {
    return addParameter( *this->ptr, static_cast<NxU32>( Parameter ), Value );
  }
  
//=============================+=====================================+=
bool                            PhysicsCollection::AddSceneInstance(String^ InstanceID, String^ SceneName, Matrix4x4 RootNode, bool IgnorePlane, UserPropertiesType UserProperties) 
  {
    const char* instanceID     = ToNx( InstanceID );
    const char* sceneName      = ToNx( SceneName );
    const char* userProperties = ToChar( UserProperties );
    
    bool Result = addSceneInstance( *this->ptr, instanceID, sceneName, ToNx( RootNode ), IgnorePlane, userProperties);
    
    delete[] instanceID;
    delete[] sceneName;
    delete[] userProperties;

    return Result;
  }

//=============================+=====================================+=
bool                            PhysicsCollection::AddToCurrentSceneInstance(String^ InstanceID, String^ SceneName, Matrix4x4 RootNode, bool IgnorePlane, UserPropertiesType UserProperties)
  {
    const char* instanceID     = ToNx( InstanceID );
    const char* sceneName      = ToNx( SceneName );
    const char* userProperties = ToChar( UserProperties );
    
    bool Result = addToCurrentSceneInstance( *this->ptr, instanceID, sceneName, ToNx( RootNode ), IgnorePlane, userProperties);
    
    delete[] instanceID;
    delete[] sceneName;
    delete[] userProperties;

    return Result;
  }
