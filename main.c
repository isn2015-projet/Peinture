#include "toolbox.h"
#include "initialisation.c"
#include "fonctions.c"

int main( int argc, char** argv )
{
    initialisation_projet(/*titre*/"Peinture", /*width*/1200, /*height*/700, bouton);
    
    
    
    
    attendre(5000);
    quitter(0);
}
