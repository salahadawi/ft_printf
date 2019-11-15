//ADD HEADER

int ft_ulonglen(unsigned long int nbr)
{
  int i;

  i = 0;
  while (nbr || i == 0)
    {
      nbr /= 10;
      i++;
    }
  return (i);
}
