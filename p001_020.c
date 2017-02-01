#include "p001_020.h"
#include <stdio.h>
#include <stdlib.h>

// Problem 1 - Multiples of 3 and 5
long p001()
{
  int out = 0;
	
  // i is the index value of the for loop
  int i = 0;
  for(i = 0; i < 1000; i++)
  {
    //sum values that are divisible by 3 and 5
    if(i % 3 == 0 || i % 5 == 0)
    {
      out += i;
    }
  }
  return out;
}

// Problem 2 - Even Fibonacci numbers
long p002()
{
  int out = 0;

  // fibonacci variables
  int f1 = 1;
  int f2 = 1; 

  // loop until the sequence is at 4000000
  while (f1 < 4000000){
    // sum the even entries
    if (f1 % 2 == 0)
    {
      out += f1;
    }

    // compute the next entry in the sequence
    f2 = f1 + f2;
    f1 = f2 - f1;
  }
  return out;
}

// Problem 3 - Largest prime Factor
long p003()
{
  //i counting, val is target, root is count limit
  long i;
  long val = 600851475143;
  long root = sqrt(val); 
 
  //only have to loop root times
  for(i = root; i > 0; i--)
  {
    //if i is a factor of val
    if (val % i == 0)
    {
      //check if it's prime
      if (isPrime(i))
      {
        return i;
      }
    }     
  }
  return 0;
}

// Problem 4 - Largest palindrome product
long p004()
{
  //i and j are the operands
  int i, j;
  //pal will store the product
  int pal;
  //largest will store the largest palindrome product we've found
  int largest = 0;

  //only need three digit numbers
  for(i = 999; i > 99; i--)
  {
    //loop down from i to reduce computations
    for(j = i; j > 99; j--)
    {
      //multiply
      pal = i * j;

      //check if the product is a palindrome
      if (isPalindrome(pal))
      {
        if (largest < pal)
        {
          largest = pal;
        }
      }
    }
  }
  return largest;
}

// Problem 5 - Smallest multiple
long p005()
{
  int i, j;
  int num;
  int *list = malloc(20 * sizeof(int));
  for(i = 0; i < 20; i++)
  {
    *(list + i) = 0;
  }

  for(i = 2; i <= 20; i++)
  {
    num = i;
    j = 0;
    while(num != 1)
    {
      if (*(list + j) == 0)
      {
        *(list + j) = num;
        num = 1;
      }
      else
      {
        if (num % *(list + j) == 0)
        {
          num = num / *(list + j);
        }
        j++;
      }
    }
  } 
  
  i = 0;
  num = 1;
  while(*(list + i))
  { 
    num *= *(list + i);
    i++;
  }

  free(list);
  return num;
}

// Problem 6 - Sum square difference
long p006()
{
  //sumsquare will be the sum of squares
  int sumsquare = 0;
  //squaresum will be the square of sums
  int squaresum = 0;
  
  //i is counting variable
  int i;

  //loop through once
  for(i = 1; i <= 100; i++)
  {
    sumsquare += (i * i);
    squaresum += i;
  } 

  //square the sum
  squaresum = squaresum * squaresum;

  //return the difference
  return squaresum - sumsquare;
}

// Problem 7 - 10001st prime
long p007()
{
  //genPrime is a common function as it might be used later
  return genPrime(10001);
}

//Problem 8 - Largest product in a series
long p008()
{
  //open file to read in sequence
  FILE* p8in = fopen("p8","r");

  //allocate memory (file known to contain 1000 digits)
  int * arr = malloc(sizeof(int) * 1000);

  //variables
  int i = 0;
  long largest = 0;
  long current = 0;
  int j = 0;

  //read in data from file
	for(i = 0; i < 1000; i++)
  {
    *(arr + i) = fgetc(p8in) - '0';
  } 

  fclose(p8in);

  //start from begginning and compute to last 13 long sequence
  for(i = 0; i < 987; i++)
  {
    //init current each time through loop
    current = 1;
    //compute the 13 long product
    for(j = i; j < i + 13; j++)
    {
      //if we find a zero just stop computing
      //we should be able to jump i forware here
      if(*(arr + j) == 0)
      {
        break;
      }
      //cumulative multiplication
      current *= *(arr + j);
    }
    //update largest is necessary
    if (current > largest)
    {
      largest = current;
    }
  }

  free(arr);

  return largest;
}

//Problem 9 - Special Pythagorean triplet
long p009()
{
  //variables
  int a, b, c;

  //for solution a < b < c

  //since two entries must be greater than a it is bounded by 1/3 of 1000
  for(a = 1; a < 334; a++)
  {
    //since one entry must be greater than b it is bounded by 1/2 of 1000
    for(b = a + 1; b < 501; b++)
    {
      //c is computed based on the rule that a+b+c=1000
      c = (1000 - a) - b;

      //check for pythagorean triplet
      if ((a * a) + (b * b) == (c * c))
      {
        return a * b * c;
      } 
    }
  }

  return 0;
}

// Provide the expected result for formatting in main
long p001_020_expected(int index)
{
  switch(index)
  {
    case 1:
      return 233168;
    case 2:
      return 4613732;
    case 3:
      return 6857;
    case 4:
      return 906609;
    case 5:
      return 232792560;
    case 6:
      return 25164150;
    case 7:
      return 104743;
    case 8:
      return 23514624000;
    case 9:
      return 31875000;
    default:
      return 0;
  }
}

// return the function pointer for a specific problem
long (*p001_020_select(int index))()
{
  switch (index)
  {
    case 1:
      return &p001;
    case 2:
      return &p002;
    case 3:
      return &p003;
    case 4:
      return &p004;
    case 5:
      return &p005;
    case 6:
      return &p006;
    case 7:
      return &p007;
    case 8:
      return &p008;
    case 9:
      return &p009;
    default:
      return &p001;
  } 
}
