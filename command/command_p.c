/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:23:22 by hyenam            #+#    #+#             */
/*   Updated: 2021/08/26 16:21:45 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pa(t_stack *a, t_stack *b)
{
    printf("pa ");

    t_node *temp;

    temp = b->tail;
    if (temp == NULL)
        return;
    add_last(a, temp->data);
    delete_last(b);
}

void pb(t_stack *a, t_stack *b)
{
    printf("pb ");
    t_node *temp;

    temp = a->tail;
    if (temp == NULL)
        return;
    add_last(b, temp->data);
    delete_last(a);
}
