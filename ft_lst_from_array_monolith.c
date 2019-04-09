/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_from_array_monolith.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 22:35:52 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/08 23:04:58 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_from_array_monolith(void *arr, size_t size, size_t amount)
{
	t_list	*result;
	t_list	*temp;

	result = NULL;
	while (amount)
	{
		if (!(temp = ft_lstnew_without_copy(arr, size)))
		{
			ft_lst_free_chain(result);
			return (NULL);
		}
		ft_lstadd_to_end(&result, temp);
		arr = ft_jump_pointer_to_n(arr, size);
		amount--;
	}
	return (result);
}
