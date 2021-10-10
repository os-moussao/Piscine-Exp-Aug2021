/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:20:56 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:21:02 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	rb(unsigned char octet)
{
	unsigned char	res;
	unsigned char	power;
	unsigned char	tmp;
	int				i;

	power = 1;
	i = 0;
	res = 0;
	while (i < 4)
	{
		tmp = octet >> (7 - 2 * i++); 
		res = res | (tmp & power);
		power *= 2;
	}
	while (i < 8)
	{
		tmp = octet << (2 * i++ - 7);
		res = res | (tmp & power);
		power *= 2;
	}
	return (res);
}

int	main(void)
{
	printf("%d", rb(37));
}
