#include "p001_020.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bigint.h"

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
  char * primeList = genPrime(10001);

  int i = 1;
  int val = 0;

  //loop through and find the 10001st prime
  while (val != 10001)
  {
    i++;
    if (*(primeList + i))
    {
      val++;
    }
  }

  free(primeList);

  return i;
}

//Problem 8 - Largest product in a series
long p008()
{
  //open file to read in sequence
  FILE* p8in = fopen("pdata/p8","r");

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

//Problem 10 - Summation of primes
long p010()
{
  long index = 2000000;
  char* list = genPrime(index);

  long i = 2;
  long val = 0;
  long sum = 0;

  //loop through and sum all primes below 2000000
  while(i < index)
  {
    if(*(list + i))
    {
      sum += i;
      val++;
    }
    i++;
  } 

  free(list);

  return sum;
}

//Problem 11 - Largest product in a grid
long p011()
{
  //open file for reading
  FILE* p11in = fopen("pdata/p11","r");

  //i and j are counting variables
  int i, j;
  //array stores the data
  int* array = malloc(sizeof(int) * 400);

  long current = 0;
  long largest = 0;

  //read in the data from the file
  for(i = 0; i < 400; i++)
  {
    *(array + i) = (fgetc(p11in) - '0') * 10;
    *(array + i) += fgetc(p11in) - '0'; 
    fgetc(p11in);
  }

  //close the file
  fclose(p11in);

  //multiply and find the largest
  for(i = 3; i < 20; i++)
  {
    for(j = 3; j < 20; j++)
    {
      //only i direction (negative)
      current = *(array + j + (i * 20)) * *(array + j + ((i - 1) * 20)) * *(array + j + ((i - 2) * 20)) * *(array + j + ((i - 3) * 20)); 

      largest = current > largest ? current : largest;

      //both i and j directions (negative)
      current = *(array + j + (i * 20)) * *(array + (j - 1) + ((i - 1) * 20)) * *(array + (j - 2) + ((i - 2) * 20)) * *(array + (j - 3) + ((i - 3) * 20));

      largest = current > largest ? current : largest;

      //only j direction (negative)
      current = *(array + j + (i * 20)) * *(array + (j - 1) + (i * 20)) * *(array + (j - 2) + (i * 20)) * *(array + (j - 3) + (i * 20));

      largest = current > largest ? current : largest;

      //both i and j directions (i positive and j negative)
      if (i + 3 < 20)
      {
        current = *(array + j + (i * 20)) * *(array + (j - 1) + ((i + 1) * 20)) * *(array + (j - 2) + ((i + 2) * 20)) * *(array + (j - 3) + ((i + 3) * 20));

        largest = current > largest ? current : largest;
      }
    }
  }

  //free the temp array
  free(array);
  
  return largest;
}

//Problem 12 - Highly divisible triangular numberj
long p012()
{
  int i = 0;
  long num = 0;
  int count = 0;

  //looking for 500 factors
  while(count < 500)
  {
    num += i;
    i++;
    count = numFactors(num);
  }
  return num;
}

//Large sum
long p013()
{
  //open file for reading
  FILE* p11in = fopen("pdata/p13","r");

  //i and j are counting variables
  int i, j;
  //array stores the data
  char* buffer = malloc(sizeof(char) * 60);
  size_t bufLength = 60;

  BIGINT temp = allocateBigInt();

  long value = 0;
  int digitCount = 0;

  //read in the data from the file
  for(i = 0; i < 100; i++)
  {
    getline(&buffer, &bufLength, p11in);

    addBigInt(temp, convertStringToBigInt(buffer, 50));
  }

  i = BIGINT_LENGTH - 1;
  while(*(temp + i) == 0)
  {
    i--;
  }

  while(value < 10000000000)
  {
    value = value * BIGINT_CELL;
    value += *(temp + i);
    i--;
  }
  
  digitCount = log10(value);
  
  for(; digitCount >= 10; digitCount--)
  {
    value = value / 10;
  }

  return value;
}

//Problem 14 - Longest Collatz sequence
long p014()
{
  long ret = 0;
  long largest = 0;
  long current = 0;
  long val = 0;
  long i = 0;

  //test all numbers below 1000000
  for(i = 1; i < 1000000; i++)
  {
    //reset current and skip all even entries
    current = 0;
    if (val % 2 != 0)
    {
      val = i;
      //perform the sequence
      while (val != 1)
      {
        if (val % 2 == 0)
        {
          val = val / 2;
        }
        else
        {
          val = (3 * val) + 1;
        }
        //maintain the conut
        current++;
      }
      //if we found a new bigger one, save it
      if (current > largest)
      {
        largest = current;
        ret = i;
      }
    }
  }

	return ret;
}

long p015()
{
  return 0;
}

long p020()
{
  BIGINT value = allocateBigInt();
  int i;
  long outVal = 0;

  addScalarToBigInt(value, 1);
  
  for(i = 1; i <= 100; i++)
  {
    multiplyBigIntByScalar(value, i);
  }

  i = BIGINT_LENGTH;
  while (*(value + i) == 0)
  {
    i--;
  }

  i++;

  outVal = 0;
  while (i > 0)
  {
    while(*(value + i) != 0)
    {
      outVal += *(value + i) % 10;
      *(value + i ) = *(value + i) / 10;
    }
    i--;
  }

  return outVal;
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
    case 10:
      return 142913828922;
    case 11:
      return 70600674;
    case 12:
      return 76576500;
    case 13:
      return 5537376230;
    case 14:
      return 837799;
    case 15:
      return 137846528820;
    case 20:
      return 648;
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
    case 10:
      return &p010;
    case 11:
      return &p011;
    case 12:
      return &p012;
    case 13:
      return &p013;
    case 14:
      return &p014;
    case 15:
      return &p015;
    case 20:
      return &p020;
    default:
      return &p001;
  } 
}
