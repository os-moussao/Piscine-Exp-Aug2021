/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 14:33:15 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/21 14:38:25 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	read_stdin(void)
{
	char	buff;

	while (read(STDIN, &buff, 1))
		write(STDOUT, &buff, 1);
}