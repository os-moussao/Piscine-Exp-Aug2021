/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:24:32 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:24:34 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	pgcd(int a, int b)
{
	int	divider;
	int	result;
	int	min;

	if (a == b)
		return (a);
	min = (a < b) * a + (b < a) * b;
	result = 1;
	divider = 1;
	while (divider <= min)
	{
		if (a % divider == 0 && b % divider == 0)
			result = divider;
		divider++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc != 3)
	{
		printf("\n");
		return (1);
	}
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	if (a <= 0 || b <= 0)
	{
		printf("\n");
		return (2);
	}
	printf("%d\n", pgcd(a, b));
}
