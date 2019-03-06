#include "libft.h"

long int ft_math_rounding_down_float(float num)
{
  long int result;

  result = (long int)num;
  if (result >= 0 && (float)result <= num)
    return (result);
  else if (result >= 0 && (float)result > num)
    return (result - 1);
  else if (result < 0 && (float)result >= num)
    return (result);
  return (result + 1);
}
