/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 08:51:18 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/14 13:14:23 by omoussao         ###   ########.fr       */
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
		if (base[len] == '+' || base[len] == '-')
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

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	sign;
	int	base_len;
	int	i;

	base_len = check_base(base);
	if (!base_len)
		return (0);
	res = 0;
	sign = 1;
	i = 0;
	while (is_w_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
		sign *= 1 - 2 * (str[i++] == '-');
	while (check_index(str[i], base) != -1)
		res = res * base_len + check_index(str[i++], base);
	return (sign * res);
}

#include <stdio.h>

int	main(void)
{
	printf("%d", ft_atoi_base("  ----111d111", "01"));
}
