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
