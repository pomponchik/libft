#include "libft.h"

char *ft_math_long_arithmetic_string_multi_free_both(char *n1, char *n2)
{
	char *result;

	if (!(result = ft_math_long_arithmetic_string_multi(n1, n2)))
		return (NULL);
	ft_free_both(n1, n2);
	return (result);
}
