/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:43:35 by hyenam            #+#    #+#             */
/*   Updated: 2021/06/25 15:54:25 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_a(int count, char *nums[], t_stack *stack)
{
	int i;
	int j;

	stack->a = (int *)malloc(sizeof(int) * count - 1);
	stack->b = (int *)malloc(sizeof(int) * count - 1);
	i = 0;
	while (++i < count)
	{
		j = -1;
		while (nums[i][++j])
		{
			if (!ft_isdigit(nums[i][j]))
				print_error();
			stack->a[i - 1] = ft_atoi(nums[i]);
		}
	}
	arr_print(stack, count - 1);
	free(stack->a);
	free(stack->b);
}

