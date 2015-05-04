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
    POINT p,pi,P;
    P.x=LARGEUR_MENU;P.y=LARGEUR_MENU;
    p=position_souris();
    if(bouton_appuye(CLIC_GCH)==true){
        pi=p;
        while(p.x>LARGEUR_MENU && p.y>LARGEUR_MENU && bouton_appuye(CLIC_GCH)==true){
            p=position_souris();
            dessine_image(sans_titre,P);
            dessine_ligne(pi,p,colour.pri);
            affiche_tout();
        }
        pi.x-=50;pi.y-=50;p.x-=50;p.y-=50;
        dessine_ligne_image(pi,p,colour.pri);
    }
}



void remplissage() {
    if(bouton_appuye(CLIC_GCH)==true) {
        int k = 0;
        int courant = 0;
        POINT p, p2;
        COULEUR prevc;
        p.x = 0;
        p.y = 0;
        int nb_pixel_a_traiter = 0;
        int i, j;
        for(i = 0; i < 1150*625; i++) {
            T_REMPLISSAGE[i] = p;
        }
        for(i = 0; i < 1151; i++) {
            for(j = 0; j < 626; j++) {
                T_REMPLISSAGE_INT[i][j] = 0;
            }
        }
        p = position_souris();
        prevc = lit_pixel_image(sans_titre,p);
        T_REMPLISSAGE[k] = p;
        nb_pixel_a_traiter++;
        
        while(nb_pixel_a_traiter > 0) {
            p.x = T_REMPLISSAGE[courant].x;
            p.y = T_REMPLISSAGE[courant].y;
   
            p2.x = p.x + 1;
            p2.y = p.y;
            if(lit_pixel_image(sans_titre,p2) == prevc && p2.x<WIDTH && T_REMPLISSAGE_INT[p2.x][p2.y] == 0) {
                nb_pixel_a_traiter++;
                k++;
                T_REMPLISSAGE[k] = p2;
                printf("%d - %d\n", p2.x, p2.y);
                T_REMPLISSAGE_INT[p2.x][p2.y] = 1;
            }
            
            p2.x = p.x - 1;
            p2.y = p.y;
            if(lit_pixel_image(sans_titre,p2) == prevc && p2.x>WIDTH  && T_REMPLISSAGE_INT[p2.x][p2.y] == 0) {
                nb_pixel_a_traiter++;
                k++;
                T_REMPLISSAGE[k] = p2;
                printf("%d - %d\n", p2.x, p2.y);
                T_REMPLISSAGE_INT[p2.x][p2.y] = 1;
            }
            
            p2.x = p.x;
            p2.y = p.y + 1;
            if(lit_pixel_image(sans_titre,p2) == prevc && p2.y<HEIGHT  && T_REMPLISSAGE_INT[p2.x][p2.y] == 0) {
                nb_pixel_a_traiter++;
                k++;
                T_REMPLISSAGE[k] = p2;
                printf("%d - %d\n", p2.x, p2.y);
                T_REMPLISSAGE_INT[p2.x][p2.y] = 1;
            }
            
            p2.x = p.x;
            p2.y = p.y - 1;
            if(lit_pixel_image(sans_titre,p2) == prevc && p2.y>HEIGHT  && T_REMPLISSAGE_INT[p2.x][p2.y] == 0) {
                nb_pixel_a_traiter++;
                k++;
                T_REMPLISSAGE[k] = p2;
                printf("%d - %d\n", p2.x, p2.y);
                T_REMPLISSAGE_INT[p2.x][p2.y] = 1;
            }
            dessine_pixel_image(sans_titre,p,colour.pri);
            printf("%d\n",nb_pixel_a_traiter);
            courant++;
            nb_pixel_a_traiter--;

        }
    }
    
}

void polygone(){}
