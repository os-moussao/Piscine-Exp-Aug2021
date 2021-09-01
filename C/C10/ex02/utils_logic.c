/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:15:27 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/26 12:31:44 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libtail.h"

char	*get_buff(int size)
{
	char	*buff;
	int		i;

	buff = malloc(size + 1);
	i = -1;
	while (++i < size + 1)
		buff[i] = 0;
	return (buff);
}

void	push_to_tail(char *buff, int size, char ch)
{
	int	i;

	i = -1;
	while (++i < size - 1)
		buff[i] = buff[i + 1];
	buff[i] = ch;
}

int	get_offset(char *num)
{
	int	i;
	int	offset;

	offset = 0;
	i = -1;
	while (num[++i])
	{
		if (!('0' <= num[i] && num[i] <= '9'))
			return (-1);
		offset = offset * 10 + num[i] - '0';
	}
	return (offset);
}

t_option	get_option(int ac, char **av)
{
	t_option	option;
	char		*op;

	op = av[0];
	option.val = 0;
	option.error = 1;
	if (op[0] == '-' && op[1] == 'c' && !op[2] && ac != 1)
	{
		option.ac = ac - 2;
		option.av = av + 2;
		option.val = av[1];
		option.offset = get_offset(av[1]);
		option.error = 0;
	}
	else if (op[0] == '-' && op[1] == 'c' && op[2])
	{
		option.ac = ac - 1;
		option.av = av + 1;
		option.val = op + 2;
		option.offset = get_offset(op + 2);
		option.error = 0;
	}
	else if (op[0] == '-' && op[1] != 'c')
		option.error = 2;
	return (option);
}
