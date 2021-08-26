/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:22:31 by hyenam            #+#    #+#             */
/*   Updated: 2021/08/26 14:58:18 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_node
{
    struct s_node *prev;
    struct s_node *next;
    int data;
} t_node;

typedef struct s_stack
{
    t_node *head;
    t_node *tail;
    int size;
} t_stack;

typedef struct s_pivot
{
    int big;
    int small;
}   t_pivot;


void error_handler(void);
void ft_free(char **arr);

void add_first(t_stack *stack, int data);
void add_last(t_stack *stack, int data);
void add_pos(t_stack *stack, int pos, int data);
void delete_first(t_stack *stack);
void delete_last(t_stack *stack);
void delete_pos(t_stack *stack, int pos);

t_stack *init_stack(void);
void reset_stack(t_stack *stack);
void replace_data(t_stack *stack, int pos, int data);
int search_pos_data(t_stack *stack, int pos);
void print_stack(t_stack *stack);

void check_duplicate(t_stack *stack);
void quick_sort(int *arr, int left, int right);
void swap(int *arr, int a, int b);
void duplicate(int *arr, int size);
int ready_made(int *arr, t_stack *stack);
// t_pivot *set_pivot(int *arr, t_stack *stack);

void sort(t_stack *a);
void a_to_b(t_stack *a, t_stack *b, int call);
void b_to_a(t_stack *a, t_stack *b, int call);

void sa(t_stack *stack);
void sb(t_stack *stack);
void ss(t_stack *a, t_stack *b);

void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);

void ra(t_stack *stack);
void rb(t_stack *stack);
void rr(t_stack *a, t_stack *b);

void rra(t_stack *stack);
void rrb(t_stack *stack);
void rrr(t_stack *a, t_stack *b);

#endif
