/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:46:21 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/18 19:30:42 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *(sep++))
			return (1);
	}
	return (0);
}

void	my_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = -1;
	while (++i < n - 1)
		dest[i] = src[i];
	dest[i] = 0;
}

int	count_words(char *str, char *seps)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (is_sep(str[i], seps))
		{
			i++;
			continue ;
		}
		count++;
		while (!is_sep(str[i], seps) && str[i])
			i++;
	}
	return (count);
}

void	fill_array_with_words(char **arr, char *str, char *seps)
{
	int	index;
	int	i;
	int	tmp_i;

	index = 0;
	i = 0;
	while (str[i])
	{
		if (is_sep(str[i], seps))
		{
			i++;
			continue ;
		}
		tmp_i = i;
		while (!is_sep(str[i], seps) && str[i])
			i++;
		arr[index] = malloc(i - tmp_i + 1);
		my_strncpy(arr[index], str + tmp_i, i - tmp_i + 1);
		index++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		words_count;

	words_count = count_words(str, charset);
	array = malloc((words_count + 1) * sizeof(char *));
	if (!array)
		return (0);
	array[words_count] = 0;
	fill_array_with_words(array, str, charset);
	return (array);
}
