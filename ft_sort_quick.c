#include "libft.h"

void ft_sort_quick(void *a, size_t size, size_t amount, int (*f)(void *, void *))
{
	void *temp;
	size_t index;

	if (!a || !f || amount <= 1 || !size)
		return ;
	temp = ft_jump_pointer_to_n(a, size * (amount / 2));
	index = 0;
	if (f(a, temp - size) < 0)
		ft_swap_n_bytes(a, temp - size, size);
	while (index != amount / 2)
	{
		temp = ft_jump_pointer_to_n(a, size * index);
		if (f(a, temp) > 0)
			ft_swap_n_bytes(a, temp, size);
		index++;
	}
	temp = ft_jump_pointer_to_n(a, size * (amount / 2));
	if (f(a, temp) > 0)
		ft_swap_n_bytes(a, temp, size);
	while (index != amount)
	{
		temp = ft_jump_pointer_to_n(a, size * index);
		if (f(a, temp) < 0)
			ft_swap_n_bytes(a, temp, size);
		index++;
	}
	ft_sort_quick(a, size, amount / 2, f);
	temp = ft_jump_pointer_to_n(a, size * (amount / 2));
	ft_sort_quick(temp, size, amount - (amount / 2), f);
}
