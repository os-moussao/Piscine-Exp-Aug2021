/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libtail.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:05:15 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/26 12:09:00 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBTAIL_H
# define FT_LIBTAIL_H

# include <libgen.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>

typedef struct s_option
{
	int		ac;
	char	**av;
	char	*val;
	int		offset;
	int		error;
}				t_option;

void		push_to_tail(char *buff, int size, char ch);
char		*get_buff(int size);
void		read_tail(int fd, int bytes);
t_option	get_option(int ac, char **av);
void		display_error(char *program, char *file, char *error);
void		usage_error(int type, char *holder, char *program);
void		handle_files(t_option option, char *program);

#endif
