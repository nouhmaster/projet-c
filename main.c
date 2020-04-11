#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "function.h"
#include "function.c"
#define LARGEUR 4
#define HAUTEUR 4


int main()
{
  int l = 4;
  int c = 4;
  Pos *pos;
  pos = (Pos *) malloc(sizeof(Pos));

  pos->x = l-1;
  pos->y = c-1;

  int **tab = NULL;

create_2darray_bis(&tab,LARGEUR,HAUTEUR);
fill_2darray(tab,l,c);
disp_2darray(tab,l,c);
haut(tab,HAUTEUR,LARGEUR,pos);
disp_2darray(tab,l,c);
haut(tab,HAUTEUR,LARGEUR,pos);
disp_2darray(tab,l,c);
haut(tab,HAUTEUR,LARGEUR,pos);
disp_2darray(tab,l,c);
haut(tab,HAUTEUR,LARGEUR,pos);
droite(tab,HAUTEUR,LARGEUR,pos);
disp_2darray(tab,l,c);
droite(tab,HAUTEUR,LARGEUR,pos);
disp_2darray(tab,l,c);
droite(tab,HAUTEUR,LARGEUR,pos);
disp_2darray(tab,l,c);


}


