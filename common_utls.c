#include "common_utls.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

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

int isPalindrome(int num)
{
  int order = log10l(num);

  int* pal = malloc(order * sizeof(int));

  int i = 0;

  while(num)
  {
    *(pal + i)  = num % 10;

    num = num / 10;
    i++;
  }

  for(i = 0; i < order / 2; i++)
  {
    if (*(pal + i) != *(pal + (order - i)))
    {
      free(pal);
      return 0;
    }
  }

  free(pal);
  return 1;
}
