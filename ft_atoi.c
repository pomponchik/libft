/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:59:11 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/04 20:53:18 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int				search_space(char let)
{
	if (let == ' ' || let == '\n' || let == '\t')
		return (1);
	else if (let == '\r' || let == '\v' || let == '\f')
		return (1);
	return (0);
}

static void				add_digit(char let, long int *digit, int *error)
{
	let -= '0';
	if (!*digit && !let)
		return ;
	else if (((*digit * 10 + (long int)let) > *digit))
		*digit = *digit * 10 + (long int)let;
	else
		*error = 1;
}

static long int			check_maxlong(void)
{
	return ((long int)(~((unsigned long int)0) / 2));
}

static int				error_checker(long int digit, int minus, int error)
{
	if (error && minus == 1)
		return (-1);
	if (error && minus == -1)
		return (0);
	if (digit == check_maxlong() && minus == 1)
		return ((int)digit);
	return ((int)(digit * (long int)minus));
}

int						ft_atoi(const char *str)
{
	int					minus;
	int					plus;
	long int			digit;
	int					error;

	minus = 1;
	plus = 0;
	digit = 0;
	error = 0;
	while (*str)
	{
		if (*str == '-' && minus == 1 && !plus && !digit)
			minus = -1;
		else if (*str == '+' && minus == 1 && !plus && !digit)
			plus = 1;
		else if (search_space(*str) && !digit && minus == 1 && !plus)
			;
		else if (*str >= '0' && *str <= '9')
			add_digit(*str, &digit, &error);
		else
			break ;
		str++;
	}
	return (error_checker(digit, minus, error));
}
