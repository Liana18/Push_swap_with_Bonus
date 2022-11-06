/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:38:42 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/06 15:55:50 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	arr_to_list(int *arr, int len)
{
	t_list	*node;
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = -1;
	stack_b = NULL;
	node = malloc(sizeof(t_list));
	stack_a = node;
	while (++i < len)
	{
		stack_a->data = arr[i];
		if (i + 1 == len)
		{
			stack_a->next = NULL;
			break ;
		}
		stack_a->next = malloc(sizeof(t_list));
		stack_a = stack_a->next;
		stack_a->next = NULL;
	}
	stack_a = node;
	read_data(&stack_a, &stack_b);
	free_leakc(&stack_a);
}
