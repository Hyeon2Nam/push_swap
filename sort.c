/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:18:37 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/14 13:50:21 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_push(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		pb(a, b);
	else
		calc_pos_b(a, b);
}

void	hold_num(t_stack *stack, t_pivot *pivot, int min, int max)
{
	t_node	*first;
	t_node	*last;

	first = stack->head;
	last = stack->tail;
	pivot->hold_f = NULL;
	pivot->hold_l = NULL;
	while (pivot->hold_f == NULL && first != stack->tail)
	{
		if (min <= first->data && first->data < max)
			pivot->hold_f = first;
		first = first->next;
	}
	if (pivot->hold_f == NULL && min <= first->data && first->data < max)
		pivot->hold_f = first;
	while (pivot->hold_l == NULL && last != stack->head)
	{
		if (min <= last->data && last->data < max)
			pivot->hold_l = last;
		last = last->prev;
	}
	if (stack->size == 1)
		pivot->hold_f = stack->head;
}

void	b_to_a(t_stack *a, t_stack *b)
{
	int	i;

	while (b->size != 0)
	{
		i = search_pos(b, find_min_max(b, 0));
		if (i > b->size / 2)
		{
			i = b->size - i;
			while (i)
			{
				rrb(b);
				i--;
			}
		}
		else
		{
			while (i)
			{
				rb(b);
				i--;
			}
		}
		pa(a, b);
	}
}

void	a_to_b(t_stack *a, t_stack *b)
{
	t_pivot	pivot;
	int		chunk;
	int		range;
	int		min;
	int		max;

	min = find_min_max(a, 1);
	max = find_min_max(a, 0);
	chunk = ft_sqrt(ft_abs(min) + ft_abs(max)) / 2 + 1;
	range = a->size / chunk;
	while (a->size != 0)
	{
		hold_num(a, &pivot, min, min + range);
		if (pivot.hold_f == NULL)
		{
			min += range;
			continue ;
		}
		compare_mcount(a, &pivot);
		is_push(a, b);
	}
	b_to_a(a, b);
}

void	sort(t_stack *a)
{
	t_stack	*b;

	b = init_stack();
	a_to_b(a, b);
	reset_stack(b);
	free(b);
}
