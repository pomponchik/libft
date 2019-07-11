#include "libft.h"

int ft_lst_stack_turn(size_t channel)
{
	t_list	*stack;

	if (ft_lst_stack_is_empty(channel))
		return (0);
	if (!(stack = ft_lst_stack_new_stack(channel)))
			return (0);
	ft_lst_turn(stack);
	return (1);
}
