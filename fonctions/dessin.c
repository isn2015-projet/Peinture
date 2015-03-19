void pinceau(){
    POINT p;
    p=position_souris();

    if/*while*/(bouton_appuye(CLIC_GCH)==true && p.x>50 && p.y>50){
        p=position_souris();
        dessine_cercle_plein(p,4,colour.pri);
        }

    if/*while*/(bouton_appuye(CLIC_DRT)==true && p.x>50 && p.y>50){
        p=position_souris();
        dessine_cercle_plein(p,4,colour.sec);
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
            
        dessine_pixel(P,colour.pri);
        affiche_tout();
    }
    
    if/*while*/(bouton_appuye(CLIC_DRT)==true && p.x>50 && p.y>50){
        cosinus=(reel_aleatoire()+entier_aleatoire(4))*2;
            
        P.x=floor(p.x+cos(cosinus)*entier_aleatoire(10));
        P.y=floor(p.y+sin(cosinus)*entier_aleatoire(10));
        
        dessine_pixel(P,colour.sec);
    }
}
