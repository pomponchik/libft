#include "libft.h"

void ft_swap_n_bytes(void *a, void *b, size_t n)
{
	size_t index;

	if (!a || !b || !n || !(a == b))
		return ;
	index = 0;
	while (index != n)
	{
		ft_swap_byte(a + index, b + index);
		index++;
	}
}
