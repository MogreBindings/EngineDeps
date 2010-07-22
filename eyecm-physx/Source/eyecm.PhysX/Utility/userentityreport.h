//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "nxlist.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
generic<typename T>
public interface class          IUserEntityReport
  {
      bool                      OnEvent(ReadOnlyCollection<T>^ List);
  };

//=============================+=====================================+=
template<
  typename Tgi,
  typename TNx    = Tgi::NxType,
  typename TgiRef = Tgi^
>
class                           giUserEntityReport:                   public NxUserEntityReport<TNx>
  {
    private:
      typedef                   giUserEntityReport<Tgi, TNx, TgiRef>  ThisType;

      template<typename T>
      struct                    TypeHelper
        {
          typedef               T                                     ReportedType;
        };

      template<typename T>
      struct                    TypeHelper<giValueWrapper<T>^>
        {
          typedef               T                                     ReportedType;
        };

    public:
      typedef          typename TypeHelper<TgiRef>::ReportedType      ReportedType;
      typedef                   ReadOnlyCollection<ReportedType>      CollectionType;
      typedef                   IUserEntityReport<ReportedType>       IFaceType;
      typedef                   giNxStaticList<Tgi, TNx, ReportedType> ListType;

    public:
      gcroot<IFaceType^>        iface;

    public:
      giUserEntityReport(bool) { }

      giUserEntityReport(IFaceType^ iface)
        {
          if( iface == nullptr ) throw gcnew NullReferenceException();
          this->iface = iface;
        }

      ~giUserEntityReport() { iface = nullptr; }

    private:
      bool                      onEvent(NxU32 nbEntities, TNx* entities)
        {
          CollectionType^ list   = gcnew ListType( entities, nbEntities );
          bool            result = iface->OnEvent( list );

          delete list;
          return result;
        }
  };

//=============================+=====================================+=
                                EndNamespace

