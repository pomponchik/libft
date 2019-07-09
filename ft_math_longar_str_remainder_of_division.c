#include "libft.h"

char *ft_math_longar_str_remainder_of_division(char *n1, char *n2)
{
	char *multi;
	char *subs;

	if (!n1 || !n2)
		return (NULL);
	multi = ft_math_longar_str_division(n1, n2);
	multi = ft_math_longar_str_multi_free_1(multi, n2);
	subs = ft_math_longar_str_subtraction(n1, multi);
	free(multi);
	return (subs);
}
