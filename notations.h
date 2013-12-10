#ifndef NOTATIONS_H
#define NOTATIONS_H

#include "notations.h"
#include "bigNum.h"
#include <stdlib.h>

#define E_STRING_DOES_NOT_EXIST (8015)
#define E_VAR_NAME_TOO_LONG (0165)

#define NONE (0)
#define NUM (1)
#define FUNC (2)
#define VAR (3)

#define BRACK_OP (0)
#define BRACK_CL (1)
#define ADD (2)
#define DIF (3)
#define MUL (4)
#define DIV (5)
#define DEG (6)
#define UNDIF (7)

typedef struct _Operand {
  int type;
  union {
    BigNum *num;
    char *varName;
    int func;
  } data;
} Operand;

typedef struct _OpList {
  Operand operand;
  struct _OpList *next;
} OpList;

void test();
OpList *getOpListByStr(char *s, int *error);

#endif // NOTATIONS_H
