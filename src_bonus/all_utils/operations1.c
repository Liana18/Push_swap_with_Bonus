/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:44:01 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/05 13:42:15 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rr(t_list **list_a, t_list **list_b)
{
	ra_rb(list_a);
	ra_rb(list_b);
}

void	rra_rrb(t_list **list)
{
	t_list	*adress;
	t_list	*tmp;
	t_list	*tmp2;

	if (*list)
	{
		adress = *list;
		tmp = *list;
		while (adress->next != NULL)
		{
			tmp2 = adress;
			adress = adress->next;
		}
		tmp2->next = NULL;
		adress->next = tmp;
		*list = adress;
	}
}

void	rrr(t_list **list_a, t_list **list_b)
{
	rra_rrb(list_a);
	rra_rrb(list_b);
}
