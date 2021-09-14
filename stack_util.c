/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:59:07 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/14 14:56:01 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

void	reset_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*cur;

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

int	search_pos(t_stack *stack, int data)
{
	t_node	*cur;
	int		i;

	i = 0;
	cur = stack->head;
	while (cur->data != data)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}
