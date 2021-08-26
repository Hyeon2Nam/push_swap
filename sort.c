/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:18:37 by hyenam            #+#    #+#             */
/*   Updated: 2021/08/26 16:13:04 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calc_pivot(t_stack *stack)
{
    t_node *cur;
    int *arr;
    int res;
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
    res = arr[stack->size / 2];
    free(arr);
    return (res);
}

void b_to_a(t_stack *a, t_stack *b, int call)
{
    t_node *cur;
    int temp;
    int size;
    int i;
    int rbc;
    int pac;

    if (call == 1)
    {
        pb(a, b);
        return;
    }
    temp = calc_pivot(b);
    printf("temp:%d\n", temp);
    size = b->size;
    rbc = 0;
    pac = 0;
    i = -1;
    while (++i < size)
    {
        cur = b->tail;
        if (cur->data >= temp)
        {
            rb(b);
            rbc++;
        }
        else
        {
            pa(a, b);
            pac++;
        }
    }
    i = -1;
    while (++i < rbc)
        rrb(b);
    printf("A\n");
    print_stack(a);
    printf("B\n");
    print_stack(b);
    a_to_b(a, b, pac);
    b_to_a(a, b, rbc);
}

void a_to_b(t_stack *a, t_stack *b, int call)
{
    t_node *cur;
    int temp;
    int size;
    int i;
    int rac;
    int pbc;

    if (call == 1)
        return;
    temp = calc_pivot(a);
    printf("temp:%d\n", temp);
    size = a->size;
    rac = 0;
    pbc = 0;
    i = -1;
    while (++i < size)
    {
        cur = a->tail;
        if (cur->data >= temp)
        {
            ra(a);
            rac++;
        }
        else
        {
            pb(a, b);
            pbc++;
        }
    }
    i = -1;
    while (++i < rac)
        rra(a);
    printf("A\n");
    print_stack(a);
    printf("B\n");
    print_stack(b);
    a_to_b(a, b, rac);
    b_to_a(a, b, pbc);
}

void sort(t_stack *a)
{
    printf("----------------\n");
    t_stack *b;
    // (void)pivot;
    b = init_stack();
    a_to_b(a, b, a->size);
    printf("----------------\n");
    printf("A\n");
    print_stack(a);
    printf("B\n");
    print_stack(b);
    reset_stack(b);
    free(b);
}