/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 21:52:00 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/12 21:52:01 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_issorted(void *array, size_t arr_size, size_t piece_size, int (*f)(void *, void *))
{
	size_t index;

	if (!array || !arr_size || !piece_size || !f)
		return (0);
	index = 0;
	while (index < arr_size - 1)
	{
		if (f(array, ))
		index++;
	}
}
