/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strlen_cs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 19:21:05 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/17 19:21:07 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lst_strlen_cs(t_list *lst)
{
	size_t	result;

	if (!lst)
		return (0);
	result = 0;
	while (lst)
	{
		result += lst->content_size;
		lst = lst->next;
	}
	return (result);
}
