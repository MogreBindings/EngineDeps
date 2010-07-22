//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Scene.h"
#include                       "nxlist.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
public ref class                DebugRenderable
  {
    public:
      [StructLayout( LayoutKind::Sequential )]
      value struct              DebugPosition
        {
            float               x, y, z;
        };

      [StructLayout( LayoutKind::Sequential )]
      value struct              DebugColor
        {
            UInt32              bgra;

            property UInt32     rgba
              {
                UInt32          get()                                 { return ARGBToABGR( bgra ); }
              }
        };

      [StructLayout( LayoutKind::Sequential )]
      value struct              DebugPoint
        {
          internal:
            typedef             const NxDebugPoint                    NxType;

          public:
            DebugPosition       p;
            DebugColor          color;

          internal:
            inline static
            DebugPoint          Cast(NxType* ptr)                     { return *reinterpret_cast<DebugPoint*>( const_cast<NxDebugPoint*>( ptr ) ); }
        };

      [StructLayout( LayoutKind::Sequential )]
      value struct              DebugLine
        {
          internal:
            typedef             const NxDebugLine                     NxType;

          public:
            DebugPosition       p0, p1;
            DebugColor          color;

          internal:
            inline static
            DebugLine           Cast(NxType* ptr)                     { return *reinterpret_cast<DebugLine*>( const_cast<NxDebugLine*>( ptr ) ); }
        };

      [StructLayout( LayoutKind::Sequential )]
      value struct              DebugTriangle
        {
          internal:
            typedef             const NxDebugTriangle                 NxType;

          public:
            DebugPosition       p0, p1, p2;
            DebugColor          color;

          internal:
            inline static
            DebugTriangle       Cast(NxType* ptr)                     { return *reinterpret_cast<DebugTriangle*>( const_cast<NxDebugTriangle*>( ptr ) ); }
        };

    private:

      typedef                   giNxStaticList<
                                  DebugPoint,
                                  const NxDebugPoint,
                                  DebugPoint
                                >                                     PointListRef;
      typedef                   ReadOnlyCollection<DebugPoint>        PointList;

      typedef                   giNxStaticList<
                                  DebugLine,
                                  const NxDebugLine,
                                  DebugLine
                                >                                     LineListRef;
      typedef                   ReadOnlyCollection<DebugLine>         LineList;

      typedef                   giNxStaticList<
                                  DebugTriangle,
                                  const NxDebugTriangle,
                                  DebugTriangle
                                >                                     TriangleListRef;
      typedef                   ReadOnlyCollection<DebugTriangle>     TriangleList;

      PointListRef^             pointlist;
      LineListRef^              linelist;
      TriangleListRef^          trianglelist;

    internal:
      DebugRenderable(const NxDebugRenderable* renderable)
        {
          pointlist    = gcnew PointListRef   ( renderable->getPoints(),    renderable->getNbPoints()    );
          linelist     = gcnew LineListRef    ( renderable->getLines(),     renderable->getNbLines()     );
          trianglelist = gcnew TriangleListRef( renderable->getTriangles(), renderable->getNbTriangles() );
        }

    public:
      ~DebugRenderable() { this->!DebugRenderable(); }
      !DebugRenderable()
        {
          delete pointlist;    pointlist    = nullptr;
          delete linelist;     linelist     = nullptr;
          delete trianglelist; trianglelist = nullptr;
        }

    public:
      property PointList^       Points
        {
          PointList^            get()                                 { return pointlist; }
        }

      property LineList^        Lines
        {
          LineList^             get()                                 { return linelist; }
        }

      property TriangleList^    Triangles
        {
          TriangleList^         get()                                 { return trianglelist; }
        }

      property int              PointBufferByteSize
        {
          int                   get()                                 { return Points->Count * (3 * 4 + 1 * 4); }
        }

      property int              LineBufferByteSize
        {
          int                   get()                                 { return Lines->Count * 2 * (3 * 4 + 1 * 4); }
        }

      property int              TriangleBufferByteSize
        {
          int                   get()                                 { return Triangles->Count * 3 * (3 * 4 + 1 * 4); }
        }

      void                      CopyPointsToBuffer(IntPtr Target, int ByteOffset)
        {
          float*              ptr        = reinterpret_cast<float*>( reinterpret_cast<intptr_t>( Target.ToPointer() ) + ByteOffset );
          const NxDebugPoint* pts        = pointlist->ptr->items;
          const int           pointcount = pointlist->ptr->count;

          for( int i = 0; i < pointcount; i++ ) {

            const NxU32 col = ARGBToABGR( pts[i].color );

            const NxVec3& p0 = pts[i].p; *ptr++ = p0.x; *ptr++ = p0.y; *ptr++ = p0.z;
            *reinterpret_cast<NxU32*>( ptr++ ) = col;
          }
        }

      ///<summary>Copies debug line vertex data to a preallocated buffer</summary>
      void                      CopyLinesToBuffer(IntPtr Target, int ByteOffset)
        {
          float*             ptr       = reinterpret_cast<float*>( reinterpret_cast<intptr_t>( Target.ToPointer() ) + ByteOffset );
          const NxDebugLine* lines     = this->linelist->ptr->items;
          const int          linecount = this->linelist->ptr->count;

          for( int i = 0; i < linecount; i++ ) {

            const NxU32 col = ARGBToABGR( lines[i].color );

            const NxVec3& p0 = lines[i].p0; *ptr++ = p0.x; *ptr++ = p0.y; *ptr++ = p0.z;
            *reinterpret_cast<NxU32*>( ptr++ ) = col;

            const NxVec3& p1 = lines[i].p1; *ptr++ = p1.x; *ptr++ = p1.y; *ptr++ = p1.z;
            *reinterpret_cast<NxU32*>( ptr++ ) = col;
          }
        }

      void                      CopyTrianglesToBuffer(IntPtr Target, int ByteOffset)
        {
          float*                 ptr           = reinterpret_cast<float*>( reinterpret_cast<intptr_t>( Target.ToPointer() ) + ByteOffset );
          const NxDebugTriangle* tris          = trianglelist->ptr->items;
          const int              trianglecount = trianglelist->ptr->count;

          for( int i = 0; i < trianglecount; i++ ) {

            const NxU32  col = ARGBToABGR( tris[i].color );;

            const NxVec3& p0 = tris[i].p0; *ptr++ = p0.x; *ptr++ = p0.y; *ptr++ = p0.z;
            *reinterpret_cast<NxU32*>( ptr++ ) = col;

            const NxVec3& p1 = tris[i].p1; *ptr++ = p1.x; *ptr++ = p1.y; *ptr++ = p1.z;
            *reinterpret_cast<NxU32*>( ptr++ ) = col;

            const NxVec3& p2 = tris[i].p2; *ptr++ = p2.x; *ptr++ = p2.y; *ptr++ = p2.z;
            *reinterpret_cast<NxU32*>( ptr++ ) = col;
          }
        }
  };

//=============================+=====================================+=
template<>
struct                          InstanceEquals<DebugRenderable::DebugPoint>
  {
    bool                        operator()(DebugRenderable::DebugPoint, DebugRenderable::DebugPoint) { return false; }
  };

//=============================+=====================================+=
template<>
struct                          InstanceEquals<DebugRenderable::DebugLine>
  {
    bool                        operator()(DebugRenderable::DebugLine, DebugRenderable::DebugLine) { return false; }
  };

//=============================+=====================================+=
template<>
struct                          InstanceEquals<DebugRenderable::DebugTriangle>
  {
    bool                        operator()(DebugRenderable::DebugTriangle, DebugRenderable::DebugTriangle) { return false; }
  };

//=============================+=====================================+=
                                EndNamespace

//=============================+=====================================+=
DebugRenderable^                Scene::GetDebugRenderable()
  {
    return gcnew DebugRenderable( ptr->getDebugRenderable() );
  }
