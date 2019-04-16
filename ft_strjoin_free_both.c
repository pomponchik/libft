/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_both.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 05:53:12 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/16 05:53:15 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_free_both(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin_free_1(s1, s2);
	free(s2);
	return (result);
}
