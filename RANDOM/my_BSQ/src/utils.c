/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:18:05 by asabani           #+#    #+#             */
/*   Updated: 2021/08/25 16:32:17 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft.h"

int	is_digit(char digit)
{
	if (digit >= '0' && digit <= '9')
		return (1);
	else
		return (0);
}

int	is_twice(char *chars)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = i + 1;
		while (j < 3)
		{
			if (chars[i] == chars[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_map_error(t_map_data *map)
{
	int	i;

	i = -1;
	while (++i < map->rows)
		free(map->map[i]);
	free(map->map);
	free(map);
	write(2, "map error\n", 10);
}
