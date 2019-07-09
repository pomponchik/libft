/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_cut_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:39:52 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/09 20:38:29 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lst_atoi_strings_helper(size_t *indicate, \
	t_list **number, t_list **result)
{
	size_t size;

	*indicate = 1;
	if (*number)
	{
		ft_lstadd(result, \
			ft_lstnew_no_copy(ft_lst_strjoin_counter_out_free_cs(ft_lst_turn(*number), &size), size + 1));
		*number = NULL;
	}
}

t_list		*ft_lst_cut_numbers(char *exp)
{
	size_t	i;
	size_t	indicate;
	t_list	*n;
	t_list	*result;

	ft_nuller_double_point((void **)&n, (void **)&result);
	ft_nuller_double_size_t(&i, &indicate);
	while (exp[i])
	{
		if (ft_isdigit(exp[i]))
		{
			indicate = 0;
			ft_lstadd(&n, ft_lstnew_no_copy(ft_strnew_filler(1, exp[i]), 1));
		}
		else
		{
			if (exp[i] == '-' && (indicate || !i) && ft_isdigit(exp[i + 1]))
				ft_lstadd(&n, ft_lstnew_no_copy(ft_strnew_filler(1, exp[i]), 1));
			else
				ft_lst_atoi_strings_helper(&indicate, &n, &result);
		}
		i++;
	}
	ft_lst_atoi_strings_helper(&indicate, &n, &result);
	return (ft_lst_turn(result));
}
