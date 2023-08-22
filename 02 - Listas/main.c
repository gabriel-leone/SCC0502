#include <stdio.h>
#include <string.h>
#include "lista.h"

int main() {
  t_lista l;
  t_elemento e;

  criar(&l);

  e.chave = 247;
  strcpy(e.nome, "Joao");
  inserir(e, &l);

  e.chave = 123;
  strcpy(e.nome, "Maria");
  inserir(e, &l);

  for (int i = 0; i < MAX; i++) {
    e.chave = i;
    strcpy(e.nome, "Nome");
    inserir(e, &l);
  }

  remover(247, &l);

  imprimir(&l);
}