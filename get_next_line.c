/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:11:57 by mmbatha           #+#    #+#             */
/*   Updated: 2018/06/28 14:17:20 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/includes/get_next_line.h"

static int		ft_buffer_saved(char *buffer, char **to_save, \
		char **to_save_malloc)
{
	char *new_save;

	new_save = ft_strjoin(*to_save, buffer);
	free(*to_save_malloc);
	*to_save = new_save;
	*to_save_malloc = new_save;
	return (1);
}

static int		ft_save_buff_line(char *buffer, char **line, \
		char **to_save, char **to_save_malloc)
{
	char *new_line;

	new_line = ft_strchr(buffer, '\n');
	if (new_line == NULL)
	{
		ft_buffer_saved(buffer, to_save, to_save_malloc);
		return (0);
	}
	else
	{
		*new_line = '\0';
		*line = ft_strjoin(*to_save, buffer);
		**to_save = '\0';
		ft_buffer_saved(new_line + 1, to_save, to_save_malloc);
		return (1);
	}
}

static int		ft_save_line(int eof, char **line, char **to_save)
{
	char *new_line;

	if (eof)
	{
		*line = ft_strdup(*to_save);
		**to_save = '\0';
		return (1);
	}
	new_line = ft_strchr(*to_save, '\n');
	if (new_line == NULL)
		return (0);
	else
	{
		*new_line = '\0';
		*line = ft_strdup(*to_save);
		*to_save = new_line + 1;
		return (1);
	}
}

static int		ft_save_it_all(char **buffer, char **to_save, \
		char **to_save_malloc)
{
	if (*to_save == NULL)
	{
		*to_save = (char *)malloc(sizeof(char));
		*to_save_malloc = *to_save;
		**to_save = '\0';
	}
	if (*buffer == NULL)
		*buffer = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int			result;
	char		*buffer;
	char		*to_save_malloc;
	static char *to_save = NULL;

	buffer = NULL;
	to_save_malloc = NULL;
	if (fd <= -1 || line == NULL)
		return (-1);
	ft_save_it_all(&buffer, &to_save, &to_save_malloc);
	if (ft_save_line(0, line, &to_save))
		return (1);
	while ((result = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[result] = '\0';
		if (ft_save_buff_line(buffer, line, &to_save, &to_save_malloc))
			return (1);
	}
	if (result == -1)
		return (-1);
	ft_save_line(1, line, &to_save);
	if (**line != '\0')
		return (1);
	free(to_save_malloc);
	return (0);
}
