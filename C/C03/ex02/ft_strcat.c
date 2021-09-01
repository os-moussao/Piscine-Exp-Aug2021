/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:43:09 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/12 15:14:39 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	char	*destination;

	destination = dest;
	while (*dest)
		dest++;
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
	return (destination);
}
