/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_turn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 22:02:51 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/19 22:07:11 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*lst_turn_helper(t_list *begin, t_list *end)
{
	end->next = begin;
	while (begin)
	{
		if (begin->next == end)
			break ;
		begin = begin->next;
	}
	begin->next = NULL;
	return (end);
}

t_list			*ft_lst_turn(t_list *begin)
{
	t_list		*temp_begin;
	t_list		*end;

	temp_begin = begin;
	while (end != temp_begin)
	{
		end = begin;
		while (end->next)
			end = end->next;
		if (end != temp_begin)
			begin = lst_reverse_helper(begin, end);
	}
	return (begin);
}
