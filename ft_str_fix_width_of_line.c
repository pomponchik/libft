/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_fix_width_of_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 22:51:56 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/27 22:51:58 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_str_fix_width_of_line(char *str, char filler, size_t len, int dont_cut)
{
	size_t different;
	size_t half;
	size_t size;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if (len == size)
		return (str);
	if (len > size)
	{
		different = len - size;
		half = different / 2;
		if (half)
			str = ft_strjoin_free_1(ft_strnew_filler(half, filler), str);
		if ((half = different - half))
			str = ft_strjoin_free_both(str, ft_strnew_filler(half, filler));
		return (str);
	}
	if (len < size && !dont_cut)
		return (ft_strdup_n(str, len));
	return (str);
}
