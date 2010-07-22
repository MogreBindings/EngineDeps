//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "eyecmPhysX.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
generic<typename T>
public interface class          IEnumerableWithCount:                 public IEnumerable<T>
  {
      property int              Count                                 { int get(); }
  };

//=============================+=====================================+=
template<
  typename                TgiOwner,
  typename                Tgi,
  typename Tgi::NxType* (*next) (typename TgiOwner::NxType*),
  void                  (*reset)(typename TgiOwner::NxType*),
  int                   (*count)(typename TgiOwner::NxType*),
  typename                TgiOwnerRef = TgiOwner^,
  typename                TgiRef      = Tgi^,
  typename                Iface       = IEnumerableWithCount<TgiRef>
>
ref class                       giNxEnumerable:                       public Iface
  {
    private:
      typedef                   giNxEnumerable<
                                  TgiOwner, Tgi,
                                  next, reset, count,
                                  TgiOwnerRef, TgiRef, Iface
                                >                                     ThisType;

      typedef          typename TgiOwner::NxType                      TNxOwner;
      typedef          typename Tgi::NxType                           TNx;

    private:
      TgiOwnerRef               ownerptr;

    private:
      giNxEnumerable(TgiOwnerRef ownerptr) { this->ownerptr = ownerptr; }
      ~giNxEnumerable() { ownerptr = nullptr; }

    public:
      virtual property int      Count
        {
          int                   get()                                 { return (*count)( ownerptr->ptr ); }
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

      ref class                 Enumerator:                           IEnumerator<TgiRef>
        {
          private:
            TgiOwnerRef         ownerptr;
            TNx*                current;

          public:
            Enumerator(TgiOwnerRef ownerptr) { this->ownerptr = ownerptr; current = 0; }
            ~Enumerator() { ownerptr = nullptr; }

          public:
            virtual bool        MoveNext()                            { return ( current = (*next)( ownerptr->ptr ) ) != 0; }
            virtual void        Reset()                               { (*reset)( ownerptr->ptr ); current = 0; }

          internal:
            virtual
            property Object^    CurrentIEnumerator
              {
                Object^         get() = System::Collections::IEnumerator::Current::get { return Current; }
              }

          public:
            virtual
            property Tgi^       Current
              {
                Tgi^            get()                                 { if( !current ) throw gcnew InvalidOperationException(); return Tgi::CastOrNull( current ); }
              }
        };

    internal:
      static Iface^             Create(TgiOwnerRef ownerptr)          { return gcnew ThisType( ownerptr );  }
  };

//=============================+=====================================+=
                                EndNamespace

