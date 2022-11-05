/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:19:23 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/24 14:46:02 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterfly_sort(t_list **stack_a, t_list **stack_b, int n)
{
	int	count;

	count = 0;
	while ((*stack_a))
	{
		if ((*stack_a)->index <= count)
		{
			pb(stack_a, stack_b);
			ra_rb(stack_b, 2);
			count++;
		}
		else if ((*stack_a)->index <= count + n)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else
			ra_rb(stack_a, 1);
	}
}

void	push_stack_a(t_list **stack_a, t_list **stack_b, int len)
{
	int	max;

	max = 0;
	while (*stack_b)
	{
		max = find_max(stack_b);
		if (max <= len / 2)
		{
			while (max-- >= 1)
				ra_rb(stack_b, 2);
			pa(stack_a, stack_b);
			len--;
		}
		else if (max > len / 2)
		{
			while (len - max)
			{
				rra_rrb(stack_b, 2);
				max++;
			}
			pa(stack_a, stack_b);
			len--;
		}
	}
}
