/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:26:49 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/15 11:43:01 by omoussao         ###   ########.fr       */
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
			// if full: print and go back once
			if (col == 9)
			{
				write(1, state, 10);
				write(1, "\n", 1);
				if (++(*count) == 724)
					return ;
				break ;
			}
			// else: fill position and get_av_path(new state, col + 1, pos = '0')
			else
				get_av_path(state, col + 1, '0', count);
		}
		pos++;
	}
	// if the while ended and the code arrived to this line... this means we reached a dead end
	// or that we - yaaay :) - reached a solution, but we still have to backtrack
	// so...
	// save the position at this col in orddeer to skip it the next time (to_skip = state[col])
	// --> backtrack the state (state[col] = NUL)
	// --> start from the new "back tracked" state: get_av_path(state, col - 1, to_skip + 1))
	if (*count < 724)
	{
		get_av_path(state, col - 1, state[col - 1] + 1, count);
		return ;
	}
	return ;
}

int	ft_ten_queens_puzzle(void)
{
	int		i;
	char	buffer[10];
	int		count;

	i = -1;
	while (++i < 10)
		buffer[i] = 0;
	count = 0;
	get_av_path(buffer, 0, '0', &count);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	int	sol_count;
	
	sol_count = ft_ten_queens_puzzle();
	printf("\n\n\nSolutions: %d\n\n\n", sol_count);
}

