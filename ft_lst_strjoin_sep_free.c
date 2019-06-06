#include "libft.h"

char		*ft_lst_strjoin_sep_free(t_list *lst, char *separator)
{
  char *result;

  result = ft_lst_strjoin_sep(lst, separator);
  ft_lst_free_chain(lst);
  return (result);
}
