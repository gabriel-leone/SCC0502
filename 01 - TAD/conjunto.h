#ifndef CONJUNTO_H
#define CONJUNTO_H

#define maximo 1024

typedef int t_elemento;
typedef t_elemento t_conjunto[maximo + 1];

#define NAO_EXISTE -1;
#define JA_EXISTE -2;
#define SUCESSO 1;
#define INVALIDO -3;

void inicializar(t_conjunto A);
// int esta_nos_limites(t_elemento e);
// int pertence(t_elemento e, t_conjunto A);
int inserir(t_elemento e, t_conjunto A);
int remover(t_elemento e, t_conjunto A);
void interseccao(t_conjunto A, t_conjunto B, t_conjunto C);
void uniao(t_conjunto A, t_conjunto B, t_conjunto C);
void imprimir(t_conjunto A);

#endif