/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_this_files_is_same.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:54:41 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/16 20:35:40 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_this_files_is_same_opener(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd > 0)
		return (fd);
	return (-1);
}

static int	ft_this_files_is_same_loop(int fd1, int fd2)
{
	char	*line_1;
	char	*line_2;
	int		r1;
	int		r2;

	while (1)
	{
		r1 = get_next_line(fd1, &line_1);
		r2 = get_next_line(fd2, &line_2);
		if (((r1 <= 0) && (r2 > 0)) || ((r2 <= 0) && (r1 > 0)))
		{
			ft_free_both(line_1, line_2);
			if (r1 < 0 || r2 < 0)
				return (-1);
			return (0);
		}
		if (ft_strcmp(line_1, line_2))
		{
			ft_putstr("1: <");
			ft_putstr(line_1);
			ft_putstr(">\n");
			ft_putstr("2: <");
			ft_putstr(line_2);
			ft_putstr(">\n");
			//ft_free_both(line_1, line_2);
			return (0);
		}
		ft_free_both(line_1, line_2);
		if (!r1 && r1 == r2)
			break ;
	}
	return (1);
}

int			ft_this_files_is_same(char *fn1, char *fn2)
{
	int		fd1;
	int		fd2;
	int		result;

	if ((fd1 = ft_this_files_is_same_opener(fn1)) <= 0)
		return (fd1);
	if ((fd2 = ft_this_files_is_same_opener(fn2)) <= 0)
	{
		close(fd1);
		return (fd2);
	}
	result = ft_this_files_is_same_loop(fd1, fd2);
	close(fd1);
	close(fd2);
	return (result);
}
