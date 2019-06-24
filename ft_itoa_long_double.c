#include "libft.h"

char					*ft_itoa_long_double(long double num/*, size_t accuracy*/)
{
	long long int i;

	i = 0;
	ft_bits_copy(&num, &i, 15, 1);
	char *result = ft_itoa_long_long(i);

	ft_bits_print(&i, sizeof(long long int) * 8);
	ft_putchar('\n');
	return (result);
}
