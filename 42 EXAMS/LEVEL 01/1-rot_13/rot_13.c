/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:18:01 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:18:03 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_alpha_plus_13(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - (c + 13 > 'z') * 26 + 13;
	if (c >= 'A' && c <= 'Z')
		c = c - (c + 13 > 'Z') * 26 + 13;
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (*argv[1])
	{
		write_alpha_plus_13(*argv[1]);
		argv[1]++;
	}
	write(1, "\n", 1);
	return (0);
}
