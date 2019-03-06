/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:05:34 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/06 19:12:15 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	post_dot_size_num(float residue)
{
	if (residue < 0)
		residue *= -1.0;
	while (residue - ft_math_rounding_down_float(residue))
		residue *= 10;
	return (residue);
}

static int		one_num_from_multi_num(char *num)
{
	if (!*(num + 1))
		return ((int)(num - '0'));
	if (one_num_from_multi_num(num + 1) >= 5)
	{
		if (*num - '0' + 1 <= 9)
			return ((int)(*num - '0' + 1));
		else
			return (9);
	}
	return ((int)*num);
}

static char		*ft_rounding_endstr(char *num)
{
	char		*result;

	if (ft_strlen(num) > 6)
	{
		num[5] = (char)one_num_from_multi_num(num + 5) + '0';
		num[6] = '\0';
		result = ft_strdup(num);
		free(num);
		return (result);
	}
	return (num);
}

char			*ft_itoa_float(float num)
{
	long int	intermediate;
	char		*result;
	char		*temp;
	float		residue;

	intermediate = ft_math_rounding_down_float(num);
	temp = ft_itoa_long(intermediate);
	result = ft_strjoin(temp, ".");
	free(temp);
	residue = num - intermediate;
	if (!residue)
	{
		temp = ft_strjoin(result, "0");
		free(result);
		return (temp);
	}
	intermediate = ft_math_rounding_down_float(post_dot_size_num(residue));
	temp = ft_rounding_endstr(ft_itoa_long(intermediate));
	result = ft_strjoin(result, temp);
	free(temp);
	return (result);
}
