/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:24:43 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:24:46 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
		ft_putchar('\n');
		return (1);
	}
	i = 0;
	while (is_delimiter(argv[1][i]) && argv[1][i])
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
			write(1, "   ", 3);
		while (argv[1][i] && !is_delimiter(argv[1][i]))
			ft_putchar(argv[1][i++]);
	}
	ft_putchar('\n');
}
