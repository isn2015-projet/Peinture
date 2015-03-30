void affiche_option_specifique(POINT p1, POINT p2) {
   switch(outil){
        case 0:
            p2.x -= 15;
            p1.x -= 5;
        
            p1.y -= 20;
            p2.y += 35;
            dessine_rectangle_plein(p1,p2,colour.pri);
            dessine_rectangle(p1,p2,colour.sec);
            p1.y -= 10;
            p2.y -= 17;
            dessine_rectangle_plein(p1,p2,colour.pri);
            dessine_rectangle(p1,p2,colour.sec);
            p1.y -= 13;
            p2.y -= 20;
            dessine_rectangle_plein(p1,p2,colour.pri);
            dessine_rectangle(p1,p2,colour.sec);
            break;
    }
}

void affiche_options_menu(POINT p1, POINT p2) {
    p1.x = 3; p2.x = LARGEUR_MENU-3;
    p1.y -= 40; p2.y -= 80;
    dessine_rectangle(p1,p2,COULEUR_BORDURE);
    p1.x += 10;
    dessine_texte("opt.",12,p1,COULEUR_TEXTE);
    affiche_option_specifique(p1,p2);
}
