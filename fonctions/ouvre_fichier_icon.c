void ouvre_fichier_icon(int numero) {
    char line[1024];
    char lien[30];
    sprintf(lien, "icons/%d.txt", numero+1);
    FILE *fp = fopen(lien,"r");
    int v = 0;
    if( fp != NULL ) {
            
            while( fgets(line,1024,fp) ) {
                bouton_icons[numero][v] = atoi(line);
                v++;
            }
    }

}
