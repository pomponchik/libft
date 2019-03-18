#include "libft.h"



void ft_sort_quick(void *arr, size_t size, size_t amount, int (*f)(void *, void *))
{
	void *p_temp;
	void *p_temp_1;
	size_t index;
	size_t size_temp;

	size = parameters[0];
	amount = parameters[1];
	if (!a || !b || !f || amount <= 1 || !size)
		return ;
	p_temp = ft_jump_pointer_to_n(arr, size * (amount / 2));
	index = 0;
	if (f(arr, p_temp - size) < 0)
		ft_swap_n_bytes(arr, p_temp - size, size);
	while (index != amount / 2)
	{
		p_temp = ft_jump_pointer_to_n(arr, size * index);
		if (f(arr, p_temp) > 0)
			ft_swap_n_bytes(arr, p_temp, size);
		index++;
	}
	p_temp = ft_jump_pointer_to_n(arr, size * (amount / 2));
	if (f(arr, p_temp) > 0)
		ft_swap_n_bytes(arr, p_temp, size);
	while (index != amount)
	{
		p_temp = ft_jump_pointer_to_n(arr, size * index);
		if (f(arr, p_temp) < 0)
			ft_swap_n_bytes(arr, p_temp, size);
		index++;
	}
	ft_sort_quick(arr, size, amount / 2, f);
	p_temp = ft_jump_pointer_to_n(arr, size * (amount / 2));
	ft_sort_quick(p_temp, size, amount - (amount / 2), f);
}
