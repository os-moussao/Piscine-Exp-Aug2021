/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: os-moussao <omoussao@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:26:28 by os-moussao        #+#    #+#             */
/*   Updated: 2021/10/10 14:26:32 by os-moussao       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>

void	ft_list_foreach(t_list *begin, void (*f) (void *))
{
	if (begin)
	{
		(*f)(begin->data);
		ft_list_foreach(begin->next, f);
	}
}
