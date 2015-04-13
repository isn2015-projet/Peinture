int affiche_option_specifique(POINT p1, POINT p2) {
    int bordure_option = 6;
    int coord_y_derniere_option = 0;
    POINT p12, p22;
    switch(outil){
        case 0:
           p1.x += bordure_option;
           p1.y -= 60;
           p2.x = p1.x + 20;
           p2.y = p1.y - 10;
           dessine_rectangle_plein(p1,p2,colour.pri);
           dessine_rectangle(p1,p2,colour.sec);
            p12.x = p1.x + 1;
            p12.y = p1.y + 1;
            p22.x = p2.x + 1;
            p22.y = p2.y + 1;
           dessine_rectangle(p12,p22,colour.sec);

           
           p1.y = p2.y - bordure_option;
           p2.x = p1.x + 20;
           p2.y = p1.y - 20;
           dessine_rectangle_plein(p1,p2,colour.pri);
           dessine_rectangle(p1,p2,colour.sec);
            p12.x = p1.x + 1;
            p12.y = p1.y + 1;
            p22.x = p2.x + 1;
            p22.y = p2.y + 1;
            dessine_rectangle(p12,p22,colour.sec);
            
            
            p1.y = p2.y - bordure_option;
            p2.x = p1.x + 20;
            p2.y = p1.y - 30;
            dessine_rectangle_plein(p1,p2,colour.pri);
            dessine_rectangle(p1,p2,colour.sec);
            p12.x = p1.x + 1;
            p12.y = p1.y + 1;
            p22.x = p2.x + 1;
            p22.y = p2.y + 1;
            dessine_rectangle(p12,p22,colour.sec);
            
            coord_y_derniere_option = p2.y;
            
            break;
    }
    
    return coord_y_derniere_option;
}

void affiche_options_menu(POINT p1, POINT p2) {
    int coord_y_derniere_option = affiche_option_specifique(p1,p2);
    p1.x = 3; p2.x = LARGEUR_MENU-3;
    p1.y -= 40; p2.y = coord_y_derniere_option - 5;
    dessine_rectangle(p1,p2,COULEUR_BORDURE);
    p1.x += 10;
    dessine_texte("opt.",12,p1,COULEUR_TEXTE);

}
