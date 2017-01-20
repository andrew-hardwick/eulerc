#include "p001_020.h"
#include <stdio.h>

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

// Problem 3 - Largest Prime Factor
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
    default:
      return &p001;
  } 
}
