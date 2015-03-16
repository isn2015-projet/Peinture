BOOL Bouton(POINT p, int x_min, int x_max, int y_min, int y_max){
    if(p.x>x_min && p.x<x_max && p.y>y_min && p.y<y_max){return True;}
    else {return False;}
}

void gestion_interface(){
    POINT clic_gch,clic_drt;
    int i;

    clic_gch=position_clic( CLIC_GCH );
    clic_drt=position_clic( CLIC_DRT );

    for(i=0;i<NB_COULEUR;i++){
        if(i<NB_COULEUR/2){
            if(Bouton(clic_gch,60+i*15,75+i*15,25,40)==true){colour.pri=palette[i];}
            if(Bouton(clic_drt,60+i*15,75+i*15,25,40)==true){colour.sec=palette[i];}
        }
        if(i>=NB_COULEUR/2){
            if(Bouton(clic_gch,-75+i*15,-60+i*15,10,25)==true){colour.pri=palette[i];}
            if(Bouton(clic_drt,-75+i*15,-60+i*15,10,25)==true){colour.sec=palette[i];}
        }
    }
    
    
    
    int i_bouton = 0, duet = 0, bordure_bouton_top = 10;
    POINT p1, p2;
    int i_selection_outil;
    for(i_bouton = 0; i_bouton < NB_BOUTON; i_bouton++)
    {
        if(i_bouton == 0)
        {
            p1.y = HEIGHT-bordure_bouton_top;
            p2.y = HEIGHT-bordure_bouton_top-24;
        }
        if(duet == 1) {
            p1.x = 1;
            p2.x = 25;
            p1.x = 25;
            p2.x = 49;
        }
        else {
            p1.x = 1;
            p2.x = 25;
            
            p1.y -= 24;
            p2.y -= 24;
        }
        if(Bouton(clic_gch,p1.x,p2.x,p2.y,p1.y)==true)
        {
            p1.x = WIDTH-170; p1.y = 23;
            switch(i_bouton){
                case 0:
                    sprintf(mode, "Outil: Pinceau");
                    break;
                case 1:
                    sprintf(mode, "Outil: Brosse");
                    break;
                case 2:
                    sprintf(mode, "Outil: Aerographe");
                    break;
                default :
                    sprintf(mode, "Outil: undefined");
            }
            dessine_texte(mode,12,p1,COULEUR_TEXTE);
            for (i_selection_outil = 0; i_selection_outil < NB_BOUTON; i_selection_outil++) {
                if(i_selection_outil==i_bouton)
                {
                    selection_outil[i_selection_outil] = true;
                }
                else {
                    selection_outil[i_selection_outil] = false;
                }
            }
        }
        duet = 1 - duet;
    }
}
