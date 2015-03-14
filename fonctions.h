
void ouvre_fichier_icon(int numero) {
    char line[1024];
    char lien[30];
    sprintf(lien, "icons/%d.txt", numero+1);
    FILE *fp = fopen(lien,"r");
    int v = 0;
    if( fp != NULL ) {
            
            while( fgets(line,1024,fp) ) {
                printf(">%d: %d<\n",v, atoi(line));
                bouton_icons[numero][v] = atoi(line);
                v++;
            }
    }

}


int dec2hex_rgb(int parametre, int intColor) {
    if(parametre==0) { // on extrait le rouge
        return (intColor & 0xff0000) >> 16;
    }
    else if(parametre==1) { // on extrait le vert
        return (intColor & 0x00ff00) >> 8;
    }
    else { // on extrait le bleu
        return (intColor & 0x0000ff);
    }
}
