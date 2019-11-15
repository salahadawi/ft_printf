//ADD HEADER

int ft_longlen(long int nbr)
{
  int i;

  i = 0;
  if (nbr < 0)
    i++;
  while (nbr || i == 0)
    {
      nbr /= 10;
      i++;
    }
  return (i);
}
