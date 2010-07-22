//=============================+=====================================+=
#include                       "NxUserAllocator.h"

//=============================+=====================================+=
class                           giUserAllocator:                      public NxUserAllocator
  {
    private:
      void*                     mallocDEBUG(size_t size, const char* /*fileName*/, int /*line*/) { return malloc( size ); }
      //
      void*                     malloc(size_t size)                   { return ::malloc( size ); }
      void*                     realloc(void* memory, size_t size)    { return ::realloc( memory, size ); }
      void                      free(void* memory)                    { return ::free( memory ); }
  };

//=============================+=====================================+=
NxUserAllocator*                GetUserAllocator()
  {  
    return new giUserAllocator;
  }
