BOOL Bouton(POINT p, POINT p1, POINT p2){
    if(p.x>p1.x && p.x<p2.x && p.y>p2.y && p.y<p1.y){return True;}
    else {return False;}
}

void pipette(){
    POINT p,p1,p2;
    
    p1.x=50;p1.y=50;p2.x=1200;p2.y=675;
    
    p=position_souris();
    
    p.x-=50;
    p.y-=50;
    if(p.x>p1.x && p.x<p2.x && p.y>p1.y && p.y<p2.y && bouton_appuye(CLIC_GCH)==true){
        colour.pri=lit_pixel_image( sans_titre, p );
    }
    
    if(p.x>p1.x && p.x<p2.x && p.y>p1.y && p.y<p2.y && bouton_appuye(CLIC_DRT)==true){
        colour.sec=lit_pixel_image( sans_titre, p );
    }
}

void ligne(POINT p1,POINT p2,COULEUR c){
    POINT p;
    float m1,m2,o1,o2,n1,n2;
    int l,i;
    
    o1=p1.x;
    o2=p1.y;
    p=p1;
    
    n1=p1.y-p2.y;
    n2=p1.x-p2.x;
    
    m1=n1/n2;
    m2=n2/n1;
    l=sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
    
    if((m2>m1 && m1>=0) || (m1>m2 && m1<=0)){
        for(i=0;i<l;i++){
            dessine_pixel_image(sans_titre,p,c);
            p.x=o1;
            p.y=o2;
            if(p2.x>p1.x){o1+=1;o2+=m1;}
            if(p2.x<p1.x){o1-=1;o2-=m1;}
    }}
    
    if((m1>m2 && m1>=0) || (m2>m1 && m1<=0)){
        for(i=0;i<l;i++){
            dessine_pixel(sans_titre,p,c);
            p.x=o1;
            p.y=o2;
            if(p2.y>p1.y){o1+=m2;o2+=1;}
            if(p2.y<p1.y){o1-=m2;o2-=1;}
    }}
    }
