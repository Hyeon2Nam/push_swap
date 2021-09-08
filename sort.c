/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:18:37 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/08 17:50:28 by hyenam           ###   ########.fr       */
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
		return (0);
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

int ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

double ft_sqrt(double num)
{
	double res;
	int i;

	res = 2;
	i = 0;
	while (i < 10)
	{
		res = (res + (num / res)) / 2;
		i++;
	}
	return (res);
}

void b_to_a(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
}

void a_to_b(t_stack *a, t_stack *b)
{
	(void)b;
	t_node *cur;
	int chunk;
	int range;
	int min;
	int max;
	int i;
	int temp;

	cur = a->tail;
	min = find_min_max(a, 1);
	max = find_min_max(a, 0);
	chunk = ft_sqrt(ft_abs(min) + ft_abs(max)) / 2 + 1;
	range = a->size / chunk;
	i = 0;
	while (min <= max)
	{
		printf("%d <= %d < %d\n", min, cur->data, min + range);
		if (min <= cur->data && cur->data < min + range)
		{
			if (cur == a->head)
				min += range;
			i = search_pos(a, cur->data) + 1;
			if (i > a->size / 2)
			{
				i = a->size - i + 1;
				while (--i)
					ra(a);
			}
			else
				while (i)
				{
					rra(a);
					i--;
				}
			if (cur->prev->data == cur->data)
				cur = cur->prev;
			cur = cur->prev;
			if (b->tail != NULL && find_min_max(b, 0) < a->tail->data)
			{
				temp = find_min_max(b, 1);
				i = search_pos(b, temp) + 1;
				if (i > b->size / 2)
				{
					i = b->size - i + 1;
					while (--i)
						rb(b);
				}
				else
					while (i)
					{
						rrb(b);
						i--;
					}
			}
			printf("A:");
			print_stack(a);
			printf("B:");
			print_stack(b);
			printf("before prev:%d cur:%d next:%d \n", cur->prev->data, cur->data, cur->next->data);
			pb(a, b);
			printf("after:%d cur:%d next:%d \n", cur->prev->data, cur->data, cur->next->data);
			printf("A:");
			print_stack(a);
			printf("B:");
			print_stack(b);
		}
		else
		{
			if (cur == a->head)
				min += range;
			cur = cur->prev;
		}
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