/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:05:13 by asabani           #+#    #+#             */
/*   Updated: 2021/08/25 13:36:39 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // TODO : remove this line
#include <stdlib.h>
#include <unistd.h>
#include "../include/ft.h"

int	get_rows(char *str, int index)
{
	int	i;
	int	res;

	res = 0;
	i = -1;
	while (++i < index)
	{
		if (!is_digit(str[i]))
			return (-1);
		res = res * 10 + str[i] - '0';
	}
	return (res);
}

void	read_first_line(int fd, t_map_data *map)
{
	char	*str;
	int		i;

	str = malloc(30);
	i = 0;
	map->rows = 0;
	map->cols = 0;
	while (read(fd, str + i, 1))
	{
		if (str[i++] == '\n')
			break ;
	}
	str[--i] = 0;
	if (is_twice(str + i - 3))
	{
		map->empty = str[i - 3];
		map->obstacle = str[i - 2];
		map->full = str[i - 1];
		map->rows = get_rows(str, i - 3);
		map->is_valid = map->rows != -1;
	}
	else
		map->is_valid = 0;
	free(str);
}

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

void	check_each_line(int fd, t_map_data *map_data)
{
	int		*line;
	int		i;
	char	buff;
	int		cols;
	int		k;

	i = 0;
	k = 0;
	cols = 0;
	map_data->is_valid = 1;
	while (read(fd, &buff, 1))
	{
		if (buff == '\n')
		{
			if (k == 0)
				cols = i;
			if (k > 0 && cols != i)
			{
				map_data->is_valid = 0;
				return ;
			}
			map_data->map[k] = line;
			map_data->cols = i;
			i = 0;
			line = 0;
			k++;
			continue ;
		}
		if (buff == map_data->obstacle)
			line = line_pusher(line, i, 0);
		else if (buff == map_data->empty)
			line = line_pusher(line, i, 1);
		else
		{
			map_data->is_valid = 0;
			return ;
		}
		i++;
	}	
}

t_map_data	*ft_get_map(int fd)
{
	t_map_data	*map_data;

	map_data = malloc(sizeof(t_map_data));
	//check_first_line(fd, map_data);
	read_first_line(fd, map_data);
	map_data->map = malloc(map_data->rows * sizeof(int *));
	check_each_line(fd, map_data);
	return (map_data);
}
