/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:09:07 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/07 23:09:11 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push.h"
#include "instruction.h"
#include "sort.h"
#include "optimization.h"
#include "utils.h"

static int	get_median(t_stack *stack, int n);
static void	add_marker(t_push_swap *push_swap);
static void	push_until_marker(t_push_swap *push_swap);

/**
 * Quick sort n elements in a stack using sorted index.
 * Exit with the FAILURE code if an error is encountered.
 * All used instructions are stored in the instructions stack.
 * @param push_swap
 * @param current_stack
 * @param n
 */
void	quicksort(t_push_swap *push_swap, char current_stack, int n)
{
	int	median;

	swap_if_near(push_swap);
	if (current_stack == STACK_A && is_sort_stack(*push_swap->stack_a, n, ASC))
		return ;
	if (current_stack == STACK_B && is_sort_stack(*push_swap->stack_b, n, DESC))
		return ;
	if (current_stack == STACK_A)
	{
		median = get_median(*push_swap->stack_a, n);
		add_marker(push_swap);
		push_all_small(push_swap, median, n, STACK_A);
		quicksort(push_swap, STACK_A, n / 2 + (n % 2));
		quicksort(push_swap, STACK_B, n / 2);
		push_until_marker(push_swap);
	}
	else
	{
		median = get_median(*push_swap->stack_b, n);
		push_all_greater(push_swap, median, n, STACK_B);
		quicksort(push_swap, STACK_A, n / 2 + (n % 2));
		quicksort(push_swap, STACK_B, n / 2);
	}
}

static int	get_median(t_stack *stack, int n)
{
	int	median;
	int	index;

	median = 0;
	index = 0;
	while (stack != NULL && index < n)
	{
		median += stack->index;
		index++;
		stack = stack->next;
	}
	median /= n;
	if (n % 2 == 0)
		return (median + 1);
	return (median);
}

static void	add_marker(t_push_swap *push_swap)
{
	if (add_stack(push_swap->stack_b, create_node_stack(0, -10)) < 0)
		exit_push_swap(push_swap, EXIT_FAILURE);
}

static void	push_until_marker(t_push_swap *push_swap)
{
	while ((*push_swap->stack_b)->index != -10)
		push_instruction(push_swap, STACK_A);
	pop_stack(push_swap->stack_b);
}
