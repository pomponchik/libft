#include "libft.h"

void ft_swap_n_bytes(void *a, void *b, size_t size)
{
	unsigned char *a_temp;
	unsigned char *b_temp;
	size_t index;

	if (!a || !b || !size)
		return ;
	a_temp = (unsigned char *)a;
	b_temp = (unsigned char *)b;
	index = 0;
	while (index != size)
	{
		ft_swap_byte(a_temp + index, b_temp + index);
		index++;
	}
}
