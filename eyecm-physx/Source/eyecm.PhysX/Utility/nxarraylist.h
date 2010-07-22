//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "eyecmPhysX.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
template<
  typename Tgi, 
  typename TNx, 
  typename TgiRef = Tgi^
>
ref class                       giNxWrapperHelper
  {    
    public:
      inline TgiRef             Wrap(TNx& data)                       { return Tgi::Wrap( data ); }
      inline TgiRef             Wrap(TNx* ptr)                        { return Tgi::Wrap( *ptr ); }
  };
  
//=============================+=====================================+=
template<
  typename Tgi, 
  typename TNx, 
  typename Tparam,
  typename TgiRef = Tgi^
>
ref class                       giNxWrapperHelperParam
  {
    private:
      Tparam^                   param;

    public:
      giNxWrapperHelperParam(Tparam^ param): param( param ) { }
  
    public:  
      inline TgiRef             Wrap(TNx& data)                       { return Tgi::Wrap( param, data ); }
      inline TgiRef             Wrap(TNx* ptr)                        { return Tgi::Wrap( param, *ptr ); }
  };

//=============================+=====================================+=
template<
  typename Tgi,
  typename TNx,
  typename Twrapper = giNxWrapperHelper<Tgi, TNx, Tgi^>,
  typename Tarray   = NxArray<TNx*>,
  typename TgiRef   = Tgi^
>
ref class                       giNxArrayList:                        IList<TgiRef>
  {
    internal:
      typedef                   giNxArrayList<
                                  Tgi, TNx, Twrapper,
                                  Tarray, TgiRef
                                >                                     ThisType;
    
      Tarray*                   arr;  // reference to the nx array
      List<TgiRef>^             warr; // list of wrapped objects
      Twrapper^                 wrapper;
      
    internal:
      giNxArrayList(Tarray* arr, Twrapper^ wrapper): arr( arr ), wrapper( wrapper )
        {
          const int cnt = Count;
          warr = gcnew List<TgiRef>( cnt );
          for( int i = 0; i < cnt; i++ ) warr->Add( nullptr );
        }

      ~giNxArrayList()
        {
          arr = 0;
          
          delete warr;    warr    = nullptr;
          delete wrapper; wrapper = nullptr;
        }
                
      template<typename T>
      ref struct                TypeHelper
        {
          inline static void    Push(Tarray* arr, TgiRef v)            { arr->push_back( *v->GetNx() ); }
          inline static void    Set(Tarray* arr, int idx, TgiRef v)    { arr->operator []( idx ) = *v->GetNx(); }
          inline static void    Insert(Tarray* arr, int idx, TgiRef v) { arr->insert( arr->begin() + idx, 1, *v->GetNx() ); }
          inline static void    Erase(Tarray* arr, int idx)            { T ptr = arr->begin() + idx; /*ptr->~TNx();*/ arr->erase( ptr, ptr + 1 ); }
        };

      template<typename T>
      ref struct                TypeHelper<T**>
        {
          inline static void    Push(Tarray* arr, TgiRef v)            { arr->push_back( v != nullptr ? v->GetNx() : 0 ); }
          inline static void    Set(Tarray* arr, int idx, TgiRef v)    { arr->operator []( idx ) = v->GetNx(); }
          inline static void    Insert(Tarray* arr, int idx, TgiRef v) { arr->insert( arr->begin() + idx, 1, v != nullptr ? v->GetNx() : 0 ); }
          inline static void    Erase(Tarray* arr, int idx)            { T** ptr = arr->begin() + idx; arr->erase( ptr, ptr + 1 ); }
        };
        
      typedef                   TypeHelper<typename Tarray::Iterator> CurTypeHelper;

      inline TgiRef             WrapOrGet(int idx)
        {
          TgiRef result = warr[idx];
          
          if( result == nullptr )
            warr[idx] = result = wrapper->Wrap( arr->operator []( idx ) );

          return result;
        }
      
      inline void               Set(int idx, TgiRef v)
        {
          warr[idx] = v;
          CurTypeHelper::Set( arr, idx, v );
        }      

    public:
      virtual property TgiRef   default[int]
        {
          TgiRef                get(int idx)                          { return WrapOrGet( idx ); }
          void                  set(int idx, TgiRef v)                { Set( idx, v ); }
        }

      virtual property int      Count                                 { int get() { return static_cast<int>( arr->size() ); } }
      virtual int               IndexOf(TgiRef v)                     { return warr->IndexOf( v ); }
      virtual bool              Contains(TgiRef v)                    { return warr->Contains( v ); }
      virtual property bool     IsReadOnly                            { bool get() { return false; } }

      virtual void              Add(TgiRef v)                         { warr->Add( v ); CurTypeHelper::Push( arr, v ); }
      virtual void              Insert(int idx, TgiRef v)             { warr->Insert( idx, v ); CurTypeHelper::Insert( arr, idx, v ); }
      virtual void              RemoveAt(int idx)                     { warr->RemoveAt( idx ); CurTypeHelper::Erase( arr, idx );
      }
      virtual bool              Remove(TgiRef v)                      { int idx = IndexOf( v ); if( idx < 0 ) return false; RemoveAt( idx ); return true; }
      virtual void              Clear()                               { warr->Clear(); arr->clear(); }

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
      IEnumerator<TgiRef>^      GetEnumerator()                       { return gcnew Enumerator( this ); }


      //-------------------------------------------------------------
      //---------------------== Enumerator ==------------------------
      //-------------------------------------------------------------

      ref class                 Enumerator:                           IEnumerator<TgiRef> // TODO: enumerator should be invalidated when the underlying collection changes
        {
          internal:
            typedef             ThisType^                             TgiOwnerRef;
            
          private:
            TgiOwnerRef         ownerptr;
            int                 idx;

          public:
            Enumerator(TgiOwnerRef ownerptr) { this->ownerptr = ownerptr; idx = -1; }
            ~Enumerator() { ownerptr = nullptr; }

          public:
            virtual bool        MoveNext()                            { return ++idx < ownerptr->Count; }
            virtual void        Reset()                               { idx = -1; }

          internal:
            virtual
            property Object^    CurrentIEnumerator                    { Object^ get() = System::Collections::IEnumerator::Current::get { return Current; } }

          public:
            virtual
            property TgiRef     Current
              {
                TgiRef          get()                                 
                  { 
                    if( idx >= ownerptr->Count ) throw gcnew InvalidOperationException(); 
                    return ownerptr->default [idx]; 
                  }
              }
        };
};

