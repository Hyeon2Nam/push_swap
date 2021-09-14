/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:22:31 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/14 15:35:35 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				data;
}				t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}				t_stack;

typedef struct s_pivot
{
	t_node	*hold_f;
	t_node	*hold_l;
}				t_pivot;

void	error_handler(void);
void	sort_case(t_stack *stack);
void	input_data(t_stack *stack, int argc, char *args[]);

t_stack	*init_stack(void);
void	reset_stack(t_stack *stack);
int		search_pos(t_stack *stack, int data);
void	print_stack(t_stack *stack);

void	add_first(t_stack *stack, int data);
void	add_last(t_stack *stack, int data);
void	add_pos(t_stack *stack, int pos, int data);
void	delete_first(t_stack *stack);
void	delete_last(t_stack *stack);

void	check_args(t_stack *stack);
void	quick_sort(int *arr, int left, int right);
void	swap(int *arr, int a, int b);
void	duplicate(int *arr, int size);
int		ready_made(t_stack *stack);

void	exsort(t_stack *stack, int size);
void	extra_three_sort(t_stack *stack);
void	three_sort(t_stack *stack);
void	five_sort(t_stack *a);
void	calc_pos_a(t_stack *a, t_stack *b);

void	sort(t_stack *a);
void	a_to_b(t_stack *a, t_stack *b);
void	b_to_a(t_stack *a, t_stack *b);
void	hold_num(t_stack *stack, t_pivot *pivot, int min, int max);
void	is_push(t_stack *a, t_stack *b);

int		find_min_max(t_stack *stack, int key);
void	move_top_a(t_stack *stack, int pos);
void	move_top_b(t_stack *stack, int pos);
void	calc_pos_b(t_stack *a, t_stack *b);
void	compare_mcount(t_stack *stack, t_pivot *pivot);

void	ft_free(char **arr);
double	ft_sqrt(double num);
int		ft_abs(int num);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);

#endif
