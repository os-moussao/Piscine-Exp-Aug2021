/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:21:22 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:21:25 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = -1;
	while (argv[1][++i])
	{
		while (*argv[2])
		{
			if (*argv[2] != argv[1][i] && !*(argv[2] + 1))
			{
				write(1, "\n", 1);
				return (1);
			}
			else if (*argv[2] == argv[1][i])
				break ;
			argv[2]++;
		}
	}
	write(1, argv[1], i);
	write(1, "\n", 1);
	return (0);
}
