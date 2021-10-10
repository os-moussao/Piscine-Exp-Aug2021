/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:23:38 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:23:41 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	my_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
	{
		if (i * i == n)
			break ;
		i++;
	}
	return (i);
}


int	is_prime(int p)
{
	int	sq;
	int	i;

	if (p <= 1)
		return (0);
	sq = my_sqrt(p);
	i = 0;
	while (++i <= sq)
	{
		if (p % i == 0)
			return (0);
	}
	return (1);
}

int	main(void)
{
	printf("%d", is_prime(9));
}
