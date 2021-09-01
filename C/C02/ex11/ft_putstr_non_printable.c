/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:31:51 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/10 17:44:15 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define BASE "0123456789abcdef"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	write_hex(unsigned char c)
{
	ft_putchar('\\');
	ft_putchar(BASE[c / 16]);
	ft_putchar(BASE[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	if (!*str)
		return ;
	if ((unsigned char) *str < 32 || (unsigned char) *str >= 127)
		write_hex((unsigned char) *str);
	else
		ft_putchar(*str);
	ft_putstr_non_printable(str + 1);
}
