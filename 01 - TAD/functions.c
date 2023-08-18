#include <stdio.h>
#include "conjunto.h"

void inicializar(t_conjunto A)
{
  int i;
  for (i = 0; i <= maximo; i++)
  {
    A[i] = 0;
  }
}

static int esta_nos_limites(t_elemento e)
{
  return e >= 0 && e <= maximo;
}

static int pertence(t_elemento e, t_conjunto A)
{
  return A[e];
}

int inserir(t_elemento e, t_conjunto A)
{

  if (!esta_nos_limites(e))
  {
    printf("Elemento invalido\n");
    return INVALIDO;
  }

  if (pertence(e, A))
  {
    printf("Ja pertence ao conjunto\n");
    return JA_EXISTE;
  }

  A[e] = 1;
  return SUCESSO;
}

int remover(t_elemento e, t_conjunto A)
{
  if (!esta_nos_limites(e))
  {
    printf("Elemento invalido\n");
    return INVALIDO;
  }

  if (!pertence(e, A))
  {
    printf("Nao pertence ao conjunto\n");
    return NAO_EXISTE;
  }

  A[e] = 0;
  return SUCESSO;
}

void interseccao(t_conjunto A, t_conjunto B, t_conjunto C)
{
  for (int i = 0; i <= maximo; i++)
  {
    C[i] = A[i] && B[i];
  }
  return;
}

void uniao(t_conjunto A, t_conjunto B, t_conjunto C)
{
  for (int i = 0; i <= maximo; i++)
  {
    C[i] = A[i] || B[i];
  }
  return;
}

void imprimir(t_conjunto A)
{
  int i;
  for (i = 0; i <= maximo; i++)
  {
    if (pertence(i, A))
    {
      printf("%d ", i);
    }
  }
  printf("\n");
}