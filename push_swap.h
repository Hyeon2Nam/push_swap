/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:22:31 by hyenam            #+#    #+#             */
/*   Updated: 2021/06/25 21:32:47 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h> 
# include "libft/libft.h"

typedef struct s_stack
{
    int *a;
    int *b;
} t_stack;


void	print_error(void);
void arr_print(t_stack *stack, int argc);
void init_a(int count, char *nums[], t_stack *stack);

void sa(t_stack *stack);
void sb(t_stack *stack);
void ss(t_stack *stack);

void pa(t_stack *stack);
void pb(t_stack *stack);

void ra(t_stack *stack);
void rb(t_stack *stack);
void rr(t_stack *stack);

void rra(t_stack *stack);
void rrb(t_stack *stack);
void rrr(t_stack *stack);


#endif
