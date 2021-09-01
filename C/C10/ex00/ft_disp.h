/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 08:54:48 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/21 12:47:23 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISP_H
# define FT_DISP_H

# include <unistd.h>
# include <fcntl.h>

# define MISSING "File name missing.\n"
# define MANY "Too many arguments.\n"
# define RD_ERROR "Cannot read file.\n"
# define FAILURE 1
# define SUCCESS 0
# define STDOUT 1
# define STDERR 2

void	ft_display_file(int file);
void	ft_puterr(int error);

#endif
