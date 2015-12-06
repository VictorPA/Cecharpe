using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bouteille
{
    class Bouteille
    {
        //...
        private static int totalBouteillesCrées = 0;
        public Bouteille()
        {
            //...
            //...

            ++totalBouteillesCrées;
        }
        public static int TotalBouteillesCrées
        {
            get{ return totalBouteillesCrées; }
        }
    }
}
