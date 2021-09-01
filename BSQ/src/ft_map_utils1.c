/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:43:52 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/25 19:44:15 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	get_rows(char *str, int index)
{
	int	i;
	int	res;

	res = 0;
	i = -1;
	while (++i < index)
	{
		if (!is_digit(str[i]))
			return (0);
		res = res * 10 + str[i] - '0';
	}
	return (res);
}

char	*read_first_line(char *buffer, t_map_data *map)
{
	int		i;

	i = 0;
	map->rows = 0;
	map->cols = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (is_twice(buffer + i - 3))
	{
		map->empty = buffer[i - 3];
		map->obstacle = buffer[i - 2];
		map->full = buffer[i - 1];
		map->rows = get_rows(buffer, i - 3);
		map->is_valid = map->rows != 0;
	}
	else
		map->is_valid = 0;
	return (buffer + i + 1);
}
