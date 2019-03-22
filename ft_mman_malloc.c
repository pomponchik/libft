#include "libft.h"

void *ft_mmanage_malloc(size_t size)
{
	static t_block *mem_chain;
	static t_man *manage;

	if (!manage)
		manage = ft_mman_cr_manage();
	if (!size || !manage)
		return (NULL);
	if (!mem_chain)
		create_mmanage_chain(&mem_chain, manage);

}
