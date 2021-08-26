/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:22:23 by hyenam            #+#    #+#             */
/*   Updated: 2021/08/26 16:01:18 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rra(t_stack *stack)
{
    // printf("rra\n");
    add_last(stack, stack->head->data);
    delete_first(stack);
}

void rrb(t_stack *stack)
{
    // printf("rrb\n");
    add_last(stack, stack->head->data);
    delete_first(stack);
}

void rrr(t_stack *a, t_stack *b)
{
    printf("rrr\n");
    rra(a);
    rrb(b);
}
