char *affiche_option_specifique() {
    switch(outil){
        case 0:
            switch(option){
                case 1:
                    return "   fin";
                    break;
                case 2:
                    return "moyen";
                    break;
                case 3:
                    return " large";
                    break;
                default:
                    return "moyen";
                    break;
             }
            break;
        case 2:
            switch(option){
                case 1:
                    return "   fin";
                    break;
                case 2:
                    return "moyen";
                    break;
                case 3:
                    return " large";
                    break;
                default:
                    return "moyen";
                    break;
            }
            break;
        default:
            return "moyen";
            break;
    }
}

void affiche_options_menu(POINT p1, POINT p2) {


    POINT rectl, recbr;
    rectl.x = 3; rectl.y = p1.y - 40;
    recbr.x = LARGEUR_MENU-3; recbr.y = rectl.y - 60;
    dessine_rectangle(rectl,recbr,COULEUR_BORDURE);
    
    POINT text;
    text.x = rectl.x + 10;
    text.y = rectl.y;
    dessine_texte("opt.",12,text,COULEUR_TEXTE);
    
    POINT t1, t2, t3;
    t1.x = 10; t1.y = text.y - 30;
    t2.x = t1.x + 5; t2.y = t1.y + 5;
    t3.x = t1.x + 5; t3.y = t1.y - 5;
    dessine_triangle_plein(t1, t2, t3, noir);
    
    t1.x = LARGEUR_MENU-10; t1.y = text.y - 30;
    t2.x = t1.x - 5; t2.y = t1.y + 5;
    t3.x = t1.x - 5; t3.y = t1.y - 5;
    dessine_triangle_plein(t1, t2, t3, noir); 
    
    text.x = LARGEUR_MENU/2-4;
    text.y = text.y - 21;   
    dessine_entier(option, 12, text, noir);
    
    text.x = 7;
    text.y = text.y - 20;  
    dessine_texte(affiche_option_specifique(), 10, text, noir);
}
