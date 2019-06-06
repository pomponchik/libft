#include "libft.h"

char		*ft_lst_strjoin_sep_counter_out_free(t_list *lst, \
	char *separator, size_t *counter)
{
	char	*result;

	if (!lst || !counter)
		return (NULL);
	result = ft_lst_strjoin_sep_counter_out(lst, separator, counter);
	ft_lst_free_chain(lst);
	return (result);
}
