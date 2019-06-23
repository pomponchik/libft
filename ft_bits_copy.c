#include "libft.h"
#include <stdio.h>

static size_t ft_bits_copy_helper(void *src, void *dst, \
	size_t amount, size_t begin)
{
	size_t index;
	size_t result;
	unsigned char value;

	index = 0;
	result = 0;
	size_t y = 0;
	//printf("begin = %lu, amount = %lu\n", begin, amount);
	//ft_bits_filler(dst, begin, amount, 1);
	while (result < amount)
	{
		//printf("%lu, index = %lu, begin = %lu\n", y, index, begin);
		//ft_bits_write_bit(void *byte, size_t num_bit, unsigned char value)
		//ft_bits_write_bit(void *byte, size_t num_bit, unsigned char value)
		if (ft_bits_read_bit(src, begin))
			value = 1;
		else
			value = 0;
		ft_bits_write_bit(dst, index, value);
		index++;
		begin++;
		if (begin == 8)
		{
			//printf("n1\n");
			begin = 0;
			src = ft_jump_pointer_size_t(src, 1);
		}
		if (index == 8)
		{
			//printf("n2\n");
			index = 0;
			dst = ft_jump_pointer_size_t(dst, 1);
		}
		result++;
		y++;
	}
	return (result / 8 + (result % 8) ? 1 : 0);
}

size_t ft_bits_copy(void *src, void *dst, size_t amount, size_t begin)
{
	size_t jump;

	if (!src || !amount || !dst)
		return (0);
	jump = 0;
	//printf("begin = %lu, amount = %lu\n", begin, amount);
	if (begin > 7)
	{
		jump = (begin) / 8;
		src = ft_jump_pointer_size_t(src, jump);
		begin -= jump * 8;
	}
	//printf("begin = %lu, amount = %lu\n", begin, amount);
	return (ft_bits_copy_helper(src, dst, amount, begin));
}
