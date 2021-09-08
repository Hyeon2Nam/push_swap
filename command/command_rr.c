/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:22:23 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/08 17:14:32 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rra(t_stack *stack)
{
    printf("rra\n");
    add_first(stack, stack->tail->data);
    delete_last(stack);
}

void rrb(t_stack *stack)
{
    printf("rrb\n");
    add_first(stack, stack->tail->data);
    delete_last(stack);
}

void rrr(t_stack *a, t_stack *b)
{
    printf("rrr\n");
    rra(a);
    rrb(b);
}
