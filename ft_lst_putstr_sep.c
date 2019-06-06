#include "libft.h"

size_t		ft_lst_putstr_sep(t_list *lst, char *separator)
{
	char	*str;
	size_t	str_size;

	if (!lst || !(str = ft_lst_strjoin_sep_counter_out(lst, \
    separator, &str_size)))
		return (0);
	ft_putstr_len(str, str_size);
	free(str);
	return (str_size);
}
