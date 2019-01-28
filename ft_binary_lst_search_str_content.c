/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_lst_search_str_content.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 00:34:16 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/29 00:34:18 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_two_list *ft_binary_lst_search_str_content(t_two_list *alst, char *to_search)
{
  t_two_list *temp;

	if (!alst || !to_search)
		return (NULL);
  temp = alst;
  while (temp)
  {
    if (!ft_strcmp((char *)temp->content, to_search))
      return (temp);
    temp = temp->next;
  }
  temp = alst->back;
  while (temp)
  {
    if (!ft_strcmp((char *)temp->content, to_search))
      return (temp);
    temp = temp->back;
  }
  return (NULL);
}
