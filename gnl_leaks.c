/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL_leaks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dponsonb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:16:07 by dponsonb          #+#    #+#             */
/*   Updated: 2019/11/11 06:18:56 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int			main(void)
{
	int		fd;
	char	*str;

	fd = open("bible.txt", O_RDONLY);
	while (get_next_line(fd, &str))
	{
		ft_putendl(str);
		sleep(15);
		free(str);
	}
	return (0);
}
