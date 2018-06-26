/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tmp_ret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dponsonb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 08:05:38 by dponsonb          #+#    #+#             */
/*   Updated: 2018/06/26 08:08:20 by dponsonb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*#include <stdio.h>*/
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc < 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
/*	while*/ get_next_line(fd, &line);
/*	{
		printf("%s\n", line);
	}*/
	return (0);
}
