//=============================+=====================================+=
#define                         DefProxyBase                          giNxProxyData
#define                         DefCBProxyBase                        giNxCallbackProxyData

//=============================+=====================================+=
#ifdef                         _DEBUG
  #define                       DefThrowOnDisposed(obj, type, action) if( obj->IsDisposed ) throw gcnew NullReferenceException( "Attempted to " action " a '" #type "' that is disposed." );
#else
  #define                       DefThrowOnDisposed(obj, type, action)
#endif

//=============================+=====================================+=
#define                         DefCloneCopyFuncsOnly(type, isnew) \
    [Obsolete( "Use " #type "::CopyFrom instead." )] \
    type^                       Copy(type^ From) { return CopyFrom( From ); } \
    type^                       CopyFrom(type^ From) \
      { \
        DefThrowOnDisposed( this, type, "copy to" ) \
        DefThrowOnDisposed( From, type, "copy from" ) \
        *data = *From->data; \
        CopyCustom( From ); \
        PostSet(); \
        return this;  \
      } \
    type^                       Clone() isnew { return gcnew type( this ); }

//=============================+=====================================+=
#define                         DefCloneCopy(type) \
  public: \
    type(type^ Original): BaseType( const_cast<const NxType&>( *Original->data ) ) \
      { \
        DefThrowOnDisposed( Original, type, "clone" ) \
        CopyCustom( Original ); \
        PostSet(); \
      } \
  public: \
                                DefCloneCopyFuncsOnly( type, DefNothing )

//=============================+=====================================+=
#define                         DefProxyConstructorsX(type, validdefault) \
  internal: \
    type(NxType& desc): BaseType( desc ) { flags |= ProxyFlagsThrowOnDispose; } \
  public: \
                                DefCloneCopy( type ) \
                                validdefault

//=============================+=====================================+=
#define                         DefCBProxyConstructorsX(type, validdefault) \
  internal: \
    type(ChangedDelegate^ OnChanged): BaseType( OnChanged ) { } \
    type(ChangedDelegate^ OnChanged, NxType& desc): BaseType( OnChanged, desc ) { } \
    \
                                DefProxyConstructorsX( type, validdefault )

//=============================+=====================================+=
#define                         DefCBProxyConstructors(type)          DefCBProxyConstructorsX( type, DefValidDefault )
#define                         DefCBProxyConstructorsPin(type)       DefCBProxyConstructorsX( type, DefValidDefaultUnpin )
#define                         DefProxyConstructors(type)            DefProxyConstructorsX( type, DefValidDefault )
#define                         DefProxyConstructorsPin(type)         DefProxyConstructorsX( type, DefValidDefaultUnpin )

//=============================+=====================================+=
#define                         DefDataConstructorsX(type, validdefault) \
  public: \
                                DefCloneCopy( type ) \
                                validdefault 



//=============================+=====================================+=
#define                         DefDataConstructors(type)             DefDataConstructorsX( type, DefValidDefault )
#define                         DefDataConstructorsPin(type)          DefDataConstructorsX( type, DefValidDefaultUnpin )

//=============================+=====================================+=
#define                         DefProxyGetSetXX(type, name, getter, init, afterconstruct) \
    internal: \
      type^                     proxy##name; \
      \
    public: \
      property type^            name \
        { \
          type^                 get() \
            { \
              DefThrowOnDisposed( this, type, "access" ) \
              if( proxy##name == nullptr && !IsDisposed ) { proxy##name = gcnew type( init ); afterconstruct ; getter } \
              return proxy##name; \
            } \
        }

//=============================+=====================================+=
#define                         DefProxyGetSetX(type, name, getter, init)     DefProxyGetSetXX( type, name, getter, init, )
#define                         DefProxyGetSetPin(type, name, token)          DefProxyGetSetXX( type, name, , data->token, proxy##name->AutoManageCounts=true )
#define                         DefProxyGetSet(type, name, token)             DefProxyGetSetX(  type, name, , data->token )
#define                         DefProxyGetSetM(owner, type, name)            DefProxyGetSetX(  type, name, ptr->get##name( *proxy##name->data );  , gcnew type::ChangedDelegate( this, &owner::On##name##Changed ) )
#define                         DefProxyGetSetm(owner, type, name)            DefProxyGetSetX(  type, name, *proxy##name->data = ptr->get##name(); , gcnew type::ChangedDelegate( this, &owner::On##name##Changed ) )
#define                         DefProxyGetSetmPin(owner, type, name)         DefProxyGetSetXX( type, name, *proxy##name->data = ptr->get##name(); , gcnew type::ChangedDelegate( this, &owner::On##name##Changed ),  proxy##name->AutoManageCounts = true )
#define                         DefProxyGetSetG(owner, type, gname, name)     DefProxyGetSetX(  type, name, *proxy##name->data = ptr->get##gname(); , gcnew type::ChangedDelegate( this, &owner::On##name##Changed ) )
#define                         DefProxyGetSetGPin(owner, type, gname, name)  DefProxyGetSetXX( type, name, *proxy##name->data = ptr->get##gname(); , gcnew type::ChangedDelegate( this, &owner::On##name##Changed ), proxy##name->AutoManageCounts = true )

//=============================+=====================================+=
#define                         DefProxyDestroy( name )               if( proxy##name != nullptr ) { proxy##name->DeleteSelf(); proxy##name = nullptr; }

//=============================+=====================================+=
#define                         DefProxyCopyFastX( name, other )      if( other->proxy##name != nullptr ) name->CopyFrom( other->proxy##name );
#define                         DefProxyCopyFast( name )              DefProxyCopyFastX( name, Desc );
