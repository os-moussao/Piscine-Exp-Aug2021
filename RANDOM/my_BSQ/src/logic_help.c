/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:14:31 by omoussao          #+#    #+#             */
/*   Updated: 2021/08/25 16:52:05 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

void	append(t_list **head, int new_data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->data = new_data;
	new->next = NULL;
	
}
