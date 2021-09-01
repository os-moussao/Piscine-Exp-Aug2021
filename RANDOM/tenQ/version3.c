/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:26:49 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/14 18:53:30 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// I need a diagonal check
// a function that checks av paths
// a function that checks dead ends
// a function the prints a solution and reverse itself to print next ones
// how to define my state:
// 		* solution buffer filled with NUL chars
// 		* state is how many filled chars
// 		* a solution is a full state buff[10] is not NUL


int	under_attack(char *buff, int col, char pos)
{
	int	diff;
	int	i;

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

#include <string.h>

void	get_av_path(char *state, int col, char pos)
{
	char	to_skip;

	while (pos <= '9')
	{
		if (!under_attack(state, col, pos))
		{
			state[col] = pos;
			// if full: print and go back once
			if (col == 9)
			{
				write(1, state, 10);
				write(1, "\n", 1);
				if (!strncmp(state, "9742051863", 10))
					return ;
				break ;
			}
			// else: fill position and get_av_path(new state, col + 1, pos = '0')
			else
				get_av_path(state, col + 1, '0');
		}
		pos++;
	}
	// if the while ended and the code arrived to this line... this means we reached a dead end
	// or that we - yaaay :) - reached a solution, but we still have to backtrack
	// so...
	// save the position at this col in orddeer to skip it the next time (to_skip = state[col])
	// --> backtrack the state (state[col] = NUL)
	// --> start from the new "back tracked" state: get_av_path(state, col - 1, to_skip + 1))
	to_skip = state[col];
	state[col] = 0;
	get_av_path(state, col - 1, to_skip + 1);
}

int	ft_ten_queens_puzzle(void)
{
	int		i;
	char	buffer[20];

	i = -1;
	while (++i < 10)
		buffer[i] = 0;
	get_av_path(buffer, 0, '0');
	return (0);
}

#include <stdio.h>

int	main(void)
{
	ft_ten_queens_puzzle();
}
