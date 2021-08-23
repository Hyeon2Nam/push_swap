/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:16:11 by hyenam            #+#    #+#             */
/*   Updated: 2021/08/23 14:44:10 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *args[])
{
	char **temp;
	t_stack *stack;

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
	check_duplicate(stack);
	// sort(stack);
	reset_stack(stack);
	free(stack);
}

void error_handler(void)
{
	printf("Error\n");
	exit(1);
}
