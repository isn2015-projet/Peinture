//defines
#define NB_BOUTON 3
#define NB_COULEUR 18
#define COULEUR_FOND couleur_RGB(255,255,255)
#define COULEUR_COLONNE couleur_RGB(230,230,230)
#define COULEUR_TEXTE couleur_RGB(0,0,0)
#define COULEUR_BORDURE couleur_RGB(150,150,150)
#define WIDTH 1200
#define HEIGHT 700
#define LARGEUR_MENU 50

//variables utilisées:
int bouton[NB_BOUTON];
int bouton_icons[NB_BOUTON][576];
char mode[200] = "Outil choisi: Aucun";
COULEUR palette[NB_COULEUR];

typedef struct{
	COULEUR pri;
	COULEUR sec;
}couleurs;

couleurs colour;

int outil;


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
