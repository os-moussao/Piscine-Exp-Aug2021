/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:23:42 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:23:49 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_delimiter(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char **argv)
{
	int	i;
	int	begin_i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	while (is_delimiter(argv[1][i]))
		i++;
	begin_i = i;
	while (argv[1][i])
	{
		if (is_delimiter(argv[1][i]))
		{
			i++;
			continue ;
		}
		if (i != begin_i)
			write(1, " ", 1);
		while (!is_delimiter(argv[1][i]) && argv[1][i])
			write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
}
