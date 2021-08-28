/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:16:11 by hyenam            #+#    #+#             */
/*   Updated: 2021/08/26 18:32:51 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main(int argc, char *args[])
int main()
{
	// char **temp;
	t_stack *stack;

	// if (argc == 1)
	// 	exit(0);
	stack = init_stack();
	// for (int i = 1; i < argc; i++)
	// {
	// 	temp = ft_split(args[i], ' ');
	// 	for (int j = 0; temp[j]; j++)
	// 		add_last(stack, ft_atoi(temp[j]));
	// 	ft_free(temp);
	// }
	add_last(stack, 3);
	add_last(stack, 1);
	add_last(stack, 5);
	add_last(stack, 9);
	add_last(stack, 6);
	add_last(stack, 8);
	add_last(stack, 10);
	add_last(stack, 4);
	add_last(stack, 7);
	add_last(stack, 2);
	if (ready_made(stack))
		exit(0);
	// check_duplicate(stack);
	sort(stack);
	reset_stack(stack);
	free(stack);
}

void error_handler(void)
{
	printf("Error\n");
	exit(1);
}
