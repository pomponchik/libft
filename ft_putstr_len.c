/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:42:34 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/26 16:42:37 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_putstr_len(char const *s, size_t len)
{
	if (!s || len)
		return (NULL);
	write(1, s, len);
	return ((char *)s + len);
}
