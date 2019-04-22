/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_stack_keep_stacks.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 22:04:35 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/22 23:12:17 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				**ft_lst_stack_keep_stacks(void)
{
	static t_list	**stacks;

	if (!stacks)
	{
		if (!(stacks = (t_list **)malloc(sizeof(t_list *))))
			return (NULL);
		*stacks = ft_lstnew_without_copy(NULL, 0);
	}
	return (stacks);
}
