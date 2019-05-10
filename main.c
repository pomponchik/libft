#include "includes/libft.h"
#include <stdio.h>

int main()
{
	int i;

	i = 1;
	ft_bits_reverse_memory(&i, sizeof(int));
	ft_bits_reverse_memory(&i, sizeof(int));
	printf("result = %d\n", i);
	return 0;
}
