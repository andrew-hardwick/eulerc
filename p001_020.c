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

int p001_020_expected(int index)
{
  switch(index)
  {
    case 1:
      return 233168;
    default:
      return 0;
  }
}

int (*p001_020_select())(int index)
{
  return &p001;
}
