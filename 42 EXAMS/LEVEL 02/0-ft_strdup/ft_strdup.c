/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:20:07 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:20:13 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		len;
	int		i;

	len = 0;
	while (src[len])
		len++;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		*(ptr + i) = src[i];
	*(ptr + i) = '\0';
	return (ptr);
}
