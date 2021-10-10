/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:18:16 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:18:20 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'));
}

int	main(int argc, char *argv[1])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (*argv[1])
	{
		if (*argv[1] == 'z' || *argv[1] == 'Z')
		{
			ft_putchar(*argv[1]++ - 25);
			continue ;
		}
		ft_putchar(*argv[1] + 1 * is_alpha(*argv[1]));
		argv[1]++;
	}
	ft_putchar('\n');
	return (0);
}
