/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:55:18 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/25 17:08:34 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*result;

	if (!(result = (char *)malloc(ft_strlen(src) + 1)))
		return (NULL);
	result = ft_memcpy(result, src, ft_strlen(src) + 1);
	return (result);
}
