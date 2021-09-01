/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:26:49 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/14 18:31:31 by omoussao         ###   ########.fr       */
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

char	get_av_path(char *state, int col, char pos)
{
	char	to_skip;

	while (pos <= '9')
	{
		if (!under_attack(state, col, pos))
		{
			state[col] = pos;
			// if full: print			// if full: print and go back once
			if (col = 9)
			{
				write(1, state, 10);
				write(1, "\n", 1);
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

//char	print_solutions(char *buff)
//{
//	if (buff[10])
//	{
//		write(1, buff, 10);
//		write(1, "\n", 1);
//		return (print_solutions());
//	}
//	else if ()
//}

int	ft_ten_queens_puzzle(void)
{
	int		i;
	char	buffer[10];
	i = -1;
	while (++i < 11)
		buffer[i] = 0;
	buffer[0] = '0';
	buffer[1] = '2';
	buffer[2] = '4';
	return (under_attack(buffer, 3, '1'));
}

#include <stdio.h>

int	main(void)
{
	printf("%c\n", get_av_path("02413", , '2'));
}
