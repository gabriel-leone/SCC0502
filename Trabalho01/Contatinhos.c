#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SKIPLIST_MAX_LEVEL 6

typedef struct snode
{
  char name[50]; // Chave: nome da pessoa
  int number;    // Valor: número de telefone
  struct snode **forward;
} snode;

typedef struct skiplist
{
  int level;
  int size;
  struct snode *header;
} skiplist;

skiplist *skiplist_init(skiplist *list)
{
  int i;

  snode *header = (snode *)malloc(sizeof(snode));
  list->header = header;
  strcpy(header->name, "");
  header->forward = (snode **)malloc(sizeof(snode *) * (SKIPLIST_MAX_LEVEL + 1));

  for (i = 0; i <= SKIPLIST_MAX_LEVEL; i++)
  {
    header->forward[i] = list->header;
  }

  list->level = 1;
  list->size = 0;

  return list;
}

static int rand_level()
{
  int level = 1;
  while (rand() < RAND_MAX / 2 && level < SKIPLIST_MAX_LEVEL)
    level++;
  return level;
}

int skiplist_insert(skiplist *list, char name[50], int number)
{
  snode *update[SKIPLIST_MAX_LEVEL + 1];
  snode *x = list->header;
  int i, level;
  for (i = list->level; i >= 1; i--)
  {
    while (x->forward[i] != list->header && strcmp(x->forward[i]->name, name) < 0)
      x = x->forward[i];
    update[i] = x;
  }
  x = x->forward[1];
  if (x != list->header && strcmp(x->name, name) == 0)
  {
    return 1; // Contato já existe, retornar 1
  }
  else
  {
    level = rand_level();
    if (level > list->level)
    {
      for (i = list->level + 1; i <= level; i++)
      {
        update[i] = list->header;
      }
      list->level = level;
    }
    x = (snode *)malloc(sizeof(snode));
    strcpy(x->name, name);
    x->number = number;
    x->forward = (snode **)malloc(sizeof(snode *) * (level + 1));
    for (i = 1; i <= level; i++)
    {
      x->forward[i] = update[i]->forward[i];
      update[i]->forward[i] = x;
    }
    return 0; // Contato inserido com sucesso, retornar 0
  }
}

snode *skiplist_search(skiplist *list, char name[50])
{
  snode *x = list->header;
  int i;
  for (i = list->level; i >= 1; i--)
  {
    while (x->forward[i] != list->header && strcmp(x->forward[i]->name, name) < 0)
      x = x->forward[i];
  }
  x = x->forward[1];
  if (x != list->header && strcmp(x->name, name) == 0)
  {
    return x;
  }
  else
  {
    return NULL;
  }
}

static void skiplist_node_free(snode *x)
{
  if (x)
  {
    free(x->forward);
    free(x);
  }
}

int skiplist_delete(skiplist *list, char name[50])
{
  int i;
  snode *update[SKIPLIST_MAX_LEVEL + 1];
  snode *x = list->header;
  for (i = list->level; i >= 1; i--)
  {
    while (strcmp(x->forward[i]->name, name) < 0)
      x = x->forward[i];
    update[i] = x;
  }
  x = x->forward[1];
  if (strcmp(x->name, name) == 0)
  {
    for (i = 1; i <= list->level; i++)
    {
      if (update[i]->forward[i] != x)
        break;
      update[i]->forward[i] = x->forward[i];
    }
    skiplist_node_free(x);
    while (list->level > 1 && list->header->forward[list->level] == list->header)
      list->level--;
    return 0;
  }
  return 1;
}

int skiplist_change(skiplist *list, char name[50], int number)
{
  snode *node = skiplist_search(list, name);
  if (node != NULL)
  {
    node->number = number;
    return 0;
  }
  else
  {
    return 1;
  }
}

int main() {
    srand((unsigned int)time(NULL));
    skiplist list;
    skiplist_init(&list);
    char input[256];
    char name[50];
    int number;

    while (fgets(input, sizeof(input), stdin) != NULL) {
        char command;
        if (sscanf(input, " %c", &command) != 1) {
            printf("Comando inválido: %s", input);
            continue;
        }

        if (command == '0' || command == '0') {
            // Saída quando o programa termina
            break;
        }

        if (command == 'I' || command == 'i') {
            if (sscanf(input, " %*c %49s %d", name, &number) != 2) {
                printf("Entrada inválida: %s", input);
                continue;
            }
            int result = skiplist_insert(&list, name, number);
            if (result == 0) {
                // Contato inserido com sucesso
            } else {
                printf("Contatinho ja inserido\n");
            }
        } else if (command == 'P' || command == 'p') {
            if (sscanf(input, " %*c %49s", name) != 1) {
                printf("Entrada inválida: %s", input);
                continue;
            }
            snode *node = skiplist_search(&list, name);
            if (node != NULL) {
                printf("Contatinho encontrado: telefone %d\n", node->number);
            } else {
                printf("Contatinho nao encontrado\n");
            }
        } else if (command == 'R' || command == 'r') {
            if (sscanf(input, " %*c %49s", name) != 1) {
                printf("Entrada inválida: %s", input);
                continue;
            }
            int result = skiplist_delete(&list, name);
            if (result == 0) {
                // Contato excluído com sucesso
            } else {
                printf("Operacao invalida: contatinho nao encontrado\n");
            }
        } else if (command == 'A' || command == 'a') {
            if (sscanf(input, " %*c %49s %d", name, &number) != 2) {
                printf("Entrada inválida: %s", input);
                continue;
            }
            int result = skiplist_change(&list, name, number);
            if (result == 0) {
                // Contato alterado com sucesso
            } else {
                printf("Operacao invalida: contatinho nao encontrado\n");
            }
        } else {
            printf("Comando desconhecido: %c\n", command);
        }
    }

    return 0;
}