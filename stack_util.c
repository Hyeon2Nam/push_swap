/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:59:07 by hyenam            #+#    #+#             */
/*   Updated: 2021/08/18 17:52:53 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(void)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;

	return (stack);
}

void reset_stack(t_stack *stack)
{
    t_node *node;
    t_node *cur;

    cur = stack->head;
    while (cur != stack->tail)
    {
        node = cur->next;
        free(cur);
        cur = node;
    }
    free(cur);
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
}

void replace_data(t_stack *stack, int pos, int data)
{
    t_node *cur;

    cur = stack->head;
    while (--pos)
        cur = cur->next;
    cur->data = data;
}

void search_node(t_stack *stack, int pos)
{
    t_node *cur;
    int n;

    cur = stack->head;
    if (pos == 1)
        printf("data[%d] = %d\n", pos, cur->data);
    else
    {
        n = pos;
        while (--n)
            cur = cur->next;
        printf("data[%d] = %d\n", pos, cur->data);
    }
}

void print_stack(t_stack *stack)
{
    t_node *cur;
    int n;

    cur = stack->head;
    if (cur == NULL)
        printf("stack is empty\n");
    else
    {
        n = 1;
        while (cur != stack->tail)
        {
            printf("Data[%d] = %d\n", n, cur->data);
            cur = cur->next;
            n++;
        }
        printf("Data[%d] = %d\n", n, cur->data);
    }
    printf("-------------------\n");
}