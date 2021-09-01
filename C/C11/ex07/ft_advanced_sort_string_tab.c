/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 11:58:25 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/22 15:23:12 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_len(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void	swap_strings(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	length;
	int	swapped;

	length = get_len(tab);
	i = -1;
	while (++i < length)
	{
		j = 0;
		swapped = 0;
		while (j + 1 < length - i)
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
			{
				swap_strings(&tab[j], &tab[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			return ;
	}
}
