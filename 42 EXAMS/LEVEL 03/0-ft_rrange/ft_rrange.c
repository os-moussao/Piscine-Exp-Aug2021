/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:24:22 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:24:25 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int	size;
	int	order;
	int	index;
	int	*arr;

	size = end - start;
	order = 1 - (size < 0) * 2;
	size = (size * order) + 1;
	arr = malloc(size * sizeof(int));
	index = -1;
	while (++index < size)
		arr[index] = end - order * index;
	return (arr);
}

int	main(void)
{
	int	*arr;

	arr = ft_rrange(3, 0);
	for (int i = 0; i < 4; i++)
		printf("%d	", arr[i]);
	free(arr);
}
