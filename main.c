/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:16:11 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/11 16:46:13 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_handler(void)
{
	ft_putstr_fd("Error\n");
	exit(1);
}

int main(int argc, char *args[])
{
	char **temp;
	t_stack *stack;
	int n;

	if (argc == 1)
		exit(0);
	stack = init_stack();
	for (int i = 1; i < argc; i++)
	{
		temp = ft_split(args[i], ' ');
		for (int j = 0; temp[j]; j++)
			add_last(stack, ft_atoi(temp[j]));
		ft_free(temp);
	}

	check_args(stack);
	if (ready_made(stack))
		exit(0);
	if (stack->size == 2 || stack->size == 3 || stack->size == 5)
		exsort(stack, stack->size);
	else
		sort(stack);
	reset_stack(stack);
	free(stack);
	putchar(scanf("%d", &n));
}
