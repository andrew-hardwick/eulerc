#include <stdio.h>
#include "p001_020.h"

#define false 0
#define true 1

int main()
{
  int perf[] = {1};

  int result = 0;
  int expec = 0;

  int i = 0;
  int count = sizeof(perf) / sizeof(int);

  for (i = 0; i < count; i++)
  {
    int (*func)();
    func = p001_020_select(perf[i]);
    
    expec = p001_020_expected(perf[i]);
    result = func();

    if(expec == result)
    {
      printf("%i: %i is correct.\n", perf[i], result);
    }
    else
    {
      printf("%i: %i is incorrect, expected %i", perf[i], result, expec);
    }
  }
  return 0; 
}
