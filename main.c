#include <stdio.h>
#include "p001_020.h"

int main()
{
  // array that defines the problems to run
  int perf[] = {1, 2, 3, 4, 5, 6, 7};

  // actual and expected result
  int result = 0;
  int expec = 0;

  // function pointer to the functions that compute the actual result
  int (*func)();

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
      printf("%i: %i is correct.\n", perf[i], result);
    }
    else
    {
      printf("%i: %i is incorrect, expected %i.\n", perf[i], result, expec);
    }
  }

  return 0; 
}
