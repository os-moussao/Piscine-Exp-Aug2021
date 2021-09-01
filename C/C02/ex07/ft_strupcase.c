/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:24:42 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/11 10:09:29 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*root;

	if (!str)
		return (str);
	root = str;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str += 'A' - 'a';
		str++;
	}
	return (root);
}