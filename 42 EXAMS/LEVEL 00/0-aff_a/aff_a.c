/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:13:48 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:14:01 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "a\n", 2);
		return (1);
	}
	while (*argv[1])
	{
		if (*argv[1] == 'a')
		{
			write(1, argv[1], 1);
			write(1, "\n", 1);
			return (0);
		}
		argv[1]++;
	}
	write(1, "\n", 1);
	return (1);
}
