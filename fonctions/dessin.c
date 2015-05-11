void cercle(POINT P,int h,COULEUR c){
    int i;
    POINT p,centre;
    centre.x = P.x - LARGEUR_MENU;
    centre.y = P.y - LARGEUR_MENU;
    dessine_pixel_image(sans_titre,centre,c);
    for(i=0;i<h*20;i++){
        p.x=round(P.x+cos(i)*h)-LARGEUR_MENU;
        p.y=round(P.y+sin(i)*h)-LARGEUR_MENU;
            
        dessine_pixel_image(sans_titre,p,c);
    }
    
}
void pinceau(){
    POINT p;
    p=position_souris();
    int hauteur=2*option,i;
    if(p.x>LARGEUR_MENU && p.y>LARGEUR_MENU){
        for(i=hauteur;i>0;i--){
            if(bouton_appuye(CLIC_GCH)==true) {
                cercle(p,i,colour.pri);
            }
            else if(bouton_appuye(CLIC_DRT)==true) {
                cercle(p,i,colour.sec);
            }
        }
        
    }
}

void aerographe(){
    POINT p,P;
    float cosinus=0;
    int j;
    p=position_souris();
    
    if/*while*/(p.x>LARGEUR_MENU && p.y>LARGEUR_MENU){
        cosinus=(reel_aleatoire()+entier_aleatoire(4))*2;
        affiche_tout();
        if(bouton_appuye(CLIC_GCH)==true) {
            for(j=0;j<5;j++) {
                P.x=floor(p.x+cos(cosinus)*entier_aleatoire(10*option)-LARGEUR_MENU);
                P.y=floor(p.y+sin(cosinus)*entier_aleatoire(10*option)-LARGEUR_MENU);
                dessine_pixel_image(sans_titre,P,colour.pri);
            }
        }
        else if(bouton_appuye(CLIC_GCH)==true) {
            for(j=0;j<5;j++) {
                P.x=floor(p.x+cos(cosinus)*entier_aleatoire(10*option));
                P.y=floor(p.y+sin(cosinus)*entier_aleatoire(10*option));
                dessine_pixel_image(sans_titre,P,colour.sec);
            }
        }
        affiche_tout();
    }

}

void ligne(){
    POINT p,pi,P, p1, p2;
    P.x=LARGEUR_MENU;P.y=LARGEUR_MENU;
    p=position_souris();
    if(bouton_appuye(CLIC_GCH)==true){
        pi=p;
        while(p.x>LARGEUR_MENU && p.y>LARGEUR_MENU && bouton_appuye(CLIC_GCH)==true){
            p=position_souris();
            dessine_image(sans_titre,P);
            dessine_ligne(pi,p,colour.pri);
            
            
            //fixed: les bordures de la barre d'outil disparaissaient
            p1.x = 0; p1.y = LARGEUR_MENU;
            p2.x = WIDTH; p2.y = LARGEUR_MENU;
            dessine_ligne(p1, p2, COULEUR_BORDURE);
            
            p1.x = 0; p1.y = HEIGHT-(LARGEUR_MENU/2);
            p2.x = WIDTH; p2.y = HEIGHT-(LARGEUR_MENU/2);
            dessine_ligne(p1, p2, COULEUR_BORDURE);
            
            p1.x = LARGEUR_MENU; p1.y = HEIGHT-(LARGEUR_MENU/2);
            p2.x = LARGEUR_MENU; p2.y = LARGEUR_MENU;
            dessine_ligne(p1, p2, COULEUR_BORDURE);
            //fin fixed
            
            affiche_tout();
        }
        pi.x-=50;pi.y-=50;p.x-=50;p.y-=50;
        dessine_ligne_image(pi,p,colour.pri);
    }
    if(bouton_appuye(CLIC_DRT)==true){
        pi=p;
        while(p.x>LARGEUR_MENU && p.y>LARGEUR_MENU && bouton_appuye(CLIC_DRT)==true){
            p=position_souris();
            dessine_image(sans_titre,P);
            dessine_ligne(pi,p,colour.sec);
            
            
            //fixed: les bordures de la barre d'outil disparaissaient
            p1.x = 0; p1.y = LARGEUR_MENU;
            p2.x = WIDTH; p2.y = LARGEUR_MENU;
            dessine_ligne(p1, p2, COULEUR_BORDURE);
            
            p1.x = 0; p1.y = HEIGHT-(LARGEUR_MENU/2);
            p2.x = WIDTH; p2.y = HEIGHT-(LARGEUR_MENU/2);
            dessine_ligne(p1, p2, COULEUR_BORDURE);
            
            p1.x = LARGEUR_MENU; p1.y = HEIGHT-(LARGEUR_MENU/2);
            p2.x = LARGEUR_MENU; p2.y = LARGEUR_MENU;
            dessine_ligne(p1, p2, COULEUR_BORDURE);
            //fin fixed
            
            affiche_tout();
        }
        pi.x-=50;pi.y-=50;p.x-=50;p.y-=50;
        dessine_ligne_image(pi,p,colour.sec);
    }
}



