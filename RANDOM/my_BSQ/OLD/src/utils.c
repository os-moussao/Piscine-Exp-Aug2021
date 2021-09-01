/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:18:05 by asabani           #+#    #+#             */
/*   Updated: 2021/08/25 08:16:43 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_digit(char digit)
{
	if (digit >= '0' && digit <= '9')
		return (1);
	else
		return (0);
}

int	is_twice(char *chars)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = i + 1;
		while (j < 3)
		{
			if (chars[i] == chars[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_map_error(void)
{
	write(2, "map error\n", 10);
}
