#include "libft.h"

void *ft_jump_pointer_to_n(void *pointer, size_t n)
{
	char *temp_pointer;

	if (!pointer)
		return (NULL);
	temp_pointer = (char *)pointer;
	return (temp_pointer + n);
}
