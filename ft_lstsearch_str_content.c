/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch_str_content.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 00:35:52 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/29 00:35:57 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstsearch_str_content(t_list *lst, char *to_search)
{
	t_list *temp;

	  if (!lst || !to_search)
    return (NULL);
	temp = lst;
	while (temp)
	{
    if (!ft_strcmp((char *)temp->content, to_search))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
