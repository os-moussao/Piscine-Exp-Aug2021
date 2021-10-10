/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:24:47 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:24:50 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		sign *= 1 - (str[i++] == '-') * 2;
	while (str[i] <= '9' && str[i] >= '0')
		res = res * 10 + (str[i++] - '0');
	return (sign * res);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		return ;
	}
	ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int	main(int argc, char **argv)
{
	int	num;
	int	mult;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (1);
	}
	num = ft_atoi(argv[1]);
	mult = 0;
	while (++mult <= 9)
	{
		ft_putnbr(mult);
		write(1, " x ", 3);
		ft_putnbr(num);
		write(1, " = ", 3);
		ft_putnbr(num * mult);
		ft_putchar('\n');
	}
}
