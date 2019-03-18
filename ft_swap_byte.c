#include "libft.h"

void ft_swap_byte(unsigned char *a, unsigned char *b)
{
	unsigned char temp;

	if (!a || !b)
		return ;
	temp = *a;
	*a = *b;
	*b = temp;
}
