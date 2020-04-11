#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

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
void droite(int **A,int L,int C,struct Pos *pos);
void gauche(int **A,int L,int C,struct Pos *pos);
void bas(int **A,int L,int C,struct Pos *pos);
void haut(int **A,int L,int C,struct Pos *pos);


#endif // FUNCTION_H_INCLUDED
