void cercle(POINT P,int h,COULEUR c){
    int i;
    POINT p;
    for(i=0;i<h*20;i++){
        p.x=floor(P.x+cos(i)*h)-50;
        p.y=floor(P.y+sin(i)*h)-50;
            
        dessine_pixel_image(sans_titre,p,c);
    }
    
}

void pinceau(){

    POINT p;
    p=position_souris();
    int hauteur=4,i;
    if/*while*/(bouton_appuye(CLIC_GCH)==true && p.x>50 && p.y>50){
        p=position_souris();
        for(i=hauteur;i>0;i--){
            cercle(p,i,colour.pri);}
        }

    if/*while*/(bouton_appuye(CLIC_DRT)==true && p.x>50 && p.y>50){
        p=position_souris();
        for(i=hauteur;i>0;i--){
            cercle(p,i,colour.sec);}
        }
}

void aerographe(){
    POINT p,P;
    float cosinus=0;
    
    p=position_souris();
    
    if/*while*/(bouton_appuye(CLIC_GCH)==true && p.x>50 && p.y>50){
        cosinus=(reel_aleatoire()+entier_aleatoire(4))*2;
            
        P.x=floor(p.x+cos(cosinus)*entier_aleatoire(10));
        P.y=floor(p.y+sin(cosinus)*entier_aleatoire(10));
            
        dessine_pixel_image(sans_titre,P,colour.pri);
        affiche_tout();
    }
    
    if/*while*/(bouton_appuye(CLIC_DRT)==true && p.x>50 && p.y>50){
        cosinus=(reel_aleatoire()+entier_aleatoire(4))*2;
            
        P.x=floor(p.x+cos(cosinus)*entier_aleatoire(10));
        P.y=floor(p.y+sin(cosinus)*entier_aleatoire(10));
        
        dessine_pixel_image(sans_titre,P,colour.sec);
    }
}
