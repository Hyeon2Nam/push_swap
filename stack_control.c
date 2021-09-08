/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:55:10 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/08 17:33:06 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_first(t_stack *stack, int data)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;

	if (stack->head == NULL)
	{
		stack->head = node;
		stack->tail = node;
		stack->head->prev = node;
		stack->head->next = node;
	}
	else
	{
		node->prev = stack->head->prev;
		node->next = stack->head;
		stack->head->prev = node;
		stack->tail->next = node;
		stack->head = node;
	}
	stack->size++;
}

void add_last(t_stack *stack, int data)
{
	t_node *node = (t_node *)malloc(sizeof(t_node));

	node->data = data;
	if (stack->tail == NULL)
	{
		stack->head = node;
		stack->tail = node;
		stack->tail->prev = node;
		stack->tail->next = node;
	}
	else
	{
		node->prev = stack->tail;
		node->next = stack->tail->next;
		stack->tail->next = node;
		stack->head->prev = node;
		stack->tail = node;
	}
	stack->size++;
}

void add_pos(t_stack *stack, int pos, int data)
{
	t_node *node;
	t_node *cur;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	cur = stack->head;
	if (pos <= stack->size)
	{
		if (pos == 0)
			add_first(stack, data);
		else if (pos == stack->size - 1)
			add_last(stack, data);
		else
		{
			while (pos)
			{
				cur = cur->next;
				pos--;
			}
			node->prev = cur;
			node->next = cur->next;
			cur->next = node;
			node->next->prev = node;
			stack->size++;
		}
	}
	else
		printf("add error\n");
}

void delete_first(t_stack *stack)
{
	t_node *node;
	t_node *head;

	head = stack->head;
	if (head == NULL)
		printf("stack is empty\n");
	if (stack->size == 1)
		reset_stack(stack);
	else
	{
		node = stack->head->next;
		node->prev = stack->head->next;
		stack->tail->next = node;
		stack->head = node;
		free(head);
		stack->size--;
	}
}

void delete_last(t_stack *stack)
{
	t_node *node;
	t_node *tail;

	tail = stack->tail;
	if (tail == NULL)
		printf("stack is empty\n");
	if (stack->size == 1)
		reset_stack(stack);
	else
	{
		node = stack->tail->prev;
		node->next = stack->head;
		stack->head->prev = node;
		stack->tail = node;
		free(tail);
		stack->size--;
	}
}

void delete_pos(t_stack *stack, int pos)
{
	t_node *node;
	t_node *cur;

	cur = stack->head;
	if (pos <= stack->size)
	{
		if (stack->head == NULL)
			printf("stack is empty\n");
		else if (pos == 0)
			delete_first(stack);
		else if (pos == stack->size)
			delete_last(stack);
		else
		{
			pos--;
			while (--pos)
				cur = cur->next;
		}
		node = cur;
		cur->prev->next = node->next;
		cur->next->prev = node->prev;
		free(node);
		stack->size--;
	}
	else
		printf("delete error\n");
}