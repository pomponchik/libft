/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_long_arithmetic_string_add.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 18:45:23 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/19 19:15:27 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_lasatemp(char *str, size_t size, char residue)
{
	t_list		*lst;
	char		temp;

	lst = NULL;
	while (size)
	{
		temp = str[size - 1] - '0' + residue;
		if (temp > 9)
		{
			residue = 1;
			temp -= 10;
		}
		else
			residue = 0;
		temp += '0';
		ft_lstadd(&lst, ft_lstnew(&temp, 1));
		size--;
	}
	if (residue)
	{
		residue += '0';
		ft_lstadd(&lst, ft_lstnew(&residue, 1));
	}
	return (ft_lst_strjoin_counter_out_cs(lst, &size));
}

static char		*ft_long_arithmetic_string_add_result(char **to_fly, \
	size_t *size, t_list *lst, char residue)
{
	char		*temp_res;
	char		*temp;
	size_t		s;

	if (lst)
		temp_res = ft_lst_strjoin_counter_out_cs(lst, &size[0]);
	else
	{
		if (size[1])
			return (ft_strdup(to_fly[0]));
		return (ft_strdup(to_fly[1]));
	}
	if (size[1])
	{
		s = size[1];
		temp = to_fly[0];
	}
	if (size[2])
	{
		s = size[2];
		temp = to_fly[1];
	}
	if (!(temp = ft_strjoin_fr_both(ft_lasatemp(temp, s, residue), temp_res)))
		return (ft_strnew_filler(1, '0'));
	return (temp);
}

static char		*ft_long_arithmetic_string_add_work(char **fly, \
	size_t *size)
{
	t_list		*lst;
	char		temp;
	char		residue;

	lst = NULL;
	residue = 0;
	while (size[0])
	{
		temp = fly[0][size[1] - 1] - '0' + fly[1][size[2] - 1] - '0' + residue;
		if (temp > 9)
		{
			residue = 1;
			temp -= 10;
		}
		else
			residue = 0;
		temp += '0';
		ft_lstadd(&lst, ft_lstnew(&temp, 1));
		size[2]--;
		size[1]--;
		size[0]--;
	}
	return (ft_long_arithmetic_string_add_result(fly, size, lst, residue));
}

char			*ft_math_long_arithmetic_string_add(char *n1, char *n2)
{
	size_t		size[3];
	char		*to_fly[2];

	if (!n1 || !n2)
		return (NULL);
	size[1] = ft_strlen(n1);
	size[2] = ft_strlen(n2);
	if (size[1] > size[2])
		size[0] = size[2];
	else
		size[0] = size[1];
	to_fly[0] = n1;
	to_fly[1] = n2;
	return (ft_long_arithmetic_string_add_work(to_fly, size));
}
