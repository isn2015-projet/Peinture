#include "toolbox.h"
#include "declarations.c"
#include "fonctions.h"
#include "initialisation.c"



int main( int argc, char** argv )
{
    initialisation_projet("Peinture", WIDTH, HEIGHT);
    while(1)
    {
        affichage_interface(WIDTH, HEIGHT);
        gestion_interface();
        gestion_fonction();
    }
    
    
    attendre_echap();
}
