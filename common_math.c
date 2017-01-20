#include "common_math.h"
#include <math.h>

int isPrime(int num)
{
  int root = sqrt(num);
  int i;

  for (i = 2; i < root; i++)
  {
    if (num % i == 0)
    {
      return 0;
    }
  }
  return 1;
}
