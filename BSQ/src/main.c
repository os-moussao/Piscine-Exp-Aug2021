/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:29:34 by asabani           #+#    #+#             */
/*   Updated: 2021/08/25 19:50:18 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft.h"
#define STDIN 0

void	run(char **buff, int fd)
{
	t_map_data	*map_data;

	reader(buff, fd);
	map_data = ft_get_map(*buff);
	if (map_data->is_valid)
	{
		find_bsq(map_data);
		print_bsq(map_data);
	}
	else
		ft_map_error(map_data);
	free(*buff);
}

int	main(int ac, char **av)
{
	char		*buff;
	int			fd;
	int			i;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			fd = open(av[i], O_RDONLY);
			if (fd == -1)
				write(2, "map error\n", 10);
			else
				run(&buff, fd);
			if (ac > 1 && i + 1 != ac)
				write(1, "\n", 1);
			i++;
		}
	}
	else
		run(&buff, STDIN);
}
