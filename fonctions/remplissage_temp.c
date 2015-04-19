/*----------Initialisation----------*/
int points_remplissage[1150][625];
for(i = 0; i < 1150; i++) {
    for(j = 0; j < 625; j++) {
        points_remplissage[i][j] = 0;
    }
}
 
/*----------Appel de la fonction----------*/
remplissage(1, -1, -1, noir);
 
 
/*----------Fonction remplissage():----------*/
void remplissage(int remplissage_initialisation, int x, int y, COULEUR colorPicked) {
    POINT pos_souris_initialisation;
    COULEUR colorPicked_initialisation;
   
   
    if(remplissage_initialisation==1) {
        pos_souris_initialisation = position_souris();
        if(bouton_appuye(CLIC_GCH)==TRUE && pos_souris_initialisation.x>LARGEUR_MENU && pos_souris_initialisation.x < WIDTH && pos_souris_initialisation.y>LARGEUR_MENU && pos_souris_initialisation.y < HEIGHT) {
            pos_souris_initialisation.x -= LARGEUR_MENU;
            pos_souris_initialisation.y -= LARGEUR_MENU;
            colorPicked_initialisation = lit_pixel_image(sans_titre, pos_souris_initialisation);
           
            dessine_pixel_image(sans_titre, pos_souris_initialisation, colour.pri);
 
            remplissage(0, pos_souris_initialisation.x - 1, pos_souris_initialisation.y, colorPicked_initialisation); //left
            remplissage(0, pos_souris_initialisation.x, pos_souris_initialisation.y + 1, colorPicked_initialisation); //top
            remplissage(0, pos_souris_initialisation.x + 1, pos_souris_initialisation.y, colorPicked_initialisation); //right
            remplissage(0, pos_souris_initialisation.x, pos_souris_initialisation.y - 1, colorPicked_initialisation); //bottom
           
        }
    }
   
 
    else if(remplissage_initialisation == 0) {      
        pos_souris_initialisation.x = x;
        pos_souris_initialisation.y = y;
        colorPicked_initialisation = colorPicked;
        if(lit_pixel_image(sans_titre,pos_souris_initialisation)==colorPicked_initialisation && x>0 && x<WIDTH && y > 0 && y < HEIGHT && points_remplissage[x][y] != 1) {
            /*La prochaine condition empêche une boucle infinie:*/
            if(lit_pixel_image(sans_titre,pos_souris_initialisation)!=colour.pri) {
                dessine_pixel_image(sans_titre, pos_souris_initialisation, colour.pri);
               
           
                /*Fonctionne parfaitement dans toutes les conditions sauf lorsqu'on introduit right et left en même temps, si on désactive left, ça fonctionne*/
                remplissage(0, x - 1, y, colorPicked_initialisation); //left
                remplissage(0, x + 1, y, colorPicked_initialisation); // right
                remplissage(0, x, y + 1, colorPicked_initialisation); // top
                remplissage(0, x, y - 1, colorPicked_initialisation); //bottom
               
                points_remplissage[x][y] = 1;
               
            }
       
        }
 
       
       
    }
}
