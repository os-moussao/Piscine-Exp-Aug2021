/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:18:05 by asabani           #+#    #+#             */
/*   Updated: 2021/08/25 19:41:04 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft.h"
#define MAX_SIZE 10485760

char	*buffer_duplicate(char *buffer, int k)
{
	char	*bt;
	int		i;

	bt = (char *)malloc(sizeof(char) * (k + MAX_SIZE + 1));
	i = 0;
	while (i < k && buffer[i])
	{
		bt[i] = buffer[i];
		i++;
	}
	bt[i] = '\0';
	free(buffer);
	return (bt);
}

void	reader(char **buff, int fd)
{
	int	k;
	int	j;
	int	count;

	k = 0;
	j = 0;
	while (1)
	{
		if (j % MAX_SIZE == 0)
		{
			*buff = buffer_duplicate(*buff, k);
			j = 0;
		}
		count = read(fd, *buff + k, MAX_SIZE - j);
		k += count;
		j += count;
		if (count == 0)
			break ;
	}
	(*buff)[k] = 0;
}

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
