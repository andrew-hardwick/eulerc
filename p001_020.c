// Problem 1
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

// Problem 2
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

// Provide the expected result for formatting in main
int p001_020_expected(int index)
{
  switch(index)
  {
    case 1:
      return 233168;
    case 2:
      return 4613732;
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
    default:
      return &p001;
  } 
}
