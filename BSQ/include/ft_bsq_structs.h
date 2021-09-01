/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:58:37 by asabani           #+#    #+#             */
/*   Updated: 2021/08/25 08:51:48 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_STRUCTS_H
# define FT_BSQ_STRUCTS_H

typedef struct s_map_data{
	int		**map;
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	int		is_valid;
}	t_map_data;

typedef struct s_bsq
{
	int	i;
	int	j;
	int	sq;
}				t_bsq;
#endif
