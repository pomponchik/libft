t_list *ft_lstsearch_cs(t_list *lst, size_t fd)
{
	t_list *temp;

	temp = lst;
	while (temp)
	{
		if (temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
