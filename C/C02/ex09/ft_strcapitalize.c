/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:36:55 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/10 10:57:52 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_alphanum(char c)
{
	return (is_lower(c) || is_upper(c)
		|| (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!is_alphanum(str[i]))
			continue ;
		str[i] += ('A' - 'a') * (is_lower(str[i]));
		while (is_alphanum(str[++i]))
			str[i] += ('a' - 'A') * is_upper(str[i]);
	}
	return (str);
}
