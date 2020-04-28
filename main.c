#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "function.h"
#include "function.c"

int main()
{

choixdifficultes(&hauteur,&largeur);//permet de choisir la difficultes en augmentant la taille du tableaux 2d (les parametre sont des var global qui gere la taille du tableaux)


  Pos *pos;// var pos de type Pos
  pos = (Pos *) malloc(sizeof(Pos)); // allocation dynamique de la structure Pos

  pos->x = largeur-1; // lar var x prend la position du 0 qui est toujours la largeur  - 1 au debut de partie
  pos->y = hauteur-1; // lar var y prend la position du 0 qui est toujours la hauteur  - 1 au debut de partie


create_2darray_bis(&tab,largeur,hauteur);// creation du tab 2d avec comme param l'adresse du tableaux et la taille qui sont deja modifier grace a choixdifficultes
fill_2darray(tab,largeur,hauteur);// remplissage du tableaux
disp_2darray(tab,largeur,hauteur);// affichage du tableaux
moove(tab,hauteur,largeur,pos);// fonction qui gere le deplacement


return 0;
}


