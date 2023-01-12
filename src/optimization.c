/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:34:09 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/09 23:34:09 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "optimization.h"
#include "simplification.h"
#include "instruction.h"

static int	search_simplification(t_stack **instructions);
static void	free_and_next(t_stack **instructions, int quantity);

void	swap_if_near(t_push_swap *push_swap)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = *push_swap->stack_a;
	stack_b = *push_swap->stack_b;
	if (size_stack(stack_a) >= 2)
	{
		if (stack_a->index - stack_a->next->index == 1)
			swap_instruction(push_swap, STACK_A);
	}
	if (size_stack(stack_b) >= 2)
	{
		if (stack_b->index - stack_b->next->index == -1)
			swap_instruction(push_swap, STACK_B);
	}
}

int	search_optimization(t_stack **instructions)
{
	int	count;

	count = 0;
	while (search_simplification(instructions))
		count++;
	return (count > 0);
}

static int	search_simplification(t_stack **instructions)
{
	t_stack	*node;
	t_stack	*temp_node;
	int		size;

	node = *instructions;
	size = size_stack(node);
	*instructions = NULL;
	while (node != NULL)
	{
		if (simplify_two_instructions(node, instructions))
			free_and_next(&node, 2);
		else if (simplify_three_instructions(node, instructions))
			free_and_next(&node, 3);
		else if (simplify_four_instructions(node, instructions))
			free_and_next(&node, 4);
		else
		{
			temp_node = node;
			node = node->next;
			add_stack(instructions, temp_node);
		}
	}
	reverse_stack(instructions);
	return (size_stack(*instructions) < size);
}

static void	free_and_next(t_stack **instructions, int quantity)
{
	t_stack	*temp_node;
	int		count;

	count = 0;
	while (count < quantity)
	{
		temp_node = *instructions;
		*instructions = temp_node->next;
		free(temp_node);
		count++;
	}
}
