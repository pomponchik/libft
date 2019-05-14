/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_putstr_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:17:39 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/14 16:32:59 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_putstr_free(t_list *lst)
{
	char	*str;
	size_t	str_size;

	if (!(str = ft_lst_strjoin_counter_out_free(lst, &str_size)))
		return ;
	ft_putstr_len(str, str_size);
	free(str);
}
