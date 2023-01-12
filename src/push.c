/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:18:11 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/09 15:18:12 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "instruction.h"
#include "optimization.h"

static int	count_small(t_stack *stack, int median, int n);
static int	count_greater(t_stack *stack, int median, int n);

void	push_all_small(t_push_swap *push_swap, int median, int n, char stack)
{
	t_stack	**stack_src;
	int		count;
	int		count_max;
	int		rotate;

	if (stack == STACK_A)
		stack_src = push_swap->stack_a;
	else
		stack_src = push_swap->stack_b;
	count_max = count_small(*stack_src, median, n);
	count = 0;
	rotate = 0;
	while (count < count_max)
	{
		swap_if_near(push_swap);
		if ((*stack_src)->index < median)
			count += reverse_push_instruction(push_swap, stack);
		else
			rotate += multiple_rotate_instruction(push_swap, stack, 1);
	}
	count = size_stack(*stack_src);
	if (count - rotate < rotate)
		multiple_rotate_instruction(push_swap, stack, count - rotate);
	else
		multiple_reverse_rotate_instruction(push_swap, stack, rotate);
}

static int	count_small(t_stack *stack, int median, int n)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (index < n)
	{
		if (stack->index < median)
			count++;
		stack = stack->next;
		index++;
	}
	return (count);
}

void	push_all_greater(t_push_swap *push_swap, int median, int n, char stack)
{
	t_stack	**stack_src;
	int		count;
	int		count_max;
	int		rotate;

	if (stack == STACK_A)
		stack_src = push_swap->stack_a;
	else
		stack_src = push_swap->stack_b;
	count_max = count_greater(*stack_src, median, n);
	count = 0;
	rotate = 0;
	while (count < count_max)
	{
		swap_if_near(push_swap);
		if ((*stack_src)->index >= median)
			count += reverse_push_instruction(push_swap, stack);
		else
			rotate += multiple_rotate_instruction(push_swap, stack, 1);
	}
	count = size_stack(*stack_src);
	if (count - rotate < rotate)
		multiple_rotate_instruction(push_swap, stack, count - rotate);
	else
		multiple_reverse_rotate_instruction(push_swap, stack, rotate);
}

static int	count_greater(t_stack *stack, int median, int n)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (index < n)
	{
		if (stack->index >= median)
			count++;
		stack = stack->next;
		index++;
	}
	return (count);
}
