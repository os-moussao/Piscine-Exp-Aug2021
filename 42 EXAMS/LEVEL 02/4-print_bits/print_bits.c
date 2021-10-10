/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:21:33 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:21:38 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_bits(unsigned char octet)
{
	int	res;
	int	power;

	res = 0;
	power = 1;
	while (octet)
	{
		res += (octet % 2) * power;
		octet /= 2;
		power *= 10;
	}
	power = 10000000;
	while (power >= 1)
	{
		ft_putchar(((res / power) % 10) + '0');
		power /= 10;
	}
}

int	main(void)
{
	unsigned char	uc = '€';
	print_bits(uc);
	ft_putchar('\n');
}
