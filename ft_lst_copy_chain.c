#include "libft.h"

t_list *ft_lst_copy_chain(t_list *lst)
{
  t_list *new;

  if (!lst)
    return (NULL);
  new = ft_lst_unit_transfer_with_malloc(lst);
  lst = lst->next;
  while (lst)
  {
    ft_lstadd(&new, ft_lst_unit_transfer_with_malloc(lst));
    lst = lst->next;
  }
  new = ft_lst_turn(new);
  return (new);
}
