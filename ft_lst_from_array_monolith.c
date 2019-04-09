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
	t_list	*temp_lst;
	t_list	*temp_arr;

	result = NULL;
	if (!(temp_arr = (t_list *)malloc(amount * size)))
		return (NULL);
	while (amount)
	{
		temp_lst = ft_lstnew_monolith(arr, temp_arr, size);
		ft_lstadd_to_end(&result, temp_lst);
		arr = ft_jump_pointer_to_n(arr, size);
		temp_lst = ft_jump_pointer_to_n(temp_lst, sizeof(t_list));
		amount--;
	}
	return (result);
}
