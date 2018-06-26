/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dponsonb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:16:07 by dponsonb          #+#    #+#             */
/*   Updated: 2018/06/26 10:04:19 by dponsonb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	if (argc < 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	return (0);
}
