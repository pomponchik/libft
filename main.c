#include "libft.h"
#include <stdio.h>

int main()
{
	long double num = 11.5654;
	printf("%Lg, %s\n", num, ft_itoa_long_double(num, 3));
	return (0);
}
