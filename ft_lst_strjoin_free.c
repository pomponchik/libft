/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strjoin_fr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 23:24:55 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/05 00:01:33 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lst_strjoin_fr(t_list *lst)
{
	char	*result;
	void	*temp;
	size_t	size;
	t_list	*t;
	size_t max;

	if (!lst || !(result = (char *)malloc(ft_lst_strlen(lst) + 1)))
		return (NULL);
	temp = (void *)result;
	max = 0;
	while (lst)
	{
		t = lst;
		size = ft_strlen_safe((char *)lst->content);
		max += size;
		if (lst->content)
		{
			ft_memcpy(temp, lst->content, size);
			temp = ft_jump_pointer_size_t(temp, size);
		}
		if (lst->content)
			free(t->content);
		lst = lst->next;
		free(t);
	}
	result[max] = '\0';
	return (result);
}
