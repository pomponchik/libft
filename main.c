#include "libft.h"

// t_list *lister(int argc, char **argv)
// {
// 	t_list *result;
// 	size_t index;
// 	size_t argc_t;
//
//  argc_t = (size_t)argc;
// 	argc_t--;
// 	index = 0;
// 	result = NULL;
// 	while (index < argc_t)
// 	{
// 		ft_lstadd_to_end(&result, ft_lstnew(argv[index + 1], \
// 			ft_strlen(argv[index + 1]) + 1));
// 		index++;
// 	}
// 	return (result);
// }
//
// int prover(t_list *lst)
// {
// 	t_list *temp;
// 	t_list *temp2;
// 	int res;
//
// 	temp = lst;
// 	while (temp)
// 	{
// 		temp2 = lst;
// 		while (temp2)
// 		{
// 			if (!(res = ft_this_files_is_same((char *)temp2->content, \
// 			(char *)temp->content)))
// 				return (0);
// 			else if (res < 0)
// 				return (res);
// 			temp2 = temp2->next;
// 		}
// 		temp = temp->next;
// 	}
// 	return (1);
// }
//
// int main(int argc, char **argv)
// {
// 	t_list *lst;
// 	int res;
//
// 	if (argc < 3)
// 		ft_putstr("Usage: ./samefiles {filename1} {filename2} {...}\n");
// 	else
// 	{
// 		lst = lister(argc, argv);
// 		res = prover(lst);
// 		ft_lst_free_chain(lst);
// 		if (!res)
// 			ft_putstr("No. This files is not same.\n");
// 		else if (res > 0)
// 			ft_putstr("Yes! This files is same.\n");
// 		else
// 			ft_putstr("Error. Think better.\n");
// 	}
// 	return (0);
// }

#include <stdio.h>

// int main()
// {
// 	double lol = 1.0;
// 	printf("%.1f\n", lol);
// 	printf("%s\n", ft_itoa_long_double_wrapper(lol, 1, 1));
// 	return 0;
// }

int main()
{
	printf("%s\n", ft_str_fix_width_of_line("1234567890", '0', 6, "crop: end"));
	return 0;
}
