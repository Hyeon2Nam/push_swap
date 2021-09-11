/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:23:22 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/11 18:49:33 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	ft_putstr_fd("pa\n");
	temp = b->head;
	if (temp == NULL)
		return ;
	add_first(a, temp->data);
	delete_first(b);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	ft_putstr_fd("pb\n");
	temp = a->head;
	if (temp == NULL)
		return ;
	add_first(b, temp->data);
	delete_first(a);
}
