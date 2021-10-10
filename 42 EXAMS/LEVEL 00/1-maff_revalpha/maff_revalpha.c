/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:16:03 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:16:07 by os-moussao       ###   ########.fr       */
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

	alpha = 'z' + 1;
	while (--alpha >= 'a')
		ft_putchar(alpha - (alpha % 2) * 32);
	ft_putchar('\n');
	return (0);
}
