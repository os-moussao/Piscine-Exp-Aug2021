/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:08:38 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/06 12:25:49 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(int n, int m)
{
	ft_putchar(n / 10 + '0');
	ft_putchar(n % 10 + '0');
	ft_putchar(' ');
	ft_putchar(m / 10 + '0');
	ft_putchar(m % 10 + '0');
	if (n != 98)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= 99)
	{
		j = i;
		while (++j <= 99)
			ft_print_comb(i, j);
	}
}
