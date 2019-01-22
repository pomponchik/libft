/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:57:54 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/25 17:19:58 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	size_t	index;

	if (!s || !f)
		return (NULL);
	if (!(result = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	index = 0;
	ft_memcpy(result, s, ft_strlen(s));
	while (s[index])
	{
		result[index] = f(s[index]);
		index++;
	}
	result[ft_strlen(s)] = '\0';
	return (result);
}
