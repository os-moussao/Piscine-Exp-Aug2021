/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:27:18 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:27:23 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	get_size(int nbr)
{
	int	size;

	size = nbr < 0;
	while (nbr)
	{
		nbr /= 10;
		size++;
	}
	return (size + 1);
}

int	power(int base, int exp)
{
	if (exp < 0)
		return (0);
	if (exp == 1)
		return (base);
	return (base * power(base, exp - 1));
}

int	get_int_power(int nbr)
{
	int	power;

	power = 1;
	while (nbr / 10)
	{
		power *= 10;
		nbr /= 10;
	}
	return (power);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		size;
	int		int_power;
	int		i;

	int_power = get_int_power(nbr);
	size = get_size(nbr);
	str = malloc(size);
	str[size - 1] = 0;
	i = (nbr < 0);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (int_power)
	{
		str[i++] = (nbr / int_power) + '0';
		nbr = nbr % int_power;
		int_power /= 10;
	}
	return (str);
}

int	main(void)
{
	char	*nbr;

	nbr = ft_itoa(-1337);
	printf("%s", nbr);
	free(nbr);
}
