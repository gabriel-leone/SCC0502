#include <stdio.h>
#include <stdlib.h>

#define MAX_OPERATIONS 110

typedef struct
{
  int data[MAX_OPERATIONS];
  int top;
} Stack;

typedef struct
{
  int data[MAX_OPERATIONS];
  int front;
  int rear;
} Queue;

void initStack(Stack *stack)
{
  stack->top = -1;
}

void push(Stack *stack, int item)
{
  stack->data[++stack->top] = item;
}

int pop(Stack *stack)
{
  return stack->data[stack->top--];
}

void initQueue(Queue *queue)
{
  queue->front = 0;
  queue->rear = -1;
}

void enqueue(Queue *queue, int item)
{
  queue->data[++queue->rear] = item;
}

int dequeue(Queue *queue)
{
  return queue->data[queue->front++];
}

int main()
{
  int quantidadeArrays;
  scanf("%d", &quantidadeArrays);

  for (int i = 0; i < quantidadeArrays; i++)
  {
    int tamanhoArray;
    scanf("%d", &tamanhoArray);

    Stack stack;
    Queue queue;
    initStack(&stack);
    initQueue(&queue);

    int isStack = 1;
    int isQueue = 1;

    for (int j = 0; j < tamanhoArray; j++)
    {
      char operacao;
      int valor;
      scanf(" %c %d", &operacao, &valor);

      if (isStack)
      {
        if (operacao == 'i')
        {
          push(&stack, valor);
        }
        else
        { // operação de remoção
          if (stack.top == -1 || pop(&stack) != valor)
          {
            isStack = 0;
          }
        }
      }

      if (isQueue)
      {
        if (operacao == 'i')
        {
          enqueue(&queue, valor);
        }
        else
        { // operação de remoção
          if (queue.front > queue.rear || dequeue(&queue) != valor)
          {
            isQueue = 0;
          }
        }
      }
    }

    if (!isStack && !isQueue)
    {
      printf("impossivel\n");
    }
    else if (isStack && !isQueue)
    {
      printf("pilha\n");
    }
    else if (!isStack && isQueue)
    {
      printf("fila\n");
    }
    else
    {
      printf("indefinido\n");
    }
  }

  return 0;
}