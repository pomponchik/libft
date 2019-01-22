/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 08:54:52 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/25 17:43:46 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned	int	index;

	if (!s || !f)
		return (NULL);
	if (!(result = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	index = 0;
	ft_memcpy(result, s, ft_strlen(s));
	while (s[index])
	{
		result[index] = f(index, s[index]);
		index++;
	}
	result[ft_strlen(s)] = '\0';
	return (result);
}
