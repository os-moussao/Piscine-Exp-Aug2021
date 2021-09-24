/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn_simple.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussaoui040@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:24:45 by os-moussao        #+#    #+#             */
/*   Updated: 2021/09/24 17:43:33 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Another solution for ft_print_combn exercise
 * I came up with this solution after the pool, and wanted to share it here
 * it's more efficient and simple to understand
 * I used backtracking, which - in this case -  acts like multiple nested loops
 * norminette: OK!
**/

#include <unistd.h>

int	g_total = 0;

void	backtrack(char stack[], int index, int start, int n)
{
	if (index == n)
	{
		if (g_total)
			write(1, ", ", 2);
		write(1, stack, n);
		g_total++;
		return ;
	}
	while (start <= '9')
	{
		stack[index] = start;
		backtrack(stack, index + 1, start + 1, n);
		start++;
	}
}

void	ft_print_combn(int n)
{
	char	stack[10];

	g_total = 0;
	backtrack(stack, 0, '0', n);
}
