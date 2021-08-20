/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:19:57 by hyenam            #+#    #+#             */
/*   Updated: 2021/08/18 17:36:40 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sa(t_stack *stack)
{
    int data;

    data = stack->tail->data;
    add_pos(stack, stack->size-1, data);
    delete_last(stack);
    printf("sa\n");
}

void sb(t_stack *stack)
{
    int data;

    data = stack->tail->data;
    add_pos(stack, stack->size-1, data);
    delete_last(stack);
    printf("sb\n");
}

void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
    printf("ss\n");
}
