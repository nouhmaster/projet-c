#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void fill_2darray(int **A, int L, int C);
int ** create_2darray(int L, int C);
void create_2darray_bis(int ***A, int L, int C);
void disp_2darray(int **A,int L,int C);
void freeA(int ** A);

int main()
{
  int x = 0;
  int y = 0;
  int **tab = NULL;
  printf("entré le nombre de ligne que vous voulez : ");
  scanf("%d",&x);
  printf("entré le nombre de colonne que vous voulez : ");
  scanf("%d",&y);
  create_2darray_bis(&tab,x,y);
  fill_2darray(tab,x,y);
  disp_2darray(tab,x,y);
  freeA(tab);
}


void create_2darray_bis(int ***A, int L, int C) // on cree un tableaux a 2 dimension qui va contenir le "plateaux de jeux"
{

    if(*A==NULL) // on verifie que l'allocation memoire a bien reussie
        printf("Erreur malloc ");

  *A = (int **)malloc(sizeof(int*) * L); // allocation memoire dynamique en fonction du nombre de ligne
    for (int i = 0; i < L; i++)
    {
      (*A)[i] = (int *)malloc(C * sizeof(int)); // allocation memoire dynamique en fonction du nombre de colonne
    }
}

void fill_2darray(int **A, int L, int C) // fonction qui remplit le plateaux de nombre aleatoire comprit entre 15 et 0
{
  int count_j;
  int count_i;
  for (int i = 0; i <  L; i++)
    {
      usleep(5000);
        for (int j = 0; j < C; j++)
        {


            for(int count = 1; count < 20; count ++)
                {

                    if (i == L - 1 && j == C - 1)
                    {
                        A[i][j] = 0; // permet de remplacer la derniere case du tableaux par 0 pour pouvoir jouer
                    }
                    else
                        A[i][j]=(rand()%15)+1;// remplit la case du tableaux avec un nombre aleatoire generer par rand entre 15 et 0
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
            printf("[%d] ", A[i][j]); // affiche le contenus de la Ligne i et de la Colonne j
        }
        printf("\n");
    }
}

void freeA(int **A) // libere l'espace allouer au tableaux
{
    free(A); // permet de librere l'espace memoire du tableaux a la fin du programme
}
