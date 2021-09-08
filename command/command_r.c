/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:23:05 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/08 17:14:31 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ra(t_stack *stack)
{
    printf("ra\n");
    add_last(stack, stack->head->data);
    delete_first(stack);
}

void rb(t_stack *stack)
{
    printf("rb\n");
    add_last(stack, stack->head->data);
    delete_first(stack);
}

void rr(t_stack *a, t_stack *b)
{
    printf("rr\n");
    ra(a);
    rb(b);
}