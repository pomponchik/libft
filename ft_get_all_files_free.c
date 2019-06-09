#include "libft.h"

t_list *ft_get_all_files_free(t_list *paths)
{
  t_list *result;

  if (!(result = ft_get_all_files(paths)))
    return (NULL);
  ft_lst_free_chain(paths);
  return (result);
}
