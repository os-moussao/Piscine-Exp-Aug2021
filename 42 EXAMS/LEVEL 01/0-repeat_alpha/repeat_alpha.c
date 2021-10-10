/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:17:20 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:17:23 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	rep_count(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 1);
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 1);
	return (1);
}

int	main(int argc, char *argv[])
{
	int	rep;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (*argv[1])
	{
		rep = rep_count(*argv[1]);
		while (rep--)
			write(1, argv[1], 1);
		argv[1]++;
	}
	write(1, "\n", 1);
	return (0);
}
