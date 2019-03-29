#include "libft.h"
#include <stdio.h>

int main()
{
	long double num = 15;
	printf("%.3Lg, %s\n", num, ft_itoa_long_double(num, 5));
	return (0);
}

// int main()
// {
// 	char a;
// 	char b;
// 	char x1 [] = "1234567890";
// 	char x2 [] = "ABCDEFGHYTN";
// 	while ((a = ft_range_str(x1)) && (b = ft_range_str(x2)))
// 	{
// 		printf("%c%c", a, b);
// 	}
// 	return (0);
// }
