/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:26:16 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:26:21 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

// yes the error is intentional
int		next_prime(unsigned int nb)
{
	unsigned int	i;

	i = 2;
	while (i * i <= nb)
	{
		if (nb % i++ == 0)
			return (next_prime(nb + 1));
	}
	return (nb);
}


void	fprime(unsigned int nb)
{
	int	i;

	i = 2;
	while (next_prime(nb) != nb && nb > 1)
	{
		if (nb % i == 0)
		{
			printf("%d*", i);
			nb /= i;
		}
		else //(nb % i != 0)
			i = next_prime(i + 1);
	}
	printf("%d", nb);
}

int	main(int ac, char **av)
{
	if (ac == 2 && *av[1])
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
