#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#define LARGEUR 4
#define HAUTEUR 4

typedef struct Pos
{
  int x;
  int y;
}Pos;

int moduloPositif(int vakeur,int modulo);
void fill_2darray(int **A, int L, int C);
int ** create_2darray(int L, int C);
void create_2darray_bis(int ***A, int L, int C);
void disp_2darray(int **A,int L,int C);
void freeA(int ** A);
void test(int ** A, int L, int C, struct Pos * pos);
void droite(int **A,int L,int C,struct Pos *pos);
void gauche(int **A,int L,int C,struct Pos *pos);
void bas(int **A,int L,int C,struct Pos *pos);
void haut(int **A,int L,int C,struct Pos *pos);
void moove(int ** A, int L, int C, struct Pos * pos);
//void triABulle2D(int ** tab, int T, int T2);




#endif // FUNCTION_H_INCLUDED
