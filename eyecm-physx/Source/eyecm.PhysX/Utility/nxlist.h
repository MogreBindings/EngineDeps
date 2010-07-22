//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "eyecmPhysX.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
template<typename T>
public ref class                giValueWrapper
  {
    internal:
      typedef                   T                                     NxType;

    public:
      inline static T           Cast(T* ptr)                          { return *ptr; }
  };

//=============================+=====================================+=
template<
  typename                TgiOwner,
  typename                Tgi,
  typename Tgi::NxType* (*getbyidx)(typename TgiOwner::NxType*, int),
  int                   (*count   )(typename TgiOwner::NxType*),
  typename                TgiOwnerRef = TgiOwner^,
  typename                TgiRef      = Tgi^
>
ref class                       giNxList:                             public IList<TgiRef>
  {
    private:
      typedef                   giNxList<
                                  TgiOwner, Tgi,
                                  getbyidx, count,
                                  TgiOwnerRef, TgiRef
                                >                                     ThisType;

      typedef          typename TgiOwner::NxType                      TNxOwner;
      typedef          typename Tgi::NxType                           TNx;

    internal:
      TgiOwnerRef               ownerptr;

    internal:
      giNxList(TgiOwnerRef ownerptr) { this->ownerptr = ownerptr; }
      ~giNxList() { ownerptr = nullptr; }

    public:
      virtual property TgiRef   default[int]
        {
          TgiRef                get(int idx)                          { if( idx < 0 || idx >= Count ) throw gcnew IndexOutOfRangeException(); return Tgi::Cast( (*getbyidx)( ownerptr->GetNx(), idx ) ); }
          void                  set(int, TgiRef)                      { throw gcnew NotSupportedException(); }
        }

      virtual property int      Count
        {
          int                   get()                                 { return (*count)( ownerptr->GetNx() ); }
        }

      virtual int               IndexOf(TgiRef m)
        {
          int cnt = Count;

          for( int i = 0; i < cnt; i++ )
            if( InstanceEquals<TgiRef>()( this->default[i], m ) ) return i;

          return -1;
        }

      virtual bool              Contains(TgiRef m)                    { return IndexOf( m ) != -1; }
      virtual property bool     IsReadOnly                            { bool get() { return true; } }

      virtual void              Add(TgiRef)                           { throw gcnew NotSupportedException(); }
      virtual void              Insert(int, TgiRef)                   { throw gcnew NotSupportedException(); }
      virtual void              RemoveAt(int)                         { throw gcnew NotSupportedException(); }
      virtual bool              Remove(TgiRef)                        { throw gcnew NotSupportedException(); }
      virtual void              Clear()                               { throw gcnew NotSupportedException(); }

      virtual void              CopyTo(cli::array<TgiRef, 1>^ arr, int idx)
        {
          const int cnt = Count;

          for( int i = 0; i < cnt; i++ )
            arr[i + idx] = this->default[i];
        }

    internal:
      virtual
      System::Collections::
      IEnumerator^              GetEnumeratorIEnumerable() = System::Collections::IEnumerable::GetEnumerator
        {
          return GetEnumerator();
        }

    public:
      virtual
      IEnumerator<TgiRef>^      GetEnumerator()                       { return gcnew Enumerator( ownerptr ); }


      //-------------------------------------------------------------
      //---------------------== Enumerator ==------------------------
      //-------------------------------------------------------------

      ref class                 Enumerator:                           IEnumerator<TgiRef> // enumerator should be invalidated when the underlying collection changes
        {
          private:
            TgiOwnerRef         ownerptr;
            int                 idx;

          public:
            Enumerator(TgiOwnerRef ownerptr) { this->ownerptr = ownerptr; idx = -1; }
            ~Enumerator() {}

          public:
            virtual bool        MoveNext()                            { return ++idx < (*count)( ownerptr->GetNx() ); }
            virtual void        Reset()                               { idx = -1; }

          internal:
            virtual
            property Object^    CurrentIEnumerator
              {
                Object^         get() = System::Collections::IEnumerator::Current::get { return Current; }
              }

          public:
            virtual
            property TgiRef     Current
              {
                TgiRef          get()                                 { if( idx >= (*count)( ownerptr->GetNx() ) ) throw gcnew InvalidOperationException(); return Tgi::Cast( (*getbyidx)( ownerptr->GetNx(), idx ) ); }
              }
        };
  };

