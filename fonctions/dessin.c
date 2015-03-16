void pinceau(){
    POINT p;
    p=position_souris();

    if/*while*/(bouton_appuye(CLIC_GCH)==true && p.x>50 && p.y>50){
        p=position_souris();
        dessine_cercle_plein(p,4,colour.pri);
        attendre(10);
        }

    if/*while*/(bouton_appuye(CLIC_DRT)==true && p.x>50 && p.y>50){
        p=position_souris();
        dessine_cercle_plein(p,4,colour.sec);
        attendre(10);
        }
}
