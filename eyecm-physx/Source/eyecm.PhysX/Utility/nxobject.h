//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "eyecmPhysX.h"

#define							            _DEBUG_FINALIZERS

#if                             defined( _DEBUG ) && defined( _DEBUG_FINALIZERS )
#define                         DefDebugDestructor() Console::Write( "~" );
#define                         DefDebugFinalizer() \
                                Console::WriteLine( "!" + (TNx::typeid)->ToString() );
#else
#define                         DefDebugDestructor()
#define                         DefDebugFinalizer()
#endif

// TODO: all public properties and methods from templated giNX* should be reexposed in derived classes or they're not seen by IntelliSense

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
enum                            giProxyFlags
  {
                                ProxyFlagsDontDelete               = (1 << 0),
                                ProxyFlagsThrowOnDispose           = (1 << 1),
  };

//=============================+=====================================+=
template<                                                             // proxy objects that only store pointers to nx objects and datas
  typename TNx,
  typename base = Object
>
public ref struct               giNxProxy:                            public base
  {
    internal:
      typedef                   TNx                                   NxType;
      typedef                   giNxProxy<TNx, base>                  BaseType;

      TNx*                      data;
      
      inline TNx*               GetNx()                               { return data; }

      inline void               PostSet()                             { }
      void                      DeleteSelf()
        {
          delete this;
        }

    protected:
      giNxProxy(TNx* data)
        {
          this->data = data;
          if( this->data == 0 ) throw gcnew ArgumentNullException();
        }

      giNxProxy(TNx& data)
        {
          this->data = &data;
        }

    public:
      virtual ~giNxProxy() 
      { 
        DefDebugDestructor();
        //
        this->!giNxProxy(); 
      }
      !giNxProxy() 
      { 
        DefDebugFinalizer()
        //
        data = 0; 
      }

    public:
      property bool             IsDisposed
        {
          bool                  get()                                 { return data == 0; }
        }

      virtual String^           ToString() override
        {
          return IsDisposed ? "DISPOSED" : Object::ToString();
        }
  };

//=============================+=====================================+=
template<typename TNx>                                                // data objects own/create/delete their Nx objects
public ref struct               giNxData
  {
    internal:
      typedef                   TNx                                   NxType;
      typedef                   giNxData<TNx>                         BaseType;

      TNx*                      data;

      inline TNx*               GetNx()                               { return data; }

      inline void               PostSet()                             { }

      void                      DeleteSelf()
        {
          delete this;
        }

    protected:
      giNxData()
        {
          this->data = new TNx();
          if( this->data == 0 ) throw gcnew ArgumentNullException();
        }

      giNxData(TNx* data) // sometimes data can not be new-ed without passing arguments to TNx constructor (NxContactStreamIterator)
        {
          this->data = data;
          if( this->data == 0 ) throw gcnew ArgumentNullException();
        }

      giNxData(const TNx& tocopy)
        {
          this->data = new TNx( tocopy );
          if( this->data == 0 ) throw gcnew ArgumentNullException();
        }

      virtual ~giNxData() 
        { 
          DefDebugDestructor();
          //
          this->!giNxData(); 
        }
      !giNxData() 
        { 
          DefDebugFinalizer()
          //
          delete data; data = 0; 
        }

    public:
      property bool             IsDisposed
        {
          bool                  get()                                 { return data == 0; }
        }

      virtual String^           ToString() override
        {
          return IsDisposed ? "DISPOSED" : Object::ToString();
        }
  };

//=============================+=====================================+=
template<                                                             // proxydata objects either own/create/delete or simply wrap their Nx objects
  typename TNx
