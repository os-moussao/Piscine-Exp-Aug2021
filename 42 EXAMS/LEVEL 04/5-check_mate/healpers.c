/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   healpers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:27:47 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:27:52 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check.h"

int	get_col(char piece, char *row)
{
	int	col;

	col = -1;
	while (row[++col])
	{
		if (piece == row[col])
			return (col);
	}
	return (-1);
}

t_pos	get_pos(char **tab, int size, char piece)
{
	t_pos	position;
	int		i;

	position.piece = piece;
	position.row = -1;
	position.col = -1;
	i = -1;
	while (++i < size)
	{
		if (get_col(piece, tab[i]) != -1)
		{
			position.row = i;
			position.col = get_col(piece, tab[i]);
			break ;
		}
	}
	return (position);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**set_the_board(char **rows, int size)
{
	char	**tab;
	int		i;

	tab = malloc(size * sizeof(char *));
	i = -1;
	while (++i < size)
	{
		tab[i] = malloc(size + 1);
		ft_strncpy(tab[i], rows[i], size);
	}
	return (tab);
}
