#include <stdio.h>
#include <stdlib.h>
#include "ListaDinamica.h"

int inicializar(t_lista *l) {
  l->primeiro = NULL;
  return SUCESSO;
}

int inserir(t_elemento e, t_lista *l) {
  t_apontador p = (t_apontador) malloc(sizeof(t_no));

  if(p == NULL) {
    printf("Memoria insuficiente");
    return CHEIA;
  }

  p->elemento = e;
  p->proximo = l->primeiro;
  l->primeiro = p;

  return SUCESSO;
}

int remover(t_chave chave, t_lista *l) {
  if (vazia(l)) {
    return VAZIA;
  }

  t_apontador p = l->primeiro;
  t_apontador aux;

  if (p->elemento.chave == chave) {
    aux = l->primeiro;
    l->primeiro = aux->proximo;
    free(aux);
    return SUCESSO;
  }

  while (p->proximo!=NULL) {

    if(p->proximo->elemento.chave == chave) {
      aux = p->proximo;
      p->proximo = aux->proximo;
      free(aux);
      return SUCESSO;
    }
    p = p->proximo;
  }

  printf("Elemento nao encontrado");
  return NAO_EXISTE;
}

t_elemento pesquisar(t_chave chave, t_lista *l) {

  t_apontador p = l->primeiro;

  while (p!=NULL) {
    if(p->elemento.chave == chave) {
      return p->elemento;
    }
    p = p->proximo;
  }
}

int vazia(t_lista *l) {
  if (l->primeiro == NULL) {
    return 1;
  }
  return 0;
}

void imprimir(t_lista *l) {
  t_apontador p = l->primeiro;

  while (p!=NULL) {
    printf("%d ", p->elemento.chave);
    p = p->proximo;
  }
  printf("\n");
}