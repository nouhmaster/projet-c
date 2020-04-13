#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "function.h"
#include "function.c"




int main()
{

  Pos *pos;
  pos = (Pos *) malloc(sizeof(Pos));

  pos->x = LARGEUR-1;
  pos->y = HAUTEUR-1;

  int **tab = NULL;

create_2darray_bis(&tab,LARGEUR,HAUTEUR);
fill_2darray(tab,LARGEUR,HAUTEUR);
disp_2darray(tab,LARGEUR,HAUTEUR);
moove(tab,HAUTEUR,LARGEUR,pos);


return 0;
//disp_2darray(tab,LARGEUR,HAUTEUR);
}


