/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_read_bit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:33:57 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/09 18:33:59 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char ft_bits_read_bit(void *byte, size_t num_bit)
{
	return ((unsigned char)(*((unsigned char *)byte) & (1 << num_bit)));
}
