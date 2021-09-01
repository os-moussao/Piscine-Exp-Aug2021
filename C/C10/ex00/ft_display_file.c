/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 09:14:08 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/21 12:46:07 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disp.h"

void	ft_display_file(int file)
{
	char	buffer[1];

	while (read(file, buffer, 1))
		write(STDOUT, buffer, 1);
}
