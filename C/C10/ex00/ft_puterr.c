/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:28:30 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/21 12:44:33 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disp.h"

void	ft_puterr(int error)
{
	if (error == 1)
		write(STDERR, MISSING, 19);
	else if (error == 2)
		write(STDERR, MANY, 20);
}
