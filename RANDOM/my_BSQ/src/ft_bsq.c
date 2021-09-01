/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 07:33:40 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/25 16:20:11 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft.h"

int	min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void	fill_bsq(t_bsq *bsq, int i, int j, int sq)
{
	(*bsq).i = i;
	(*bsq).j = j;
	(*bsq).sq = sq;
}

void	update_map(t_map_data *map, t_bsq bsq)
{
	int	i;
	int	j;

	i = bsq.i - 1;
	while (++i < bsq.i + bsq.sq)
	{
		j = bsq.j - 1;
		while (++j < bsq.j + bsq.sq)
			map->map[i][j] = -1;
	}
}

void	find_bsq(t_map_data *map)
{
	int		i;
	int		j;
	t_bsq	bsq;

	fill_bsq(&bsq, 0, 0, 0);
	i = map->rows;
	while (--i >= 0)
	{
		j = map->cols;
		while (--j >= 0)
		{
			if (i != map->rows - 1 && j != map->cols - 1 && map->map[i][j])
				map->map[i][j] += min(map->map[i + 1][j + 1],
						map->map[i][j + 1], map->map[i + 1][j]);
			if (map->map[i][j] >= bsq.sq)
				fill_bsq(&bsq, i, j, map->map[i][j]);
		}
	}
	update_map(map, bsq);
}

void	print_bsq(t_map_data *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->map[i][j] == -1)
				write(1, &map->full, 1);
			else if (map->map[i][j])
				write(1, &map->empty, 1);
			else
				write(1, &map->obstacle, 1);
		}
		write(1, "\n", 1);
		free(map->map[i]);
	}
	free(map->map);
	free(map);
}

/*
void	print_bsq(t_map_data map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map.rows)
	{
		j = -1;
		while (++j < map.cols)
		{
			if (map.map[i][j] == -1)
				write(1, &map.full, 1);
			else if (map.map[i][j])
				write(1, &map.empty, 1);
			else
				write(1, &map.obstacle, 1);
		}
		write(1, "\n", 1);
		// free(map[i]);
	}
	// free map
}
*/

/*
void	print_bsq(t_map_data map)
{
	int		i;
	int		j;
	int		len;
	int		r;
	char	*res;

	r = map.rows;
	len = (r + 1) * map.cols;
	res = malloc(len);
	i = -1;
	while (++i < r)
	{
		j = -1;
		while (++j < map.cols)
		{
			if (map.map[i][j] == -1)
				res[i * r + i + j] = map.full;
				//write(1, &map.full, 1);
			else if (map.map[i][j])
				res[i * r + i + j] = map.empty;
				//write(1, &map.empty, 1);
			else
				res[i * r + i + j] = map.obstacle;
				//write(1, &map.obstacle, 1);
		}
		res[i * r + i + j] = '\n';
		//write(1, "\n", 1);
	}
	write(1, res, len);
	free(res);
}
*/
