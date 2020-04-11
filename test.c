#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct Pos
{
  int x;
  int y;
}Pos;

void fill_2darray(int **A, int L, int C);
int ** create_2darray(int L, int C);
void create_2darray_bis(int ***A, int L, int C);
void disp_2darray(int **A,int L,int C);
void freeA(int ** A);
void droite(int **A,int L,int C,struct Pos *pos);
void gauche(int **A,int L,int C,struct Pos *pos);
void bas(int **A,int L,int C,struct Pos *pos);
void haut(int **A,int L,int C,struct Pos *pos);

int main()
{
  int l = 4;
  int c = 4;
  Pos *pos;
  pos = (Pos *) malloc(sizeof(Pos));

  pos->x = l-1;
  pos->y = c-1;

  int **tab = NULL;

  create_2darray_bis(&tab,l,c);
  fill_2darray(tab,l,c);
  disp_2darray(tab,l,c);
  haut(tab,pos->x,pos->y,pos);
disp_2darray(tab,l,c);
haut(tab,pos->x,pos->y,pos);
disp_2darray(tab,l,c);
haut(tab,pos->x,pos->y,pos);
disp_2darray(tab,l,c);
bas(tab,pos->x,pos->y,pos);
disp_2darray(tab,l,c);
bas(tab,pos->x,pos->y,pos);
disp_2darray(tab,l,c);
gauche(tab,pos->x,pos->y,pos);
disp_2darray(tab,l,c);
droite(tab,pos->x,pos->y,pos);
disp_2darray(tab,l,c);






  //direction(tab,x-1,y-1);

  //freeA(tab);
}



void create_2darray_bis(int ***A, int L, int C) // on cree un tableaux a 2 dimension qui va contenir le "plateaux de jeux"
{

  *A = (int **)malloc(sizeof(int*) * L); // allocation memoire dynamique en fonction du nombre de ligne
    for (int i = 0; i < L; i++)
    {
      (*A)[i] = (int *)malloc(C * sizeof(int)); // allocation memoire dynamique en fonction du nombre de colonne
    }
}

void fill_2darray(int **A, int L, int C) // fonction qui remplit le plateaux de nombre aleatoire comprit entre 15 et 0
{

  for (int i = 0; i <  L; i++)
    {
        for (int j = 0; j < C; j++)
        {


            for(int count = 1; count < 20; count ++)
                {

                    if (i == L - 1 && j == C - 1)
                    {
                        A[i][j] = 0; // permet de remplacer la derniere case du tableaux par 0 pour pouvoir jouer
                    }
                    else
                        A[i][j]=rand()%(15 + 1 - 1) + 1;// remplit la case du tableaux avec un nombre aleatoire generer par rand entre 15 et 0
                }

        }
    }
}

void disp_2darray(int **A,int L,int C)// affiche le contenus du tableaux
{
  for (int i = 0; i <  L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("\t[%d] ", A[i][j]); // affiche le contenus de la Ligne i et de la Colonne j
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    //direction(A,L,C);
}

void freeA(int **A) // libere l'espace allouer au tableaux
{
    free(A); // permet de librere l'espace memoire du tableaux a la fin du programme
}

void haut(int **A,int L,int C,struct Pos *pos)
{
    int temps; // 1 2 3
    temps = A[pos->y][pos->x]; //2
    A[pos->y][pos->x] = A[--(pos->y)][pos->x]; // 2 -> 1
    A[pos->y][pos->x] = temps;
}
void droite(int **A,int L,int C,struct Pos *pos)
{
    int temps; // 1 2 3
    temps = A[pos->y][pos->x]; //2
    A[pos->y][pos->x] = A[pos->y][++(pos->x)]; // 2 -> 1
    A[pos->y][pos->x] = temps;
}
void gauche(int **A,int L,int C,struct Pos *pos)
{
    int temps; // 1 2 3
    temps = A[pos->y][pos->x]; //2
    A[pos->y][pos->x] = A[pos->y][--(pos->x)]; // 2 -> 1
    A[pos->y][pos->x] = temps;
}
void bas(int **A,int L,int C,struct Pos *pos)
{
    int temps; // 1 2 3
    temps = A[pos->y][pos->x]; //2
    A[pos->y][pos->x] = A[++(pos->y)][pos->x]; // 2 -> 1
    A[pos->y][pos->x] = temps;
}
