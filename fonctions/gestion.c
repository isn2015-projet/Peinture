void gestion_interface(){
    POINT clic_gch,clic_drt,p1,p2;
    int i;

    clic_gch=position_clic( CLIC_GCH );
    clic_drt=position_clic( CLIC_DRT );


    //gestion options
    POINT t1, t2;
    t1.x = 10; t1.y = 457;
    t2.x = 15; t2.y = 447;
    if(Bouton(clic_gch,t1,t2)==true || touche_nb_appuis(80)==1){
        if(option!=0) {
            option--;
        }
    }
    t1.x = 35; t1.y = 457;
    t2.x = 40; t2.y = 447;
    if(Bouton(clic_gch,t1,t2)==true || touche_nb_appuis(79)==1){
        if(option!=3) {
            option++;
        }    
   }
    
    
    //gestion sauvegarde
    POINT save1, save2;
    save1.x = 271+LARGEUR_MENU;
    save1.y = 646+LARGEUR_MENU;
    save2.x = 405+LARGEUR_MENU;
    save2.y = 624+LARGEUR_MENU;
    if(Bouton(clic_gch,save1, save2)==true){
        sauvegarde_document();
    }
    

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
                case 3:
                    sprintf(mode, "Outil: Remplissage");
                    break;
                case 4:
                    sprintf(mode, "Outil: Gomme");
                    break;
                case 5:
                    sprintf(mode, "Outil: Pipette");
                    break;
                case 6:
                    sprintf(mode, "Outil: Ligne");
                    break;
                case 7:
                    sprintf(mode, "Outil: Rectangle");
                    break;
                case 8:
                    sprintf(mode, "Outil: Polygone");
                    break;
                case 9:
                    sprintf(mode, "Outil: Ellipse");
                    break;
                case 10:
                    sprintf(mode, "Outil: Rectangle Arrondi");
                    break;
                default :
                    sprintf(mode, "Outil: undefined");
            }
            dessine_texte(mode,12,p1,COULEUR_TEXTE);
            outil=i_bouton;
        }
        duet = 1 - duet;
    }
}

void gestion_fonction(){
    switch(outil){
        case 0:
            pinceau();
            break;
        case 1:
            brosse();
            break;
        case 2:
            aerographe();
            break;
        case 3:
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
        /*case 10:
            rectangle_arrondi();
            break;*/
    }

}
