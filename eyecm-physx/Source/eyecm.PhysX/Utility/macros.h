// LEGEND for 'DefXY'
//
//  X
// ---
//  R - only get method defined (read directly from data)
//  P - get and set methods defined (read from and written to data directly )
//  M - get and set through method call on ptr
//  m - get only through method call on ptr
//  s - set only through method call on ptr
//
//  Y
// ---
//  0 - no type casting done
//  c - explicit type casting performed
//  x - type conversion performed via ToNx, FromNx
//
//=============================+=====================================+=
#define                         DefNothing
#define                         DefPrefixComma( x )                  , x

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public ref class                MyDocAttrAttribute:                   public System::Attribute
  {
    public:
      String^                   nxtype;
      String^                   nxmemb;
      bool                      method;
    public:
      MyDocAttrAttribute(Type^ nxtype, String^ nxmemb, bool method): nxtype( nxtype->FullName ), nxmemb( nxmemb ), method( method ) { }
  };

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
#define                         DefRc( ret, name, cast, memb ) \
      [MyDocAttr( NxType::typeid, #memb, false )] \
      property ret              name \
        { \
          ret                   get()                                 { return static_cast<ret>( data->memb ); } \
        } \

#define                         DefR0( ret, name, memb ) \
      [MyDocAttr( NxType::typeid, #memb, false )] \
      property ret              name \
        { \
          ret                   get()                                 { return data->memb; } \
        } \

#define                         DefRx( ret, name, memb ) \
      [MyDocAttr( NxType::typeid, #memb, false )] \
      property ret              name \
        { \
          ret                   get()                                 { return FromNx( data->memb ); } \
        } \

//=============================+=====================================+=
#define                         DefPc( ret, name, cast, memb ) \
      [MyDocAttr( NxType::typeid, #memb, false )] \
      property ret              name \
        { \
          ret                   get()                                 { return static_cast<ret>( data->memb ); } \
          void                  set(ret v)                            { data->memb = static_cast<cast>( v ); PostSet(); } \
        } \
\

#define                         DefPcc( ret, name, cast1, cast2, memb ) \
      [MyDocAttr( NxType::typeid, #memb, false )] \
      property ret              name \
        { \
          ret                   get()                                 { return static_cast<ret>( data->memb ); } \
          void                  set(ret v)                            { data->memb = static_cast<cast1>( static_cast<cast2>( v ) ); PostSet(); } \
        } \
\

#define                         DefP0( ret, name, memb ) \
      [MyDocAttr( NxType::typeid, #memb, false )] \
      property ret              name \
        { \
          ret                   get()                                 { return data->memb; } \
          void                  set(ret v)                            { data->memb = v; PostSet(); } \
        } \
\

#define                         DefPx( ret, name, memb ) \
      [MyDocAttr( NxType::typeid, #memb, false )] \
      property ret              name \
        { \
          ret                   get()                                 { return FromNx( data->memb ); } \
          void                  set(ret v)                            { data->memb = ToNx( v ); PostSet(); } \
        } \

//=============================+=====================================+=
#define                         DefMc( ret, name, cast, memb ) \
      [MyDocAttr( NxType::typeid, #memb, true )] \
      property ret              name \
        { \
          ret                   get()                                 { return static_cast<ret>( GetNx()->get##memb() ); } \
          void                  set(ret v)                            { GetNx()->set##memb( static_cast<cast>( v ) ); } \
        } \

#define                         DefM0( ret, name, memb ) \
      [MyDocAttr( NxType::typeid, #memb, true )] \
      property ret              name \
        { \
          ret                   get()                                 { return GetNx()->get##memb(); } \
          void                  set(ret v)                            { GetNx()->set##memb( v ); } \
        } \

#define                         DefMx( ret, name, memb ) \
      [MyDocAttr( NxType::typeid, #memb, true )] \
      property ret              name \
        { \
          ret                   get()                                 { return FromNx( GetNx()->get##memb() ); } \
          void                  set(ret v)                            { GetNx()->set##memb( ToNx( v ) ); } \
        } \

//=============================+=====================================+=
#define                         Defmc( ret, name, memb ) \
      [MyDocAttr( NxType::typeid, #memb, true )] \
      property ret              name \
        { \
          ret                   get()                                 { return static_cast<ret>( GetNx()->get##memb() ); } \
        } \

#define                         Defm0( ret, name, memb ) \
      [MyDocAttr( NxType::typeid, #memb, true )] \
      property ret              name \
        { \
          ret                   get()                                 { return ptr->get##memb(); } \
        } \

#define                         Defmx( ret, name, memb ) \
      [MyDocAttr( NxType::typeid, #memb, true )] \
      property ret              name \
        { \
          ret                   get()                                 { return FromNx( ptr->get##memb() ); } \
        } \

//=============================+=====================================+=
#define                         Defs0( ret, name, memb ) \
      [MyDocAttr( NxType::typeid, #memb, true )] \
      property ret              name \
        { \
          void                  set(ret val)                          { return GetNx()->set##memb( val ); } \
        } \

#define                         Defsc( ret, name, cast, memb ) \
      [MyDocAttr( NxType::typeid, #memb, true )] \
      property ret              name \
        { \
          void                  set(ret val)                          { return GetNx()->set##memb( static_cast<cast>( val ) ); } \
        } \
        
//=============================+=====================================+=
#define                         DefSaveToDescX( type, ptr ) \
      type^                     SaveToDesc()                          { type^ Desc = gcnew type(); ptr->saveToDesc( *Desc->data ); return Desc; } \
      void                      SaveToDesc([Out] type^% Desc)         { if( Desc == nullptr ) Desc = SaveToDesc(); else ptr->saveToDesc( *Desc->data ); } \

//=============================+=====================================+=
#define                         DefLoadSaveToDescX( type, ptr ) \
      void                      LoadFromDesc(type^ Desc)              { ptr->loadFromDesc( *Desc->data ); } \
                                DefSaveToDescX( type, ptr ) \

//=============================+=====================================+=
#define                         DefSaveToDesc( type )                 DefSaveToDescX( type##Desc, ptr )
#define                         DefLoadSaveToDesc( type )             DefLoadSaveToDescX( type##Desc, ptr )

//=============================+=====================================+=
#define                         DefRecastPtr( type, base ) \
    internal: \
      property type*            ptr                                   { type* get() { return static_cast<type*>( base::ptr ); } } \
      type*                     GetNx() new                           { return static_cast<type*>( base::ptr ); }

//=============================+=====================================+=
#define                         DefRecastData( type, base ) \
    internal: \
      property type*            data                                  { inline type* get() { return static_cast<type*>( base::data ); } } \
      type*                     GetNx() new                           { return static_cast<type*>( base::data ); }


//=============================+=====================================+=
#define                         DefValidDefaultXX(x, newornot) \
      property bool             IsValid \
        { \
          bool                  get() newornot                        { return data->isValid(); } \
        } \
      \
      void                      SetToDefault() newornot               { x } \

//=============================+=====================================+=
#define                         DefValidDefaultX(x)                   DefValidDefaultXX( x, DefNothing )
#define                         DefValidDefault                       DefValidDefaultX( data->setToDefault(); PostSet(); )
#define                         DefValidDefaultUnpin                  DefValidDefaultX( data->setToDefault(); UnpinAll(); PostSet(); )
#define                         DefValidDefaultNew                    DefValidDefaultXX( data->setToDefault(); PostSet();, new )
#define                         DefValidDefaultNewUnpin               DefValidDefaultXX( data->setToDefault(); UnpinAll(); PostSet();, new )

//=============================+=====================================+=
#define                         DefCBPrevent                          ChangedDelegate^ OldChanged = OnChanged; OnChanged = nullptr;
#define                         DefCBReenable                         OnChanged = OldChanged; PostSet();

//=============================+=====================================+=
#include                       "macros.proxy.h"
#include                       "macros.pin.h"
