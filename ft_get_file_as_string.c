/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_as_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:58:05 by ahalmon-          #+#    #+#             */
/*   Updated: 2020/01/06 15:34:42 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_get_file_as_string_counter(void *file, size_t size)
{
	size_t			index;
	size_t			result;
	unsigned char	*file_bytes;

	index = 0;
	result = 0;
	file_bytes = (unsigned char *)file;
	while (index < size)
	{
		if (file_bytes[index] != '\0')
			result++;
		index++;
	}
	return (result);
}

static void			ft_get_file_as_string_filler(unsigned char *result, \
	unsigned char *file, size_t size)
{
	size_t			counter;

	counter = 0;
	while (counter < size)
	{
		if (*file != '\0')
		{
			*result = *file;
			result++;
			counter++;
		}
		file++;
	}
}

unsigned char		*ft_get_file_as_string(char *filename)
{
	void			*file;
	size_t			size;
	size_t			new_size;
	unsigned char	*result;

	if (!(file = ft_get_file(filename, &size)))
		return (NULL);
	new_size = ft_get_file_as_string_counter(file, size);
	if (((size_t)(size + new_size + 1) - new_size - 1) != size)
		return (ft_free(file));
	if (!(result = (unsigned char *)malloc(new_size + 1)))
		return (ft_free(file));
	result[new_size] = '\0';
	ft_get_file_as_string_filler(result, (unsigned char *)file, new_size);
	return (result);
}
