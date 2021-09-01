/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:29:06 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/22 10:39:23 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fill_array(t_op *arr)
{
	arr[0] = &add;
	arr[1] = &sub;
	arr[2] = &mult;
	arr[3] = &div;
	arr[4] = &mod;
}

int	get_op_index(char c)
{
	if (c == '+')
		return (0);
	else if (c == '-')
		return (1);
	else if (c == '*')
		return (2);
	else if (c == '/')
		return (3);
	else if (c == '%')
		return (4);
	else
		return (-1);
}

void	display_error(int op)
{
	if (op == 3)
		write(2, "Stop : division by zero\n", 24);
	else if (op == 4)
		write(2, "Stop : modulo by zero\n", 22);
}
