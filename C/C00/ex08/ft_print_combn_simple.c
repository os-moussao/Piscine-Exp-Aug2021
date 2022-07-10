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

void	show_comma(char stack[], int index, int n)
{
    int	  i = 10 - n;

    for (int j = 0; j <= n; j++)
        if (stack[j] - '0' != i++) {
            write(1, ", ", 2);
            return;
        }
}

void	backtrack(char stack[], int index, int start, int n)
{
    if (index == n) {
        show_comma(stack, index, n);
        write(1, stack, n);
        return;
    }
    while (start <= '9') {
        stack[index] = start;
        backtrack(stack, index + 1, ++start, n);
    }
}

void	ft_print_combn(int n)
{
    char    stack[10];

    backtrack(stack, 0, '0', n);
}
