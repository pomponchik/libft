/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:43:22 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/07 16:56:51 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int				one_num_from_multi_num_ld(char *num, size_t *ind_in)
{
	size_t ind_out;

	if (!*(num + 1))
	{
		*ind_in = 0;
		return ((int)(num - '0'));
	}
	if (one_num_from_multi_num_ld(num + 1, &ind_out) + ind_out >= 5)
	{
		if (*num - '0' + ind_out <= 9)
		{
			*ind_in = 0;
			return ((int)(*num - '0' + ind_out));
		}
		else
		{
			*ind_in = 1;
			return ((*num - '0' + ind_out) - 10);
		}
	}
	*ind_in = 0;
	return ((int)*num - '0' + ind_out);
}

static void ft_round_end_ld2(char *num, size_t acc, char **or, long double n)
{
	size_t ind_out;
	char *temp;

	num[acc - 1] = (char)one_num_from_multi_num_ld(num + acc - 1, &ind_out) + ind_out + '0';
	num[acc] = '\0';
	if (ind_out)
	{
		while (acc)
		{
			if (num[acc - 1] - '0' + ind_out > 9)
				num[acc - 1] = '0';
			else
			{
				num[acc - 1] = num[acc - 1] + 1;
				ind_out = 0;
				break ;
			}
			acc--;
		}
		if (ind_out)
		{
			temp = ft_itoa_long_double(ft_math_rounding_down_long_double(n) + 1, acc);
			free(*or);
			*or = temp;
		}
	}
}

static void ft_round_endstr_ld(char *num, size_t acc, char **or, long double n)
{
	size_t difference;
	char *temp;

	if (!acc)
	{
		ft_memcmp(num, "0", 2);
	}
	else if (ft_strlen(num) > acc)
	{
		ft_round_end_ld2(num, acc, or, n);
	}
	else if (ft_strlen(num) < acc)
	{
		temp = *or;
		difference = acc - ft_strlen(num);
		*or = ft_strjoin_free_both(*or, ft_new_null_str(difference));
	}
}

char *str_from_long_double(char *str, long double num, size_t size)
{
	size_t count;
	size_t index;
	long double temp;
	char dot_indicate;

	index = 0;
	dot_indicate = 0;
	count = ft_math_long_double_normilize(&num);
	while (index < size)
	{
		temp = ft_math_rounding_down_long_double(num);
		str[index] = (char)temp + '0';
		num = (num - temp) * 10;
		count--;
		if (!count && !dot_indicate)
		{
			index++;
			str[index] = '.';
			dot_indicate++;
		}
		index++;
	}
	return (str);
}

char					*ft_itoa_long_double(long double num, size_t accuracy)
{
	char *result;
	char *temp;
	size_t size;
	int minus;

	minus = 0;
	size = ft_math_numlen_long_double(num);
	if (num < 0)
	{
		num *= -1;
		minus = 1;
	}
	if (num - ft_math_rounding_down_long_double(num))
		size++;
	if (!(result = (char *)malloc(size + 1)))
		return (NULL);
	result = str_from_long_double(result, num, size);
	result[size] = '\0';
	temp = result;
	if (ft_strlen_safe(ft_strchr(result, '.')) > accuracy + 1)
		ft_round_endstr_ld(ft_strchr(result, '.') + 1, accuracy, &temp, num);
	if (!(result = ft_strdup(ft_str_disnuller_end(temp))))
		return (NULL);
	free(temp);
	if (minus)
		result = ft_strjoin_free_2("-", result);
	return (result);
}
