/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:17:36 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/08 14:31:39 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void print_arr(int *arr, int size)
// {
//     for (int i = 0; i < size; i++)
//         printf("arr[%d]:%d\n", i, arr[i]);
// }

int ready_made(t_stack *stack)
{
	t_node *cur;

	cur = stack->head;
	while (cur != stack->tail)
	{
		if (cur->data < cur->next->data)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void duplicate(int *arr, int size)
{
	int i;

	i = -1;
	while (++i < size)
		if (arr[i + 1] && arr[i] == arr[i + 1])
			error_handler();
}

void swap(int *arr, int a, int b)
{
	int temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void quick_sort(int *arr, int left, int right)
{
	int pivot;
	int i;
	int j;

	if (left >= right)
		return;
	pivot = arr[left];
	i = left + 1;
	j = right;

	while (i <= j)
	{
		while (arr[i] >= pivot && i <= right)
			i++;
		while (arr[j] <= pivot && j > left)
			j--;
		if (i <= j)
			swap(arr, i, j);
		else
			swap(arr, left, j);
	}
	quick_sort(arr, left, j - 1);
	quick_sort(arr, j + 1, right);
}

void check_args(t_stack *stack)
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
	// print_arr(arr, stack->size);
	duplicate(arr, stack->size);
	free(arr);
}