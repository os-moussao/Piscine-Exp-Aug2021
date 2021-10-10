/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:26:46 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:26:49 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ascending(int a, int b)
{
	return (a <= b);
}

int descending(int a, int b)
{
	return (a >= b);
}

void	sort(int *tab, int size, int (*cmp)(int, int))
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if ((*cmp)(tab[i], tab[i + 1]))
			i++;
		else
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
	}
}

int	main(void)
{
	int tab[10] = {1, 5, 9, 3, 7, 6, 4, 9, 8, 2};
	sort(tab, 10, &descending);
	for(int i = 0; i < 10; i++)
		printf("%d	", tab[i]);
}