>                                                
public ref struct               giNxProxyData
  {
    internal:
      typedef                   TNx                                   NxType;
      typedef                   giNxProxyData<TNx>                    BaseType;

      TNx*                      data;
      unsigned                  flags;

      inline TNx*               GetNx()                               { return data; }

      template<typename T>
      inline void               CopyCustom(T^)                        { }

      inline void               PostSet()                             { }

      void                      DeleteSelf()
        {
          flags &= ~ProxyFlagsThrowOnDispose; // owner is being disposed, so this object will be disposed as well
          delete this;
        }

    protected:
      giNxProxyData() // the class derived from this template is created from scratch, delete is ok
        {
          this->data = new TNx();
          if( this->data == 0 ) throw gcnew ArgumentNullException();
        }

      giNxProxyData(TNx* data) // data is created by subclasses of the class derived from this template - data itself is a subclass of TNx, delete is ok
        {
          this->data = data;
          if( this->data == 0 ) throw gcnew ArgumentNullException();
        }

      giNxProxyData(TNx& data) // used for wrapping stack- or api-allocated TNx objects, delete NOT ok
        {
          this->data = &data;
          flags |= ProxyFlagsDontDelete;
        }

      giNxProxyData(const TNx& data) // copy of the original data must be made in some cases (clone & copy), delete is ok
        {
          this->data = new TNx( data );
          if( this->data == 0 ) throw gcnew ArgumentNullException();
        }

    public:
      virtual ~giNxProxyData()
        {
          DefDebugDestructor();
          //
          if( flags & ProxyFlagsThrowOnDispose ) throw gcnew InvalidOperationException( "Attempted to dispose a desc that is owned by another object.");
          this->!giNxProxyData();
        }

    protected:
      !giNxProxyData()
        {
          DefDebugFinalizer()
          //
          if( !(flags & ProxyFlagsDontDelete) ) delete data;
          //
          data = 0;
        }

    public:
      property bool             IsDisposed
        {
          bool                  get()                                 { return data == 0; }
        }

      virtual String^           ToString() override
        {
          return IsDisposed ? "DISPOSED" : Object::ToString();
        }
  };

//=============================+=====================================+=
template<typename TNx>
public ref struct               giNxCallbackProxyData:                public giNxProxyData<TNx>
  {
    internal:
      typedef                   giNxCallbackProxyData<TNx>            BaseType;

      delegate void ChangedDelegate(TNx*);
      ChangedDelegate^          OnChanged;

      void                      PostSet() new                         { if( OnChanged ) OnChanged( data ); }

      template<typename T>
      inline void               CopyCustom(T^)                        { }

      void                      DeleteSelf() new
        {
          flags &= ~ProxyFlagsThrowOnDispose;
          delete OnChanged; OnChanged = nullptr;
          delete this;
        }

    protected:
      giNxCallbackProxyData() {}

    internal:
      giNxCallbackProxyData(const NxType& data): giNxProxyData( data ) { }
      giNxCallbackProxyData(NxType& data): giNxProxyData( data ) { }
      giNxCallbackProxyData(ChangedDelegate^ OnChanged): OnChanged( OnChanged ) { flags |= ProxyFlagsThrowOnDispose; }
      giNxCallbackProxyData(ChangedDelegate^ OnChanged, NxType& data): giNxProxyData( data ), OnChanged( OnChanged ) { flags |= ProxyFlagsThrowOnDispose; }
  };

//=============================+=====================================+=
template<
  typename TNx,
  typename Tgi,
  typename Tbase //= System::Object
