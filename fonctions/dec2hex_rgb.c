/*Cette fonction sert à extraire les composantes d'une couleur envoyée en paramètre*/
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
