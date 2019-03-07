/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:31:12 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/06 19:34:09 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				numeric(long long int c)
{
	int					result;

	if (!c)
		return (1);
	result = 0;
	if (c < 0)
		result++;
	while (c)
	{
		c /= 10;
		result++;
	}
	return (result);
}

static long long int	shorter(long long int *n, char *result)
{
	long long int		temp;
	long long int		temp_temp;
	long long int		correct;
	long long int		correct2;

	temp = ft_maxmin("long", "min");
	correct = numeric(*n) - 2;
	correct2 = 1;
	if (*n == temp)
	{
		while (correct--)
			correct2 *= 10;
		while (temp)
		{
			temp_temp = temp;
			temp /= 10;
		}
		temp = temp_temp * -1;
		result[1] = (char)(temp + '0');
		temp = *n + (temp * correct2);
		return (temp * -1);
	}
	return (*n * -1);
}

char					*ft_itoa_long_long(long long int n)
{
	char				*result;
	int					index;
	int					hren_indicate;

	index = numeric(n);
	if (!(result = (char *)malloc(numeric(n) + 1)))
		return (NULL);
	hren_indicate = 0;
	result[index] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n = shorter(&n, result);
		hren_indicate = 1;
	}
	while (index)
	{
		if (!(hren_indicate && n == 0))
			result[index - 1] = n % 10 + '0';
		n /= 10;
		index--;
	}
	return (result);
}
