#include "libft.h"

int			ft_this_all_files_is_same_free(t_list *files)
{
  int result;

  result = ft_this_all_files_is_same(files);
  ft_lst_free_chain(files);
  return (result);
}
