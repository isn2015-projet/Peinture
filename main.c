#include "toolbox.h"
#include "initialisation.c"
#include "fonctions.c"

int main( int argc, char** argv )
{
    initialisation_projet(/*titre*/"Peinture", /*width*/1200, /*height*/700, bouton);
    
    
    
    //instruction bloquante, n'est pas présente dans la version finale, sera remplacée par un while(1) qui
    //attendra les instructions
    attendre_echap();
}
