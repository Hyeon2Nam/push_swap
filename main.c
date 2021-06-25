/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:16:11 by hyenam            #+#    #+#             */
/*   Updated: 2021/06/25 15:51:56 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void arr_print(t_stack *stack, int argc)
{
	for (int i = 0; i < argc; i++)
		printf(" %d %d \n", stack->a[i], stack->b[i]);
	printf("-----\n");
	printf(" a b \n");
}

int main(int argc, char *argv[])
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack) * 1);
	init_a(argc, argv, stack);
}

void	print_error(void)
{
	printf("Error\n");
	exit(1);
}

//gcc -Wall -Werror -Wextra *.c -Llibft -lft