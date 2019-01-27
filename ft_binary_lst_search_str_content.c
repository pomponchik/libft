#include "libft.h"

t_two_list *ft_binary_lst_search_str_content(t_two_list *alst, char *to_search)
{
  t_two_list *temp;

	if (!alst || !to_search)
		return (NULL);
  temp = alst;
  while (temp)
  {
    if (!ft_strcmp((char *)temp->content, to_search))
      return (temp);
    temp = temp->next;
  }
  temp = alst->back;
  while (temp)
  {
    if (!ft_strcmp((char *)temp->content, to_search))
      return (temp);
    temp = temp->back;
  }
  return (NULL);
}
