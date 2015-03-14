//on développe notre fonction d'initialisation du projet
void initialisation_projet(char *titre, int width, int height) {
    printf("Lancement de l'initialisation du projet...\n");
    
    
    initialiser_fenetre(width, height, titre);
    affiche_auto_off();
    
    
    
    //Création du tableau bouton où nous stockerons les informations liés aux boutons
    int i;
    for(i = 0; i < NB_BOUTON; i++) {
        bouton[i] = i + 1;
        ouvre_fichier_icon(i);
    }
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
    //Affichage des boutons
    //on remplacera pas mal de truc par des defines
    int i_bouton = 0, duet = 0, bordure_bouton_top = /*remplacé par les define*/70;
    int u, v, array = 0;
    POINT pixel_icon;
    for(i_bouton = 0; i_bouton < NB_BOUTON; i_bouton++)
    {
        array = 0;
        if(i_bouton == 0)
        {
            p1.y = height-bordure_bouton_top;
            p2.y = height-bordure_bouton_top-24;
        }
        if(duet == 1) {
            p1.x = 0;
            p2.x = 24;
            p1.x = 26;
            p2.x = 50;
        }
        else {
            p1.x = 0;
            p2.x = 24;
            
            p1.y -= 24;
            p2.y -= 24;
        }
        dessine_rectangle_plein(p1, p2, COULEUR_BORDURE);//sera remplacé par le chargement d'une image
        
        
        for(u = p1.x; u < p2.x; u++) {
            for(v = p1.y; v > p2.y; v--) {
                pixel_icon.x = u;
                pixel_icon.y = v;
                dessine_pixel(pixel_icon, couleur_RGB(dec2hex_rgb(0, bouton_icons[i_bouton][array]),dec2hex_rgb(1, bouton_icons[i_bouton][array]), dec2hex_rgb(2, bouton_icons[i_bouton][array])));
                array ++ ;

            }
        }
        //dessine_entier(i_bouton+1,12,p1,COULEUR_TEXTE);//à enlever
        
        duet = 1 - duet;
    }
    //Affichage des options
    p1.x = 3; p2.x = LARGEUR_MENU-3;
    p1.y -= 40; p2.y -= 80;
    dessine_rectangle_plein(p1,p2,COULEUR_BORDURE);
    ///////////////////

    
    
    //////////////////PALETTE
    p1.x=59; p1.y=41;
    p2.x=196; p2.y=9;
    dessine_rectangle(p1,p2,COULEUR_BORDURE);
    
    int i_palette;
    p1.x=60; p1.y=40;
    
    for(i_palette=0; i_palette<NB_COULEUR; i_palette++){
    
        if(i_palette==9){p1.x=60; p1.y=25; p2.x=p1.x+15; p2.y=p1.y-15;}
        
        dessine_rectangle_plein(p1,p2,palette[i_palette]);
        p1.x+=15; p2.x=p1.x+15; p2.y=p1.y-15;
    }
    
    //Affichage des culeurs sélectionné
    p1.x=19;p1.y=31; p2.x=p1.x+22; p2.y=p1.y-22;
    dessine_rectangle_plein(p1,p2,COULEUR_BORDURE);
    
    p1.x=20;p1.y=30; p2.x=p1.x+20; p2.y=p1.y-20;
    dessine_rectangle_plein(p1,p2,couleur_RGB(255,255,255));
    
    
    p1.x=9;p1.y=41; p2.x=p1.x+22; p2.y=p1.y-22;
    dessine_rectangle_plein(p1,p2,COULEUR_BORDURE);
    
    p1.x=10;p1.y=40; p2.x=p1.x+20; p2.y=p1.y-20;
    dessine_rectangle_plein(p1,p2,couleur_RGB(0,0,0));
    
    //Option pour modifier la palette
    p1.x=206; p1.y=35;
    dessine_texte("Modifier la palette",12,p1,COULEUR_TEXTE);
    
    /////////////////
    affiche_tout();
}
