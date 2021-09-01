/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:05:13 by asabani           #+#    #+#             */
/*   Updated: 2021/08/25 19:45:56 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft.h"

int	*line_pusher(int *old_line, int size, int num)
{
	int	*new_buff;
	int	i;

	if (!old_line)
		old_line = malloc(1);
	new_buff = malloc(sizeof(int) * (size + 1));
	i = 0;
	while (i < size)
	{
		new_buff[i] = old_line[i];
		i++;
	}
	new_buff[i] = num;
	return (new_buff);
}

char	*get_line_info(char *buffer, t_map_data *map_data)
{
	int	*line;
	int	i;

	i = 0;
	map_data->is_valid = 1;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			map_data->map[0] = line;
			map_data->cols = i;
			break ;
		}
		if (buffer[i] == map_data->obstacle)
			line = line_pusher(line, i, 0);
		else if (buffer[i] == map_data->empty)
			line = line_pusher(line, i, 1);
		else
		{
			map_data->is_valid = 0;
			return (0);
		}
		i++;
	}
	return (buffer + i + 1);
}

int	get_each_line(char *buffer, t_map_data *map_data)
{
	int		j;
	int		i;
	int		k;

	i = -1;
	k = 1;
	while (buffer[++i])
	{
		map_data->map[k++] = malloc(sizeof(int) * map_data->cols);
		j = -1;
		while (buffer[++j] != '\n' && buffer[i])
		{
			if (buffer[i++] == map_data->obstacle)
				map_data->map[k - 1][j] = 0;
			else if (buffer[i - 1] == map_data->empty)
				map_data->map[k - 1][j] = 1;
			else
				return (0);
		}
		if (j != map_data->cols)
			return (0);
	}
	if (k != map_data->rows)
		return (0);
	return (1);
}

t_map_data	*ft_get_map(char *buffer)
{
	t_map_data	*map_data;
	char		*str;

	str = buffer;
	map_data = malloc(sizeof(t_map_data));
	str = read_first_line(str, map_data);
	if (!map_data->is_valid)
		return (map_data);
	map_data->map = malloc(map_data->rows * sizeof(int *));
	str = get_line_info(str, map_data);
	if (!map_data->is_valid)
		return (map_data);
	if (!get_each_line(str, map_data))
		map_data->is_valid = 0;
	return (map_data);
}
