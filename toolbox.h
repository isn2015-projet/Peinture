// ###############################################
// Franck QUESSETTE -- Franck.Quessette@uvsq.fr
// Version de novembre 2009
//
// Adapt� pour l'ISN par E.Villani (2012-2013)
// ################################################


/****************************************
 ****************************************
 ***   NE PAS MODIFIER CE FICHIER...  ***
 ****************************************
 ****************************************/


#ifndef __TOOLBOX_H__
	// Creation d'un type bool�en
	typedef int BOOL;

	// Constantes bool�ennes
	#define TRUE 1
	#define True 1
	#define true 1
	#define FALSE 0
	#define False 0
	#define false 0

	// Renvoie un float dans l'intervalle [0;1[
	float reel_aleatoire();

	// Renvoie un int dans l'intervalle [0..N[
	// c�d N valeurs diff�rentes de 0 � N-1
	int entier_aleatoire(int N);

	// Renvoie l'entier tap� au clavier.
	// Cette fonction est bloquante
	int lire_entier_clavier();

	// Fonction prenant soin de liberer la memoire
	//    ouverte par les differents modules
	void quitter( int code_erreur )  __attribute__((noreturn));

	/* Librairies g�n�rales *************/
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <sys/time.h>
	#include <sys/types.h>
	#include <unistd.h>
	#include <time.h>
	#include <math.h>
	/************************************/

	/* Librairies facultatives **********/
	#ifdef WITH_GRAPHICS
		#include "graphics/graphics.h"
	#endif

	#ifdef WITH_AUDIO
		#include "audio/audio.h"
	#endif

	#ifdef WITH_NET
		#include "net/net.h"
	#endif
	/************************************/

	#define __TOOLBOX_H__
#endif
