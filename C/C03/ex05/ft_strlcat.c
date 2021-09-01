/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:46:19 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/12 17:58:48 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	if (!*str++)
		return (0);
	return (1 + ft_strlen(str));
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	len;
	unsigned int	i;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	len = d_len;
	if (size <= d_len)
		return (size + s_len);
	i = 0;
	while (src[i] && len < size - 1)
		dest[len++] = src[i++];
	dest[len] = 0;
	return (d_len + s_len);
}
