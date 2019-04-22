/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_rounding_down_l_double.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:44:18 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/17 22:43:53 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double	round_ld_alghorithm(long double num, size_t count)
{
	long double		temp;
	long double		result;

	result = 0;
	while (count)
	{
		temp = (long double)(ft_math_rounding_down_float(num));
		result = result * 10 + temp;
		num -= temp;
		num *= 10;
		count--;
	}
	return (result);
}

long double			ft_math_rounding_down_l_double(long double num)
{
	size_t			count;
	size_t			minus;

	minus = 0;
	if (num == -0.0)
		num = 0.0;
	else if (num < 0)
	{
		num *= -1.0;
		minus++;
	}
	if (num < 1)
		return (0);
	count = ft_math_long_double_normilize(&num);
	num = round_ld_alghorithm(num, count);
	if (minus)
		num *= -1.0;
	return (num);
}
