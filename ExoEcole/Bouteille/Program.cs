using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bouteille
{
    class Program
    {
        static void Main(string[] args)
        {
          //  System.Console.WriteLine(Bouteille.TotalBouteillesCrées);
            Bouteille bouteille1 = new Bouteille();
            System.Console.WriteLine(Bouteille.TotalBouteillesCrées);
            Bouteille bouteille2 = new Bouteille();
            System.Console.WriteLine(Bouteille.TotalBouteillesCrées);
            System.Console.ReadKey();
        }
    }
}
