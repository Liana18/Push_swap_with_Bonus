/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:04:44 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/24 17:37:33 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap.h"

void	checker(char *str)
{
	int	i;

	i = 0;
	if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' '
		|| ((str[i] == '+' || str[i] == '-')
			&& (str[i + 1] >= '0' && str[i + 1] <= '9')))
			i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
			i++;
		else
			if ((str[i] == '+' || str[i] == '-')
				&& (str[i + 1] >= '0' && str[i + 1] <= '9')
				&& str[i - 1] == ' ')
			i++;
		else
			print_error();
	}
}

void	checke_dup(int *arr_int, int arr_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_len)
	{
		j = i + 1;
		while (j < arr_len)
		{
			if (arr_int[i] == arr_int[j] && i != j)
				print_error();
			j++;
		}
		i++;
	}
}
