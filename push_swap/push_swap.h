/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:06:18 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/12 14:42:25 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# define SA 1
# define SB 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RRA 7
# define RRB 8

typedef struct s_stack
{
	int		*a;
	size_t	size_a;
	int		*b;
	size_t	size_b;
	int		*operations;
	size_t	curr_size_op;
	size_t	total_size_op;
}	t_stack;

// setup.c

void	initialize_arrays(t_stack *stack, int n_numbers, int argc, char **argv);

// normalize.c

void	normalize_array(t_stack *stack);

// quicksort.c

void	quicksort(int *arr, int left, int right);

// memory.c

void	initialize_struct(t_stack **stack, int n_numbers);
void	free_stack(t_stack *stack);
void	free_double_array(char **array);
void	error_exit(void);

// sort.c

void	my_sort(t_stack *stack, bool split);

// cheapest_operation.c

int		cheapest_operation_a(t_stack *stack);
int		cheapest_operation_b(t_stack *stack);

// sort_help.c

void	to_top(t_stack *stack, t_stack *s, int key, char c);
void	find_and_insert(t_stack *stack, t_stack *s, int key, char c);
int		closest_number(t_stack *stack, int key, char c);

// operations

void	add_operation(t_stack *stack, int operation, t_stack *s);
int		peek(t_stack *stack, char c);
void	pa(t_stack *stack, t_stack *s);
void	pb(t_stack *stack, t_stack *s);
void	sa(t_stack *stack, t_stack *s);
void	sb(t_stack *stack, t_stack *s);
void	ra(t_stack *stack, t_stack *s);
void	rb(t_stack *stack, t_stack *s);
void	rra(t_stack *stack, t_stack *s);
void	rrb(t_stack *stack, t_stack *s);

// functions

int		get_word_count(char *s, char c);
void	swap(int *arr, int i, int j);
int		*int_strdup(const int *s, size_t len);
bool	is_number(char *str);
int		*int_strlcpy(int *dst, int *src, size_t size);

#endif
