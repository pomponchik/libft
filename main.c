#include <stdlib.h>
#include "libft.h"

int main()
{


	// ft_putstr(ft_math_long_arithmetic_string_subtraction(ft_strdup("15"), ft_strdup("7")));
	// ft_putstr("\n");
	int i = 0;
	ft_bits_print(&i, sizeof(int));
	ft_putchar('\n');
	int b = 0;
	ft_bits_copy(&i, &b, sizeof(int) * 8, 0);
	ft_bits_print(&b, sizeof(int));
	ft_putchar('\n');
	return (0);
}
