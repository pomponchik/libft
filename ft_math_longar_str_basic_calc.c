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

static int ft_math_longar_str_basic_calc_worker_mult(t_list *num, t_list *sign, int mult)
{
	char si;
	char *result;
	t_list *temp;
	int ind;

	ft_putstr(num->content);
	ft_putstr(" ");
	ft_putstr(sign->content);
	ft_putstr(" ");
	ft_putstr((num->next)->content);
	ft_putstr("\n");
	si = ((char *)(sign->content))[0];
	ind = 0;
	if (si == '+' && !mult)
	{
		ind = 1;
		result = ft_math_longar_str_add(num->content, (num->next)->content);
	}
	else if (si == '-' && !mult)
	{
		result = ft_math_longar_str_subtraction(num->content, (num->next)->content);
	}
	else if (si == '*' && mult)
	{
		ind = 1;
		result = ft_math_longar_str_multi(num->content, (num->next)->content);
	}
	else if (si == '/' && mult)
	{
		ind = 1;
		result = ft_math_longar_str_division(num->content, (num->next)->content);
	}
	else if (si == '%' && mult)
	{
		ind = 1;
		result = ft_math_longar_str_remainder_of_division(num->content, (num->next)->content);
	}
	else
	{
		ind = 1;
		result = ft_math_longar_str_exponent_mix(num->content, \
			(unsigned long int)ft_atoi((num->next)->content));
	}
	ft_free_both(num->content, (num->next)->content);
	if (ind)
	{
		temp = num->next;
		num->next = (num->next)->next;
		free(num->next);
		num->content = result;
		return (1);
	}
	return (0);
}

static char *ft_math_longar_str_basic_calc_worker(t_list *numbers, t_list *signs)
{
	t_list *numbers_t;
	t_list *signs_t;
	t_list *previous;
	t_list *temp;
	int res;

	if (!numbers || !signs)
	{
		ft_lst_free_chain(numbers);
		ft_lst_free_chain(signs);
		return (NULL);
	}
	ft_putstr("hi1\n");
	numbers_t = numbers;
	signs_t = signs;
	previous = NULL;
	ft_putstr("hi2\n");
	while (signs && numbers->next)
	{
		ft_putstr("dd1\n");
		res = ft_math_longar_str_basic_calc_worker_mult(numbers, signs, 1);
		ft_putstr("dd2\n");
		if (res)
		{
			ft_putstr("dd3\n");
			if (previous)
			{
				ft_putstr("dd4\n");
				temp = signs->next;
				ft_free_both(signs->content, signs);
				//numbers = numbers->next;
				previous->next = temp;
				signs = temp;
				ft_putstr("dd5\n");
				continue ;
			}
			ft_putstr("dd6\n");
			temp = signs->next;
			ft_free_both(signs->content, signs);
			signs = temp;
			ft_putstr("dd7\n");
			signs_t = temp;
			//numbers = numbers->next;
			ft_putstr("dd8\n");
			continue ;
		}
		ft_putstr("dd9\n");
		previous = signs;
		numbers = numbers->next;
		signs = signs->next;
		ft_putstr("dd10\n");
	}
	ft_putstr("hi3\n");
	numbers = numbers_t;
	previous = NULL;
	while (signs_t && numbers->next)
	{
		res = ft_math_longar_str_basic_calc_worker_mult(numbers_t, signs_t, 1);
		if (res)
		{
			if (previous)
			{
				temp = signs_t->next;
				ft_free_both(signs_t->content, signs_t);
				//numbers_t = numbers_t->next;
				previous->next = temp;
				signs_t = temp;
				continue ;
			}
			temp = signs_t->next;
			ft_free_both(signs_t->content, signs_t);
			signs_t = temp;
			//numbers_t = numbers_t->next;
			continue ;
		}
		previous = signs_t;
		numbers_t = numbers_t->next;
		signs_t = signs_t->next;
	}
	ft_putstr("hi4\n");
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
