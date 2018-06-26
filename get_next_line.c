/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dponsonb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:59:39 by dponsonb          #+#    #+#             */
/*   Updated: 2018/06/26 13:05:17 by dponsonb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"

static int		ft_findnl(char *tmp)
{
	int				i;

	i = 0;
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	return (i);
}

static char		*ft_freejoin(char *tmp, char *buf)
{
	size_t			len;
	char			*mem;

	if (!tmp || !buf)
		return (NULL);
	len = ((ft_strlen(tmp) + ft_strlen(buf)));
	if (!(mem = ft_strnew(len)))
		return (NULL);
	mem = ft_strcat(mem, tmp);
	free(tmp);
	mem = ft_strcat(mem, buf);
	return (mem);
}

static char		*ft_makeline(char **line, char *tmp, int nlpos)
{
	char			*str;

	*line = ft_strsub(tmp, 0, nlpos);
	if (ft_strcmp(*line, tmp) == 0)
		tmp = NULL;
	else
	{
		str = tmp;
		tmp = ft_strsub(tmp, nlpos + 1, ft_strlen(tmp + nlpos + 1));
		free(str);
	}
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	int				read_ret;
	char			buf[BUFF_SIZE + 1];
	static char		*tmp;
	int				nlpos;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (tmp == NULL)
		tmp = ft_strnew(0);
	while ((read_ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_ret] = '\0';
		tmp = ft_freejoin(tmp, buf);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	if (read_ret < BUFF_SIZE && !ft_strlen(tmp))
		return (0);
	nlpos = ft_findnl(tmp);
	tmp = ft_makeline(line, tmp, nlpos);
	return (1);
}
