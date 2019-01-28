/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_lst_search_content.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 00:33:24 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/29 00:33:28 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_two_list *ft_binary_lst_search_content(t_two_list *alst, void *to_search)
{
  t_two_list *temp;

	if (!alst || !to_search)
		return (NULL);
  temp = alst;
  while (temp)
  {
    if (!ft_strncmp(temp->content, to_search, temp->content_size))
      return (temp);
    temp = temp->next;
  }
  temp = alst->back;
  while (temp)
  {
    if (!ft_strncmp(temp->content, to_search, temp->content_size))
      return (temp);
    temp = temp->back;
  }
  return (NULL);
}
