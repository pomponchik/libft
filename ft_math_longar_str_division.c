#include "libft.h"

static char *ft_math_longar_str_division_adder(char *n1, char *n2, char *begin)
{
	char *temp;
	int cmp;

	temp = ft_math_longar_str_multi(n2, begin);
	if ((cmp = ft_math_longar_str_comparison(temp, n1)) < 0)
	{
		free(temp);
		return (ft_math_longar_str_division_adder(n1, n2, ft_strjoin_free_1(begin, "0")));
	}
	else if (cmp == 0)
	{
		free(temp);
		return (begin);
	}
	free(temp);
	return (ft_strdup_n_free(begin, ft_strlen(begin) - 1));
}

static char *ft_math_longar_str_division_helper(char *n1, char *n2)
{
	char *temp;
	char *temp_mult;
	size_t index;

	temp = ft_math_longar_str_division_adder(n1, n2, ft_strdup("1"));
	index = 0;
	while (temp[index])
	{
		while (temp[index] <= '9')
		{
			temp_mult = ft_math_longar_str_multi(n2, temp);
			if (ft_math_longar_str_comparison(temp_mult, n1) > 0)
			{
				temp[index]--;
				free(temp_mult);
				break ;
			}
			else if (ft_math_longar_str_comparison(temp_mult, n1) == 0)
			{
				free(temp_mult);
				return (temp);
			}
			free(temp_mult);
			if (temp[index] == '9')
				break ;
			temp[index]++;
		}
		index++;
	}
	return (temp);
}

char *ft_math_longar_str_division(char *n1, char *n2)
{
	char *result;

	if (!n1 || !n2 || n2[0] == '0')
		return (NULL);
	if (n1[0] == '-' && n2[0] == '-')
		result = ft_math_longar_str_division(ft_jump(n1, 1), ft_jump(n2, 1));
	else if (n1[0] == '-' && n2[0] != '-')
	{
		result = ft_math_longar_str_division(ft_jump(n1, 1), n2);
		result = ft_strjoin_free_2("-", result);
	}
	else if (n1[0] != '-' && n2[0] == '-')
	{
		result = ft_math_longar_str_division(n1, ft_jump(n2, 1));
		result = ft_strjoin_free_2("-", result);
	}
	else
	{
		if (ft_math_longar_str_comparison(n2, n1) > 0)
			return (ft_strdup("0"));
		result = ft_math_longar_str_division_helper(n1, n2);
	}
	return (result);
}
