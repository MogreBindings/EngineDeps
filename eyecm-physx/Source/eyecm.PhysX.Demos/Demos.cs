using System;

namespace eyecm.PhysX.Demos
{
    public static class Demos
    {
        [STAThread]
        public static void Main()
        {
            DemoClass.Run( "Null demo", new DemoClass() );
        }
    }
}