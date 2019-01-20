/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:47:43 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/20 20:04:32 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_strdel(t_list *alst, t_list *first)
{
	t_list	*temp;

	if (!alst)
		return ;
	ft_bzero(alst->content, ft_strlen((char *)alst->content));
	free(alst->content);
	if (alst->next)
	{
		alst->content = (alst->next)->content;
		alst->content_size = (alst->next)->content_size;
		temp = alst->next;
		alst->next = (alst->next)->next;
		free(temp);
	}
	else
	{
		if (alst != first)
		{
			while (first->next != alst && first->next)
				first = first->next;
			if (first->next == alst)
			{
				first->next = NULL;
				free(alst);
			}
		}
	}
}
