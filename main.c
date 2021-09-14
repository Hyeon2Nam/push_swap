/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:16:11 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/14 13:50:29 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(void)
{
	ft_putstr_fd("Error\n");
	// int n;
	// putchar(scanf("%d",&n));
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

void find_error(t_stack *stack)
{
	t_node	*cur;
	int		*arr;
	int		i;

	i = -1;
	cur = stack->head;
	arr = (int *)malloc(sizeof(int) * (stack->size + 1));
	if (!arr)
		return ;
	while (++i <= stack->size)
	{
		arr[i] = cur->data;
		cur = cur->next;
	}
	quick_sort(arr, 0, stack->size - 1);
	cur = stack->head;
	printf("adsf");
	for (int j = 0; j < stack->size; j++)
	{
		if (arr[j] != cur->data)
			printf("%d번째 데이터 오류 quick:%d stack:%d\n", j, arr[j], cur->data);
		cur = cur->next;
	}
	
	free(arr);
}

int	main(int argc, char *args[])
{
	t_stack	*stack;

	if (argc == 1)
		exit(0);
	stack = init_stack();
	input_data(stack, argc, args);
	sort_case(stack);
	// print_stack(stack);
	// find_error(stack);
	reset_stack(stack);
	free(stack);
	// int n;
	// putchar(scanf("%d",&n));
}
