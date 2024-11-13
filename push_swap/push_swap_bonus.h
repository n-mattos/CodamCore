/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattos- <nmattos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:25:01 by nmattos-          #+#    #+#             */
/*   Updated: 2024/11/11 16:13:27 by nmattos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# define ERROR -1
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_stack
{
	int		*a;
	size_t	size_a;
	int		*b;
	size_t	size_b;
}	t_stack;

// checker.c

void	error_exit(void);

// memory.c

void	initialize_struct(t_stack **stack, int n_numbers);
void	free_stack(t_stack *stack);
void	free_double_array(char **array);

// setup.c

void	initialize_arrays(t_stack *stack, int n_numbers, int argc, char **argv);

// functions.c

int		get_word_count(char *s, char c);
bool	is_number(char *str);
int		peek(t_stack *stack, char c);
void	swap(int *arr, int i, int j);
bool	is_sorted(t_stack *stack);

// operations

void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

// get_next_line

char	*get_next_line(int fd);
char	*ft_strcpy(char *dst, char *src);
char	*ft_realloc(char **original, size_t size);
void	free_p(char **p);

#endif