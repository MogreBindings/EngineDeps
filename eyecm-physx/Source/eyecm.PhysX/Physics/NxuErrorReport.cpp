//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "eyecmPhysx.h"

//=============================+=====================================+=
class                           giNxuErrorReport:                     public NXU_errorReport
  {
    private:
      void                      NXU_errorMessage(bool isError, const char  *str)
        {
          String^ Message = gcnew String( str );
          Console::WriteLine( "NXU: " + Message );
          if( isError ) throw gcnew Exception( Message );
        }

      static giNxuErrorReport*  ptr;

    public:
      static void               Init()
        {
          if( ptr ) return;
          ptr = new giNxuErrorReport;
          NXU::setErrorReport( ptr );
        }

      static void               DeInit()
        {
          if( !ptr ) return;
          NXU::setErrorReport( 0 );
          delete ptr; ptr = 0;
        }
  };

//=============================+=====================================+=
giNxuErrorReport*               giNxuErrorReport::ptr;

//=============================+=====================================+=
void                            InitNxuErrorReport()                  { giNxuErrorReport::Init(); }
void                            DeInitNxuErrorReport()                { giNxuErrorReport::DeInit(); }
