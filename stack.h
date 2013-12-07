#ifndef STACK_H
#define STACK_H

#define MEMORY_ALLOCATE_ERROR 1488
#define ELEMENT_IS_NOT_LAST_ERROR 1543
#define UNDERFLOW_ERROR 1682

typedef struct _Element{
  struct _Element *next;
  struct _Element *prev;
  void *data;
} Element;

typedef struct {
  Element *root;
  Element *end;
} Stack;

Stack *initializeStack(int *error);
int pop(Stack *stack);
int push(Stack *stack, void *data);
void *peak(Stack *stack);
int deleteStack(Stack **stack);

#endif // STACK_H
