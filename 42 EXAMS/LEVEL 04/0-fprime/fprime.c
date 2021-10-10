/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:26:14 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:26:15 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_prime(int n)
{
	int	i;

	if (n <= 1)
		return (0);
	i = 1;
	while (++i < n)
	{
		if (n % i == 0)
			return (0);
	}
	return (1);
}

int	next_prime(int p)
{
	if (is_prime(p + 1))
		return (p + 1);
	return (next_prime(p + 1));
}

int	main(int argc, char **argv)
{
	int	nbr;
	int	p;

	if (argc == 2)
	{
		nbr = atoi(argv[1]);
		p = 2;
		while (!is_prime(nbr) && nbr > 1)
		{
			if (nbr % p == 0)
			{
				printf("%d", p);
				if (!is_prime(nbr))
					printf("*");
				nbr /= p;
			}
			else
				p = next_prime(p);
		}
		printf("%d", nbr);
	}
	printf("\n");
}
