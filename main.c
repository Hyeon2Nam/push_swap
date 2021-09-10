/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:16:11 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/10 15:26:49 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	sort(stack);
	printf("-----------\nresult\n");
	print_stack(stack);
	reset_stack(stack);
	free(stack);
	putchar(scanf("%d", &n));
}

void error_handler(char *str)
{
	printf("Error\n%s\n",str);
	exit(1);
}
