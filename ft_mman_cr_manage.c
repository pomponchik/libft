#include "libft.h"

t_man *ft_mman_cr_manage(void)
{
	t_man *result;

	if (!(result = (t_man *)malloc(sizeof(t_man))))
		return (NULL);
	return (result);
}
