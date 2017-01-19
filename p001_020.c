int p001()
{
  int out = 0;
  int i = 0;
  for(i = 0; i < 1000; i++)
  {
    if(i % 3 == 0 || i % 5 == 0)
    {
      out += i;
    }
  }
  return out;
}

int p002()
{
  int out = 0;

  int f1 = 1;
  int f2 = 1; 

  while (f1 < 4000000){
    if (f1 % 2 == 0)
    {
      out += f1;
    }
    f2 = f1 + f2;
    f1 = f2 - f1;
  }
  return out;
}

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
