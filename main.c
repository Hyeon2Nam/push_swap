/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:16:11 by hyenam            #+#    #+#             */
/*   Updated: 2021/06/24 16:19:57 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void arr_print(int *arr, int argc)
{
	for (int i = 0; i < argc; i++)
		printf("a[%d]:%d\n", i, arr[i]);
}

int main(int argc, char *argv[])
{
	int *a;
	int *b;
	int i;
	int j;

	a = (int *)malloc(sizeof(int) * argc - 1);
	b = (int *)malloc(sizeof(int) * argc - 1);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				print_error();
			a[argc - i - 1] = ft_atoi(argv[i]);
		}
	}
	arr_print(a, argc - 1);
	free(a);
	free(b);
}

void	print_error(void)
{
	printf("Error\n");
	exit(1);
}
