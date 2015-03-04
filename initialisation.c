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




const char *bouton[NB_BOUTON] = {0};
int i;
for(i = 0; i < NB_BOUTON; i++) {
    bouton[i] = i+1;
}
