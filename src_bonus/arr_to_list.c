/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:38:42 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/05 14:34:41 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	index_list(t_list **list, int len)
{
	t_list	*node;
	t_list	*max;
	int		i;

	i = 0;
	node = (*list)->next;
	max = *list;
	while (i < len)
	{
		while (node != NULL)
		{
			if (max->data > node->data && node->index == -1)
				max = node;
			node = node->next;
		}
		max->index = i;
		max = *list;
		node = *list;
		i++;
		while (i < len && max->index != -1)
			max = max->next;
	}
}

void	arr_to_list(int *arr, int len)
{
	t_list	*node;
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 0;
	stack_b = NULL;
	node = malloc(sizeof(t_list));
	stack_a = node;
	while (i < len)
	{
		stack_a->data = arr[i];
		stack_a->index = -1;
		if (i + 1 != len)
			stack_a->next = malloc(sizeof(t_list));
		else
			break ;
		stack_a = stack_a->next;
		stack_a->next = NULL;
		i++;
	}
	stack_a = node;
	read_data(&stack_a, &stack_b);
	free_leakc(&stack_a);
}
