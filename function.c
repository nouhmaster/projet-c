#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "function.h"

int hauteur = 1;
int largeur = 1;



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

void test(int ** A, int L, int C, struct Pos * pos)
{
    int temp;
    for (int i = (L*C) - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (A[(j + 1)/C][(j + 1)%C] < A[j/C][j%C])//tri a bull d'un tableau 2d
             {
                printf("le jeux continue:\n");
                moove(A,hauteur,largeur,pos);
            }
        }
    }
    printf("gg tu a reussi\n");
    freeA(A);
    rejouer();
}





void freeA(int **A) // libere l'espace allouer au tableaux
{
    free(*A); // permet de librere l'espace memoire du tableaux a la fin du programme
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
    disp_2darray(A,largeur,hauteur);
    test(A,hauteur,largeur,pos);
}
void droite(int ** A, int L, int C, struct Pos * pos) {
    int temps; // 1 2 3
    temps = A[pos -> y][pos -> x]; //2
    pos -> x++;
    pos -> x = moduloPositif(pos -> x,C);
    A[pos -> y][moduloPositif(pos -> x - 1, C)] = A[pos -> y][pos -> x]; // 2 -> 1
    A[pos -> y][pos -> x] = temps;
    disp_2darray(A,largeur,hauteur);
    test(A,hauteur,largeur,pos);
}
void gauche(int ** A, int L, int C, struct Pos * pos) {
    int temps; // 1 2 3
    temps = A[pos -> y][pos -> x]; //2
    pos -> x--;
    pos -> x = moduloPositif(pos -> x,C);
    A[pos -> y][moduloPositif(pos -> x + 1,C)] = A[pos -> y][pos -> x]; // 2 -> 1
    A[pos -> y][pos -> x] = temps;
    disp_2darray(A,largeur,hauteur);
    test(A,hauteur,largeur,pos);

}
void bas(int ** A, int L, int C, struct Pos * pos) {
    int temps; // 1 2 3
    temps = A[pos -> y][pos -> x]; //2
    pos -> y++;
    pos -> y = moduloPositif(pos -> y,L);
    A[moduloPositif(pos -> y - 1,L)][pos -> x] = A[pos -> y][pos -> x]; // 2 -> 1
    A[pos -> y][pos -> x] = temps;
    disp_2darray(A,largeur,hauteur);
    test(A,hauteur,largeur,pos);
}
void moove(int ** A, int L, int C, struct Pos * pos)
{
    int x;
    printf("pour allez en haut mettre : 5,");
    printf(" en bas : 2,");
    printf(" a gauche : 1,");
    printf(" a droite : 3  = ");
    scanf("%d",&x);



    switch (x)
    {
    case 5:
        haut(A,hauteur,largeur,pos);
        break;
    case 2:
        bas(A,hauteur,largeur,pos);
        break;
    case 1:
        gauche(A,hauteur,largeur,pos);
        break;
    case 3:
        droite(A,hauteur,largeur,pos);
        break;
    default:
        moove(A,hauteur,largeur,pos);
        break;
    }

}
void choixdifficultes(int *hauteurptr,int *largeurptr)
{

     int x;
    printf("pour le mode debutant mettez 1 \n");
    printf("pour le mode experimenter mettez 2 \n");
    printf("pour le mode NIGHTMARE mettez 6 \n");
    printf("pour le mode ARMAGEDDON mettez le 66 \n");
    printf("pour le mode xXx Pro Game Master xXx mettez le 666 \n");
    scanf("%d",&x);



    switch (x)
    {
    case 1:
        *hauteurptr = 4;
        *largeurptr = 4;
        break;
    case 2:
        *hauteurptr = 8;
        *largeurptr = 8;
        break;
    case 6:
        *hauteurptr = 14;
        *largeurptr = 14;
        break;
    case 66:
        *hauteurptr = 29;
        *largeurptr = 29;
        break;
    case 666:
        *hauteurptr = 59;
        *largeurptr = 59;
        break;
    case 42:
        printf("allons bon vous conaissez deja la reponse au grand secret de l'univers vous pourrez donc aisement resoudre ceci \n");
        *hauteurptr = 659;
        *largeurptr = 659;
        break;
    case 0:
        printf("mode test activer \n");
        *hauteurptr = 1;
        *largeurptr = 1;
        break;

    default:
        choixdifficultes(&hauteur,&largeur);
        break;
    }


}
void rejouer()
{
    Pos *pos;
  pos = (Pos *) malloc(sizeof(Pos));

  pos->x = largeur-1;
  pos->y = hauteur-1;

    int x;
    printf("felecitation pour avoir gagner souhaitez vous rejouez ? 0 pour oui , 1 pour non \n");
    scanf("%d",&x);

    switch (x)
    {
    case 0 :
        choixdifficultes(&hauteur,&largeur);
        create_2darray_bis(&tab,largeur,hauteur);
        fill_2darray(tab,largeur,hauteur);
        disp_2darray(tab,largeur,hauteur);
        moove(tab,hauteur,largeur,pos);
        break;

    case 1 :
        break;

    default :
        rejouer();
        break;

    }
}
