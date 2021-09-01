/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:43:53 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/22 10:32:49 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_op	ops[5];
	int		op;
	int		a;
	int		b;

	if (argc != 4)
		return (1);
	op = get_op_index(argv[2][0]);
	if (argv[2][1] || op == -1)
	{
		write(1, "0\n", 2);
		return (1);
	}
	fill_array(ops);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if ((op == 3 || op == 4) && b == 0)
	{
		display_error(op);
		return (1);
	}
	ft_putnbr(ops[op](a, b));
	write(1, "\n", 1);
}
