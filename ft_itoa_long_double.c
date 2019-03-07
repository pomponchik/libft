/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:43:22 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/07 13:46:57 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double	post_dot_size_num_ld(long double residue)
{
	if (residue < 0)
		residue *= -1.0;
	while (residue - ft_math_rounding_down_long_double(residue))
		residue *= 10;
	return (residue);
}

static int			one_num_from_multi_num_ld(char *num)
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
	return ((int)*num);
}

static char			*ft_rounding_endstr_ld(char *num)
{
	char			*result;

	if (ft_strlen(num) > 12)
	{
		num[11] = (char)one_num_from_multi_num_ld(num + 11) + '0';
		num[12] = '\0';
		result = ft_strdup(num);
		free(num);
		return (result);
	}
	return (num);
}

char				*ft_itoa_long_double(long double num)
{
	long long int	intermediate;
	char			*result;
	char			*temp;
	long double		residue;

	intermediate = ft_math_rounding_down_long_double(num);
	temp = ft_itoa_long_long(intermediate);
	result = ft_strjoin(temp, ".");
	free(temp);
	residue = num - intermediate;
	if (!residue)
	{
		temp = ft_strjoin(result, "0");
		free(result);
		return (temp);
	}
	intermediate = ft_math_rounding_down_long_double(post_dot_size_num_ld(residue));
	temp = ft_rounding_endstr_ld(ft_itoa_long_long(intermediate));
	result = ft_strjoin(result, temp);
	free(temp);
	return (result);
}
