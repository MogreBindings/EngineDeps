//=============================+=====================================+=
//public ref class                Scene:                                public giNxObject<NxScene, Scene, giNxRegisteredObject<Physics> >
//  {

    internal:
      #pragma warning( disable: 4793 )

      //-------------------------------------------------------------
      //---------------------== ReportHelper ==----------------------
      //-------------------------------------------------------------
      template<
        typename TNx,
        TNx* (NxScene::*getReport)() const,
        void (NxScene::*setReport)(TNx*),
        typename Tgi,
        typename Tiface
      >
      ref class                 ReportHelper
        {
          public:
            inline static void  set(NxScene* ptr, Tiface^ v)
              {
                Tgi* funptr = static_cast<Tgi*>( (ptr->*getReport)() );

                if( funptr ) {

                  if( v ) { funptr->iface = v; return; }
                  else { delete funptr; funptr = 0; }

                } else {

                  if( v ) funptr = new Tgi( v );
                  else return;
                }
                (ptr->*setReport)( funptr );
              }

            inline static
            Tiface^             get(NxScene* ptr)
              {
                Tgi* funptr = static_cast<Tgi*>( (ptr->*getReport)() );
                return funptr ? funptr->iface : nullptr;
              }
        };

      #pragma warning( default: 4793 )

      #define                   DefSceneReportGetterSetter(type)      ReportHelper<Nx##type, &NxScene::get##type, &NxScene::set##type, giNx##type, I##type>

      #define                   DefSceneReportGetSet(type) \
        I##type^                  Scene::type::get()                  { return DefSceneReportGetterSetter( type )::get( ptr ); } \
        void                      Scene::type::set(I##type^ v)        { return DefSceneReportGetterSetter( type )::set( ptr, v ); }

      #define                   DefSceneReportGetSetDecl(type) \
      property I##type^         type                                  { I##type^ get(); void set(I##type^); }

    private:
      void                      InitReports(SceneDesc^ Desc);
      void                      DeInitReports();

    public:
      DefSceneReportGetSetDecl( UserNotify )
      DefSceneReportGetSetDecl( FluidUserNotify )
      DefSceneReportGetSetDecl( UserContactModify )
      DefSceneReportGetSetDecl( UserContactReport )
      DefSceneReportGetSetDecl( UserTriggerReport )
      DefSceneReportGetSetDecl( UserActorPairFiltering )

//  };
//=============================+=====================================+=
