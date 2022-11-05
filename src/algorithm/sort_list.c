/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:53:02 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/29 14:04:54 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **list)
{
	if ((*list)->index > (*list)->next->index)
		sa_sb(list, 1);
}

void	sort_three(t_list **list)
{
	int	i;

	i = find_max(list);
	if (i == 2)
		sort_two(list);
	if (i == 1)
	{
		rra_rrb(list, 1);
		sort_two(list);
	}
	if (i == 0)
	{
		ra_rb(list, 1);
		sort_two(list);
	}
}

void	sort_foure(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = find_max(stack_a);
	if (i == 3)
		rra_rrb(stack_a, 1);
	else if (i == 2)
	{
		rra_rrb(stack_a, 1);
		rra_rrb(stack_a, 1);
	}
	else
		if (i == 1)
			ra_rb(stack_a, 1);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	ra_rb(stack_a, 1);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = find_max(stack_a);
	if (i == 4)
		rra_rrb(stack_a, 1);
	else if (i == 3)
	{
		rra_rrb(stack_a, 1);
		rra_rrb(stack_a, 1);
	}
	else if (i == 2)
	{
		ra_rb(stack_a, 1);
		ra_rb(stack_a, 1);
	}
	else if (i == 1)
		ra_rb(stack_a, 1);
	pb(stack_a, stack_b);
	sort_foure(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra_rb(stack_a, 1);
}

void	sort_list(t_list **stack_a, t_list **stack_b, int len)
{
	if (len == 2)
		sort_two(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 4)
		sort_foure(stack_a, stack_b);
	else if (len == 5)
		sort_five(stack_a, stack_b);
	else if (len >= 6 && len <= 100)
	{
		butterfly_sort(stack_a, stack_b, 15);
		push_stack_a(stack_a, stack_b, len);
	}
	else if (len > 100 && len < 500)
	{
		butterfly_sort(stack_a, stack_b, 30);
		push_stack_a(stack_a, stack_b, len);
	}
	else if (len >= 500)
	{
		butterfly_sort(stack_a, stack_b, 40);
		push_stack_a(stack_a, stack_b, len);
	}
}
