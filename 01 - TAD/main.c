#include <stdio.h>
#include "conjunto.h"

int main()
{
  t_conjunto A;
  t_conjunto B;
  t_conjunto C;

  inicializar(A);
  inicializar(B);
  inicializar(C);

  inserir(42, A);
  inserir(124, A);
  inserir(375, A);
  inserir(1, B);
  inserir(50, B);
  inserir(2, B);
  inserir(125, B);
  inserir(42, B);
  inserir(124, B);

  imprimir(A);
  imprimir(B);

  printf("INTERSECCAO: ");
  interseccao(A, B, C);
  imprimir(C);

  printf("UNIAO: ");
  uniao(A, B, C);
  imprimir(C);
}
