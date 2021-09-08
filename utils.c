/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:40:00 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/08 18:05:33 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_top(t_stack *stack, int pos)
{
	int i;

	i = search_pos(stack, pos);
	if (i > stack->size / 2)
	{
		i = stack->size - i + 1;
		printf("i:%d\n",i);
		while (--i)
			rra(stack);
	}
	else
	{
		printf("i:%d\n",i);
		while (i)
		{
			ra(stack);
			i--;
		}
	}
}

void ft_free(char **arr)
{
	int len;
	int i;

	len = 0;
	while (arr[len])
		len++;
	i = 0;
	while (i < len)
		free(arr[i++]);
	free(arr);
}