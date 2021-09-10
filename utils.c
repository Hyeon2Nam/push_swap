/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:40:00 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/10 14:57:56 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_top(t_stack *stack, int pos)
{
	int i;

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

void ft_free(char **arr)
{
	int len;
	int i;

	len = 0;
	while (arr[len])
		len++;
	i = 0;
	while (i < len)
		free(arr[i++]);
	free(arr);
}