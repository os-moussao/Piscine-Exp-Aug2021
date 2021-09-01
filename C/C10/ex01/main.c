/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 09:45:42 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/21 14:35:44 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;

	i = 0;
	if (argc == 1)
		read_stdin();
	while (++i < argc)
	{
		if (argv[i][0] == '-' && !argv[i][1])
			read_stdin();
		else
		{
			fd = open(argv[i], O_DIRECTORY);
			if (fd == -1)
			{
				fd = open(argv[i], O_RDONLY);
				if (fd != -1)
					ft_display_file(fd);
				else
					display_error(basename(argv[0]), argv[i], 0);
			}
			else
				display_error(basename(argv[0]), argv[i], 1);
		}
	}
}
