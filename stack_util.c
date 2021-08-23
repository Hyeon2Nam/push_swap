/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:59:07 by hyenam            #+#    #+#             */
/*   Updated: 2021/08/23 16:22:38 by hyenam           ###   ########.fr       */
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

t_node *search_node(t_stack *stack, int data)
{
    t_node *cur;

    cur = stack->head;
    while (data != cur->data)
        cur = cur->next;
    return(cur);    
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
        n = 0;
        while (cur != stack->tail)
        {
            printf("Stack[%d] = %d\n", n, cur->data);
            cur = cur->next;
            n++;
        }
        printf("Stack[%d] = %d\n", n, cur->data);
    }
    printf("-------------------\n");
}