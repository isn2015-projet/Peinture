void pinceau(){
    POINT p,p1;
    int test=0,hauteur=option*2,i;
    p=position_souris();
    while(bouton_appuye(CLIC_GCH)==true || bouton_appuye(CLIC_DRT)==true){
        p1=p;
        if(test==0){p1.x-=LARGEUR_MENU;p1.y-=LARGEUR_MENU;test++;}
        p=position_souris();
        
        if(bouton_appuye(CLIC_GCH)==true) {
            for(i=hauteur;i>0;i--){
                cercle(p,i,colour.pri);
            }
        }
        else if(bouton_appuye(CLIC_DRT)==true) {
            for(i=hauteur;i>0;i--){
                cercle(p,i,colour.sec);
            }
        }
        
        p.x-=LARGEUR_MENU;p.y-=LARGEUR_MENU;
        if(bouton_appuye(CLIC_GCH)==true) {
            dessine_ligne_image(p,p1,colour.pri);
        }
        else if(bouton_appuye(CLIC_DRT)==true) {
            dessine_ligne_image(p,p1,colour.sec);
        }
        affichage_interface_fonction();
    }
}

void brosse(){
    POINT p,p1,pl1,pl2;
    int test=0,o;
    p=position_souris();
    
    while(bouton_appuye(CLIC_GCH)==true || bouton_appuye(CLIC_DRT)==true){
        p1=p;
        if(test==0){p1.x-=LARGEUR_MENU;p1.y-=LARGEUR_MENU;test++;}
        p=position_souris();
        p.x-=LARGEUR_MENU;p.y-=LARGEUR_MENU;
        pl1.x=p.x-3;pl1.y=p.y+3;
        pl2.x=p.x+3;pl2.y=p.y-3;
            
        if(bouton_appuye(CLIC_GCH)==true) {
            dessine_ligne_image(pl1,pl2,colour.pri);
        }
        else if(bouton_appuye(CLIC_DRT)==true) {
            dessine_ligne_image(pl1,pl2,colour.sec);
        }
        
        if(bouton_appuye(CLIC_GCH)==true) {
            for(o=-3;o<11;o++){
                pl1.x=p.x+o;pl1.y=p.y-o;
                pl2.x=p1.x+o;pl2.y=p1.y-o;
                dessine_ligne_image(pl1,pl2,colour.pri);
            }
            p.y++;p1.y++;
            for(o=-2;o<11;o++){
                pl1.x=p.x+o;pl1.y=p.y-o;
                pl2.x=p1.x+o;pl2.y=p1.y-o;
                dessine_ligne_image(pl1,pl2,colour.pri);
            }
        }
        else if(bouton_appuye(CLIC_DRT)==true) {
            for(o=-3;o<11;o++){
                pl1.x=p.x+o;pl1.y=p.y-o;
                pl2.x=p1.x+o;pl2.y=p1.y-o;
                dessine_ligne_image(pl1,pl2,colour.sec);
            }
            p.y++;p1.y++;
            for(o=-2;o<11;o++){
                pl1.x=p.x+o;pl1.y=p.y-o;
                pl2.x=p1.x+o;pl2.y=p1.y-o;
                dessine_ligne_image(pl1,pl2,colour.sec);
            }
        }
        affichage_interface_fonction();
    }
}

