/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:38:43 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/12 14:42:42 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../C02/ex12/ft_print_memory.c"
#include "ex05/ft_strlcat.c"

void	*ft_print_memory(void * addr, unsigned int size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	*src = "456";
	char	dest[8] = "0123";
	int		out;

	out = ft_strlcat(dest, src, 0);
	ft_print_memory(dest, 8);
	printf("\noutput: %d\n", out);
	return (0);
}
