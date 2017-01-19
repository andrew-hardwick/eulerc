#include <stdio.h>
#include "p001_020.h"

int main()
{
  int perf[] = {1, 2};

  int result = 0;
  int expec = 0;

  int (*func)();

  int i = 0;
  int count = sizeof(perf) / sizeof(int);

  for (i = 0; i < count; i++)
  {
    func = p001_020_select(perf[i]);
    result = func();

    expec = p001_020_expected(perf[i]);

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
