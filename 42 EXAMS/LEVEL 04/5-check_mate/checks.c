/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:27:28 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:27:30 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check.h"

int	check_pawn(char **tab, int size)
{
	t_pos	P_pos;
	t_pos	K_pos;

	P_pos = get_pos(tab, size, 'P');
	K_pos = get_pos(tab, size, 'K');
	if (K_pos.col != -1 && K_pos.row != -1)
	{
		if ((K_pos.col == P_pos.col + 1
				|| K_pos.col == P_pos.col - 1)
			&& K_pos.row == P_pos.row - 1)
			return (1);
	}
	return (0);
}

void	switch_pieces(char *p1, char *p2)
{
	char	tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int	inside_tab(int i, int j, int size)
{
	return (i >= 0 && i <= size - 1
		&& j >= 0 && j <= size - 1);
}

int	check_line(char **tab, int size, int r_step, int c_step)
{
	int		i;
	int		j;
	char	enemy_1;
	char	enemy_2;
	char	blocker;

	i = get_pos(tab, size, 'K').row;
	j = get_pos(tab, size, 'K').col;
	if (i == -1 || j == -1)
		return (0);
	enemy_1 = 'Q';
	enemy_2 = 'B';
	blocker = 'R';
	if (c_step == 0 || r_step == 0)
		switch_pieces(&enemy_2, &blocker);
	while (inside_tab(i + r_step, j + c_step, size))
	{
		i += r_step;
		j += c_step;
		if (tab[i][j] == blocker || tab[i][j] == 'P')
			break ;
		if (tab[i][j] == enemy_1 || tab[i][j] == enemy_2)
			return (1);
	}
	return (0);
}

int	main_check(char **tab, int size)
{
	int	pawn_check;
	int	col_check;
	int	row_check;
	int	diag_1_check;
	int	diag_2_check;

	pawn_check = check_pawn(tab, size);
	col_check = check_line(tab, size, 1, 0) || check_line(tab, size, -1, 0);
	row_check = check_line(tab, size, 0, 1) || check_line(tab, size, 0, -1);
	diag_1_check = check_line(tab, size, 1, 1) || check_line(tab, size, -1, -1);
	diag_2_check = check_line(tab, size, 1, -1) || check_line(tab, size, -1, 1);
	(void)tab;
	(void)size;
	return (pawn_check || col_check
		|| row_check || diag_1_check || diag_2_check);
}
