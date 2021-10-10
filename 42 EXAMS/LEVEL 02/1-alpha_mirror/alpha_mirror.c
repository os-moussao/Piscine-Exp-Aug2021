/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:21:11 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:21:12 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (*argv[1])
	{
		if (*argv[1] >= 'a' && *argv[1] <= 'z')
			ft_putchar(219 - *argv[1]++);
		else if (*argv[1] >= 'A' && *argv[1] <= 'Z')
			ft_putchar(155 - *argv[1]++);
		else
			ft_putchar(*argv[1]++);
	}
	ft_putchar('\n');
	return (0);
}

// get your math right to understand this one   :)
