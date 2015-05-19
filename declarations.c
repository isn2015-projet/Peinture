//defines
#define NB_BOUTON 11
#define NB_COULEUR 18
#define COULEUR_FOND couleur_RGB(255,255,255)
#define COULEUR_COLONNE couleur_RGB(230,230,230)
#define COULEUR_TEXTE couleur_RGB(0,0,0)
#define COULEUR_BORDURE couleur_RGB(150,150,150)
#define WIDTH 1200
#define width 1200
#define HEIGHT 700
#define height 700
#define LARGEUR_MENU 50

//Pour stocker les boutons et ses icons:
int bouton[NB_BOUTON];
int bouton_icons[NB_BOUTON][576];



char mode[200] = "Outil : Pinceau";

//variable qui stockera les couleurs de la palette
COULEUR palette[NB_COULEUR];


//structure qui représentera la couleur principale et secondaire du document:
typedef struct{
	COULEUR pri;
	COULEUR sec;
}couleurs;

//création de la variable couleur (pour le moment elle vaut null mais on assignera des valeurs dans l'initialisation):
couleurs colour;

// Variable qui stockera quel outil nous avons sélectionné, par défaut: Pinceau
int outil=0;
int option = 1; // par défaut: à 1 (plus petit, var max: 3)

//Structure qui représente notre document vierge sur lequel on va dessiner:
IMAGE sans_titre;


//Pour le remplissage:
POINT T_REMPLISSAGE[1150*625];
int T_REMPLISSAGE_INT[1151][626];

//Date de la dernière sauvegarde:
char derniere_sauvegarde[200] = "jamais";


/*
 Dimension d'un bouton: 24px - 24px (prendre n-1)
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
 */
