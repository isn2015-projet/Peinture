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
    POINT p,p1,po1,po2,P;
    int test=0;
    p=position_souris();
    P.x=LARGEUR_MENU; P.y=LARGEUR_MENU;
    int hauteur=2*option,i;
    while(bouton_appuye(CLIC_GCH)==true || bouton_appuye(CLIC_DRT)==true){
        p1=p;
        if(test==0){p1.x-=LARGEUR_MENU;p1.y-=LARGEUR_MENU;test++;}
        p=position_souris();
        for(i=hauteur;i>0;i--){
            if(bouton_appuye(CLIC_GCH)==true) {
                cercle(p,i,colour.pri);
            }
            else if(bouton_appuye(CLIC_DRT)==true) {
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
        
        //fixed: les bordures de la barre d'outil disparaissaient
        po1.x = 0;     po1.y = LARGEUR_MENU;
        po2.x = WIDTH; po2.y = LARGEUR_MENU;
        dessine_ligne(po1, po2, COULEUR_BORDURE);
            
        po1.x = 0;     po1.y = HEIGHT-(LARGEUR_MENU/2);
        po2.x = WIDTH; po2.y = HEIGHT-(LARGEUR_MENU/2);
        dessine_ligne(po1, po2, COULEUR_BORDURE);
            
        po1.x = LARGEUR_MENU; po1.y = HEIGHT-(LARGEUR_MENU/2);
        po2.x = LARGEUR_MENU; po2.y = LARGEUR_MENU;
        dessine_ligne(po1, po2, COULEUR_BORDURE);
        //fin fixed
            
        affiche_tout();
        dessine_image(sans_titre,P);
    }
}

void gomme(){
    POINT p,p1,po1,po2,P;
    int test=0;
    p=position_souris();
    P.x=LARGEUR_MENU; P.y=LARGEUR_MENU;
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
        
        //fixed: les bordures de la barre d'outil disparaissaient
        po1.x = 0;     po1.y = LARGEUR_MENU;
        po2.x = WIDTH; po2.y = LARGEUR_MENU;
        dessine_ligne(po1, po2, COULEUR_BORDURE);
            
        po1.x = 0;     po1.y = HEIGHT-(LARGEUR_MENU/2);
        po2.x = WIDTH; po2.y = HEIGHT-(LARGEUR_MENU/2);
        dessine_ligne(po1, po2, COULEUR_BORDURE);
            
        po1.x = LARGEUR_MENU; po1.y = HEIGHT-(LARGEUR_MENU/2);
        po2.x = LARGEUR_MENU; po2.y = LARGEUR_MENU;
        dessine_ligne(po1, po2, COULEUR_BORDURE);
        //fin fixed
            
        affiche_tout();
        dessine_image(sans_titre,P);
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
    int couleur=0;
    P.x=LARGEUR_MENU;P.y=LARGEUR_MENU;
    p=position_souris();
    if(bouton_appuye(CLIC_GCH)==true || bouton_appuye(CLIC_DRT)==true){
        pi=p;
        while(p.x>LARGEUR_MENU && p.y>LARGEUR_MENU && (bouton_appuye(CLIC_GCH)==true || bouton_appuye(CLIC_DRT)==true)){
            p=position_souris();
            dessine_image(sans_titre,P);
            if(bouton_appuye(CLIC_GCH)==true){dessine_ligne(pi,p,colour.pri); couleur=1;}
            if(bouton_appuye(CLIC_DRT)==true){dessine_ligne(pi,p,colour.sec); couleur=2;}
            
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
        if(couleur==1){dessine_ligne_image(pi,p,colour.pri);}
        if(couleur==2){dessine_ligne_image(pi,p,colour.sec);}
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
void polygone(){
    POINT p,p1,po1,po2,P;
    
    P.x=LARGEUR_MENU;
    P.y=LARGEUR_MENU;
    p=position_souris();
    
    while(bouton_appuye(CLIC_GCH)==true){
        p1=p;
        while(bouton_appuye(CLIC_GCH)==false){
            p=position_souris();
            dessine_ligne(p1,p,colour.pri);
            
            //fixed: les bordures de la barre d'outil disparaissaient
            po1.x = 0;     po1.y = LARGEUR_MENU;
            po2.x = WIDTH; po2.y = LARGEUR_MENU;
            dessine_ligne(po1, po2, COULEUR_BORDURE);
            
            po1.x = 0;     po1.y = HEIGHT-(LARGEUR_MENU/2);
            po2.x = WIDTH; po2.y = HEIGHT-(LARGEUR_MENU/2);
            dessine_ligne(po1, po2, COULEUR_BORDURE);
            
            po1.x = LARGEUR_MENU; po1.y = HEIGHT-(LARGEUR_MENU/2);
            po2.x = LARGEUR_MENU; po2.y = LARGEUR_MENU;
            dessine_ligne(po1, po2, COULEUR_BORDURE);
            //fin fixed
            
            affiche_tout();
            dessine_image(sans_titre,P);
        }
        p1.x-=50; p1.y-=50; p.x-=50; p.y-=50;
        dessine_ligne_image(p1,p,colour.pri);    
    }
}

void rectangle(){
    POINT p,p1,p2,p3,P,po1,po2;
    
    int couleur=0;
    P.x=LARGEUR_MENU;
    P.y=LARGEUR_MENU;
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
            //fixed: les bordures de la barre d'outil disparaissaient
            po1.x = 0;     po1.y = LARGEUR_MENU;
            po2.x = WIDTH; po2.y = LARGEUR_MENU;
            dessine_ligne(po1, po2, COULEUR_BORDURE);
            
            po1.x = 0;     po1.y = HEIGHT-(LARGEUR_MENU/2);
            po2.x = WIDTH; po2.y = HEIGHT-(LARGEUR_MENU/2);
            dessine_ligne(po1, po2, COULEUR_BORDURE);
            
            po1.x = LARGEUR_MENU; po1.y = HEIGHT-(LARGEUR_MENU/2);
            po2.x = LARGEUR_MENU; po2.y = LARGEUR_MENU;
            dessine_ligne(po1, po2, COULEUR_BORDURE);
            //fin fixed
            
            affiche_tout();
            dessine_image(sans_titre,P);
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
    POINT p,p1,P,po1,po2;
    POINT m;
    POINT z;
    P.x=LARGEUR_MENU;
    P.y=LARGEUR_MENU;
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
            
            //fixed: les bordures de la barre d'outil disparaissaient
            po1.x = 0;     po1.y = LARGEUR_MENU;
            po2.x = WIDTH; po2.y = LARGEUR_MENU;
            dessine_ligne(po1, po2, COULEUR_BORDURE);
            
            po1.x = 0;     po1.y = HEIGHT-(LARGEUR_MENU/2);
            po2.x = WIDTH; po2.y = HEIGHT-(LARGEUR_MENU/2);
            dessine_ligne(po1, po2, COULEUR_BORDURE);
            
            po1.x = LARGEUR_MENU; po1.y = HEIGHT-(LARGEUR_MENU/2);
            po2.x = LARGEUR_MENU; po2.y = LARGEUR_MENU;
            dessine_ligne(po1, po2, COULEUR_BORDURE);
            //fin fixed
            
            affiche_tout();
            dessine_image(sans_titre,P);
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
            
            //fixed: les bordures de la barre d'outil disparaissaient
            po1.x = 0;     po1.y = LARGEUR_MENU;
            po2.x = WIDTH; po2.y = LARGEUR_MENU;
            dessine_ligne(po1, po2, COULEUR_BORDURE);
            
            po1.x = 0;     po1.y = HEIGHT-(LARGEUR_MENU/2);
            po2.x = WIDTH; po2.y = HEIGHT-(LARGEUR_MENU/2);
            dessine_ligne(po1, po2, COULEUR_BORDURE);
            
            po1.x = LARGEUR_MENU; po1.y = HEIGHT-(LARGEUR_MENU/2);
            po2.x = LARGEUR_MENU; po2.y = LARGEUR_MENU;
            dessine_ligne(po1, po2, COULEUR_BORDURE);
            //fin fixed
            
            affiche_tout();
            dessine_image(sans_titre,P);
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
