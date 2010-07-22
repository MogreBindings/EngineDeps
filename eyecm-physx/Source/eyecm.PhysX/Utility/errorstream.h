//=============================+=====================================+=
#pragma                         once
//=============================+=====================================+=
#include                       "eyecmPhysX.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public ref class                ErrorStream
  {
    public:
      virtual void              ReportError(ErrorCodes ErrorCode, String^ Message, String^ File, int Line)
        {
            String^ msg = String::Format( "({0}) \"{1}\" [{2},{3}]", ErrorCode, Message, File, Line );
            Print( msg );

            #ifdef _DEBUG
              if( ErrorCode != ErrorCodes::NoError && static_cast<int>( ErrorCode ) < static_cast<int>( ErrorCodes::Info ) )
                throw gcnew Exception( msg );
            #endif
        }

      virtual AssertResponses   ReportAssertViolation(String^ Message, String^ File, int Line)
        {
            String^ msg = String::Format( "ASSERT \"{0}\" [{1},{2}]", Message, File, Line );
            Print( msg );

            #ifdef _DEBUG
              return AssertResponses::Breakpoint;
            #else
              return AssertResponses::Continue;
            #endif
        }

      virtual void              Print(String^ Message)
        {
          System::Console::Write( "PhysX: " );
          System::Console::WriteLine( Message );
        }
  };

//=============================+=====================================+=
class                           giNxErrorStream:                      public NxUserOutputStream
  {
      gcroot<ErrorStream^>      Stream;

    public:
      giNxErrorStream(ErrorStream^ Stream) { this->Stream = Stream; }
      ~giNxErrorStream() { this->Stream = nullptr; }

    private:
      void                      reportError(NxErrorCode code, const char* message, const char* file, int line)
        {
          Stream->ReportError( static_cast<ErrorCodes>( code ), gcnew String( message ), gcnew String( file ), line );
        }

      NxAssertResponse          reportAssertViolation(const char* message, const char* file, int line)
        {
          return static_cast<NxAssertResponse>( Stream->ReportAssertViolation( gcnew String( message ), gcnew String( file ), line ) );
        }

      void                      print(const char* message)
        {
          Stream->Print( gcnew String( message ) );
        }
  };

//=============================+=====================================+=
                                EndNamespace
