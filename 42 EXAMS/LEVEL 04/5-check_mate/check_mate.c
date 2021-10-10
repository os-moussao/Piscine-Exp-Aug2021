/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:27:24 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:27:27 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_check.h"

int	main(int argc, char **argv)
{
	char	**tab;
	int		king_under_attack;
	int		i;

	if (argc > 1)
	{
		tab = set_the_board(argv + 1, argc - 1);
		king_under_attack = main_check(tab, argc - 1);
		if (king_under_attack)
			write(1, "Success", 8);
		else
			write(1, "Fail", 5);
		i = -1;
		while (++i < argc - 1)
			free(tab[i]);
		free(tab);
	}
	write(1, "\n", 1);
}