//=============================+=====================================+=
template<
  typename                TgiOwner,
  typename                Tgi,
  typename Tgi::NxType* (*getbyidx)(typename TgiOwner::NxType*, int),
  int                   (*count   )(typename TgiOwner::NxType*),
  typename                TgiOwnerRef = TgiOwner^,
  typename                TgiRef      = Tgi^
>
ref class                       giNxReadOnlyList:                     public ReadOnlyCollection<TgiRef>
  {
    internal:
      typedef                   giNxList<
                                  TgiOwner, Tgi,
                                  getbyidx, count,
                                  TgiOwnerRef,
                                  TgiRef
                                >                                     InternalType;
    public:
      giNxReadOnlyList(TgiOwnerRef ownerptr):
        ReadOnlyCollection( gcnew InternalType( ownerptr ) )
        {
        }

      ~giNxReadOnlyList()
        {
          delete Items;
        }
  };

//=============================+=====================================+=
template<
  typename TNx,
  bool deleteitems
>
struct                          giNxStaticListData
  {
    public:
      typedef                   giNxStaticListData<TNx, deleteitems>  ThisType;

    private:
      template<typename T>
      struct                    TypeHelper
        {
          typedef               T                                     StoreType;

          inline static T*      Get(ThisType* owner, int idx)
            {
              return owner->items + idx;
            }
        };

      template<typename T>
      struct                    TypeHelper<T*>
        {
          typedef               T*                                    StoreType;

          inline static T*      Get(ThisType* owner, int idx)
            {
              return owner->items[idx];
            }
        };

    public:
      typedef                   TypeHelper<TNx>                       HelperType;
      typedef          typename HelperType::StoreType                 StoreType;

    public:
      StoreType*                items;
      int                       count;

    public:
      giNxStaticListData(StoreType* items, int count): items( items ), count( count ) { }

    public:
      template<bool> struct     DeleteHelper                          { inline static void Delete(StoreType*) {} };
      template<> struct         DeleteHelper<true>                    { inline static void Delete(StoreType* ptr) { delete[] ptr; } };

      ~giNxStaticListData() { DeleteHelper<deleteitems>::Delete( items ); items = 0; count = 0; }

    public:
      static int                GetCount(ThisType* ptr)               { return ptr->count; }
  };


//=============================+=====================================+=
template<                                                             // wraps memory blocks returned from Nx into a ReadOnlyCollection, 'owns' its data, disposable
  typename Tgi,
  typename TNxStore    = Tgi::NxType,  // how nx objects are stored (either objects or pointers)
  typename TgiRef      = Tgi^,         // need to override this for value types
  bool     deleteitems = false
>
public ref class                giNxStaticList:                       public ReadOnlyCollection<TgiRef>
  {
    internal:
      typedef                   giNxStaticList<
                                  Tgi, TNxStore, TgiRef,
                                  deleteitems
                                >                                     ThisType;
      typedef                   giNxStaticListData<
                                  TNxStore, deleteitems
                                >                                     NxType;

      NxType*                   ptr;
      NxType*                   GetNx()                               { return ptr; }

    internal:
      typedef                   giNxList<
                                  ThisType, Tgi,
                                  &NxType::HelperType::Get, &NxType::GetCount,
                                  ThisType^, TgiRef
                                >                                     ListType;
    internal:
      giNxStaticList(TNxStore* items, int count):
        ReadOnlyCollection( gcnew ListType( nullptr ) )
        {
          dynamic_cast<ListType^>( Items )->ownerptr = this;

          ptr = new NxType( items, count );
        }

    public:
      ~giNxStaticList() { delete Items; this->!giNxStaticList(); }
      !giNxStaticList() { delete ptr; ptr = 0; }

      virtual String^           ToString() override
        {
          return IsDisposed ? "DISPOSED" : ReadOnlyCollection<TgiRef>::ToString();
        }

      property bool             IsDisposed
        {
          bool                  get()                                 { return ptr == 0; }
        }
  };

//=============================+=====================================+=
                                EndNamespace

