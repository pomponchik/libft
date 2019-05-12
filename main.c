#include "includes/libft.h"
#include <stdio.h>

int main()
{
	int i;
	int g;

	i = 4;
	g = 4;
	ft_bits_shift_right(&g, sizeof(int), 1);
	printf("result = %d, result 2 = %d\n", i >> 1, g);
	return 0;
}
