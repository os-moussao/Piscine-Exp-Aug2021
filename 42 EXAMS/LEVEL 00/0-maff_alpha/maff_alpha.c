/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:15:36 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:15:42 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	char	alpha;

	alpha = 'a' - 1;
	while (++alpha <= 'z')
		ft_putchar(alpha - (alpha % 2 == 0) * 32);
	ft_putchar('\n');
	return (0);
}
