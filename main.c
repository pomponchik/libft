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
// unsigned long long int index = 0;
// t_list *temp = NULL;
// while (index <= 10)
// {
// 	//printf("%d\n", index);
// 	ft_lstadd_to_end(&temp, ft_lstnew_without_copy(ft_itoa_llu(index), ft_strlen(ft_itoa_llu(index))));
// 	index++;
// }
// temp = ft_lst_deduplication(temp);
// ft_lst_putstr_sep_free(temp, ", ");
	 //printf("%s\n", ft_itoa_long_long(ft_maxmin("long long", "min")));


	// if (ft_this_all_files_is_same_free(ft_get_all_files_free(ft_get_arguments_command_line(argc, argv))))
	// 	printf("this_files_is_same\n");
	// else
	// 	printf("nope :(\n");

	// ft_lst_putstr_sep_free(ft_lst_turn(ft_get_arguments_command_line(argc, argv)), ", ");
	// ft_putchar('\n');
	//printf("%s\n", ft_long_arithmetic_string_add("1739412749827456923857629384", "24391385624736927834659285692857649387569287634985623985769"));
	// size_t size = sizeof(long double);
	// size_t index = 0;
	// size_t i;
	// long double num = -111111111111111.9999999999999999;
	// char *n = (char *)(&num);
	// while (index < size)
	// {
	// 	i = 0;
	// 	while (i < 8)
	// 	{
	// 		if (ft_bits_read_bit(&n[index], i))
	// 			printf("1");
	// 		else
	// 			printf("0");
	// 		i++;
	// 	}
	// 	index++;
	// }
	// ft_putchar('\n');
	long double num = 0.0;
	long double n2 = 1.0;
	long long int i = 2;
	size_t index = 0;
	//size_t i = 0;
	char *res;
	char *temp;
	long double n;
	char *temp2 = ft_bits_to_string(&num, sizeof(num));
	// while (num * 2.0 > num)
	// {
	// 	num *= 2.0;
	// 	if (!(temp = ft_bits_to_string(&num, sizeof(num))))
	// 		printf("au\n");
	// 	indexer(temp, temp2);
	// 	free(temp);
	// }
	// char *r = ft_strdup(temp2);
	// num = 0.000130148430209301248;
	// while (num * 2.0 > num)
	// {
	// 	num *= 2.0;
	// 	if (!(temp = ft_bits_to_string(&num, sizeof(num))))
	// 		printf("au\n");
	// 	indexer2(temp, temp2);
	// 	free(temp);
	// }
	// num = -0.000130148430209301248;
	// while (num * 2.0 < num)
	// {
	// 	num *= 2.0;
	// 	if (!(temp = ft_bits_to_string(&num, sizeof(num))))
	// 		printf("au\n");
	// 	indexer3(temp, temp2);
	// 	free(temp);
	// }
	// num = 0.0000000000000001;
	// while (num * 2.0 > num)
	// {
	// 	num *= 2.0;
	// 	if (!(temp = ft_bits_to_string(&num, sizeof(num))))
	// 		printf("au\n");
	// 	indexer2(temp, temp2);
	// 	free(temp);
	// }
	// num = 0.0000000000000000000000001;;
	// while (num * 2.0 > num)
	// {
	// 	num *= 2.0;
	// 	if (!(temp = ft_bits_to_string(&num, sizeof(num))))
	// 		printf("au\n");
	// 	indexer2(temp, temp2);
	// 	free(temp);
	// }
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

	//indexer(r, temp2);
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
