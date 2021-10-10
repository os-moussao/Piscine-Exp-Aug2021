/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_list_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:24:11 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:24:15 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	return (1 + ft_list_size(begin_list->next));
}

int	main(void)
{
	t_list	*begin;
	t_list	*tmp;

	begin = malloc(sizeof(t_list));
	begin->next = malloc(sizeof(t_list));
	begin->next->next = malloc(sizeof(t_list));
	begin->next->next->next = malloc(sizeof(t_list));
	begin->next->next->next->next = NULL;
	printf("the size of the list is: %d", ft_list_size(begin));
	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
}
