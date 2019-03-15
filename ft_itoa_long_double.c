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

static int				one_num_from_multi_num_ld(char *num)
{
	if (!*(num + 1))
		return ((int)(num - '0'));
	if (one_num_from_multi_num_ld(num + 1) >= 5)
	{
		if (*num - '0' + 1 <= 9)
			return ((int)(*num - '0' + 1));
		else
			return (9);
	}
	return ((int)*num - '0');
}

static char				*ft_round_endstr_ld(char *num, size_t accuracy)
{
	char				*result;
	// char *temp;

	if (ft_strlen(num) > accuracy)
	{
		if (!accuracy)
		{
			num[0] = '0';
			num[1] = '\0';
			result = ft_strdup(num);
			free(num);
			return (result);
		}
		num[accuracy - 1] = (char)one_num_from_multi_num_ld(num + accuracy - 1) + '0';
		num[accuracy] = '\0';
		result = ft_strdup(num);
		free(num);
		return (result);
	}
	return (num);
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
	while (index != size)
	{
		temp = (long double)ft_math_rounding_down_float(num);
		str[index] = (char)temp + '0';
		num -= temp;
		num *= 10;
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
	size_t size;

	size = ft_math_numlen_long_double(num);
	if (num - ft_math_rounding_down_long_double(num))
		size++;
	if (!(result = (char *)malloc(size + 1)))
		return (NULL);
	result = str_from_long_double(result, num, size);
	result[size] = '\0';
	//accuracy += 2;
	if (ft_strlen(ft_strchr(result, '.')) > accuracy + 1)
		result = ft_round_endstr_ld(ft_strchr(result, '.') + 1, accuracy);
	return (result);
}