>
public ref class                giNxObject:                           public Tbase
  {
    internal:
      typedef                   Tgi                                   giType;
      typedef                   TNx                                   NxType;
      typedef                   giNxObject<TNx, Tgi, Tbase>           BaseType;

      TNx*                      ptr;

      inline TNx*               GetNx()                               { return ptr; }
      
      gcroot<Tgi^>*             rootptr;

    protected:
      giNxObject(TNx* ptr)
        {
          #ifdef _DEBUG
            if( CastUserDataOrNull( ptr->userData ) != nullptr ) throw gcnew InvalidOperationException( "Object already wrapped!!" );
          #endif
          
          this->ptr = ptr;
          if( this->ptr == 0 ) throw gcnew ArgumentNullException();

          Tgi^ obj = static_cast<Tgi^>( this );
          //
          ptr->userData = rootptr = new gcroot<Tgi^>( obj );
        }

    public:
      virtual ~giNxObject() 
        { 
          DefDebugDestructor();
          //
          this->!giNxObject(); 
        }
      !giNxObject() 
        { 
          DefDebugFinalizer()
          //
          delete rootptr; rootptr = 0;
          //
          ptr = 0; 
        }

    public:
      property bool             IsDisposed
        {
          bool                  get()                                 { return ptr == 0; }
        }

      virtual String^           ToString() override
        {
          return IsDisposed ? "DISPOSED" : Object::ToString();
        }

    internal:
      static Tgi^               Cast(const TNx* nx)                   { return CastUserData( nx->userData ); }
      static Tgi^               CastOrNull(const TNx* nx)             { return nx ? CastUserDataOrNull( nx->userData ) : nullptr; }
      static Tgi^               CastUserData(const void* ud)          { return *static_cast<gcroot<Tgi^>*>( const_cast<void*>( ud ) ); }
      static Tgi^               CastUserDataOrNull(const void* ud)    { return ud ? *static_cast<gcroot<Tgi^>*>( const_cast<void*>( ud ) ) : nullptr; }
  };

//=============================+=====================================+=
template<
  typename TNx,
  typename Tgi,
  typename Tbase //= System::Object
>
public ref class                giNxNamedObject:                      public giNxObject<TNx, Tgi, Tbase>
  {
    private:
      const char*               namestr;

    internal:
      typedef                   giNxNamedObject<TNx, Tgi, Tbase>      BaseType;

      giNxNamedObject(TNx* ptr): giNxObject( ptr ) { }

    public:
      virtual ~giNxNamedObject() { this->!giNxNamedObject(); }
      !giNxNamedObject() { delete[] namestr; namestr = 0; }

    public:
      virtual String^           ToString() override
        {
          return namestr ? gcnew String( namestr ) : giNxObject::ToString();
        }

      property String^          Name // TODO: property hidden because inside a class template - find a better solution
        {
          String^               get()
            {
              if( IsDisposed ) return "DISPOSED";

              return namestr ? gcnew String( namestr ) : nullptr;
            }

          void                  set(String^ v)
            {
              char* temp = 0;

              if( v != nullptr ) {

                IntPtr      srcptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi( v );
                const char* src    = static_cast<const char*>( srcptr.ToPointer() );
                int         len    = strlen( src ) + 1;

                temp = new char[len];
                strcpy_s( temp, len, src );

                System::Runtime::InteropServices::Marshal::FreeHGlobal( srcptr );
              }

              ptr->setName( temp );

              delete[] namestr;
              namestr = temp;
            }
        }
};

//=============================+=====================================+=
template<typename TOwner>
public ref class                giNxRegisteredObject                  // Even without a reference to a giNxRegisteredObject in the main app,
  {                                                                   // a reference exists in the owner object (thus no gc) until Dispose is called on either.
                                                                      // Finalization at app exit is ignored for giNxObject (not for giNxData),
                                                                      // since the PhysX lib should be able to clean up after itself.
    protected:
      typedef                   giNxRegisteredObject<TOwner>          RegisteredType;

    private:
      TOwner^                   ownerptr;

    internal:
      RegisteredType^           Next;
      RegisteredType^           Previous;

    public:
      virtual ~giNxRegisteredObject() 
        { 
          if( Owner != nullptr || Next != nullptr || Previous != nullptr ) throw gcnew InvalidOperationException(); 
        }

    internal:
      void                      Register(TOwner^ ownerptr)
        {
          if( this->ownerptr ) throw gcnew InvalidOperationException(); // can only register once

          this->ownerptr = ownerptr;

          Next = Owner->First;
          if( Next ) Next->Previous = this;
          Owner->First = this;
        }

      void                      Unregister()
        {
          if( Owner->First == this ) Owner->First = Next;
          else Previous->Next = Next;

          if( Next ) Next->Previous = Previous;

          ownerptr = nullptr;
          Next = Previous = nullptr;
        }

    public:
      property TOwner^          Owner
        {
          TOwner^               get()                                 { return ownerptr; }
        }
  };

//=============================+=====================================+=
                                EndNamespace

