/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_lst_search_cs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 00:33:53 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/29 00:33:55 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_two_list *ft_binary_lst_search_cs(t_two_list *alst, size_t to_search)
{
  t_two_list *temp;

	if (!alst)
		return (NULL);
  temp = alst;
  while (temp)
  {
    if (temp->content_size == to_search)
      return (temp);
    temp = temp->next;
  }
  temp = alst->back;
  while (temp)
  {
    if (temp->content_size == to_search)
      return (temp);
    temp = temp->back;
  }
  return (NULL);
}
