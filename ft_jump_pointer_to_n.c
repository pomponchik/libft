/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump_pointer_to_n.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:16:34 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/20 18:29:35 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_jump_pointer_to_n(void *pointer, size_t n)
{
	char	*temp_pointer;

	if (!pointer)
		return (NULL);
	temp_pointer = (char *)pointer;
	return (temp_pointer + n);
}
