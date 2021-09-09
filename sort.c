/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:18:37 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/09 15:08:38 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void is_push(t_stack *a, t_stack *b)
{
	t_node *cur;
	int max;
	int min;

	if (b->size == 0)
		pb(a, b);
	else
	{
		cur = b->head;
		max = find_min_max(b, 0);
		min = find_min_max(b, 1);
		if (!(a->head->data > max || a->head->data < min))
		{
			while (cur != b->tail)
			{
				if (cur->data > b->head->data && max > cur->data)
					max = cur->data;
				cur = cur->next;
			}
			if (cur->data > b->head->data && max > cur->data)
				max = cur->data;
		}
		move_top(a, max);
		pb(a, b);
	}
}

void compare_mcount(t_stack *stack, t_pivot *pivot)
{
	int f;
	int l;

	if (pivot->hold_f == NULL && pivot->hold_l != NULL)
		move_top(stack, pivot->hold_l->data);
	else if (pivot->hold_l == NULL && pivot->hold_f != NULL)
		move_top(stack, pivot->hold_f->data);
	else
	{
		f = search_pos(stack, pivot->hold_f->data);
		l = search_pos(stack, pivot->hold_l->data);
		if (f > stack->size / 2)
			f = stack->size - f;
		if (l > stack->size / 2)
			l = stack->size - l;
		printf("f:%d l:%d\n", f, l);
		if (f <= l)
			move_top(stack, pivot->hold_f->data);
		else
			move_top(stack, pivot->hold_l->data);
	}
}

void hold_num(t_stack *stack, t_pivot *pivot, int min, int max)
{
	t_node *first;
	t_node *last;

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
	if (first == stack->tail && min <= first->data && first->data < max)
		pivot->hold_f = first;
	while (pivot->hold_l == NULL && last != stack->head)
	{
		if (min <= first->data && first->data < max)
			pivot->hold_l = last;
		last = last->prev;
	}
	if (stack->size == 1)
		pivot->hold_f = stack->head;
}

void b_to_a(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
}

void a_to_b(t_stack *a, t_stack *b)
{
	t_pivot pivot;
	int chunk;
	int range;
	int min;
	int max;

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
			continue;
		}
		printf("first:%d last:%d\n", pivot.hold_f->data, pivot.hold_l->data);
		compare_mcount(a, &pivot);
		printf("A:");
		print_stack(a);
		printf("B:");
		print_stack(b);
		is_push(a, b);
	}
}

void sort(t_stack *a)
{
	printf("----------------\n");
	t_stack *b;
	b = init_stack();
	printf("A:");
	print_stack(a);
	a_to_b(a, b);
	printf("----------------\n");
	printf("A:");
	print_stack(a);
	printf("B:");
	print_stack(b);
	reset_stack(b);
	free(b);
}