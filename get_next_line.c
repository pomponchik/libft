/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:05:47 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/09 22:18:23 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*search_lst(t_list *lst, int fd, int *i)
{
	t_list			*temp;

	temp = lst;
	*i = 1;
	while (temp)
	{
		if ((int)(temp->content_size) == fd)
		{
			if (temp->content)
				return (temp);
		}
		temp = temp->next;
	}
	return (NULL);
}

static char			*adder(t_list **lst, int fd, t_iter *i)
{
	t_list			*temp;

	i->work = 0;
	i->in = 0;
	i->chr = NULL;
	temp = *lst;
	while (temp)
	{
		if ((int)(temp->content_size) == fd)
		{
			if (temp->content)
				return ((char *)(temp->content));
		}
		temp = temp->next;
	}
	temp = ft_lstnew("", 1);
	temp->content_size = (size_t)fd;
	ft_lstadd(lst, temp);
	return ((char *)(temp->content));
}

static char			*joiner(char *s1, char *s2, t_iter *i)
{
	char			*result;

	i->work = 1;
	s2[i->in] = '\0';
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

static char			*convert(char *old, t_list *lst, t_iter *i)
{
	size_t			index;
	char			*new;
	char			*residue;

	index = 0;
	while (old[index] && old[index] != '\n')
		index++;
	if (!(new = ft_strnew_not_bzero(index)))
		return (NULL);
	ft_memcpy(new, old, index);
	residue = ft_strdup((ft_strchr(old, '\n') + 1));
	free(old);
	lst->content = residue;
	i->work = 1;
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	char			buf[BUFF_SIZE + 1];
	t_iter			i;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	i.str = adder(&lst, fd, &i);
	while ((i.in = read(fd, buf, BUFF_SIZE)))
	{
		i.str = joiner(i.str, buf, &i);
		if (ft_strchr(i.str, '\n') || i.in < BUFF_SIZE)
			break ;
	}
	if (!(i.chr = ft_strchr(i.str, '\n')) && i.in < BUFF_SIZE)
		(search_lst(lst, fd, &i.work))->content_size = -1;
	if (i.in < BUFF_SIZE && !ft_strlen(i.str))
		return (0);
	if (i.chr)
		i.str = convert(i.str, search_lst(lst, fd, &i.work), &i);
	if (!i.work)
		(search_lst(lst, fd, &i.work))->content_size = -1;
	*line = i.str;
	return (1);
}
