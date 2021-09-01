/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:24:59 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/15 13:29:30 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	if (nb <= 0)
		return (nb == 0);
	res = 1;
	i = 1;
	while (i <= nb)
		res *= i++;
	return (res);
}
