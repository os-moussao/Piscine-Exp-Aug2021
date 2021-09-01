/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:03:26 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/21 18:11:53 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;
	int	counter;

	counter = 0;
	i = -1;
	while (++i < length)
	{
		if ((*f)(tab[i]))
			counter++;
	}
	return (counter);
}
