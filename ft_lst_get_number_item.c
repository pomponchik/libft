/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_number_item.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:09:20 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/11/12 21:22:40 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_get_number_item(t_list *lst, size_t number_item)
{
	size_t	index;

	index = 0;
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (index == number_item)
			return (lst);
		index++;
		lst = lst->next;
	}
	return (NULL);
}
