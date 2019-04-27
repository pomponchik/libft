/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_fix_width_of_line_free.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 23:27:39 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/27 23:30:26 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str_fix_width_of_line_free(char *str, \
	char filler, size_t len, int dont_cut)
{
	char	*result;

	result = ft_str_fix_width_of_line(str, filler, len, dont_cut);
	if (result != str)
		free(str);
	return (result);
}
