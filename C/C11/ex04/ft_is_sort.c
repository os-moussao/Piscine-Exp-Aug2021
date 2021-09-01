/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:12:39 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/22 14:04:53 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	in_order(int comp, int order)
{
	if (order > 0)
		return (comp >= 0);
	else
		return (comp <= 0);
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	order;

	if (length <= 2)
		return (1);
	order = (*f)(tab[0], tab[length - 1]);
	i = 0;
	while (i + 1 < length)
	{
		if (!in_order((*f)(tab[i], tab[i + 1]), order))
			return (0);
		i++;
	}
	return (1);
}
