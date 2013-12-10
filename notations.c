#include "notations.h"

#define elif else if

static int _operations[256] = {0,0};
static int _types[256] = {0,0};

int getOperate(int ch) {
  if (!_operations[1]) {
    memset(_operations,0,256);
    _operations['('] = BRACK_OP;
    _operations[')'] = BRACK_CL;
    _operations['+'] = ADD;
    _operations['-'] = DIF;
    _operations['*'] = MUL;
    _operations['/'] = DIV;
    _operations['^'] = DEG;
    _operations[1] = 0;
  }

  return _operations[ch];
}

int getType(int ch) {
  int i = 0;
  if(!_types[1]) {
    memset(_types,0,256);
    for(i='0';i<='9';i++)
      _types[i] = NUM;

    _types['('] = FUNC;
    _types[')'] = FUNC;
    _types['+'] = FUNC;
    _types['-'] = FUNC;
    _types['*'] = FUNC;
    _types['/'] = FUNC;
    _types['^'] = FUNC;
    for(i='a';i<='z';i++)
      _types[i] = VAR;
    for(i='A';i<='Z';i++)
      _types[i] = VAR;
    _types[1] = 1;
  }

  return _types[ch];
}

#define NEWLIST(__list) \
  (__list)->next = calloc(1,sizeof(OpList));\
  (__list) = (__list)->next;

OpList *getOpListByStr(char *s, int *error) {
  char *ch = NULL;
  *error = 0;
  int pType = NONE, nType = NONE;
  int varNameLen = 0;
  OpList *list = NULL, *root = NULL;
  Operand *op = NULL;
  BigNum *ten = intToBigNum(10,error), *dig = intToBigNum(5,error);

  if (!s) {
    *error = E_STRING_DOES_NOT_EXIST;
    return NULL;
  }

  ch = s;

  root = calloc(1,sizeof(OpList));
  list = root;

  while (*ch) {
    pType = nType;
    nType = getType(*ch);
    op = &(list->operand);

    if ((pType != NUM) && (nType == NUM)) {
      op->data.num = newBigNum(error);
      op->type = NUM;
    }

    if ((pType != VAR) && (nType == VAR)) {
      op->data.varName = calloc(sizeof(char),256);
      varNameLen = 0;
      op->type = VAR;
    }

    if (pType == NUM) {
      if (nType == NUM) {
        mul(op->data.num,ten,0,error);
        dig->digits[0] = *ch++ - '0'; // грязный хак
        add(op->data.num,dig,0,error);
      } else {
        NEWLIST(list);
      }
    } elif (pType == VAR) {
      if (nType == VAR) {
        op->data.varName[varNameLen++] = *ch++;
        if (255 == varNameLen) {
          *error = E_VAR_NAME_TOO_LONG;
          return root;
        }
      } else {
        NEWLIST(list);
      }
    } elif (nType == FUNC) {
      op->data.func = getOperate(*ch++);
      op->type = FUNC;
      NEWLIST(list);
    }
  }

  deleteBigNum(ten);
  deleteBigNum(dig);

  return root;
}