//fonction remplissage opérationnelle, mais on va l'affiner pour la rendre propre
void remplissage() {
    if(bouton_appuye(CLIC_GCH)==true) {
        POINT p, p2, pdata;
        p = position_souris();
        p.x -= LARGEUR_MENU;
        p.y -= LARGEUR_MENU;
        if(p.x>LARGEUR_MENU && p.y>LARGEUR_MENU) {
            
        int k = 0;
        int courant = 0;
        COULEUR prevc;
        pdata.x = 0;
        pdata.y = 0;
        int nb_pixel_a_traiter = 0;
        int i, j;
        for(i = 0; i < 1150*625; i++) {
            T_REMPLISSAGE[i] = pdata;
        }
        for(i = 0; i < 1151; i++) {
            for(j = 0; j < 626; j++) {
                T_REMPLISSAGE_INT[i][j] = 0;
            }
        }
        prevc = lit_pixel_image(sans_titre,p);
        T_REMPLISSAGE[k] = p;
        nb_pixel_a_traiter++;
        
        while(nb_pixel_a_traiter > 0) {
            p.x = T_REMPLISSAGE[courant].x;
            p.y = T_REMPLISSAGE[courant].y;
   
            p2.x = p.x + 1;
            p2.y = p.y;
            if(lit_pixel_image(sans_titre,p2) == prevc && p2.x<WIDTH-LARGEUR_MENU && T_REMPLISSAGE_INT[p2.x][p2.y] == 0) {
                nb_pixel_a_traiter++;
                k++;
                T_REMPLISSAGE[k] = p2;
                //printf("%d - %d\n", p2.x, p2.y);
                T_REMPLISSAGE_INT[p2.x][p2.y] = 1;
            }
            
            p2.x = p.x - 1;
            p2.y = p.y;
            if(lit_pixel_image(sans_titre,p2) == prevc && p2.x>0  && T_REMPLISSAGE_INT[p2.x][p2.y] == 0) {
                nb_pixel_a_traiter++;
                k++;
                T_REMPLISSAGE[k] = p2;
                //printf("%d - %d\n", p2.x, p2.y);
                T_REMPLISSAGE_INT[p2.x][p2.y] = 1;
            }
            
            p2.x = p.x;
            p2.y = p.y + 1;
            if(lit_pixel_image(sans_titre,p2) == prevc && p2.y<HEIGHT-(LARGEUR_MENU+20)  && T_REMPLISSAGE_INT[p2.x][p2.y] == 0) {
                nb_pixel_a_traiter++;
                k++;
                T_REMPLISSAGE[k] = p2;
                //printf("%d - %d\n", p2.x, p2.y);
                T_REMPLISSAGE_INT[p2.x][p2.y] = 1;
            }
            
            p2.x = p.x;
            p2.y = p.y - 1;
            if(lit_pixel_image(sans_titre,p2) == prevc && p2.y>0  && T_REMPLISSAGE_INT[p2.x][p2.y] == 0) {
                nb_pixel_a_traiter++;
                k++;
                T_REMPLISSAGE[k] = p2;
                //printf("%d - %d\n", p2.x, p2.y);
                T_REMPLISSAGE_INT[p2.x][p2.y] = 1;
            }
            dessine_pixel_image(sans_titre,p,colour.pri);
            //printf("%d\n",nb_pixel_a_traiter);
            courant++;
            nb_pixel_a_traiter--;
        }

        }
    }





    if(bouton_appuye(CLIC_DRT)==true) {
        POINT p, p2, pdata;
        p = position_souris();
        p.x -= LARGEUR_MENU;
        p.y -= LARGEUR_MENU;
        if(p.x>LARGEUR_MENU && p.y>LARGEUR_MENU) {
            
        int k = 0;
        int courant = 0;
        COULEUR prevc;
        pdata.x = 0;
        pdata.y = 0;
        int nb_pixel_a_traiter = 0;
        int i, j;
        for(i = 0; i < 1150*625; i++) {
            T_REMPLISSAGE[i] = pdata;
        }
        for(i = 0; i < 1151; i++) {
            for(j = 0; j < 626; j++) {
                T_REMPLISSAGE_INT[i][j] = 0;
            }
        }
        prevc = lit_pixel_image(sans_titre,p);
        T_REMPLISSAGE[k] = p;
        nb_pixel_a_traiter++;
        
        while(nb_pixel_a_traiter > 0) {
            p.x = T_REMPLISSAGE[courant].x;
            p.y = T_REMPLISSAGE[courant].y;
   
            p2.x = p.x + 1;
            p2.y = p.y;
            if(lit_pixel_image(sans_titre,p2) == prevc && p2.x<WIDTH-LARGEUR_MENU && T_REMPLISSAGE_INT[p2.x][p2.y] == 0) {
                nb_pixel_a_traiter++;
                k++;
                T_REMPLISSAGE[k] = p2;
                //printf("%d - %d\n", p2.x, p2.y);
                T_REMPLISSAGE_INT[p2.x][p2.y] = 1;
            }
            
            p2.x = p.x - 1;
            p2.y = p.y;
            if(lit_pixel_image(sans_titre,p2) == prevc && p2.x>0  && T_REMPLISSAGE_INT[p2.x][p2.y] == 0) {
                nb_pixel_a_traiter++;
                k++;
                T_REMPLISSAGE[k] = p2;
                //printf("%d - %d\n", p2.x, p2.y);
                T_REMPLISSAGE_INT[p2.x][p2.y] = 1;
            }
            
            p2.x = p.x;
            p2.y = p.y + 1;
            if(lit_pixel_image(sans_titre,p2) == prevc && p2.y<HEIGHT-(LARGEUR_MENU+20)  && T_REMPLISSAGE_INT[p2.x][p2.y] == 0) {
                nb_pixel_a_traiter++;
                k++;
                T_REMPLISSAGE[k] = p2;
                //printf("%d - %d\n", p2.x, p2.y);
                T_REMPLISSAGE_INT[p2.x][p2.y] = 1;
            }
            
            p2.x = p.x;
            p2.y = p.y - 1;
            if(lit_pixel_image(sans_titre,p2) == prevc && p2.y>0  && T_REMPLISSAGE_INT[p2.x][p2.y] == 0) {
                nb_pixel_a_traiter++;
                k++;
                T_REMPLISSAGE[k] = p2;
                //printf("%d - %d\n", p2.x, p2.y);
                T_REMPLISSAGE_INT[p2.x][p2.y] = 1;
            }
            dessine_pixel_image(sans_titre,p,colour.sec);
            //printf("%d\n",nb_pixel_a_traiter);
            courant++;
            nb_pixel_a_traiter--;
        }

        }
    }
   
}
void polygone(){}
