/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 00:34:49 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/29 00:34:58 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstsearch_content(t_list *lst, void *to_search)
{
	t_list *temp;

  if (!lst || !to_search)
    return (NULL);
	temp = lst;
	while (temp)
	{
    if (!ft_strncmp(temp->content, to_search, temp->content_size))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
