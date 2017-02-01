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

// returns a specific prime located at *index* in a list
// of all prime numbers
int genPrime(int index)
{
  int count = index * 15;
  char* list = malloc(count);

  int i;
  int j;
  int val;
  int root = sqrt(count);

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

  i = 2;
  val = 0;
  while(val != index)
  {
    if (*(list + i))
    {
      val++;
    }
    i++;
  }

  free(list);

  return i - 1;
}
