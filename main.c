#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "function.h"
#include "function.c"

int main()
{

choixdifficultes(&hauteur,&largeur);


  Pos *pos;
  pos = (Pos *) malloc(sizeof(Pos));

  pos->x = largeur-1;
  pos->y = hauteur-1;


create_2darray_bis(&tab,largeur,hauteur);
fill_2darray(tab,largeur,hauteur);
disp_2darray(tab,largeur,hauteur);
moove(tab,hauteur,largeur,pos);


return 0;
}


