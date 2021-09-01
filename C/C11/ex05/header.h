/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:38:36 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/22 10:36:59 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>

typedef int	(*t_op)(int, int);

int		add(int a, int b);
int		sub(int a, int b);
int		mult(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);

void	fill_array(t_op *arr);
int		get_op_index(char c);
void	display_error(int op);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);

#endif
