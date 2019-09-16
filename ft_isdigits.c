#include "libft.h"

int	ft_isdigits(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}
