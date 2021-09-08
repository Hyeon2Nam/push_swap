/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:19:57 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/08 17:33:14 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sa(t_stack *stack)
{
	int data;

	data = stack->head->data;
	add_pos(stack, 1, data);
	delete_first(stack);
	printf("sa\n");
}

void sb(t_stack *stack)
{
	int data;

	data = stack->head->data;
	add_pos(stack, 1, data);
	delete_first(stack);
	printf("sb\n");
}

void ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	printf("ss\n");
}
