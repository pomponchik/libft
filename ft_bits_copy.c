#include "libft.h"
#include <stdio.h>

static size_t ft_bits_copy_helper(void *src, void *dst, \
	size_t amount, size_t begin)
{
	size_t index;
	size_t index2;
	size_t result;

	index = 0;
	index2 = begin;
	result = 0;
	while (result < amount)
	{
		printf("%lu\n", index);
		ft_bits_write_bit(dst, index, ft_bits_read_bit(src, index2));
		if (index2 == 7)
		{
			index2 = 0;
			src = ft_jump_pointer_size_t(src, 1);
		}
		if (index == 7)
		{
			index = 0;
			dst = ft_jump_pointer_size_t(dst, 1);
		}
		index++;
		index2++;
		result++;
	}
	return (result / 8 + (result % 8) ? 1 : 0);
}

size_t ft_bits_copy(void *src, void *dst, size_t amount, size_t begin)
{
	size_t jump;

	if (!src || !amount || !dst)
		return (0);
	jump = 0;
	if (begin > 7)
	{
		src = ft_jump_pointer_size_t(src, (jump = (begin + 1) / 8));
		begin -= jump * 8;
	}
	return (ft_bits_copy_helper(src, dst, amount, begin));
}
