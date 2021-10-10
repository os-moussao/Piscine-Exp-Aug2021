/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:24:26 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:24:29 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (*argv[1] && *argv[2])
	{
		while (*argv[1] != *argv[2] && *argv[2])
			argv[2]++;
		if (*argv[2])
		{
			argv[2]++;
			argv[1]++;
		}
	}
	if (*argv[1])
	{
		write(1, "0\n", 2);
		return (0);
	}
	write(1, "1\n", 2);
	return (0);
}
