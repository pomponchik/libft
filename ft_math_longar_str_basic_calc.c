/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_longar_str_basic_calc.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 22:17:14 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/09 22:17:17 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list *ft_math_longar_str_basic_calc_signs(char *exp)
{
	size_t index;
	size_t count;
	t_list *result;

	ft_nuller_double_size_t(&count, &index);
	result = NULL;
	while (exp[index])
	{
		if (ft_issign(exp[index]))
		{
			if (exp[index] == '-' && count)
			{
				index++;
				break ;
			}
			if (count >= 1)
			{
				ft_lst_free_chain(result);
				return (NULL);
			}
			if (exp[index] == '*' && exp[index + 1] == '*')
				ft_lstadd(&result, ft_lstnew_no_copy(ft_strnew_filler(1, '.'), 1));
			else
				ft_lstadd(&result, ft_lstnew_no_copy(ft_strnew_filler(1, \
					exp[index]), 1));
			count++;
		}
		else
			count = 0;
		index++;
	}
	return (ft_lst_turn(result));
}

static void ft_math_longar_str_basic_calc_worker_mult(t_list *num, t_list *sign, int mult)
{
	char si;
	char *result;
	t_list *temp;
	int ind;

	si = ((char *)(sign->content))[0];
	ind = 0;
	ft_putstr("RR1\n");
	if (si == '+' && !mult)
	{
		ft_putstr("oo1\n");
		ind = 1;
		result = ft_math_longar_str_add(num->content, (num->next)->content);
	}
	else if (si == '-' && !mult)
	{
		ft_putstr("oo2\n");
		result = ft_math_longar_str_subtraction(num->content, (num->next)->content);
	}
	else if (si == '*' && mult)
	{
		ft_putstr("oo3\n");
		ft_putstr(num->content);
		ft_putstr("\n");
		ft_putstr((num->next)->content);
		ft_putstr("\n");
		ind = 1;
		result = ft_math_longar_str_multi(num->content, (num->next)->content);
	}
	else if (si == '/' && mult)
	{
		ind = 1;
		ft_putstr("oo4\n");
		result = ft_math_longar_str_division(num->content, (num->next)->content);
	}
	else if (si == '%' && mult)
	{
		ind = 1;
		ft_putstr("oo5\n");
		result = ft_math_longar_str_remainder_of_division(num->content, (num->next)->content);
	}
	else
	{
		ind = 1;
		ft_putstr("oo6\n");
		result = ft_math_longar_str_exponent_mix(num->content, \
			(unsigned long int)ft_atoi((num->next)->content));
		ft_putstr("oo7\n");
	}
	ft_putstr("RR2\n");
	ft_free_both(num->content, (num->next)->content);
	ft_putstr("RR3\n");
	if (ind)
	{
		temp = num->next;
		ft_putstr("RR4\n");
		num->next = (num->next)->next;
		ft_putstr("RR5\n");
		free(num->next);
		ft_putstr("RR6\n");
		num->content = result;
		ft_putstr("RR7\n");
	}
}

static char *ft_math_longar_str_basic_calc_worker(t_list *numbers, t_list *signs)
{
	t_list *numbers_t;
	t_list *signs_t;

	if (!numbers || !signs)
	{
		ft_lst_free_chain(numbers);
		ft_lst_free_chain(signs);
		return (NULL);
	}
	ft_putstr("hh1\n");
	numbers_t = numbers;
	signs_t = signs;
	ft_putstr("hh2\n");
	while (signs && numbers->next)
	{
		ft_putstr("hh3\n");
		ft_math_longar_str_basic_calc_worker_mult(numbers, signs, 1);
		ft_putstr("hh4\n");
		numbers = numbers->next;
		signs = signs->next;
	}
	ft_putstr("hh5\n");
	numbers = numbers_t;
	ft_putstr("hh6\n");
	while (signs_t && numbers->next)
	{
		ft_putstr("hh7\n");
		ft_math_longar_str_basic_calc_worker_mult(numbers_t, signs_t, 1);
		ft_putstr("hh8\n");
		numbers_t = numbers_t->next;
		signs_t = signs_t->next;
	}
	ft_putstr("hh9\n");
	return (ft_strdup(numbers->content));
}

char *ft_math_longar_str_basic_calc(char *exp)
{
	t_list *numbers;
	t_list *signs;
	char *result;

	if (!exp)
		return (NULL);
	numbers = ft_lst_cut_numbers(exp);
	signs = ft_math_longar_str_basic_calc_signs(exp);
	if (ft_lst_chain_len(numbers) != ft_lst_chain_len(signs) + 1)
	{
		ft_lst_free_chain(numbers);
		ft_lst_free_chain(signs);
		return (NULL);
	}
	result = ft_math_longar_str_basic_calc_worker(numbers, signs);

	if (result)
	{
		ft_lst_free_chain(numbers);
		ft_lst_free_chain(signs);
	}
	return (result);
}
// 
// 100 - 15 * 2
//
// 100 30
//    -  *
