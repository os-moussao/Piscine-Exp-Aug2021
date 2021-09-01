/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:26:49 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/15 12:02:17 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	under_attack(char *buff, int col, char pos)
{
	int	diff;
	int	i;

	if (col == 0)
		return (0);
	i = -1;
	while (++i < col)
	{
		diff = col - i;
		if (buff[i] == pos + diff || buff[i] == pos - diff
			|| buff[i] == pos)
			return (1);
	}
	return (0);
}

void	get_av_path(char *state, int col, char pos, int *count)
{
	if (*count == 724)
		return ;
	while (pos <= '9')
	{
		if (!under_attack(state, col, pos))
		{
			state[col] = pos;
			if (col == 9)
			{
				write(1, state, 10);
				write(1, "\n", 1);
				(*count)++;
				break ;
			}
			else
				get_av_path(state, col + 1, '0', count);
		}
		pos++;
	}
	get_av_path(state, col - 1, state[col - 1] + 1, count);
}

int	ft_ten_queens_puzzle(void)
{
	int		i;
	char	buffer[10];
	int		solution_count;

	i = -1;
	while (++i < 10)
		buffer[i] = 0;
	solution_count = 0;
	get_av_path(buffer, 0, '0', &solution_count);
	return (solution_count);
}
