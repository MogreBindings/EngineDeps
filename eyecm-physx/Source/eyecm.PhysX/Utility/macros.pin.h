//=============================+=====================================+=
#define                         DefPinFree(name, ptrtoken) \
    if( pin##name.IsAllocated ) pin##name.Free(); \
    data->ptrtoken = 0;

//=============================+=====================================+=
#define                         DefPinCopy(name, token) \
    if( other->pin##name.IsAllocated ) \
    { \
      pin##name = GCHandle::Alloc( other->pin##name.Target, GCHandleType::Pinned ); \
      data->token = other->data->token; \
    }

//=============================+=====================================+=
#define                         DefCntCopy(countstype) \
    if( other->counts ) \
    { \
      if( !counts ) counts = new countstype( *other->counts ); \
      else *counts = *other->counts; \
    } \
    else if( !other->counts && counts ) { delete counts; counts = 0; }

//=============================+=====================================+=
#define                         DefCntPostSet(token, condition) \
    if( counts ) data->token = (condition) ? counts : 0;

//=============================+=====================================+=
#define                         DefPinUnpinX(type, name, genprefix, argpostfix) \
      internal: \
        GCHandle                pin##name; \
        \
      public: \
        property Object^        name##PinnedObject \
          { \
            Object^             get()                                 { return pin##name.IsAllocated ? pin##name.Target : nullptr; } \
          } \
        genprefix \
        void                    Pin##name(array<type>^ Source argpostfix); \
        void                    Unpin##name();

//=============================+=====================================+=
#define                         DefPtrArgPost                         , unsigned ByteOffset, unsigned ByteStride
#define                         DefPinUnpin(name)                     DefPinUnpinX( T, name, generic<typename T> where T: System::ValueType, DefPtrArgPost )

//=============================+=====================================+=
#define                         DefPtrCast(name, ptrtype, ptrtoken) \
      public: \
        property IntPtr         name##Ptr \
          { \
            IntPtr              get()                                 { return IntPtr( const_cast<ptrtype*>( data->ptrtoken ) ); } \
            void                set(IntPtr v)                         { if( pin##name.IsAllocated ) throw gcnew InvalidOperationException( #name " is currently pinned. Unpin it to manage " #name "Ptr yourself." ); data->ptrtoken = static_cast<ptrtype*>( v.ToPointer() ); PostSet(); } \
          } \

//=============================+=====================================+=
#define                         DefPtrStride(name, stridetoken) \
      public: \
        property unsigned       name##ByteStride \
          { \
            unsigned            get()                                 { return data->stridetoken; } \
            void                set(unsigned v)                       { data->stridetoken = v; } \
          } \

//=============================+=====================================+=
// no stride/offset while pinning, array type is fixed
#define                         DefPtrNS(ptrtype, name, ptrtoken, arraytype) \
                                DefPinUnpinX( arraytype, name, DefNothing, DefNothing ) \
                                DefPtrCast( name, ptrtype, ptrtoken ) \

//=============================+=====================================+=
// pinning of generic array with stride/offset, custom stride name
#define                         DefPtr(ptrtype, name, ptrtoken, stridetoken ) \
                                DefPinUnpin( name ) \
                                DefPtrCast( name, ptrtype, ptrtoken ) \
                                DefPtrStride( name, stridetoken )

//=============================+=====================================+=
// pinning of fixed type array with stride/offset, custom stride name
#define                         DefPtrA(ptrtype, name, ptrtoken, stridetoken, arraytype ) \
                                DefPinUnpinX( arraytype, name, DefNothing, DefNothing ) \
                                DefPtrCast( name, ptrtype, ptrtoken ) \
                                DefPtrStride( name, stridetoken )

//=============================+=====================================+=
#define                         DefAutoCnt(countstype) \
      internal: \
        countstype*             counts; \
        \
        void                    PostSet() new; \
        void                    ClearCounts(); \
        void                    DeinitManaged()                       { UnpinPinned(); DeinitUnmanaged(); } \
        void                    DeinitUnmanaged()                     { delete counts; counts = 0;        } \
        \
      public: \
        property bool           AutoManageCounts \
          { \
            bool                get()                                 { return counts != 0; } \
            void                set(bool v) \
              { \
                if( counts ) { \
                  \
                  if( v ) return; \
                  delete counts; counts = 0; \
                  ClearCounts(); \
                  \
                } else { \
                  \
                  if( !v ) return; \
                  counts = new countstype( 0 ); \
                } \
                \
                PostSet(); \
              } \
          }

//=============================+=====================================+=
#define                         DefCntX(ret, name, token, cntset) \
      public: \
        property IntPtr         name##Ptr \
          { \
            IntPtr              get()                                 { return IntPtr( data->token ); } \
            void                set(IntPtr v) \
              { \
                if( counts ) throw gcnew InvalidOperationException( "Counts are currently auto-managed. Set the AutoManageCounts property to false to manage " #name"CountPtr yourself." ); \
                data->token = static_cast<unsigned*>( v.ToPointer() ); \
              } \
          } \
        property ret            name \
          { \
            ret                 get()                                 { return static_cast<ret>( data->token ? *data->token : 0 ); } \
                                cntset \
          }

//=============================+=====================================+=
#define                         DefCnt(name, token)                   DefCntX( unsigned, name##Count, token,  )
#define                         DefCntSet(name, token)                DefCntX( unsigned, name##Count, token, void set(unsigned v) { if( data->token ) *data->token = v; } )

//=============================+=====================================+=
#define                         DefPinFuncsX(type, isnew) \
      internal: \
        void                    CopyCustom(type^); \
        void                    UnpinPinned() isnew; \
      public: \
        void                    UnpinAll() isnew                      { UnpinPinned(); PostSet(); }

//=============================+=====================================+=
#define                         DefPinFuncs(type)                     DefPinFuncsX( type, DefNothing )

//=============================+=====================================+=
#define                         DefPinCntFuncs(type, counttypes) \
                                DefPinFuncs(type) \
                                DefAutoCnt(counttypes)

//=============================+=====================================+=
#define                         DefPinImplX(type, name, ptrtoken, stridetoken, owner, genprefix, arraytype, arraydim) \
\
genprefix \
void                            owner::Pin##name(array<arraytype arraydim>^ Source, unsigned ByteOffset, unsigned ByteStride) \
  { \
    DefPinFree( name, ptrtoken ) \
    if( Source == nullptr ) return; \
    \
    if( ByteStride == 0 ) ByteStride = sizeof( arraytype ); \
    \
    pin##name         = GCHandle::Alloc( Source, GCHandleType::Pinned ); \
    data->ptrtoken    = reinterpret_cast<type*>( pin##name.AddrOfPinnedObject().ToInt64() + ByteOffset ); \
    data->stridetoken = ByteStride; \
    \
    PostSet(); \
  } \

//=============================+=====================================+=
#define                         DefUnpinImplX(type, name, ptrtoken, owner) \
void                            owner::Unpin##name() \
  { \
    if( !pin##name.IsAllocated ) return; \
    pin##name.Free(); \
    data->ptrtoken = 0; \
    \
    PostSet(); \
  } \

//=============================+=====================================+=
#define                         DefArrayTypeTwoDimensional            , 2

//=============================+=====================================+=
#define                         DefPinUnpinImpl(type, name, ptrtoken, owner) \
                                DefPinImplX( type, name, ptrtoken, ptrtoken##ByteStride, owner, generic<typename T>, T, DefNothing ) \
                                DefUnpinImplX( type, name, ptrtoken, owner )

//=============================+=====================================+=
#define                         DefPinUnpinImplS(type, name, ptrtoken, stridetoken, owner) \
                                DefPinImplX( type, name, ptrtoken, stridetoken, owner, generic<typename T>, T, DefNothing ) \
                                DefUnpinImplX( type, name, ptrtoken, owner )
