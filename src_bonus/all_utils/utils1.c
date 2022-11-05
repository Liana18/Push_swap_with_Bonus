/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:04:24 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/20 19:37:25 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	matrix_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
			i++;
	return (i);
}

char	*ft_strjoin(char *str_main, char *str_copy)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = -1;
	j = -1;
	len = ft_strlen(str_main) + ft_strlen(str_copy);
	str = malloc(len + 2);
	if (!str)
		return (0);
	while (str_main[++i])
			str[i] = str_main[i];
	while (str_copy[++j])
		str[i++] = str_copy[j];
		str[i] = ' ';
		str[++i] = '\0';
	if (str_main)
		free(str_main);
	return (str);
}

int	ft_atoi(char *str)
{
	int			i;
	long int	num;
	int			min;

	min = 1;
	num = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min = min * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if (num * min > INT_MAX || num * min < INT_MIN)
		print_error();
	return (num * min);
}

int	is_sorted(int *arr, int len)
{
	int	i;

	i = 0;
	if (len == 1 || len == 0)
		return (1);
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
