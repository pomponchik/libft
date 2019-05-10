/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_fill_mem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:47:08 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/09 21:47:10 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void ft_bits_fill_from_begin(void *mem, size_t first_bit, \
	size_t *num_bits, unsigned char value)
{
	while (first_bit < 8 && *num_bits)
	{
		ft_bits_write_bit(mem, first_bit, value);
		(*num_bits)--;
		first_bit++;
	}
}

static void ft_bits_fill_from_end(void *mem, size_t *num_bits, \
	unsigned char value)
{
	size_t index;

	index = 0;
	while (num_bits)
	{
		ft_bits_write_bit(mem, index, value);
		index++;
		num_bits--;
	}
}

void ft_bits_fill_mem(void *mem, size_t first_bit, \
	size_t num_bits, unsigned char value)
{
	size_t num_bytes;
	int val;

	if (!mem || !num_bits || value > 1 || ~((size_t)0) - first_bit < num_bits)
		return ;
	if (first_bit > 7)
	{
		mem = ft_jump_pointer_size_t(mem, (first_bit / 8) - \
		(first_bit - (first_bit / 8)));
		first_bit -= (first_bit / 8) -	(first_bit - (first_bit / 8)) * 8;
	}
	ft_bits_fill_from_begin(mem, first_bit, &num_bits, value);
	if (!num_bits)
		return ;
	num_bytes = (first_bit + num_bits + 1) / 8;
	val = ft_maxmin("unsigned char", "max");
	ft_memset(ft_jump_pointer_size_t(mem, 1), val, num_bytes);
	if ((num_bits -= num_bytes * 8))
	{
		mem = ft_jump_pointer_size_t(mem, num_bytes + 1);
		ft_bits_fill_from_end(mem, &num_bits, value);
	}
}
