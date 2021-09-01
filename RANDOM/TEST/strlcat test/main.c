/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:47:58 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/11 17:27:19 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../C02/ex12/ft_print_memory.c"

void	*ft_print_memory(void * addr, unsigned int size);

int	main(void)
{
	char	*src = "456";
	char	dest[8] = "0123";
	int		out;

	out = strlcat(dest, src, 0);
	ft_print_memory(dest, 8);
	printf("\noutput: %d\n", out);
	return (0);
}
