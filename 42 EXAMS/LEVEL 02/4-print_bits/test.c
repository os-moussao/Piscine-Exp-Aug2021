/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:21:39 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:21:44 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	healper(unsigned char octet, int len)
{
	if (octet < 2)
	{
		write(1, "00000000", len - 1);
		ft_putchar(octet + '0');
		return ;
	}
	healper(octet / 2, len - 1);
	ft_putchar(octet % 2 + '0');
}

void	print_bits(unsigned char octet)
{
	healper(octet, 8);
}

int	main(void)
{
	unsigned char	uc = '€';
	print_bits(uc);
	ft_putchar('\n');
}
