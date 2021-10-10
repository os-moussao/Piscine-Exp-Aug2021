/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparaison.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:19:58 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:20:01 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1 - (str[0] == '-') * 2;
	i = (str[0] == '+' || str[0] == '-');
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	return (sign * res);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: ./a.exe [str]");
		return (1);
	}
	printf("atoi: %d			ft_atoi: %d", atoi(argv[1]), ft_atoi(argv[1]));
}
