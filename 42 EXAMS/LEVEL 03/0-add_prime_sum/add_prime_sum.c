/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:23:35 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:23:37 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr_pos(int nbr)
{
	char	ch;

	if (nbr < 10)
	{
		ch = nbr + '0';
		write(1, &ch, 1);
		return ;
	}
	ft_putnbr_pos(nbr / 10);
	ft_putnbr_pos(nbr % 10);
}

int	ft_atoi(char *str)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == '-' || str[i] == '+')
		sign *= 1 - (str[i++] == '-') * 2;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (sign * res);
}

int	is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 1;
	while (++i < nb)
	{
		if (nb % i == 0)
			return (0);
	}
	return (1);
}

int	next_prime(int	nb)
{
	if (nb <= 1)
		return (2);
	if (is_prime(nb + 1))
		return (nb + 1);
	return (next_prime(nb + 1));
}

int	main(int argc, char **argv)
{
	int	n;
	int	sum;
	int	p;

	if (argc != 2 || (argc == 2 && ft_atoi(argv[1]) < 0))
	{
		write(1, "0\n", 2);
		exit(EXIT_FAILURE);
	}
	n = ft_atoi(argv[1]);
	sum = 0;
	p = 2;
	while (p <= n)
	{
		sum += p;
		p = next_prime(p);
	}
	ft_putnbr_pos(sum);
	write(1, "\n", 1);
	exit(EXIT_SUCCESS);
}
