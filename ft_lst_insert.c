#include "libft.h"

static t_list *ft_lst_inserter(t_list *previous, t_list *next, t_list *new)
{
	t_list *temp_next;

	if (!previous)
	{
		new->next = next;
		return (new);
	}
	temp_next = previous->next;
	previous->next = new;
	new->next = temp_next;
	return (NULL);
}

static t_list *ft_lst_insert_tail(t_list *previous, t_list *to_insert, size_t position, size_t index)
{
	if (index == position)
	{
		previous->next = to_insert;
		return (to_insert);
	}
	return (NULL);
}

t_list *ft_lst_insert(t_list *lst, t_list *to_insert, size_t position)
{
	size_t index;
	t_list *previous;
	t_list *temp;
	t_list *result;

	if (!lst || !to_insert || position + 1 <= position)
		return (NULL);
	index = 0;
	previous = NULL;
	temp = lst;
	while (lst)
	{
		if (index == position)
		{
			if ((result = ft_lst_inserter(previous, lst, to_insert)))
				return (result);
			return (temp);
		}
		index++;
		previous = lst;
		lst = lst->next;
	}
	return (ft_lst_insert_tail(previous, to_insert, position, index) != NULL ? temp : NULL);
}
