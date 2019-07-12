#include "libft.h"

void		*ft_memjoin_free_1(void *mem_1, size_t size_1, void *mem_2, size_t size_2)
{
	void *result;

	result = ft_memjoin(mem_1, size_1, mem_2, size_2);
	free(mem_1);
	return(result);x
}
