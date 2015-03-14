//defines
#define NB_BOUTON 13
#define NB_COULEUR 18
#define COULEUR_FOND couleur_RGB(255,255,255)
#define COULEUR_COLONNE couleur_RGB(230,230,230)
#define COULEUR_TEXTE couleur_RGB(0,0,0)
#define COULEUR_BORDURE couleur_RGB(150,150,150)
#define WIDTH 1200
#define HEIGHT 700
#define LARGEUR_MENU 50

//variables utilisées:
int bouton[NB_BOUTON] = {0};
char mode[200] = "Outil choisi: Aucun";
COULEUR palette[NB_COULEUR];

//Initialisation du tableau de couleur
palette[0]=couleur_RGB(0  ,0  ,0  );//0x000000;
palette[1]=couleur_RGB(64 ,64 ,64 );//0x404040;
palette[2]=couleur_RGB(255,0  ,0  );//0xFF0000
palette[3]=couleur_RGB(255,106,0  );//0xFF6A00;
palette[4]=couleur_RGB(255,216,0  );//0xFFD800;
palette[5]=couleur_RGB(182,255,0  );//0xB6FF00;
palette[6]=couleur_RGB(76 ,255,0  );//0x4CFF00;
palette[7]=couleur_RGB(0  ,255,33 );//0x00FF21;
palette[8]=couleur_RGB(0  ,255,144);//0x00FF90;

palette[9]=couleur_RGB(255,255,255);//0xFFFFFF;
palette[10]=couleur_RGB(128,128,128);//0x808080;
palette[11]=couleur_RGB(0  ,255,255);//0x00FFFF;
palette[12]=couleur_RGB(0  ,148,255);//0x0094FF;
palette[13]=couleur_RGB(0  ,38 ,255);//0x0026FF;
palette[14]=couleur_RGB(72 ,0  ,255);//0x4800FF;
palette[15]=couleur_RGB(178,0  ,255);//0xB200FF;
palette[16]=couleur_RGB(255,0  ,220);//0xFF00DC;
palette[17]=couleur_RGB(255,0  ,110);//0xFF006E;



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
