BOOL Bouton(POINT p, POINT p1, POINT p2){
    if(p.x>p1.x && p.x<p2.x && p.y>p2.y && p.y<p1.y){return True;}
    else {return False;}
}

void gestion_interface(){
    POINT clic_gch,clic_drt,p1,p2;
    int i;

    clic_gch=position_clic( CLIC_GCH );
    clic_drt=position_clic( CLIC_DRT );

    for(i=0;i<NB_COULEUR;i++){
        if(i<NB_COULEUR/2){
            p1.x=60+i*15;p2.x=75+i*15;
            p1.y=40;p2.y=25;
            if(Bouton(clic_gch,p1,p2)==true){colour.pri=palette[i];}
            if(Bouton(clic_drt,p1,p2)==true){colour.sec=palette[i];}
        }
        if(i>=NB_COULEUR/2){
            p1.x=-75+i*15;p2.x=-60+i*15;
            p1.y=25;p2.y=10;
            if(Bouton(clic_gch,p1,p2)==true){colour.pri=palette[i];}
            if(Bouton(clic_drt,p1,p2)==true){colour.sec=palette[i];}
        }
    }
    
    
    
    int i_bouton = 0, duet = 0;
    int i_selection_outil;
    for(i_bouton = 0; i_bouton < NB_BOUTON; i_bouton++)
    {
        if(i_bouton == 0)
        {
            p1.y = HEIGHT-10;
            p2.y = HEIGHT-34;
        }
        if(duet == 1) {
            p1.x = 25;
            p2.x = 49;
        }
        else {
            p1.x = 1;
            p2.x = 25;
            
            p1.y -= 24;
            p2.y -= 24;
        }
        if(Bouton(clic_gch,p1,p2)==true)
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

void gestion_fonction(){
    switch(outil){
        case 0:
            pinceau();
            break;
        /*case 1:
            brosse();
            break;*/
        case 2:
            aerographe();
            break;
        /*case 3:
            remplissage();
            break;
        case 4:
            gomme();
            break;
        case 5:
            pipette();
            break;
        case 6:
            ligne();
            break;
        case 7:
            rectangle();
            break;
        case 8:
            polygone();
            break;
        case 9:
            ellipse();
            break;
        case 10:
            rectangle_arrondi();
            break;
        case 11:
            selection();
            break;
        case 12:
            texte();
            break;*/
    }

}
