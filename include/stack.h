/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:48:40 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/12 13:48:41 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../lib/libft/include/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct t_push_swap
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	t_stack	**instructions;
}	t_push_swap;

# define PB 1
# define PA 2
# define SA 3
# define SB 4
# define SS 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

# define ASC 0
# define DESC 1

# define STACK_A 1
# define STACK_B 0

int		add_stack(t_stack **stack, t_stack *node);
t_stack	*create_node_stack(int value, int index);

int		push_stack(t_stack **dst, t_stack **src);
int		pop_stack(t_stack **stack);
int		swap_stack(t_stack **stack);
int		rotate_stack(t_stack **stack);
int		reverse_rotate_stack(t_stack **stack);

int		size_stack(t_stack *stack);
int		is_sort_stack(t_stack *stack, int n, int order);
void	reverse_stack(t_stack **stack);

#endif
