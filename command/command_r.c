/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:23:05 by hyenam            #+#    #+#             */
/*   Updated: 2021/08/26 16:21:53 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ra(t_stack *stack)
{
    printf("ra ");
    add_first(stack, stack->tail->data);
    delete_last(stack);
}

void rb(t_stack *stack)
{
    printf("rb ");
    add_first(stack, stack->tail->data);
    delete_last(stack);
}

void rr(t_stack *a, t_stack *b)
{
    printf("rr\n");
    ra(a);
    rb(b);
}