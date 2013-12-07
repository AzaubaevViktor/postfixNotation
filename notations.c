#include "notations.h"
#include "bigNum.h"
#include <stdlib.h>


typedef struct _Operand {
  int type;
  union {
    int64_t num;
    int func;
  } data;
} Operand;

typedef struct _OpList {
  Operand operand;
  struct _OpList *next;
} OpList;

#define NONE 0
#define NUM 1
#define FUNC 2
#define VAR 3

#define BRACK_OP 0
#define BRACK_CL 1
#define ADD 2
#define DIF 3
#define MUL 4
#define DIV 5
#define DEG 6
#define UNADD 7
#define UNDIF 8

/*
static OpList *initList() {
  return calloc(sizeof(OpList),1);
}

OpList *stringToPrefix(const char *constpStr) {
  OpList *list_root = 0, *list = 0;
  bigNum num;
  int prev_type = NONE;
  char *pStr = (char *)constpStr;

  list = list_root = initList();

  while (*pStr) {
    switch (prev_type) {
    case NUM:
      list->operand.type = NUM;
      list->operand.data.num = num;

      list->next = initList();
      list = list->next;
      break;
    }

    switch (*pStr) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      if (NUM == prev_type) {
        num = num * 10 + (*pStr-'0');
      } else {
        prev_type = NUM;
        num = (*pStr-'0');
      }
      break;
    }
  }
}

int checkPrefixOpList(OpList *prefix);
OpList *prefixToPostfix(OpList *prefix);
int64_t postfixCalculate(OpList *postfix);

void test() {
  ;
}
*/
