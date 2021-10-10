/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:20:42 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:20:48 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*ptr;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	ptr = argv[1];
	while (*argv[1])
		argv[1]++;
	while ((*(argv[1] - 1) == ' '
			|| *(argv[1] - 1) == '	') && argv[1] != ptr)
		argv[1]--;
	while (*(argv[1] - 1) != ' '
		&& *(argv[1] - 1) != '	' && argv[1] != ptr)
		argv[1]--;
	while (*argv[1] != ' '
		&& *argv[1] != '	' && *argv[1])
		write(1, argv[1]++, 1);
	write(1, "\n", 1);
	return (0);
}
