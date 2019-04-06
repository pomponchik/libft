/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 23:31:27 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/28 23:31:29 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen_safe(const char *string)
{
	size_t	index;

	if (!string)
		return (0);
	index = 0;
	while (string[index])
		index++;
	return (index);
}