using System;
using Tao.FreeGlut;
using Tao.OpenGl;

namespace eyecm.PhysX.Demos
{
    public partial class DemoClass
    {
        protected int window;

        protected const long tickspersec = 10000000;
        protected static long lasttickcount;
        protected static double t = 0;
        protected static double dt = 0;
        protected static Vec3 eye = new Vec3( 0, 2, 10 );
        protected static Vec3 eyedir = new Vec3( 0, 0, -1 );

        protected virtual void OnReshape(int w, int h)
        {
            float fAspect = (float)h / (float)w;
            float[] fPos = new float[4] { -10.0f, 10.0f, 5.0f, 0.0f };
            float[] fCol = new float[4] { 1.0f, 1.0f, 1.0f, 1.0f };

            Gl.glViewport( 0, 0, w, h );

            Gl.glMatrixMode( Gl.GL_PROJECTION );
            Gl.glLoadIdentity();
            Gl.glFrustum( -1.0, 1.0, -fAspect, fAspect, 1.0, 128.0 );

            //Gl.glEnable( Gl.GL_CULL_FACE );
            Gl.glEnable( Gl.GL_DEPTH_TEST );
            Gl.glEnable( Gl.GL_NORMALIZE );

            Gl.glLightfv( Gl.GL_LIGHT0, Gl.GL_POSITION, fPos );
            Gl.glEnable( Gl.GL_LIGHTING );
            Gl.glEnable( Gl.GL_LIGHT0 );

            Gl.glMaterialfv( Gl.GL_FRONT, Gl.GL_AMBIENT_AND_DIFFUSE, fCol );
        }

        protected virtual void OnKeyboard(byte cChar, int nMouseX, int nMouseY)
        {
            if ( cChar == 27 ) { Glut.glutDestroyWindow( window ); return; }

            Console.WriteLine( "SampleKeyboard(): keypress '{0}' at ({1},{2})\n", cChar, nMouseX, nMouseY );
        }

        private void OnIdle()
        {
            System.Threading.Thread.Sleep( 1 );
            long ticks = DateTime.Now.Ticks;
            if ( lasttickcount == 0 ) lasttickcount = ticks;
            long tickselapsed = ticks - lasttickcount;
            lasttickcount = ticks;
            dt = (double)tickselapsed / tickspersec;
            t += dt;

            OnFrame();

            Glut.glutPostRedisplay();
        }

        protected virtual void OnFrame()
        {
            //System.Threading.Thread.Sleep( 10 );
            //phscene.Simulate( 1.0/60.0f );
            phscene.Simulate( dt );
            phscene.FlushStream();
            phscene.FetchResults( SimulationStatuses.AllFinished, true );
        }

        protected virtual void OnDraw()
        {
            Gl.glClearColor( 0.4f, 0.4f, 0.5f, 1f );
            Gl.glClear( Gl.GL_COLOR_BUFFER_BIT | Gl.GL_DEPTH_BUFFER_BIT );

            Gl.glMatrixMode( Gl.GL_MODELVIEW );
            Gl.glLoadIdentity();
            Gl.glTranslatef( -eye.x, -eye.y, -eye.z );
        }

        protected virtual void OnInit()
        {
            physics = Physics.Create();
            phscene = physics.CreateScene( new SceneDesc() );
            phscene.Timing.MaxTimestep = 1.0f / (3 * 24);

            phscene.Gravity = new Vec3( 0, -9.81f, 0 );
            var defm = phscene.Materials[0];
            defm.Restitution = 0.5f;
            defm.DynamicFriction = defm.StaticFriction = 0.6f;

            phscene.CreateActor( new ActorDesc( new PlaneShapeDesc() ) );
        }

        protected virtual void OnExit()
        {
            physics.Dispose();
            Environment.Exit( 0 );
        }
    }
}