using System;
using Tao.FreeGlut;
using Tao.OpenGl;

namespace eyecm.PhysX.Demos
{
    public partial class DemoClass
    {
        public static Physics physics;
        public static Scene phscene;

        public static DemoClass instance;
        public static string title;

        protected static Random rnd = new Random();

        public static void Run(string title, DemoClass instance)
        {
            if ( DemoClass.instance != null ) throw new Exception( "A Demo instance is already running." );

            DemoClass.instance = instance;
            DemoClass.title = title + " - PhysX Candy Wrapper";

            const int scale = 2;
            Glut.glutInitWindowSize( scale * 480, scale * 270 );
            Glut.glutInitDisplayMode( Glut.GLUT_RGB | Glut.GLUT_DOUBLE | Glut.GLUT_DEPTH );

            Glut.glutInit();

            instance.window = Glut.glutCreateWindow( title );
            Glut.glutDisplayFunc( new Glut.DisplayCallback( SampleDisplay ) );
            Glut.glutReshapeFunc( new Glut.ReshapeCallback( SampleReshape ) );
            Glut.glutKeyboardFunc( new Glut.KeyboardCallback( SampleKeyboard ) );
            Glut.glutSpecialFunc( new Glut.SpecialCallback( SampleSpecial ) );
            Glut.glutIdleFunc( new Glut.IdleCallback( SampleIdle ) );

            instance.OnInit();

            Glut.glutMainLoop();
        }

        static void SampleReshape(int nWidth, int nHeight) { instance.OnReshape( nWidth, nHeight ); }
        static void SampleKeyboard(byte cChar, int nMouseX, int nMouseY) { instance.OnKeyboard( cChar, nMouseX, nMouseY ); }
        static void SampleSpecial(int nSpecial, int nMouseX, int nMouseY){Console.WriteLine( "SampleSpecial(): special keypress {0} at ({1},{2})\n", nSpecial, nMouseX, nMouseY );}
        static void SampleIdle() { instance.OnIdle(); }

        static void SampleDisplay()
        {
            instance.OnDraw(); 
            Glut.glutSwapBuffers();
        }
    }
}