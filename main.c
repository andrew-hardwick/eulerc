#include <stdio.h>
#include "p001_020.h"

int main()
{
  // array that defines the problems to run
  int perf[] = {11};

  // actual and expected result
  long result = 0;
  long expec = 0;

  // function pointer to the functions that compute the actual result
  long (*func)();

  // i is index for for loop. count is number of items in problem array
  int i = 0;
  int count = sizeof(perf) / sizeof(int);

  for (i = 0; i < count; i++)
  {
    // retrieve the problem function and execute it
    func = p001_020_select(perf[i]);
    result = func();

    // retrieve the expected result
    expec = p001_020_expected(perf[i]);

    // output the result in a readable format
    if(expec == result)
    {
      printf("%i: %li is correct.\n", perf[i], result);
    }
    else
    {
      printf("%i: %li is incorrect, expected %li.\n", perf[i], result, expec);
    }
  }

  return 0; 
}
