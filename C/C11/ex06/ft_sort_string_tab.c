/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 11:44:37 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/22 12:10:47 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	sort_strings(char **s1, char **s2)
{
	char	*tmp;

	if (ft_strcmp(*s1, *s2) > 0)
	{
		tmp = *s1;
		*s1 = *s2;
		*s2 = tmp;
	}
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = i;
		while (tab[++j])
			sort_strings(&tab[i], &tab[j]);
	}
}
