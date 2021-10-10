/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:21:55 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:22:01 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (reject[++j])
		{
			if (reject[j] == s[i])
				return (i);
		}
	}
	return (i);
}
