using System;
using System.Collections.Generic;
using Tao.FreeGlut;
using Tao.OpenGl;

namespace eyecm.PhysX.Demos
{
    public class ExecutiveToy: DemoClass
    {
        static void Main()
        {
            Run( "Newton's Cradle", new ExecutiveToy() );
        }

        static readonly float[] shadowMat = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
        const float centery = 2;
        const float stringlength = 4.08f;
        const float radius = 1.0f;

        protected override void OnInit()
        {
            base.OnInit();

            var m = phscene.CreateMaterial( new MaterialDesc( 0.0f, 0.0f, 1.0f ) );
            var sd = new SphereShapeDesc( radius );
            sd.SkinWidth = 0.00f;
            var ad = new ActorDesc( new BodyDesc( 0.124f, 1.0f ), 150.1f, sd );
            sd.MaterialIndex = m.Index;

            for ( int i = -2; i <= 2; i++ ) {

                ad.GlobalPosition = new Vec3( 2 * radius * i, centery, 0 );
                var sac = phscene.CreateActor( ad );

                var djd = new RevoluteJointDesc();
                djd.JointFlags = JointFlags.CollisionEnabled | JointFlags.Visualization;
                djd.SetActors( null, sac );
                djd.GlobalAnchor = ad.GlobalPosition + new Vec3( 0, stringlength, 0 );
                djd.GlobalAxis = new Vec3( 0, 0, 1 );

                phscene.CreateJoint( djd );
            }
        }

        static double angle = 0;

        protected override void OnDraw()
        {
            base.OnDraw();

            Gl.glMatrixMode( Gl.GL_MODELVIEW );
            angle += dt * 10;
            Gl.glTranslatef( 0, -2, -2 );
            Gl.glRotated( angle, 0, 1, 0 );

            foreach ( var a in phscene.Actors ) {

                if ( !a.IsDynamic ) continue;

                var mat = a.GlobalPose;

                Gl.glEnable( Gl.GL_LIGHTING );
                Gl.glPushMatrix();
                Gl.glMultMatrixf( ref mat.m11 );
                Gl.glColor4f( 1.0f, 1.0f, 1.0f, 1.0f );
                Glut.glutSolidSphere( radius, 32, 32 );
                Gl.glPopMatrix();

                Gl.glPushMatrix();
                Gl.glMultMatrixf( shadowMat );
                Gl.glMultMatrixf( ref mat.m11 );
                Gl.glDisable( Gl.GL_LIGHTING );
                Gl.glColor4f( 0.1f, 0.1f, 0.2f, 1.0f );
                Glut.glutSolidSphere( radius, 32, 32 );
                Gl.glPopMatrix();
            }

            Gl.glColor4f( 0.0f, 0.0f, 0.0f, 1.0f );
            Gl.glLineWidth( 3 );
            Gl.glBegin( Gl.GL_LINES );

            for ( int i = -2; i <= 2; i++ ) {

                var a = phscene.Actors[i + 3];
                Vec3 ap = a.GlobalPosition;
                Gl.glVertex3f( ap.x, ap.y, ap.z );
                Gl.glVertex3f( 2 * radius * i, stringlength + centery, -3 );
                Gl.glVertex3f( ap.x, ap.y, ap.z );
                Gl.glVertex3f( 2 * radius * i, stringlength + centery, 3 );
            }
            Gl.glEnd();
            Gl.glLineWidth( 1 );

            Gl.glEnable( Gl.GL_LIGHTING );

            const float planesize = 4.5f;
            Gl.glBegin( Gl.GL_QUADS );
            Gl.glNormal3f( 0, 1, 0 );
/*            Gl.glVertex3f( planesize, -0.01f, planesize );
            Gl.glVertex3f( -planesize, -0.01f, planesize );
            Gl.glVertex3f( -planesize, -0.01f, -planesize );
            Gl.glVertex3f( planesize, -0.01f, -planesize );
            **/
            Gl.glVertex3f( planesize, stringlength + centery, planesize );
            Gl.glVertex3f( -planesize, stringlength + centery, planesize );
            Gl.glVertex3f( -planesize, stringlength + centery, -planesize );
            Gl.glVertex3f( planesize, stringlength + centery, -planesize );
            Gl.glEnd();
        }

        protected override void OnKeyboard(byte cChar, int nMouseX, int nMouseY)
        {
            if ( cChar == ' ' ) {

                phscene.Actors[1].AddForce( new Vec3( -7, 0, 0 ), ForceModes.VelocityChange );
                return;
            }
            base.OnKeyboard( cChar, nMouseX, nMouseY );
        }
    }
}