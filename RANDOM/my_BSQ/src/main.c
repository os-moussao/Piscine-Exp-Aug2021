/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:29:34 by asabani           #+#    #+#             */
/*   Updated: 2021/08/25 16:30:34 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <fcntl.h>
#include "ft.h"
#define STDIN 0

int	main(int ac, char **av)
{
	int			fd;
	int			i;
	t_map_data	*map_data;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			fd = open(av[i], O_RDONLY);
			if (fd == -1)
			{
				ft_map_error(map_data);
				i++;
				continue ;
			}
			map_data = ft_get_map(fd);
			if (map_data->is_valid)
			{
				find_bsq(map_data);
				print_bsq(map_data);
			}
			else
				ft_map_error(map_data);
			i++;
		}
	}
	else
	{
		map_data = ft_get_map(STDIN);
		if (map_data->is_valid)
			printf("is_valid	: %d\n", map_data->is_valid);
		else
			ft_map_error(map_data);
	}
}
