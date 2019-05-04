/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 21:43:26 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/03 21:58:42 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lst_strjoin(t_list *lst)
{
	char	*result;
	void	*temp;
	size_t	size;

	if (!lst || !(result = (char *)malloc(ft_lst_strlen(lst) + 1)))
		return (NULL);
	temp = (void *)result;
	while (lst)
	{
		size = ft_strlen((char *)lst->content);
		ft_memcpy(temp, lst->content, size);
		temp = ft_jump_pointer_size_t(temp, size);
		lst = lst->next;
	}
	*((char *)temp) = '\0';
	return (result);
}
