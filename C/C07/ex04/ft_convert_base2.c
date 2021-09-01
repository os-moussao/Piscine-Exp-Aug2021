/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:32:41 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/17 18:55:39 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_w_space(char c)
{
	return (c == 32 || (9 <= c && c <= 13));
}

int	check_base(char *base)
{
	int	len;
	int	j;

	if (!*base || !*(base + 1))
		return (0);
	len = -1;
	while (base[++len])
	{
		if (base[len] == '+' || base[len] == '-' || is_w_space(base[len]))
			return (0);
		j = len;
		while (base[++j])
		{
			if (base[len] == base[j])
				return (0);
		}
	}
	return (len);
}

int	check_index(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
	{
		if (base[i] == c)
			return (i);
	}
	return (-1);
}

int	get_nbr_size(long nbr, long base)
{
	int	size;

	size = nbr < 0;
	nbr += 1 * !(nbr);
	while (nbr)
	{
		size++;
		nbr /= base;
	}
	return (size + 1);
}

long	get_power(long base, int exp)
{
	if (exp <= 0)
		return (exp == 0);
	return (base * get_power(base, exp - 1));
}
