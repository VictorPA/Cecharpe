using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Segment
{
    class Console
    {
        Segment s1; Segment s2;

        public Console()
        {
            tests();
        }
        public static void afficherSegment(Segment s)
        {
            System.Console.WriteLine("");
            for (int i = 0; i < s.Extrémité1; ++i)
                System.Console.Write(" ");
            for (int i = 0; i < s.Longueur; ++i)
            {
                System.Console.Write("_");
            }
        }
        public void tests()
        {
            s1 = new Segment(1, 9);
            s2 = new Segment(4, 8);
            Segment s3 = Segment.intersectionSegment(s1,s2);
            afficherSegment(s1);
            afficherSegment(s2);
            afficherSegment(s3);
            System.Console.WriteLine("");
            int pointX = 0;
            
        }
    }
}

