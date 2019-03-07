/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_numlen_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 21:56:51 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/07 21:56:53 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_math_numlen_long(long int num)
{
	int		result;

	if (!num)
		return (1);
	result = 0;
	if (num < 0)
		result++;
	while (num)
	{
		num /= 10;
		result++;
	}
	return (result);
}
