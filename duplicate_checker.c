/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:17:36 by hyenam            #+#    #+#             */
/*   Updated: 2021/08/23 18:16:16 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("arr[%d]:%d\n", i, arr[i]);
}

t_pivot *set_pivot(int *arr, t_stack *stack)
{
    t_pivot *pivot;

    pivot = (t_pivot *)malloc(sizeof(t_pivot));
    pivot->small = arr[(stack->size / 2) / 2];
    pivot->big = arr[stack->size - ((stack->size / 2) / 2) - 1];
    printf("small : %d big : %d\n", pivot->small, pivot->big);
    return (pivot);
}

int ready_made(int *arr, t_stack *stack)
{
    printf("check ready_made...\n");

    t_node *cur;
    int i;
    int check;

    cur = stack->head;
    i = -1;
    check = 0;
    while (++i < stack->size)
    {
        if (arr[i] == cur->data)
            check++;
        cur = cur->next;
    }
    return (check);
}

void duplicate(int *arr, int size)
{
    printf("check duplicate...\n");

    int i;

    i = -1;
    while (++i < size)
        if (arr[i + 1] && arr[i] == arr[i + 1])
            error_handler();
}

static void swap(int *arr, int a, int b)
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
        return ;
    pivot = arr[left];
    i = left + 1;
    j = right;

    while (i <= j)
    {
        while (arr[i] <= pivot && i <= right)
            i++;
        while (arr[j] >= pivot && j > left)
            j--;
        if (i <= j)
            swap(arr, i, j);
        else
            swap(arr, left, j);
    }
    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}

t_pivot *check_duplicate(t_stack *stack)
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
    quick_sort(arr, 0, stack->size - 1);
    print_arr(arr, stack->size);
    duplicate(arr, stack->size);
    if (ready_made(arr, stack) == stack->size)
        exit(0);
    printf("PASS\n");
    return (set_pivot(arr, stack));
}