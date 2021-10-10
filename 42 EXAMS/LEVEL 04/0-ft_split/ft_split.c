/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:26:33 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:26:36 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	is_sep(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (is_sep(*str))
		{
			str++;
			continue ;
		}
		count++;
		while (!is_sep(*str) && *str)
			str++;
	}
	return (count);
}

void	fill_arr_with_words(char **arr, char *str)
{
	int	i;
	int	tmp_i;
	int	index;

	i = 0;
	index = 0;
	while (str[i])
	{
		if (is_sep(str[i]))
		{
			i++;
			continue ;
		}
		tmp_i = i;
		while (!is_sep(str[i]) && str[i])
			i++;
		arr[index] = malloc(i - tmp_i + 1);
		ft_strncpy(arr[index], str + tmp_i, i - tmp_i + 1);
		index++;
	}
}

char	**ft_split(char *str)
{
	char	**arr;
	int		words;

	words = count_words(str);
	arr = malloc((words + 1) * sizeof(char *));
	arr[words] = 0;
	fill_arr_with_words(arr, str);
	return (arr);
}
