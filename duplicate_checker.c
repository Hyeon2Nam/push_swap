/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:17:36 by hyenam            #+#    #+#             */
/*   Updated: 2021/08/20 16:30:24 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("arr[%d]:%d\n", i, arr[i]);
}

void left_sort(int *arr, int pivot)
{
    int temp;
    int i;

    i = pivot;
    while (--i >= 0)
    {
        
    }
}

void right_sort(int *arr, int pivot)
{
}

void quick_sort(int *arr, int left, int right)
{
}

void check_duplicate(t_stack *stack)
{
    t_node *cur;
    int *arr;
    int i;

    i = -1;
    cur = stack->head;
    arr = (int *)malloc(sizeof(int) * stack->size);
    while (++i <= stack->size)
    {
        arr[i] = cur->data;
        cur = cur->next;
    }
    quick_sort(arr, stack->size / 2);
}