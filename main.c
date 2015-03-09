#include "toolbox.h"
#include "fonctions.c"
#include "initialisation.c"

//idée: rassembler toutes les déclarations de fonction et variable dans un même fichier

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
