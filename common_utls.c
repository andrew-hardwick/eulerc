#include "common_utls.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

//this value is tuned to the lowest value that still adequately solves the primes problems
#define GEN_PRIME_LENGTH_MULTIPLIER 11

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

  for(i = 0; i <= order / 2; i++)
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

// returns a list of prime numbers at least *index* long
char * genPrime(long index)
{
  long count = index * GEN_PRIME_LENGTH_MULTIPLIER;
  char* list = malloc(count);

  long i;
  long j;
  long val;
  long root = sqrt(count);

  for(i = 0; i < count; i++)
  {
		*(list + i) = 0x1;
  }

  for(i = 2; i < root; i++)
  {
    if (*(list + i))
    {
      for(j = i * i; j < count; j += i)
      {
        *(list + j) = 0x0;
      }
    }
  }

  *(list + 0) = 0x0;
  *(list + 1) = 0x1;

  return list;
}

// returns count of factors
int numFactors(long val)
{
  int count = 0;
  int i;

  //only have to test to sqrt of val and then double the factors
  double root = sqrt(val);
  for(i = 1; i <= root; i++)
  {
    if (val % i == 0)
    {
      count++;
    }
  }

  //assumption is made that the number is not a clean square
  return count * 2;
}
