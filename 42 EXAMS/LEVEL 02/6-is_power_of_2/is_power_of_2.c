/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:22:15 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:22:17 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	unsigned int	power;
	int				i;

	if (n % 2)
		return (0);
	i = 0;
	power = 1;
	while (power < n)
	{
		power *= 2;
		i++;
	}
	printf("iterations: %d\n", i);
	return (power == n);
}

int	main(void)
{
	int	(*ptr) (unsigned int);

	ptr = &is_power_of_2;
	printf("%d", ptr(2147483646));
}
