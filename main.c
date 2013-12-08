#include "bigNum.h"
#include <stdlib.h>
#include <stdio.h>


int main(void)
{
  int error = 0;
  BigNum *a = NULL, *b = NULL;


#ifdef BIGNUM_TESTS
    BigNum_tests();
#else
  a = stringToBigNum("99999999",&error);
  b = stringToBigNum("3000",&error);
  deg(a,b,0,&error);
#endif

  return 0;
}

