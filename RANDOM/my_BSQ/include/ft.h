/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:24:49 by asabani           #+#    #+#             */
/*   Updated: 2021/08/25 16:29:48 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include "ft_bsq_structs.h"

int			is_twice(char *chars);
int			is_digit(char digit);
void		ft_map_error(t_map_data *map);
void		find_bsq(t_map_data *map);
void		print_bsq(t_map_data *map);
t_map_data	*ft_get_map(int fd);
void	read_first_line(int fd, t_map_data *map);

#endif
