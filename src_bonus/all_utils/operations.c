/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:06:21 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/05 13:59:23 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa_sb(t_list **list)
{
	t_list	*first;
	t_list	*second;

	if ((*list) == NULL)
		return ;
	if ((*list)->next != NULL)
	{
		first = *list;
		second = first->next;
		first->next = second->next;
		second->next = first;
		(*list) = second;
	}
}

void	ss(t_list **a_list, t_list **b_list)
{
	sa_sb(a_list);
	sa_sb(b_list);
}

void	pa(t_list **a_list, t_list **b_list)
{
	t_list	*push;

	push = NULL;
	if (*b_list)
	{
		push = *b_list;
		(*b_list) = (*b_list)->next;
		push->next = *a_list;
		*a_list = push;
	}
}

void	pb(t_list **a_list, t_list **b_list)
{
	t_list	*push;

	push = NULL;
	if (*a_list)
	{
		push = *a_list;
		(*a_list) = (*a_list)->next;
		push->next = *b_list;
		*b_list = push;
	}
}

void	ra_rb(t_list **list)
{
	t_list	*adress;
	t_list	*node;

	adress = NULL;
	node = NULL;
	if ((*list)->next != NULL)
	{
		adress = *list;
		(*list) = (*list)->next;
		node = *list;
		if (adress)
		{
			while (node->next != NULL)
			{
				node = node->next;
			}
			node->next = adress;
			node->next->next = NULL;
		}
	}
}
