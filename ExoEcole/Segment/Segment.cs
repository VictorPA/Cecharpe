using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Segment
{
    class Segment
    {

        /*1 Enoncé

Dans cet exercice, nous allons implémenter une classe modélisant un segment dans un espace à une dimension. 
Pour rappel, un segment est caractérisé par la position d’une extrémité et sa longueur (positive). 
Dans un espace à une dimension la position d’un point est caractérisé par une seule coordonnée. 
Nous utiliserons des coordonnées et des longueurs entières dans cet exercice. 
Nos segments seront semi-ouverts (c'est-à-dire qu’une seule extrémité appartient au segment).
1.1 Implémentation du segment
Implémenter une classe segment permettant de :
 Créer un segment en précisant la position d’une extrémité et sa longueur
 Connaitre ses caractéristiques (la position de ses deux extrémités et sa longueur)
 Déplacer un segment
 Savoir si un point appartient au segment
 Savoir si deux segments sont égaux
 Savoir si deux segments se chevauchent
 Connaitre l'intersection de deux segments (Il s'agit d'un nouveau segment.
Par exemple, l'intersection de [1, 10[ et [4, 12[ est [4, 10[. 
Attention au cas où les deux segments ne partagent aucun point.)
1.2 Implémentation d'une application console de tests
Vérifier à l'aide d'une application console que le segment fonctionne correctement.*/
        private int _extrémité1;
        private int _extrémité2;
        private int _longeur;
        public Segment (int point, int longueur)
        {
            _extrémité1 = point;
            _longeur = longueur;
            _extrémité2 = point + longueur;
        }

        public int Extrémité1
        {
            get { return _extrémité1; }
        }
        public int Extrémité2
        {
            get { return _extrémité2; }
        }
        public int Longueur
        {
            get { return _longeur; }
        }

        public void déplacerSegment(int déplacement)
        {
            _extrémité1 += déplacement;
            _extrémité2 += déplacement;
        }

        public bool appartientSegment(int coordX)
        {
            return (coordX >= _extrémité1 && coordX < _extrémité2);
        }

        public static Segment intersectionSegment(Segment s1, Segment s2)
        {
            int nExtrémité1, nExtrémité2, nLongeur;
            if (s1._extrémité1 >= s2._extrémité1)
                nExtrémité1 = s1._extrémité1;
            else
                nExtrémité1 = s2._extrémité1;
            if (s1._extrémité2 <= s2._extrémité2)
                nExtrémité2 = s1._extrémité2;
            else
                nExtrémité2 = s2._extrémité2;
            nLongeur = nExtrémité2 - nExtrémité1;
            if (nLongeur <= 0)
                throw new System.ArgumentException("Tentative de créer une intersection de longueur nulle", "nLongeur");
            //ctrl shift espace pour afficher les overflows
            Segment nouveauSegment = new Segment(nExtrémité1, nLongeur);
            return nouveauSegment;
        }

    }
}
