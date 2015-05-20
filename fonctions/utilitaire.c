BOOL Bouton(POINT p, POINT p1, POINT p2){
    if(p.x>p1.x && p.x<p2.x && p.y>p2.y && p.y<p1.y){return True;}
    else {return False;}
}

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

void pipette(){
    POINT p,p1,p2;
    
    p1.x=50;p1.y=50;p2.x=1200;p2.y=675;
    
    p=position_souris();
    
    p.x-=50;
    p.y-=50;
    if(p.x>p1.x && p.x<p2.x && p.y>p1.y && p.y<p2.y && bouton_appuye(CLIC_GCH)==true){
        colour.pri=lit_pixel_image( sans_titre, p );
    }
    
    if(p.x>p1.x && p.x<p2.x && p.y>p1.y && p.y<p2.y && bouton_appuye(CLIC_DRT)==true){
        colour.sec=lit_pixel_image( sans_titre, p );
    }
}

void dessine_ligne_image(POINT p1,POINT p2,COULEUR c){
    POINT p;
    float m1,m2,o1,o2,n1,n2;
    int i,test=0,o,hauteur=option*2;
    
    o1=p1.x;
    o2=p1.y;
    p=p1;
    
    n1=p2.y-p1.y;
    n2=p2.x-p1.x;
    
    if((n1<0 && abs(n1)>n2) || (n1>0 && n2<0 && abs(n2)>n1)){
    n1=p1.y-p2.y;
    n2=p1.x-p2.x;}
    
    m1=n1/n2;
    m2=n2/n1;
    
    o1+=LARGEUR_MENU;
    o2+=LARGEUR_MENU;
    
    if((m2>=m1 && m1>=0) || (m1>=m2 && m1<=0)){
        for(i=0;i<abs(n2)+1;i++){
            p.x=o1;
            p.y=o2;
            for(o=hauteur;o>0;o--){
                cercle(p,o,c);
            }
            if(p2.x>p1.x){o1+=1;o2+=m1;}
            if(p2.x<p1.x){o1-=1;o2-=m1;}
        }
    test++;
    }
    
    if((m1>=m2 && m1>=0 && test==0) || (m2>=m1 && m1<=0 && test==0)){
        for(i=0;i<abs(n1)+1;i++){
            p.x=o1;
            p.y=o2;
            for(o=hauteur;o>0;o--){
                cercle(p,o,c);
            }
            if(p2.y>p1.y){o1+=m2;o2+=1;}
            if(p2.y<p1.y){o1-=m2;o2-=1;}
        }
    }
}



void sauvegarde_document() {
    printf("Sauvegarde en cours!\n");
 
    int dimx = 1150, dimy = 625;
    int i, j;
    FILE *fp = fopen("sans_titre.bmp", "w+");
    fprintf(fp, "P6\n%d %d\n255\n", dimx, dimy);
    for (j = 0; j < dimy; ++j)
    {
        for (i = 0; i < dimx; ++i)
        {
            POINT p;
            p.x = i;
            p.y = HEIGHT-j-76;
            static unsigned char color[3];
            color[0] = ((lit_pixel_image(sans_titre, p) & 0x00FF0000) >> 16);  /* rouge */
            color[1] = ((lit_pixel_image(sans_titre, p) & 0x0000FF00) >> 8);  /* vert */
            color[2] = (lit_pixel_image(sans_titre, p) & 0x000000FF);  /* bleu */
            fwrite(color, 1, 1, fp);
            fwrite(color+1, 1, 1, fp);
            fwrite(color+2, 1, 1, fp);
        }
    }
    (void) fclose(fp);
    printf("Sauvegarde ok !\n");
    

    time_t now = time (NULL);
    struct tm tm_now = *localtime (&now);
    char s_now[sizeof "JJ/MM/AAAA HH:MM:SS"];
    strftime (s_now, sizeof s_now, "%d/%m/%Y %H:%M:%S", &tm_now);
    sprintf(derniere_sauvegarde, "%s", s_now);
}

void affichage_interface_fonction(){
    POINT P,p1,p2,po1,po2;
    P.x=50;P.y=50;
    dessine_image(sans_titre,P);
    pointeur_souris();
    
    p1.x = WIDTH-225; p1.y = 43;
    p2.x=WIDTH-20;p2.y=25;
    dessine_rectangle_plein(p1,p2,COULEUR_COLONNE);
    
    p1.x = WIDTH-170; p1.y = 43;
    p2 = position_souris();
    if(p2.x-LARGEUR_MENU>=0 && p2.y-LARGEUR_MENU>=0 && p2.y<HEIGHT-(LARGEUR_MENU/2))
    {
        char coordonnees[30];
        sprintf(coordonnees, "Position: %dx%d", p2.x-LARGEUR_MENU, p2.y-LARGEUR_MENU);
        dessine_texte(coordonnees,12,p1,COULEUR_TEXTE);
    }
    else {
        if(p2.y>HEIGHT-(LARGEUR_MENU/2)) {
            dessine_texte("Position: menu",12,p1,COULEUR_TEXTE);
        }
        else if(p2.x-LARGEUR_MENU<0 && p2.y-LARGEUR_MENU>=0) {
            dessine_texte("Position: barre d'outil",12,p1,COULEUR_TEXTE);
        }
        else if(p2.y-LARGEUR_MENU<0) {
            dessine_texte("Position: palette",12,p1,COULEUR_TEXTE);
        }
        else {
            dessine_texte("Position: non defini",12,p1,COULEUR_TEXTE);
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
}
