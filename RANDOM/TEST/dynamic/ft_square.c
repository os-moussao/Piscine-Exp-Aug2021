/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 18:03:40 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/23 12:27:30 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "bsq.h"

int	min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void	fill_pos(t_pos *pos, int i, int j, int sq)
{
	(*pos).i = i;
	(*pos).j = j;
	(*pos).sq = sq;
}

t_pos	find_bsq(int map[5][5], int len)
{
	int		i;
	int		j;
	t_pos	bsq;

	fill_pos(&bsq, 0, 0, 0);
	i = len;
	while (--i >= 0)
	{
		j = len;
		while (--j >= 0)
		{
			if (map[i][j])
			{
				if (i != len - 1 && j != len - 1)
					map[i][j] = map[i][j]
						+ min(map[i + 1][j], map[i + 1][j + 1], map[i][j + 1]);
				if (map[i][j] >= bsq.sq)
					fill_pos(&bsq, i, j, map[i][j]);
			}
		}
	}
	return (bsq);
}

void	put_bsq_in_map(int map[5][5], t_pos bsq)
{
	int	i;
	int	j;

	i = bsq.i - 1;
	while (++i < bsq.i + bsq.sq)
	{
		j = bsq.j - 1;
		while (++j < bsq.j + bsq.sq)
			map[i][j] = -1;
	}
}

void	print_bsq(int map[5][5], int len, char full, char emp, char obs)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (map[i][j] == -1)
				write(1, &full, 1);
			else if (map[i][j])
				write(1, &emp, 1);
			else
				write(1, &obs, 1);
		}
		write(1, "\n", 1);
	}
}
/* 
5.ox
o . . o .
. . o . o
o . . . o
. . . . o
. . . . .
*/
int	main(void)
{
	/*
	int map[5][5] = {
		{0, 1, 1, 0, 1},
		{1, 1, 0, 1, 0},
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1}
	};
	*/
	int map[5][5] = {
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1}
	};

	/*
	int map_sq_back[5][5] = {
		{0, 1, 1, 0, 1},
		{1, 1, 0, 1, 0},
		{0, 3, 2, 1, 0},
		{2, 2, 2, 1, 0},
		{1, 1, 1, 1, 1}
	};
	*/
	printf("Map before:\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}

	t_pos	bsq;
	bsq = find_bsq(map, 5);
	printf("\nMap after:\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
	printf("\npos.i: %d\n", bsq.i);
	printf("pos.j: %d\n", bsq.j);
	printf("pos.sq: %d\n", bsq.sq);
	put_bsq_in_map(map, bsq);
	printf("\nBSQ in MAP:\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (map[i][j] != -1)
				printf(" %d ", map[i][j]);
			else
				printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	write(1, "\n\nFINAL RESULT:\n", 16);
	print_bsq(map, 5, 'x', '.', 'o');
}

















/*
int map_sq_forw[5][5] = {
	{0, 1, 1, 0, 1},
	{1, 1, 0, 1, 0},
	{0, 1, 1, 1, 0},
	{1, 1, 2, 2, 0},
	{1, 2, 2, 3, 1}
};
*/
/*
char map_char[5][5] = {
	{'o', '.', '.', 'o', '.'},
	{'.', '.', 'o', '.', 'o'},
	{'o', '.', '.', '.', 'o'},
	{'.', '.', '.', '.', 'o'},
	{'.', '.', '.', '.', '.'}
};
*/

