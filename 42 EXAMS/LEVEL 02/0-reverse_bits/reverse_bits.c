/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:20:52 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:20:54 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int				power;
	int				i;
	unsigned char	res;
	unsigned char	tmp;

	power = 1;
	i = 1;
	res = 0;
	while (i <= 4)
	{
		tmp = octet >> (2 * (5 - i++) - 1);
		res = res | (tmp & power);
		power *= 2;
	}
	while (i <= 8)
	{
		tmp = octet << (2 * (i++ - 4) - 1);
		res = res | (tmp & power);
		power *= 2;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: ./a.exe [0 <= nbr <= 255]");
		return (1);
	}
	if (atoi(argv[1]) > 255 || atoi(argv[1]) < 0)
	{
		printf("Usage: ./a.exe [0 <= nbr <= 255]");
		return (1);
	}
	printf("%d", reverse_bits(atoi(argv[1])));
}
