/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exsort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 15:20:46 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/07 17:59:34 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void five_sort(t_stack *stack)
{
	(void)stack;
}

void three_sort(t_stack *stack)
{
	if (stack->head->data > stack->head->next->data && stack->tail->data > stack->head->next->data && stack->tail->data > stack->head->data)
		sa(stack);
	else if (stack->head->data > stack->head->next->data && stack->tail->data > stack->head->next->data && stack->tail->data < stack->head->data)
		ra(stack);
	else if (stack->tail->data < stack->head->next->data && stack->head->data < stack->head->next->data && stack->tail->data < stack->head->data)
		rra(stack);
	else if (stack->head->data < stack->head->next->data && stack->tail->data < stack->head->next->data && stack->head->data < stack->tail->data)
	{
		sa(stack);
		ra(stack);
	}
	else if (stack->head->data > stack->head->next->data && stack->tail->data < stack->head->next->data && stack->head->data > stack->tail->data)
	{
		sa(stack);
		rra(stack);
	}
}

void exsort(t_stack *stack, int size)
{
	if (size == 2)
		ra(stack);
	if (size == 3)
		three_sort(stack);
	else
		five_sort(stack);
	exit(0);
}