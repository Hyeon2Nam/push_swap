/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exsort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 15:20:46 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/10 16:08:26 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void calc_pos(t_stack *a, t_stack *b)
{
	t_node *cur;
	int max;
	int min;

	cur = a->head;
	max = find_min_max(a, 0);
	min = find_min_max(a, 1);
	if (b->head->data > max || b->head->data < min)
		move_top(a, min);
	else
	{
		while (cur != a->tail)
		{
			if (cur->data > b->head->data && max > cur->data)
				max = cur->data;
			cur = cur->next;
		}
		if (cur->data > b->head->data && max > cur->data)
			max = cur->data;
		move_top(a, max);
	}
	pa(a, b);
}

void five_sort(t_stack *a)
{
	t_stack *b;

	b = init_stack();
	pb(a, b);
	pb(a, b);
	three_sort(a);
	calc_pos(a, b);
	calc_pos(a, b);
	move_top(a, find_min_max(a, 1));
	reset_stack(b);
	free(b);
}

void three_sort(t_stack *stack)
{
	if (stack->head->data > stack->head->next->data && stack->tail->data > stack->head->next->data && stack->head->data > stack->tail->data)
		ra(stack);
	else if (stack->head->data < stack->head->next->data && stack->tail->data < stack->head->next->data && stack->tail->data < stack->head->data)
		rra(stack);
	else if (stack->head->data > stack->head->next->data && stack->tail->data > stack->head->next->data && stack->head->data < stack->tail->data)
		sa(stack);
	else if (stack->head->data < stack->head->next->data && stack->tail->data < stack->head->next->data && stack->head->data < stack->tail->data)
	{
		sa(stack);
		ra(stack);
	}
	else if (stack->head->data > stack->head->next->data && stack->tail->data < stack->head->next->data && stack->head->data > stack->tail->data)
	{
		sa(stack);
		rra(stack);
	}
}

void exsort(t_stack *stack, int size)
{
	if (size == 2)
		ra(stack);
	else if (size == 3)
		three_sort(stack);
	else
		five_sort(stack);
}