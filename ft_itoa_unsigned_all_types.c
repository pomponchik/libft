#include "libft.h"

char *ft_itoa_unsigned_all_types(void *num, unsigned int num_bits)
{
	char *listing;
	size_t index;
	char *result;

	if (!(listing = ft_bits_listing(&num, num_bits / 8 + (num_bits % 8) ? 1 : 0)))
		return (NULL);
	if (!(result = ft_strdup("0")))
		return (ft_free(listing));
	index = 0 + (num_bits % 8) ? num_bits - (num_bits - (num_bits % 8)) : 0;
	ft_str_reverse(listing);
	ft_putstr(listing);
	while (listing[index] && num_bits)
	{
		if (listing[index] == '1')
			result = ft_math_longar_str_add_free_both(result, \
				ft_math_longar_str_exponent_mix("2", (unsigned long int)num_bits - 2));
		num_bits--;
		index++;
	}
	free(listing);
	return (result);
}
