/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:16:11 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/14 14:34:16 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(void)
{
	ft_putstr_fd("Error\n");
	exit(1);
}

void	sort_case(t_stack *stack)
{
	if (stack->size == 2 || stack->size == 3 || stack->size == 5)
		exsort(stack, stack->size);
	else
		sort(stack);
}

void	input_data(t_stack *stack, int argc, char *args[])
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		temp = ft_split(args[i], ' ');
		j = 0;
		while (temp[j])
		{
			add_last(stack, ft_atoi(temp[j]));
			j++;
		}
		ft_free(temp);
	}
	check_args(stack);
	if (ready_made(stack))
		exit(0);
}

int	main(int argc, char *args[])
{
	t_stack	*stack;

	if (argc == 1)
		exit(0);
	stack = init_stack();
	input_data(stack, argc, args);
	sort_case(stack);
	reset_stack(stack);
	free(stack);
}
