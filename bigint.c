#include "bigint.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

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
