/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 05:56:27 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/16 05:56:29 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_free_1(char *s1, char *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	if (!(result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_memcpy(result, s1, ft_strlen(s1) + 1);
	result[ft_strlen(s1)] = '\0';
	free(s1);
	return (ft_strcat(result, s2));
}
