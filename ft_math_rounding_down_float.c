/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_rounding_down_float.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:05:59 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/06 19:15:40 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_math_rounding_down_float(float num)
{
	long int	result;

	result = (long int)num;
	if (result >= 0 && (float)result <= num)
		return (result);
	else if (result >= 0 && (float)result > num)
		return (result - 1);
	else if (result < 0 && (float)result >= num)
		return (result);
	return (result + 1);
}
