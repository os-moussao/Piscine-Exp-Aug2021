/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:29:02 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:29:05 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*array_init(void)
{
	char	*array;
	int		i;

	array = malloc(2048);
	i = -1;
	while (++i < 2048)
		array[i] = 0;
	return (array);
}

void	loop_backward(char *brain_f, int *index)
{
	int	match;

	match = 1;
	while (match)
	{
		(*index)--;
		if (brain_f[*index] == ']')
			match++;
		else if (brain_f[*index] == '[')
			match--;
	}
}

void	loop_forward(char *brain_f, int *index)
{
	int	match;

	match = 1;
	while (match)
	{
		(*index)++;
		if (brain_f[*index] == '[')
			match++;
		else if (brain_f[*index] == ']')
			match--;
	}
}

void	apply_inst(char *main, int *ptr, char *brain_f, int *index)
{
	if (brain_f[*index] == '>')
		*ptr = *ptr + 1;
	else if (brain_f[*index] == '<')
		*ptr = *ptr - 1;
	else if (brain_f[*index] == '+')
		main[*ptr]++;
	else if (brain_f[*index] == '-')
		main[*ptr]--;
	else if (brain_f[*index] == '.')
		write(1, &main[*ptr], 1);
	else if (brain_f[*index] == '[' && !main[*ptr])
		loop_forward(brain_f, index);
	else if (brain_f[*index] == ']' && main[*ptr])
		loop_backward(brain_f, index);
	(*index)++;
	if (brain_f[*index])
		apply_inst(main, ptr, brain_f, index);
}

int	main(int argc, char **argv)
{
	char	*main;
	int		ptr;
	int		index;

	if (argc != 2)
		return (1);
	main = array_init();
	ptr = 0;
	index = 0;
	apply_inst(main, &ptr, argv[1], &index);
	free(main);
}
