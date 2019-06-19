#include "includes/libft.h"
#include <stdio.h>

void indexer(char *str, char *str2)
{
	size_t index = 0;

	while (str[index])
	{
		if (str[index] == '1')
			str2[index] = '1';
		index++;
	}
}

void indexer2(char *str, char *str2)
{
	size_t index = 0;

	while (str[index])
	{
		if (str[index] == '1')
			str2[index] = '2';
		index++;
	}
}

void indexer3(char *str, char *str2)
{
	size_t index = 0;

	while (str[index])
	{
		if (str[index] == '1')
			str2[index] = '3';
		index++;
	}
}

int main(int argc, char **argv)
{
	long double num = 0.0;
	long double n2 = 1.0;
	long long int i = 2;
	size_t index = 0;
	char *res;
	char *temp;
	long double n;
	char *temp2 = ft_bits_to_string(&num, sizeof(num));
	size_t u = 0;
	while (num < 1.0)
	{
		printf("k1, num = %f, n2 = %f, u = %lu\n", num, n2, u);
		if (num + n2 / i < 1.0)
		{
			if (num + n2 / i == num || n2 == 0.0)
				break ;
			num += n2 / i;
			printf("k6\n");
		}

		else
		{
			i *= 2;
			printf("k5\n");
		}

		printf("k2\n");
		if (num + (n2 / i) > 1.0 || !(n2 / i) || !n2)
			break ;
		printf("k3\n");
		if (!(temp = ft_bits_to_string(&num, sizeof(num))))
			printf("au\n");
		indexer(temp, temp2);
		printf("k4\n");
		free(temp);
		u++;
		if (u > 10000)
			break ;
	}

	printf("res = %s\n%f\n", temp2, num);

	return 0;
}

// 11 = нули
// 52 - дроби
// 16 - целое
// 1 - знак
// 36 = нули
//
//
// 00000000
// 00023222
// 22223222
// 22202322
// 32222202
// 22202332
// 22232332
// 22232221
// 11111111
// 11111113
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
