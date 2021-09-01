/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:09:29 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/17 19:26:47 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_w_space(char c);
int		check_base(char *base);
int		check_index(char c, char *base);
int		get_nbr_size(long nbr, long base);
long	get_power(long base, int exp);

long	ft_atoi_base(char *str, char *base_from)
{
	long	res;
	int		sign;
	int		base_len;
	int		i;

	base_len = check_base(base_from);
	res = 0;
	sign = 1;
	i = 0;
	while (is_w_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
		sign *= 1 - 2 * (str[i++] == '-');
	while (check_index(str[i], base_from) != -1)
		res = res * base_len + check_index(str[i++], base_from);
	return (sign * res);
}

char	*ft_itoa_base(long nbr, char *base_to)
{
	char	*res;
	long	power;
	int		size;
	int		i;
	long	base;

	base = check_base(base_to);
	size = get_nbr_size(nbr, base);
	power = get_power((long)base, size - 2 - (nbr < 0));
	res = malloc(size);
	if (!res)
		return ((char *)0);
	res[size - 1] = 0;
	i = 0;
	if (nbr < 0)
	{
		res[i++] = '-';
		nbr *= -1;
	}
	while (power)
	{
		res[i++] = base_to[(nbr / power) % base];
		power /= base;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nbr_to_int;
	char	*int_to_base;

	if (!(check_base(base_from) && check_base(base_to)))
		return ((char *) 0);
	nbr_to_int = ft_atoi_base(nbr, base_from);
	int_to_base = ft_itoa_base(nbr_to_int, base_to);
	return (int_to_base);
}
