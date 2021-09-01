/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 13:00:03 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/08 08:15:46 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	make_first_comb(int n, char *comb_buff)
{
	int	i;

	i = -1;
	while (++i < n)
		comb_buff[i] = i + '0';
}

int	is_max_elem(int n, int index, char *comb)
{
	return (comb[index] == '0' + index + 10 - n);
}

char	*next_comb(int n, char *comb)
{
	int	i;
	int	tmp;

	i = n - 1;
	while (i >= 0 && is_max_elem(n, i, comb))
		i--;
	tmp = i;
	while (i >= 0 && i < n)
	{
		comb[i] = (i == tmp) * (comb[i] + 1) + (i != tmp) * (comb[i - 1] + 1);
		i++;
	}
	return (comb);
}

void	print_next_combs(int n, char *comb)
{
	write(1, comb, n);
	if (!(comb[0] == '0' + 10 - n))
	{
		write(1, ", ", 2);
		print_next_combs(n, next_comb(n, comb));
	}
}

void	ft_print_combn(int n)
{
	char	comb[10];

	if (n >= 10 || n <= 0)
		return ;
	make_first_comb(n, comb);
	print_next_combs(n, comb);
}
