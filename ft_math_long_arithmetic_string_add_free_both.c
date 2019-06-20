#include "libft.h"

char			*ft_math_long_arithmetic_string_add_free_both(char *n1, char *n2)
{
	char *result;

	if (!(result = ft_math_long_arithmetic_string_add(n1, n2)))
		return (NULL);
	free(n1);
	free(n2);
	return (result);
}
