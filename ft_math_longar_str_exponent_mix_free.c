#include "libft.h"

char		*ft_math_longar_str_exponent_mix_free(char *num, \
	unsigned long int exponent)
{
	char *result;

	if (!(result = ft_math_longar_str_exponent_mix(num, exponent)))
		return (NULL);
	free(num);
	return (result);
}
