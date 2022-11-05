/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:00:50 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/02 20:45:53 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list	t_list;
typedef struct s_stack	t_stack;
typedef struct s_sdata	t_sdata;
typedef struct s_parts	t_parts;

struct s_list
{
	int		data;
	int		index;
	t_list	*next;
};

char	**ft_split(char const *s, char c);
void	print_error(void);
int		ft_strlen(char *str);
char	*ft_join_str(char **str);
void	checker(char *str);
int		*char_to_int(int len, char **map);
int		matrix_len(char **str);
int		ft_atoi(char *str);
void	checke_dup(int *arr_int, int arr_len);
char	*ft_strjoin(char *str_main, char *str_copy);
void	arr_to_list(int *arr, int len);
int		cut_list_front(t_list **list);
void	index_list(t_list **list, int len);
void	sort_list(t_list **stack_a, t_list **stack_b, int len);
void	free_leakc(t_list **list);
void	butterfly_sort(t_list **stack_a, t_list **stack_b, int len);
void	push_stack_a(t_list **stack_a, t_list **stack_b, int n);
int		find_max(t_list **list);
int		is_sorted(int *arr, int len);

void	sa(t_list *list, int i);
void	sb(t_list *list, int i);
void	sa_sb(t_list **list, int i);
void	ra_rb(t_list **list, int i);
void	rra_rrb(t_list **list, int n);
void	rra_rrb(t_list **list, int n);
void	ss(t_list *a_list, t_list *b_list);
void	pa(t_list **a_list, t_list **b_list);
void	pb(t_list **a_list, t_list **b_list);
void	rr(t_list **list_a, t_list **list_b);
#endif
