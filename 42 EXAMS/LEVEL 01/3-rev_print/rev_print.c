/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:18:14 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:18:15 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_rev(char *str)
{
	if (*str == '\0')
		return ;
	if (*(str + 1) == '\0')
	{
		write(1, str, 1);
		return ;
	}
	print_rev(str + 1);
	write(1, str, 1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	print_rev(argv[1]);
	write(1, "\n", 1);
	return (0);
}
