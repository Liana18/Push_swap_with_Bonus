/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:25:32 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/21 00:52:41 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list **list)
{
	int		i;
	int		j;
	int		max;
	t_list	*node;

	i = 0;
	j = 0;
	node = *list;
	max = node->index;
	node = node->next;
	while (node)
	{
		if (max < node->index)
		{
			max = node->index;
			node = node->next;
			j = ++i;
		}
		else
		{
			node = node->next;
			i++;
		}
	}
	return (j);
}
