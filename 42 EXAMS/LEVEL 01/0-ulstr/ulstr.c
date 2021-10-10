/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:17:46 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:17:59 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	char_case(char c)
{
	if (c >= 'a' && c <= 'z')
		return (-1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return (1);
	}
	while (*argv[1])
	{
		ft_putchar(*argv[1] + 32 * char_case(*argv[1]));
		argv[1]++;
	}
	ft_putchar('\n');
	return (0);
}
