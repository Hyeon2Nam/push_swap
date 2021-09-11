/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:57:29 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/11 18:54:24 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compare_mcount(t_stack *stack, t_pivot *pivot)
{
	int	f;
	int	l;

	if (pivot->hold_l == NULL && pivot->hold_f != NULL)
		move_top(stack, pivot->hold_f->data);
	else
	{
		f = search_pos(stack, pivot->hold_f->data);
		l = search_pos(stack, pivot->hold_l->data);
		if (f > stack->size / 2)
			f = stack->size - f;
		if (l > stack->size / 2)
			l = stack->size - l;
		if (f <= l)
			move_top(stack, pivot->hold_f->data);
		else
			move_top(stack, pivot->hold_l->data);
	}
}

void	calc_pos_b(t_stack *a, t_stack *b)
{
	t_node	*cur;
	int		max;
	int		min;

	cur = b->head;
	max = find_min_max(b, 0);
	min = find_min_max(b, 1);
	if (a->head->data < min)
		move_top(b, min);
	else
	{
		while (cur != b->tail)
		{
			if (cur->data > a->head->data && max > cur->data)
				max = cur->data;
			cur = cur->next;
		}
		if (cur->data > a->head->data && max > cur->data)
			max = cur->data;
		move_top(b, max);
	}
	pb(a, b);
}

void	move_top(t_stack *stack, int pos)
{
	int	i;

	i = search_pos(stack, pos);
	if (i > stack->size / 2)
	{
		i = stack->size - i;
		while (i)
		{
			rra(stack);
			i--;
		}
	}
	else
	{
		while (i)
		{
			ra(stack);
			i--;
		}
	}
}

int	find_min_max(t_stack *stack, int key)
{
	t_node	*cur;
	int		*arr;
	int		i;

	i = -1;
	cur = stack->head;
	arr = (int *)malloc(sizeof(int) * stack->size);
	if (!arr)
		return (0);
	while (++i < stack->size)
	{
		arr[i] = cur->data;
		cur = cur->next;
	}
	quick_sort(arr, 0, stack->size - 1);
	if (key)
		i = arr[0];
	else
		i = arr[stack->size - 1];
	free(arr);
	return (i);
}