void gomme(){
    POINT p,p1;
    int test=0;
    p=position_souris();
    int hauteur=2*option,i;
    while(bouton_appuye(CLIC_GCH)==true){
        p1=p;
        if(test==0){p1.x-=LARGEUR_MENU;p1.y-=LARGEUR_MENU;test++;}
        p=position_souris();
        
        for(i=hauteur;i>0;i--){
            cercle(p,i,blanc);
        }
        
        p.x-=LARGEUR_MENU;p.y-=LARGEUR_MENU;
        dessine_ligne_image(p,p1,blanc);
        
        affichage_interface_fonction();
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
    POINT p,pi;
    int couleur=0;
    p=position_souris();
    if(bouton_appuye(CLIC_GCH)==true || bouton_appuye(CLIC_DRT)==true){
        pi=p;
        while(p.x>LARGEUR_MENU && p.y>LARGEUR_MENU && (bouton_appuye(CLIC_GCH)==true || bouton_appuye(CLIC_DRT)==true)){
            p=position_souris();
            if(bouton_appuye(CLIC_GCH)==true){dessine_ligne(pi,p,colour.pri); couleur=1;}
            if(bouton_appuye(CLIC_DRT)==true){dessine_ligne(pi,p,colour.sec); couleur=2;}
            
            affichage_interface_fonction();
        }
        pi.x-=50;pi.y-=50;p.x-=50;p.y-=50;
        if(couleur==1){dessine_ligne_image(pi,p,colour.pri);}
        if(couleur==2){dessine_ligne_image(pi,p,colour.sec);}
    }
    
}


void polygone(){
    POINT p,p1;
    
    while(bouton_appuye(CLIC_GCH)==true){
        p1=p;
        while(bouton_appuye(CLIC_GCH)==false){
            p=position_souris();
            dessine_ligne(p1,p,colour.pri);
            
            affichage_interface_fonction();
        }
        p1.x-=50; p1.y-=50; p.x-=50; p.y-=50;
        dessine_ligne_image(p1,p,colour.pri);    
    }
}

void rectangle(){
    POINT p,p1,p2,p3;
    
    int couleur=0;
    p=position_souris();
    
    if(bouton_appuye(CLIC_GCH)==true || bouton_appuye(CLIC_DRT)==true){
        p1=p;
        while(bouton_appuye(CLIC_GCH)==true || bouton_appuye(CLIC_DRT)==true){
            p=position_souris();
            p2.x=p.x;   p2.y=p1.y;
            p3.x=p1.x;  p3.y=p.y;
            if(bouton_appuye(CLIC_GCH)==true){
                dessine_ligne(p1,p2,colour.pri);
                dessine_ligne(p1,p3,colour.pri);
                dessine_ligne(p2,p,colour.pri);
                dessine_ligne(p3,p,colour.pri);
                couleur=1;
            }
            if(bouton_appuye(CLIC_DRT)==true){
                dessine_ligne(p1,p2,colour.sec);
                dessine_ligne(p1,p3,colour.sec);
                dessine_ligne(p2,p,colour.sec);
                dessine_ligne(p3,p,colour.sec);
                couleur=2;
            }
            affichage_interface_fonction();
        }
    p1.x-=50; p1.y-=50; p2.x-=50; p2.y-=50;
    p3.x-=50; p3.y-=50; p.x-=50;  p.y-=50;
    if(couleur==1){
        dessine_ligne_image(p1,p2,colour.pri);
        dessine_ligne_image(p1,p3,colour.pri);
        dessine_ligne_image(p2,p,colour.pri);
        dessine_ligne_image(p3,p,colour.pri);
        }
    if(couleur==2){
        dessine_ligne_image(p1,p2,colour.sec);
        dessine_ligne_image(p1,p3,colour.sec);
        dessine_ligne_image(p2,p,colour.sec);
        dessine_ligne_image(p3,p,colour.sec);
        }
    }
}

float distance(POINT a, POINT b) {  
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));  
} 
void ellipse() {
    POINT p,p1;
    POINT m;
    POINT z;
    p=position_souris();
    int i, j;
    int lg_axe = option*50; 
    if(bouton_appuye(CLIC_GCH)==true && p.x>LARGEUR_MENU && p.y > LARGEUR_MENU){
        p1=p;
        while(bouton_appuye(CLIC_GCH)==true){
            p=position_souris();

            for(i=LARGEUR_MENU;i<WIDTH;i++) {  
                m.x = i;  
                for(j=LARGEUR_MENU;j<HEIGHT-(LARGEUR_MENU/2);j++) {  
                    m.y = j;  
                    if((distance(m,p)+distance(m,p1))<=((2*lg_axe)+1) && (distance(m,p)+distance(m,p1))>=((2*lg_axe)-1)) {
                        dessine_pixel(m,colour.pri);  
                    }  
                }  
            }
            
            affichage_interface_fonction();
        }
            for(i=0;i<WIDTH;i++) {  
                m.x = i;  
                for(j=0;j<HEIGHT-(LARGEUR_MENU/2);j++) {  
                    m.y = j;  
                    if((distance(m,p)+distance(m,p1))<=((2*lg_axe)+1) && (distance(m,p)+distance(m,p1))>=((2*lg_axe)-1)) {
                        z.x = m.x - 50;
                        z.y = m.y - 50;
                        dessine_pixel_image(sans_titre,z,colour.pri);  
                    }  
                }  
            }

    }
    if(bouton_appuye(CLIC_DRT)==true && p.x>LARGEUR_MENU && p.y > LARGEUR_MENU){
        p1=p;
        while(bouton_appuye(CLIC_DRT)==true){
            p=position_souris();

            for(i=LARGEUR_MENU;i<WIDTH;i++) {  
                m.x = i;  
                for(j=LARGEUR_MENU;j<HEIGHT-(LARGEUR_MENU/2);j++) {  
                    m.y = j;  
                    if((distance(m,p)+distance(m,p1))<=((2*lg_axe)+1) && (distance(m,p)+distance(m,p1))>=((2*lg_axe)-1)) {
                        dessine_pixel(m,colour.sec);  
                    }  
                }  
            }
            
            affichage_interface_fonction();
        }
        for(i=0;i<WIDTH;i++) {  
            m.x = i;  
            for(j=0;j<HEIGHT-(LARGEUR_MENU/2);j++) {  
                m.y = j;  
                if((distance(m,p)+distance(m,p1))<=((2*lg_axe)+1) && (distance(m,p)+distance(m,p1))>=((2*lg_axe)-1)) {
                    z.x = m.x - 50;
                    z.y = m.y - 50;
                    dessine_pixel_image(sans_titre,z,colour.sec);  
                }  
            }  
        }
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
