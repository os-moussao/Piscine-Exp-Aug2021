/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:24:35 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:24:37 by os-moussao       ###   ########.fr       */
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
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		sign *= 1 - (str[i++] == '-') * 2;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (sign * res);
}

void	int_to_hex(int nbr, char *base)
{
	if (nbr < 0)
		return ;
	if (nbr < 16)
	{
		ft_putchar(base[nbr]);
		return ;
	}
	int_to_hex(nbr / 16, base);
	ft_putchar(base[nbr % 16]);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		int_to_hex(ft_atoi(argv[1]), "0123456789abcdef");
	ft_putchar('\n');
}