//=============================+=====================================+=
#define                         DefArrayListXPost(type, name, inittoken, arraytype) \
                                \
      typedef                   giNxArrayList< \
                                  type, \
                                  Nx##type, \
                                  name##ArrayWrapperType, \
                                  arraytype \
                                >                                     name##ArrayType; \
                                \
      typedef                   Collection<type^>                     name##ListType; \
      \
      name##ListType^           list##name; \
      \
      inline void               Deinit##name()                        { delete list##name; list##name = nullptr; } \
      \
    public: \
      property name##ListType^  name \
        { \
          name##ListType^       get()                                 { return list##name; } \
        }

//=============================+=====================================+=
#define                         DefArrayListX(type, name, inittoken, arraytype) \
    internal: \
      typedef                   giNxWrapperHelper<type, Nx##type>     name##ArrayWrapperType; \
                                DefArrayListXPost( type, name, inittoken, arraytype ) \
    internal: \
      inline void               Init##name()                          { list##name = gcnew name##ListType( gcnew name##ArrayType( inittoken, gcnew name##ArrayWrapperType() ) ); }

//=============================+=====================================+=
#define                         DefArrayListParamX(type, name, inittoken, paramtype, arraytype) \
    internal: \
      typedef                   giNxWrapperHelperParam< \
                                  type, \
                                  Nx##type, \
                                  paramtype \
                                >                                     name##ArrayWrapperType; \
                                DefArrayListXPost( type, name, inittoken, arraytype ) \
    internal: \
      inline void               Init##name(paramtype^ p)              { list##name = gcnew name##ListType( gcnew name##ArrayType( inittoken, gcnew name##ArrayWrapperType( p ) ) ); }
                                
//=============================+=====================================+=
#define                         DefArrayList(type, name, inittoken)                 DefArrayListX( type, name, inittoken, NxArray<Nx##type*> )
#define                         DefArrayListParam(type, name, inittoken, paramtype) DefArrayListParamX( type, name, inittoken, paramtype, NxArray<Nx##type*> )

//=============================+=====================================+=
#define                         DefArrayListFinalize( name )          list##name = nullptr;
//=============================+=====================================+=
                                EndNamespace
