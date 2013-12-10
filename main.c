#include "bigNum.h"
#include "notations.h"
#include <stdlib.h>
#include <stdio.h>

void printOpList(OpList *list) {
  int error = 0;
  char func_list[] = {'(',')','+','-','*','/','^','-'};

  while (list) {
    switch (list->operand.type) {
    case NONE:
      printf("NONE\n");
      break;
    case NUM:
      printf("NUM: \"%s\"\n",BigNumToString(list->operand.data.num,&error));
      break;
    case FUNC:
      printf("FUNC: \"%c\"\n",func_list[list->operand.data.func]);
      break;
    case VAR:
      printf("VAR: \"%s\"\n",list->operand.data.varName);
      break;
    default:
      printf("UNKNOWN");
    }
    list = list->next;
  }

  printf("Error: %d\n",error);
}

int main(void)
{
  OpList *list = NULL;
  int error = 0;

//  list = getOpListByStr("123",&error);
  list = getOpListByStr("1234+xxx/(abs^3456f-fuck*3)+((34-3)-(2-1))",&error);
  printOpList(list);

  return 0;
}

