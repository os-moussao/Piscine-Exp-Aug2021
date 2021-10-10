/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:27:31 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:27:36 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_H
# define FT_CHECK_H

# include <stdlib.h>

typedef struct	s_pos
{
	char	piece;
	int		row;
	int		col;
}				t_pos;

char	**set_the_board(char **rows, int size);

t_pos	get_pos(char **tab, int size, char piece);

int		main_check(char **tab, int size);

#endif
