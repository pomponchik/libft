#include "libft.h"

void ft_swap_byte(void *x, void *y)
{
	unsigned char temp;
	unsigned char *a;
	unsigned char *b;

	a = (unsigned char *)x;
	b = (unsigned char *)y;
	if (!a || !b)
		return ;
	temp = *a;
	*a = *b;
	*b = temp;
}
