BOOL Bouton(POINT p, int x_min, int x_max, int y_min, int y_max){
    if(p.x>x_min && p.x<x_max && p.y>y_min && p.y<y_max){return True;}
    else {return False;}
}

void gestion_palette(){
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
}
