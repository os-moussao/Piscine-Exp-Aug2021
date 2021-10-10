/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:21:18 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:21:21 by os-moussao       ###   ########.fr       */
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
			if (argv[1][i] != *argv[2] && *(argv[2] + 1))
				//write newline + return
			else if ( == )
				break ; // go to next character in argv[1]
			argv[2]++;
		}
	}
	return (0);
}
