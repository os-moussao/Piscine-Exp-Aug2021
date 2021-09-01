/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:50:22 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/21 14:59:06 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disp.h" 

int	main(int argc, char **argv)
{
	int		fd;

	if (argc == 1 || argc > 2)
	{
		ft_puterr(1 * (argc == 1) + (argc > 2) * 2);
		return (FAILURE);
	}
	fd = open(argv[1], O_DIRECTORY);
	if (fd == -1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != -1)
		{
			ft_display_file(fd);
			close(fd);
			return (SUCCESS);
		}
		else
			write(STDERR, RD_ERROR, 18);
	}
	else
		write(STDERR, RD_ERROR, 18);
	return (FAILURE);
}
