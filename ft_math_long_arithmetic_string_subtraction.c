#include "libft.h"
#include <stdio.h>

// static char *long_arithmetic_subtraction_less_to_more(char *test, \
// 	char *n1, char *n2)
// {
// 	char *temp;
// 	char *test2;
// 	char *try;
// 	int cmp;
//
// 	printf("n1\n");
// 	if (!(temp = ft_math_long_arithmetic_string_add(test, n1)))
// 		return (NULL);
// 	printf("n2\n");
// 	cmp = ft_math_long_arithmetic_string_comparison(temp, n2);
// 	if (!(cmp = ft_math_long_arithmetic_string_comparison(temp, n2)))
// 		return (temp);
// 	printf("n3, s1 = %s, s2 = %s\n", temp, n2);
// 	free(temp);
// 	if (cmp == 3)
// 		return (NULL);
// 	printf("n4, cmp = %d\n", cmp);
// 	if (cmp < 0)
// 		return (test);
// 	printf("n5\n");
// 	test2 = ft_math_long_arithmetic_string_multi_free_1(test, "2");
// 	temp = long_arithmetic_subtraction_less_to_more(test2, n1, n2);
// 	if (ft_math_long_arithmetic_string_comparison(temp, n2) < 0)
// 	{
// 		printf("n6\n");
// 		try = ft_math_long_arithmetic_string_add(test, temp);
// 		if (ft_math_long_arithmetic_string_comparison(try, n2) < 0)
// 			return (try);
// 		free(try);
// 	}
// 	printf("n7\n");
// 	free(test2);
// 	return (temp);
// }

// static char *la_subtr_loop(char *n1, char *n2)
// {
// 	char *result;
//
// 	ft_math_long_arithmetic_string_comparison(n1, n2)
// 	while (ft_math_long_arithmetic_string_comparison(n1, n2))
// 	{
// 		long_arithmetic_subtraction_less_to_more("1", n1, n2)
// 	}
// }

char *ft_math_long_arithmetic_string_subtraction(char *n1, char *n2)
{
	int carry = 0;
	size_t size = ft_strlen(n2);
	for (size_t i=0; i<size || carry; ++i) {
		n1[i] -= carry + (i < size ? n2[i] : 0);
		carry = n1[i] < 0;
		if (carry)
			n1[i] += 10;
	}


  return (n1);
}
