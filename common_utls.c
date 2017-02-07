#include "common_utls.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

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

// allocate a big int and fill it with zero
BIGINT allocateBigInt()
{
  int* ret = malloc(sizeof(int) * BIGINT_LENGTH);
  int i = 0;

  for(i = 0; i < BIGINT_LENGTH; i++)
  {
    *(ret + i ) = 0;
  }

  return ret;
}

// convert a c stringt to bigint (allocates)
BIGINT convertStringToBigInt(char* input, int length)
{
  int* ret = allocateBigInt();
  int i, j;

  int numCharsInCell = log10(BIGINT_CELL);
  int numCells = (length / numCharsInCell);
  int chOffset = 0;
  int chLoc = 50;

  // convert
  for(i = 0; i < numCells; i++)
  {
    chOffset = 0;
    for(j = 0; j < numCharsInCell; j++)
    {
      *(ret + i) *= 10;
      *(ret + i) += *(input + (chLoc - (numCharsInCell - chOffset))) - '0';

      chOffset++;
    }
    chLoc -= numCharsInCell;
  } 
  
  chOffset = 0;

  while(chLoc > 0)
  {
    *(ret + i) *= 10;
    *(ret + i) += *(input + chOffset) - '0';
    chOffset++;
    chLoc--;
  }

  return ret;
}

// multiply a BIGINT by a scalar integer value
// returns 1 if scalar is too big
int multiplyBigIntByScalar(BIGINT target, int scalar)
{
  int i;
  if (INT_MAX / BIGINT_CELL < scalar)
  {
    return 1;
  }

  for(i = 0; i < BIGINT_LENGTH; i++)
  {
    *(target + i) = *(target + i) * scalar;
  }

  balanceBigInt(target);
  return 0;
}

void addBigInt(BIGINT op1, BIGINT op2)
{
  int i = 0; 
  for(i = 0; i < BIGINT_LENGTH; i++)
  {
    *(op1 + i) = *(op1 + i) + *(op2 + i);
  }

  balanceBigInt(op1);
}

void printBigInt(BIGINT val)
{
  int i;
  for(i = BIGINT_LENGTH - 1; i >= 0; i--)
  {
    printf("%d", *(val + i));
  }
  printf("\n");
}

void balanceBigInt(BIGINT val)
{
  int i;
  int carry = 0;

  for(i = 0; i < BIGINT_LENGTH - 1; i++)
  {
    if (*(val + i) > BIGINT_CELL)
    {
      carry  = *(val + i) / BIGINT_CELL;
      *(val + i) = *(val + i) % BIGINT_CELL;
      *(val + i + 1) += carry;
    }
  }
  
  *(val + (BIGINT_LENGTH - 1)) = *(val + (BIGINT_LENGTH - 1)) % BIGINT_CELL;
}
