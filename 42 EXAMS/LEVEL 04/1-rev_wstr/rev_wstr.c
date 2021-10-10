/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:26:37 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:26:40 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

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
	return (c == ' ' || c == '\t');
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

int	main(int argc, char **argv)
{
	char	**arr;
	int		words;
	int		i;
	int		j;

	if (argc == 2)
	{
		words = count_words(argv[1]);
		arr = malloc(words * sizeof(char *));
		fill_arr_with_words(arr, argv[1]);
		i = words;
		while (--i >= 0)
		{
			j = 0;
			while (arr[i][j])
				write(1, &arr[i][j++], 1);
			free(arr[i]);
			if (i != 0)
				write(1, " ", 1);
		}
		free(arr);
	}
	write(1, "\n", 1);
}
