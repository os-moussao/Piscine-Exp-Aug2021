/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:17:34 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:17:37 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		write(1, "\n", 1);
		exit(EXIT_FAILURE);
	}
	if (ft_strlen(argv[2]) * ft_strlen(argv[3]) != 1)
	{
		write(1, "\n", 1);
		exit(EXIT_FAILURE);
	}
	while (*argv[1])
	{
		if (*argv[1] == *argv[2])
			write(1, argv[3], 1);
		else
			write(1, argv[1], 1);
		argv[1]++;
	}
	write(1, "\n", 1);
	exit(EXIT_SUCCESS);
}
