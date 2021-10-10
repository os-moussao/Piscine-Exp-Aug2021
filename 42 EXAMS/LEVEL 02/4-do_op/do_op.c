/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:21:26 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:21:29 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	mult(int a, int b)
{
	return (a * b);
}

int	divide(int a, int b)
{
	return (a / b);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("\n");
		return (1);
	}
	if (*argv[2] == '+')
		printf("%d", (atoi(argv[1]) + atoi(argv[3])));
	else if (*argv[2] == '-')
		printf("%d", (atoi(argv[1]) - atoi(argv[3])));
	else if (*argv[2] == '*')
		printf("Mult: %d", (atoi(argv[1]) * atoi(argv[3])));
	else if (*argv[2] == '/')
		printf("Div: %d", (atoi(argv[1]) / atoi(argv[3])));
	else if (*argv[2] == '%')
		printf("%d", (atoi(argv[1]) % atoi(argv[3])));
	printf("\n");
	return (0);
}
