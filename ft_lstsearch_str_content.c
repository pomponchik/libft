#include "libft.h"

t_list *ft_lstsearch_str_content(t_list *lst, char *to_search)
{
	t_list *temp;

	temp = lst;
	while (temp)
	{
    if (!ft_strcmp((char *)temp->content, to_search))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
