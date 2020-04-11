#include "function.h"



void create_2darray_bis(int ***A, int L, int C) // on cree un tableaux a 2 dimension qui va contenir le "plateaux de jeux"
{

  *A = (int **)malloc(sizeof(int*) * C); // allocation memoire dynamique en fonction du nombre de ligne
    for (int i = 0; i < C; i++)
    {
      (*A)[i] = (int *)malloc(L * sizeof(int)); // allocation memoire dynamique en fonction du nombre de colonne
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

int moduloPositif(int valeur, int modulo){
    return (valeur%modulo<0)?(valeur%modulo)+modulo:valeur%modulo;
}
void haut(int ** A, int L, int C, struct Pos * pos) {
    int temps; // 1 2 3
    temps = A[pos -> y][pos -> x]; //2
    pos -> y--;
    pos -> y = moduloPositif(pos -> y,L);
    A[moduloPositif(pos -> y + 1,L)][pos -> x] = A[pos -> y][pos -> x]; // 2 -> 1
    A[pos -> y][pos -> x] = temps;
}
void droite(int ** A, int L, int C, struct Pos * pos) {
    int temps; // 1 2 3
    temps = A[pos -> y][pos -> x]; //2
    pos -> x++;
    pos -> x = moduloPositif(pos -> x,C);
    A[pos -> y][moduloPositif(pos -> x - 1, C)] = A[pos -> y][pos -> x]; // 2 -> 1
    A[pos -> y][pos -> x] = temps;
}
void gauche(int ** A, int L, int C, struct Pos * pos) {
    int temps; // 1 2 3
    temps = A[pos -> y][pos -> x]; //2
    pos -> x--;
    pos -> x = moduloPositif(pos -> x,C);
    A[pos -> y][moduloPositif(pos -> x + 1,C)] = A[pos -> y][pos -> x]; // 2 -> 1
    A[pos -> y][pos -> x] = temps;
}
void bas(int ** A, int L, int C, struct Pos * pos) {
    int temps; // 1 2 3
    temps = A[pos -> y][pos -> x]; //2
    pos -> y++;
    pos -> y = moduloPositif(pos -> y,L);
    A[moduloPositif(pos -> y - 1,L)][pos -> x] = A[pos -> y][pos -> x]; // 2 -> 1
    A[pos -> y][pos -> x] = temps;
}
