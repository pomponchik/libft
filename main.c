#include "includes/libft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
// unsigned long long int index = 0;
// t_list *temp = NULL;
// while (index <= 10)
// {
// 	//printf("%d\n", index);
// 	ft_lstadd_to_end(&temp, ft_lstnew_without_copy(ft_itoa_llu(index), ft_strlen(ft_itoa_llu(index))));
// 	index++;
// }
// temp = ft_lst_deduplication(temp);
// ft_lst_putstr_sep_free(temp, ", ");
	 //printf("%s\n", ft_itoa_long_long(ft_maxmin("long long", "min")));


	if (ft_this_all_files_is_same_free(ft_get_all_files_free(ft_get_arguments_command_line(argc, argv))))
		printf("this_files_is_same\n");
	else
		printf("nope :(\n");
	return 0;
}
