/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:40:00 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/08 15:00:06 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_top(t_stack *stack, int pos)
{
	int i;

	i = search_pos(stack, pos) + 1;
	if (i > stack->size / 2)
	{
		i = stack->size - i + 1;
		while (--i)
			ra(stack);
	}
	else
		while (i)
		{
			rra(stack);
			i--;
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