BOOL Bouton(POINT p, POINT p1, POINT p2){
    if(p.x>p1.x && p.x<p2.x && p.y>p2.y && p.y<p1.y){return True;}
    else {return False;}
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
    int l,i;
    
    o1=p1.x;
    o2=p1.y;
    p=p1;
    
    n1=p2.y-p1.y;
    n2=p2.x-p1.x;
    
    m1=n1/n2;
    m2=n2/n1;
    l=sqrt((n2)*(n2)+(n1)*(n1));
    
    if((m2>=m1 && m1>=0) || (m1>=m2 && m1<=0)){
        for(i=0;i<l;i++){
            dessine_pixel_image(sans_titre,p,c);
            p.x=o1;
            p.y=o2;
            if(p2.x>p1.x){o1+=1;o2+=m1;}
            if(p2.x<p1.x){o1-=1;o2-=m1;}
    }}
    
    if((m1>=m2 && m1>=0) || (m2>=m1 && m1<=0)){
        for(i=0;i<l;i++){
            dessine_pixel_image(sans_titre,p,c);
            p.x=o1;
            p.y=o2;
            if(p2.y>p1.y){o1+=m2;o2+=1;}
            if(p2.y<p1.y){o1-=m2;o2-=1;}
    }}
    }



void sauvegarde_document() {
    printf("Sauvegarde en cours!\n");
 
    int dimx = 1150, dimy = 625;
    int i, j;
    FILE *fp = fopen("sans_titre.bmp", "w+"); /* b - binary mode */
    fprintf(fp, "P6\n%d %d\n255\n", dimx, dimy);
    for (j = 0; j < dimy; ++j)
    {
        for (i = 0; i < dimx; ++i)
        {
            POINT p;
            p.x = i;
            p.y = HEIGHT-j-76;
            static unsigned char color[3];
            color[0] = ((lit_pixel_image(sans_titre, p) & 0x00FF0000) >> 16);  /* red */
            color[1] = ((lit_pixel_image(sans_titre, p) & 0x0000FF00) >> 8);  /* green */
            color[2] = (lit_pixel_image(sans_titre, p) & 0x000000FF);  /* blue */
            fwrite(color, 1, 3, fp);
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
