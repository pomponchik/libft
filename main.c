#include "libft.h"
#include <stdio.h>


int fun(void *q1, void *q2)
{
	char *w1 = (char *)q1;
	char *w2 = (char *)q2;

	char res = (*w1 - *w2);
	int ret = (int)res;
	return (ret);
}

int main()
{
	char k [] = "4321";

	ft_sort_quick(k, sizeof(char), ft_strlen(k), &fun);
	printf("%s\n", k);
	return (0);
}


// int main()
// {
// 	long double num = 15.3;
// 	printf("%.5Lg, %s\n", num, ft_itoa_long_double(num,5));
// 	return (0);
// }

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


// int main()
// {
// 	char str [] = "12340000";
// 	ft_str_disnuller_end(str);
// 	printf("%s", str);
// 	return (0);
// }
