#ifndef BigNum_H
#define BigNum_H
#include <stdlib.h>

#define MEMORY_ALLOCATE_ERROR (1488)
#define PARSE_STRING_ERROR (8291)
#define NOT_BIG_NUM (7201)
#define DIVISION_BY_ZERO (8359)
#define AMOREB (-1)
#define BMOREA (1)
#define AEQB (0)
#define TESTS

/* sig -- -1 -- negative, 1 -- positive
 * len -- number of cell in the digits
 * digits[0] -- low-order digit,
 * digits[NUM_DIGITS-1] -- high-erder digit */
typedef struct {
  signed char sig;
  size_t len;
  signed char *digits;
} BigNum;

BigNum *newBigNum(int *error);
void deleteBigNum(BigNum *num);
void null(BigNum *num, int *error);
int compare(BigNum *a, BigNum *b);
int compare_abs(BigNum *a, BigNum *b);
void normalize(BigNum *num, int *error);
BigNum *stringToBigNum(char *s, int *error);
char *BigNumToString(BigNum *num, int *error);
BigNum *add(BigNum *a, BigNum *b, int isReturn, int *error);
BigNum *dif(BigNum *a, BigNum *b, int isReturn, int *error);
BigNum *mul(BigNum *a, BigNum *b, int isReturn, int *error);
BigNum *divd(BigNum *_a, BigNum *_b, int isReturn, int *error);
BigNum *mod(BigNum *_a, BigNum *_b, int isReturn, int *error);
BigNum *deg(BigNum *a, BigNum *b, int isReturn, int *error);
BigNum *unDif(BigNum *a, int isReturn, int *error);

#ifdef TESTS
#include <stdio.h>
#include <string.h>
void BigNum_tests();
#endif


#endif // BigNum_H
