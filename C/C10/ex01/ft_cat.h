/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 08:54:48 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/21 14:39:46 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# include <unistd.h>
# include <fcntl.h>
# include <libgen.h>
# include <string.h>
# include <errno.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

void	read_stdin(void);
void	display_error(char *prog, char *file, int is_dir);
void	ft_display_file(int file);

#endif
