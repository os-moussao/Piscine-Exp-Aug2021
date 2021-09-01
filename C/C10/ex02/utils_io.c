/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:31:42 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/26 12:30:06 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libtail.h"

void	ft_putstr(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

void	read_tail(int fd, int bytes)
{
	char	*buff;
	char	ch;

	buff = get_buff(bytes + 1);
	while (read(fd, &ch, 1))
		push_to_tail(buff, bytes, ch);
	write(1, buff, bytes);
	free(buff);
}

void	usage_error(int type, char *holder, char *program)
{
	ft_putstr(2, program);
	ft_putstr(2, ": ");
	if (type == 0)
	{
		ft_putstr(2, "illegal offset -- ");
		ft_putstr(2, holder);
	}
	else if (type == 1)
	{
		ft_putstr(2, "option requires an argument -- c\n");
		ft_putstr(2, "usage: tail [-F | -f | -r] [-q] ");
		ft_putstr(2, "[-b # | -c # | -n #] [file ...]");
	}
	else if (type == 2)
	{
		ft_putstr(2, "illegal option -- ");
		ft_putstr(2, holder);
		ft_putstr(2, "\n");
		ft_putstr(2, "usage: tail [-F | -f | -r] [-q] ");
		ft_putstr(2, "[-b # | -c # | -n #] [file ...]");
	}
	ft_putstr(2, "\n");
}

void	display_error(char *program, char *file, char *error)
{
	ft_putstr(2, program);
	ft_putstr(2, ": ");
	ft_putstr(2, file);
	ft_putstr(2, ": ");
	ft_putstr(2, error);
	ft_putstr(2, "\n");
}

void	handle_files(t_option option, char *program)
{
	int	i;
	int	fd;
	int	is_dir;

	i = -1;
	while (++i < option.ac)
	{
		is_dir = open(option.av[i], O_DIRECTORY);
		fd = open(option.av[i], O_RDONLY);
		if (fd == -1)
			display_error(program, option.av[i], strerror(errno));
		if (i > 0 && fd != -1)
			ft_putstr(1, "\n");
		if (option.ac > 1 && fd != -1)
		{
			ft_putstr(1, "==> ");
			ft_putstr(1, option.av[i]);
			ft_putstr(1, " <==\n");
		}
		if (is_dir == -1 && fd != -1)
			read_tail(fd, option.offset);
		close(is_dir);
	}
}
