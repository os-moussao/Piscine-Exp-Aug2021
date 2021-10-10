/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:24:39 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:24:42 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_letter(char c)
{
	return (is_lower(c) || is_upper(c));
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		ft_putchar('\n');
		return (1);
	}
	i = 0;
	while (++i < argc)
	{
		while (*argv[i])
		{
			if (!is_letter(*argv[i]))
				ft_putchar(*argv[i]);
			else
			{
				if (is_letter(*(argv[i] + 1)))
					ft_putchar(*argv[i] + 32 * is_upper(*argv[i]));
				else
					ft_putchar(*argv[i] - 32 * is_lower(*argv[i]));
			}
			argv[i]++;
		}
		ft_putchar('\n');
	}
}
