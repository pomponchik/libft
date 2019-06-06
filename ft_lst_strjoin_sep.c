#include "libft.h"

static void lst_middle_insert(t_list *lst, char *separator)
{
  t_list *new;
  size_t str_size;

  str_size = ft_strlen(separator) + 1;
  while (lst)
  {
    if (lst->next)
    {
      new = ft_lstnew_without_copy(ft_memdup(separator, str_size), str_size);
      new->next = lst->next;
      lst->next = new;
    }
    lst = lst->next;
  }
}

char		*ft_lst_strjoin_sep(t_list *lst, char *separator)
{
  t_list *temp;
  char *result;

  if (!lst)
    return (NULL);
  if (separator && *separator)
  {
    temp = ft_lst_copy_chain(lst);
    lst_middle_insert(temp, separator);
    result = ft_lst_strjoin(temp);
    ft_lst_free_chain(temp);
  }
  else
    result = ft_lst_strjoin(lst);
  return (result);
}
