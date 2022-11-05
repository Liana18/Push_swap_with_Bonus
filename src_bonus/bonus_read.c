/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:42:45 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/05 13:57:49 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	issorted(t_list **stack_a)
{
	while ((*stack_a)->next)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			return (0);
		else
			*stack_a = (*stack_a)->next;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	do_the_move(char *op, t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	if (!ft_strcmp(op, "sa\n"))
		sa_sb(stack_a);
	else if (!ft_strcmp(op, "sb\n"))
		sa_sb(stack_b);
	else if (!ft_strcmp(op, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(op, "ra\n"))
		ra_rb(stack_a);
	else if (!ft_strcmp(op, "rb\n"))
		ra_rb(stack_b);
	else if (!ft_strcmp(op, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(op, "rra\n"))
		rra_rrb(stack_a);
	else if (!ft_strcmp(op, "rrb\n"))
		rra_rrb(stack_b);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(stack_a, stack_b);
	else if (!ft_strcmp(op, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(op, "pb\n"))
		pb(stack_a, stack_b);
	else
		print_error();
}

void	read_data(t_list **stack_a, t_list **stack_b)
{
	char	*op;

	if (!*stack_a)
		print_error();
	op = get_next_line(0);
	while (op)
	{
		do_the_move(op, stack_a, stack_b);
		op = get_next_line(0);
	}
	if (*stack_b == NULL && *stack_a && issorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
