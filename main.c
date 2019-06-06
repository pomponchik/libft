#include "includes/libft.h"
#include <stdio.h>

int main()
{
unsigned long long int index = 0;
t_list *temp = NULL;
while (index <= 10)
{
	//printf("%d\n", index);
	ft_lstadd_to_end(&temp, ft_lstnew_without_copy(ft_itoa_llu(index), ft_strlen(ft_itoa_llu(index))));
	index++;
}
temp = ft_lst_deduplication(temp);
ft_lst_putstr_sep_free(temp, ", ");
	 //printf("%s\n", ft_itoa_long_long(ft_maxmin("long long", "min")));
	return 0;
}
