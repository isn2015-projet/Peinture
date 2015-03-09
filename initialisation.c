//on développe notre fonction d'initialisation du projet
void initialisation_projet(char *titre, int width, int height) {
    printf("Lancement de l'initialisation du projet...\n");
    
    
    initialiser_fenetre(width, height, titre);
    affiche_auto_off();
    
    
    
    //Création du tableau bouton où nous stockerons les informations liés aux boutons
    int i;
    for(i = 0; i < NB_BOUTON; i++) {
        bouton[i] = i + 1;
    }
    
    
    
    printf("Fin de l'initisalisation.\n");
}


void affichage_interface(int width, int height) {
    remplir_ecran(COULEUR_FOND);
    
    
    //colonne de gauche
    POINT p1, p2;
    p1.x = 0; p1.y = 0;
    p2.x = LARGEUR_MENU; p2.y = height;
    dessine_rectangle_plein(p1, p2, COULEUR_COLONNE);
    
    //ligne du bas
    p1.x = 0; p1.y = 0;
    p2.x = width; p2.y = LARGEUR_MENU;
    dessine_rectangle_plein(p1, p2, COULEUR_COLONNE);
    
    //bordures
    p1.x = 0; p1.y = LARGEUR_MENU;
    p2.x = width; p2.y = LARGEUR_MENU;
    dessine_ligne(p1, p2, COULEUR_BORDURE);
    p1.x = LARGEUR_MENU; p1.y = height;
    p2.x = LARGEUR_MENU; p2.y = LARGEUR_MENU;
    dessine_ligne(p1, p2, COULEUR_BORDURE);
    //
    //informations bottom right (outil sélectionné + position curseur)
    p1.x = width-170; p1.y = 43;
    p2 = position_souris();
    char coordonnees[30];
    sprintf(coordonnees, "Position: %dx%d", p2.x-LARGEUR_MENU, p2.y-LARGEUR_MENU);
    dessine_texte(coordonnees,12,p1,COULEUR_TEXTE);
    p1.y -= 20;
    dessine_texte(mode,12,p1,COULEUR_TEXTE);
    
    
    
    ////////////////////TABLEAU DE BOUTON
    //-----
    ///////////////////
    
    
    //////////////////PALETTE
    //-----
    /////////////////
    affiche_tout();
}
