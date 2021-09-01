/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:55:24 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/12 15:22:18 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*destination;
	unsigned int	i;

	destination = dest;
	while (*dest)
		dest++;
	i = -1;
	while (src[++i] && i < nb)
		dest[i] = src[i];
	if (nb)
		dest[i] = 0;
	return (destination);
}
