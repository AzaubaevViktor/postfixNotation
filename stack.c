#include "stack.h"
#include <stdlib.h>

static Element *initializeElement(){
  return (Element *) calloc(sizeof(Element),1);
}

static void bindElements(Element *parent,Element *child) {
  parent->next = child;
  child->prev = parent;
}

Stack *initializeStack(int *error) {
  Stack *stack = (Stack *) calloc(sizeof(Stack),1);
  *error = 0;

  if (!stack) {
    *error = MEMORY_ALLOCATE_ERROR;
    return NULL;
  }

  return stack;
}

int pop(Stack *stack) {
  Element *elem = 0;

  if (!(stack->end))
    return UNDERFLOW_ERROR;

  elem = stack->end;

  if (stack->end == stack->root)
    stack->root = 0;

  if (stack->end)
    stack->end = stack->end->prev;

  if (elem->next)
    return ELEMENT_IS_NOT_LAST_ERROR;

  if (elem->prev)
    (elem->prev)->next = 0;


  if (elem->data)
    free(elem->data);

  free(elem);

  return 0;
}

int push(Stack *stack, void *data) {
  Element *elem = initializeElement();
  if (!elem)
    return MEMORY_ALLOCATE_ERROR;

  elem->data = data;

  if (stack->end)
    bindElements(stack->end,elem);

  if (!(stack->root))
    stack->root = elem;

  stack->end = elem;

  return 0;
}

void *peak(Stack *stack) {
  return stack->end->data;
}

int deleteStack(Stack **stack){
  Element *elem = (*stack)->root, *prevElem = 0;
  while (elem) {
    prevElem = elem;
    elem = elem->next;
    free(prevElem);
  }
  free(*stack);
  *stack = 0;
  return 0;
}
