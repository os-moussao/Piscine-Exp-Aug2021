/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:27:03 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:27:04 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*ptr;
	int		tmp;

	ptr = lst;
	while (lst && lst->next)
	{
		if ((*cmp)(lst->data, lst->next->data))
			lst = lst->next;
		else
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = ptr;
		}
	}
	return (ptr);
}
