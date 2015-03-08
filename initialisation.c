//--------------PARAMETRES---------------
#define NB_BOUTON 13
/*
Dimension d'un bouton: 24px - 24px
1: Pinceau
2: Brosse
3: Aérographe
4: Remplissage
5: Gomme
6: Pipette
7: Ligne
8: Rectangle
9: Polygone
10: Ellipse
11: Rectangle Arrondi
12: Selection
13: Texte
*/
//----------------------------------------

//on déclare les variables dont nous aurons besoin
int bouton[NB_BOUTON] = {0};


//on développe notre fonction d'initialisation du projet
void initialisation_projet(char *titre, int width, int height, int *bouton) {
    printf("Lancement de l'initialisation du projet...\n");
    
    
    initialiser_fenetre(width, height, titre);
    remplir_ecran(blanc);
    
    //colonne de gauche
    POINT p1, p2;
    p1.x = 0; p1.y = 0;
    p2.x = 50; p2.y = height;
    dessine_rectangle_plein(p1, p2, couleur_RGB(230,230,230));
    
    //Création du tableau bouton où nous stockerons les informations liés aux boutons
    int i;
    for(i = 0; i < NB_BOUTON; i++) {
        bouton[i] = i + 1;
    }
    
    
    
    
    printf("Fin de l'initisalisation.\n");
}

