/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:21:14 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:21:16 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				max;

	if (len == 0)
		return (0);
	max = tab[0];
	i = 0;
	while (++i < len)
	{
		if (tab[i] > max)
			max = tab[i];
	}
	return (max);
}
