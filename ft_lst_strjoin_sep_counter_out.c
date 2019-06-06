#include "libft.h"

static void lst_middle_insert_co(t_list *lst, char *separator)
{
  t_list *new;
  t_list *temp;
  size_t str_size;

  str_size = ft_strlen(separator) + 1;
  while (lst)
  {
    temp = lst->next;
    if (lst->next)
    {
      new = ft_lstnew_without_copy(ft_memdup(separator, str_size), str_size);
      new->next = lst->next;
      lst->next = new;
    }
    lst = temp;
  }
}

char		*ft_lst_strjoin_sep_counter_out(t_list *lst, \
  char *separator, size_t *counter)
{
  t_list *temp;
  char *result;

  if (!lst)
    return (NULL);
  if (separator && *separator)
  {
    temp = ft_lst_copy_chain(lst);
    lst_middle_insert_co(temp, separator);
    result = ft_lst_strjoin_counter_out(temp, counter);
    ft_lst_free_chain(temp);
  }
  else
    result = ft_lst_strjoin_counter_out(lst, counter);
  return (result);
}
