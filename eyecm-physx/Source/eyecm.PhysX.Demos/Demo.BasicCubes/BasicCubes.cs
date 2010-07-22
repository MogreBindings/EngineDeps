using System;
using System.Collections.Generic;
using Tao.FreeGlut;
using Tao.OpenGl;

namespace eyecm.PhysX.Demos
{
    public class BasicCubes: DemoClass
    {
        static void Main()
        {
            Run( "Basic Cubes", new BasicCubes() );
        }

        static readonly float[] shadowMat = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };

        protected override void OnDraw()
        {
            base.OnDraw();

            foreach ( var a in phscene.Actors ) {

                if ( !a.IsDynamic ) continue;

                float d = 2 * (a.Shapes[0] as BoxShape).Dimensions.x;
                var mat = a.GlobalPose;

                Gl.glPushMatrix();
                Gl.glMultMatrixf( ref mat.m11 );
                Glut.glutSolidCube( d );
                Gl.glPopMatrix();

                Gl.glPushMatrix();
                Gl.glMultMatrixf( shadowMat );
                Gl.glMultMatrixf( ref mat.m11 );
                Gl.glDisable( Gl.GL_LIGHTING );
                Gl.glColor4f( 0.1f, 0.1f, 0.2f, 1.0f );
                Glut.glutSolidCube( d );
                Gl.glEnable( Gl.GL_LIGHTING );
                Gl.glPopMatrix();
            }
        }

        protected override void OnKeyboard(byte cChar, int nMouseX, int nMouseY)
        {
            if ( cChar == ' ' ) {

                double d = 0.1 + 0.2 * rnd.NextDouble();
                var ad = new ActorDesc( new BodyDesc(), 10, new BoxShapeDesc( new Vec3( d, d, d ) ) );
                ad.GlobalPosition = new Vec3( 10 * (rnd.NextDouble() - rnd.NextDouble()), (10 * rnd.NextDouble()), (5 * rnd.NextDouble()) );

                var a = phscene.CreateActor( ad );
                a.AddTorque( new Vec3( 0, 0, 15 * d * (rnd.NextDouble() - rnd.NextDouble()) ), ForceModes.Impulse );
                return;
            }
            if ( cChar == 'a' ) {

                var acs = phscene.Actors;
                int idx = rnd.Next( acs.Count );
                if ( acs[idx].IsDynamic ) acs[idx].Dispose();
            }
            if ( cChar == 's' ) {

                double d = 0.1 + 0.2 * rnd.NextDouble();
                Vec3 pos = new Vec3( -10 * d, d, 0 ); ;

                for ( int j = 0; j < 10; j++ ) {

                    float tempy = pos.y;

                    pos.x += 2 * (float)(d - physics.Parameters.SkinWidth);
                    pos.z += 1f * (float)(d + physics.Parameters.SkinWidth);

                    for ( int i = 0; i < 1 + j; i++ ) {

                        var ad = new ActorDesc( new BodyDesc(), 10, new BoxShapeDesc( new Vec3( d, d, d ) ) );
                        ad.GlobalPosition = pos;
                        pos.y += 2 * (float)(d - physics.Parameters.SkinWidth);
                        var a = phscene.CreateActor( ad );
                    }
                    pos.y = tempy;
                }
                return;
            }
            if ( cChar == 'q' ) {

                var actors = phscene.Actors;

                List<Actor> todelete = new List<Actor>();

                foreach ( var a in actors ) if ( a.IsDynamic ) todelete.Add( a );
                foreach ( var a in todelete ) a.Dispose();
            }

            base.OnKeyboard( cChar, nMouseX, nMouseY );
        }
    }
}