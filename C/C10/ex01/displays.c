/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 14:34:03 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/21 14:40:02 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_put_error(char *error)
{
	while (*error)
		write(STDERR, error++, 1);
}

void	display_error(char *prog, char *file, int is_dir)
{
	if (!is_dir)
	{
		ft_put_error(prog);
		ft_put_error(": ");
		ft_put_error(file);
		ft_put_error(": ");
		ft_put_error(strerror(errno));
		ft_put_error("\n");
	}
	else
	{
		ft_put_error(prog);
		ft_put_error(": ");
		ft_put_error(file);
		ft_put_error(": ");
		ft_put_error("Is a directory");
		ft_put_error("\n");
	}
}

void	ft_display_file(int file)
{
	char	buffer;

	while (read(file, &buffer, 1))
		write(STDOUT, &buffer, 1);
}
