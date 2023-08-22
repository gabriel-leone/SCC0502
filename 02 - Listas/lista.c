#include <stdio.h>
#include <string.h>
#include "lista.h"

// #define MAX 128

// #define SUCESSO 1
// #define NAO_EXISTE -1
// #define JA_EXISTE -2
// #define INVALIDO -3
// #define CHEIA -4
// #define VAZIA -5

// typedef int t_chave;

// typedef struct {
//   t_chave chave;
//   char nome[50];
// } t_elemento;

// typedef struct {
//   int ultimo;
//   t_elemento lista[MAX];
// } t_lista;

int criar(t_lista *l)
{
  l->ultimo = -1;
}

int inserir(t_elemento e, t_lista *l)
{
  // if (cheia(l))
  // {
  //   printf("A lista esta cheia!\n");
  //   return CHEIA;
  // }

  if (pesquisar(e.chave, l) != NAO_EXISTE)
  {
    printf("O elemento já existe!\n");
    return JA_EXISTE;
  }

  l->ultimo++;
  l->lista[l->ultimo] = e;
}

int remover(t_chave chave, t_lista *l)
{
  int pos = pesquisar(chave, l);
  if (pos == NAO_EXISTE)
  {
    return NAO_EXISTE;
  }

  for (int i = pos; i <= l->ultimo; i++)
  {
    l->lista[i] = l->lista[i + 1];
  }
}

int pesquisar(t_chave chave, t_lista *l)
{
  for (int i = 0; i <= l->ultimo; i++)
  {
    if (l->lista[i].chave == chave)
    {
      return i;
    }
    return NAO_EXISTE;
  }
}

int vazia(t_lista *l)
{
  if (l->ultimo == -1)
  {
    return 1;
  }
  return 0;
}

int cheia(t_lista *l)
{
  if (l->ultimo == MAX-1)
  {
    return 1;
  }
}

void imprimir(t_lista *l)
{
  for (int i = 0; i <= l->ultimo - 1; i++)
  {
    printf("%d %s\n", l->lista[i].chave, l->lista[i].nome);
  }
}