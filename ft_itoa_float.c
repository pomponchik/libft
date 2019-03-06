#include "libft.h"

long int ft_math_rounding_down_float(float num);
char				*ft_itoa_long(long int n);

static float post_dot_size_num(float residue)
{
  while (residue - ft_math_rounding_down_float(residue))
    residue *= 10;
  return (residue);
}

char *ft_itoa_float(float num)
{
  long int intermediate;
  char *result;
  char *temp;
  float residue;

  intermediate = ft_math_rounding_down_float(num);
  temp = ft_itoa_long(intermediate);
  result = ft_strjoin(temp, ".");
  free(temp);
  residue = num - intermediate;
  if (!residue)
  {
    temp = ft_strjoin(result, "0");
    free(result);
    return (temp);
  }
  intermediate = ft_math_rounding_down_float(post_dot_size_num(residue));
  temp = ft_itoa_long(intermediate);
  result = ft_strjoin(result, temp);
  free(temp);
  return (result);
}

#include <stdio.h>
int main()
{
  printf(ft_itoa_float(168.765739));
  return 0;
}
