/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:21:07 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:21:09 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	duplicate_found(char *str, int index)
{
	int	j;

	j = index;
	while (--j >= 0)
	{
		if (str[index] == str[j])
			return (1);
	}
	return (0);
}

int	char_found(char *str, char c)
{
	while (*str)
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = -1;
	while (argv[1][++i])
	{
		if (!duplicate_found(argv[1], i))
			write(1, &argv[1][i], 1);
	}
	j = -1;
	while (argv[2][++j])
	{
		if (!duplicate_found(argv[2], j)
			&& !char_found(argv[1], argv[2][j]))
			write(1, &argv[2][j], 1);
	}
	write(1, "\n", 1);
	return (0);
}
