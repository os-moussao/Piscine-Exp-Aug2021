/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:13:36 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/21 17:37:08 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*res;
	int	i;

	res = malloc(length * sizeof(int));
	if (!res)
		return (0);
	i = -1;
	while (++i < length)
		res[i] = (*f)(tab[i]);
	return (res);
}
