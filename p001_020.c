#include "p001_020.h"
#include <stdio.h>
#include <stdlib.h>

// Problem 1 - Multiples of 3 and 5
int p001()
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
int p002()
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
int p003()
{
  long i;
  long val = 600851475143;
  long root = sqrt(val); 
  
  for(i = root; i > 0; i--)
  {
    
    if (val % i == 0)
    {
      if (isPrime(i))
      {
        return i;
      }
    } 
  }
  return 0;
}

// Problem 4 - Largest palindrome product
int p004()
{
  int i, j;
  int pal;
  int largest = 0;
  for(i = 999; i > 99; i--)
  {
    for(j = i; j > 99; j--)
    {
      pal = i * j;
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
int p005()
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
int p006()
{
  int sumsquare = 0;
  int squaresum = 0;
  
  int i;

  for(i = 1; i <= 100; i++)
  {
    sumsquare += (i * i);
    squaresum += i;
  } 

  squaresum = squaresum * squaresum;

  return squaresum - sumsquare;
}

// Problem 7 - 10001st prime
int p007()
{
  return genPrime(10001);
}

// Provide the expected result for formatting in main
int p001_020_expected(int index)
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
    default:
      return 0;
  }
}

// return the function pointer for a specific problem
int (*p001_020_select(int index))()
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
    default:
      return &p001;
  } 
}
