/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:18:37 by hyenam            #+#    #+#             */
/*   Updated: 2021/08/28 16:52:35 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min_max(t_stack *stack, int key)
{
	t_node *cur;
	int *arr;
	int i;

	i = -1;
	cur = stack->head;
	arr = (int *)malloc(sizeof(int) * stack->size);
	if (!arr)
		return;
	while (++i <= stack->size)
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

int ft_sqrt(int num)
{
	int i;

	if (num <= 0)
		return (0);
	if (num == 1)
		return (1);
	i = 2;
	while (i * i <= num)
	{
		if (i * i == num)
			return (i);
		i++;
	}
	return (0);
}

void b_to_a(t_stack *a, t_stack *b)
{
	t_node *max;
	int max;
	int j;

	max = find_min_max(b, 0);
	j = search_pos(max) + 1;
	if (j - 1 > b->size / 2)
		while (b->size - (--j))
			rra(a);
	while (b->head != NULL)
		pa(a, b);
}

void a_to_b(t_stack *a, t_stack *b)
{
	t_node *cur;
	int chunk;
	int min;
	int size;
	int i;
	int j;

	cur = a->head;
	chunk = ft_sqrt(size) / 2;
	i = 1;
	while (i <= chunk)
	{
		if (chunk * (i - 1) - 1 < cur->data && cur->data >= chunk * i - 1)
		{
			if (cur == a->tail)
				i++;
			j = search_pos(cur->data) + 1;
			if (j - 1 > a->size / 2)
				while (a->size - (--j))
					rra(a);
			else
				while (--j)
					ra(a);
			if (b->head->data < a->head)
			{
				min = find_min_max(b, 1);
				j = search_pos(min) + 1;
				if (j - 1 > b->size / 2)
					while (a->size - (--j))
						rra(a);
				else
					while (--j)
						ra(a);
			}
			pb(a, b);
			cur = cur->next;
		}
	}
	b_to_a(a, b);
}

void sort(t_stack *a)
{
	printf("----------------\n");
	t_stack *b;
	// (void)pivot;
	b = init_stack();
	a_to_b(a, b);
	printf("----------------\n");
	printf("A:");
	print_stack(a);
	printf("B:");
	print_stack(b);
	reset_stack(b);
	free(b);
}