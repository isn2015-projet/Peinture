#include "toolbox.h"
#include "fonctions.c"
#include "initialisation.c"

/*idée: rassembler toutes les déclarations de fonction et variable dans un même fichier
--> declarations.h par exemple à inclure au tout début, ça permet de déclarer une fonction sans
pour autant la développer, puisque qu'on peut le faire ensuite

idée: il faudrait qu'on développe le fichier initialisation ensemble, 
mais pas en même temps, comme ça on part sur la même base*,
puis, pour les fonctions, qui sont les éléments importants, au lieu d'inclure fonctions.c on inclut
fonctions.h où, dans ce fichier on inclut les fichiers de fonctions.c, comme ça on peut travailler en même temps
sans modifier la version de l'autre sur une fonction différente chacun */



int main( int argc, char** argv )
{
    initialisation_projet(/*titre*/"Peinture", /*width*/1200, /*height*/700, bouton);
    while(1)
    {
        affichage_interface(1200, 700);
        attendre(20);
    }
    
    
    attendre_echap();
}
