void affiche_options(POINT p1, POINT p2) {
    p1.x = 3; p2.x = LARGEUR_MENU-3;
    p1.y -= 40; p2.y -= 80;
    dessine_rectangle(p1,p2,COULEUR_BORDURE);
    p1.x += 10;
    dessine_texte("opt.",12,p1,COULEUR_TEXTE);
}
