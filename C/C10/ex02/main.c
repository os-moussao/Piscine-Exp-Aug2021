/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:30:39 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/26 12:34:37 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libtail.h"

int	main(int argc, char **argv)
{
	t_option	option;

	if (argc >= 2)
	{
		option = get_option(argc - 1, argv + 1);
		if (option.error == 2)
		{
			usage_error(2, &argv[1][1], basename(argv[0]));
			return (1);
		}
		if (option.error == 1)
		{
			usage_error(1, "", basename(argv[0]));
			return (1);
		}
		else
		{
			if (option.offset == -1)
				usage_error(0, option.val, basename(argv[0]));
			else if (option.ac == 0)
				read_tail(0, option.offset);
			else
				handle_files(option, basename(argv[0]));
		}
	}
}
