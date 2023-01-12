/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:15:45 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/09 15:15:46 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "stack.h"
#include "utils.h"

int	push_instruction(t_push_swap *push_swap, char stack)
{
	t_stack	*instruction_node;

	instruction_node = NULL;
	if (stack == STACK_A
		&& push_stack(push_swap->stack_a, push_swap->stack_b) >= 0)
		instruction_node = create_node_stack(PA, 0);
	else if (stack == STACK_B
		&& push_stack(push_swap->stack_b, push_swap->stack_a) >= 0)
		instruction_node = create_node_stack(PB, 0);
	else
		return (0);
	if (add_stack(push_swap->instructions, instruction_node) < 0)
		exit_push_swap(push_swap, EXIT_FAILURE);
	return (1);
}

int	reverse_push_instruction(t_push_swap *push_swap, char stack)
{
	t_stack	*instruction_node;

	instruction_node = NULL;
	if (stack == STACK_A
		&& push_stack(push_swap->stack_b, push_swap->stack_a) >= 0)
		instruction_node = create_node_stack(PB, 0);
	else if (stack == STACK_B
		&& push_stack(push_swap->stack_a, push_swap->stack_b) >= 0)
		instruction_node = create_node_stack(PA, 0);
	else
		return (0);
	if (add_stack(push_swap->instructions, instruction_node) < 0)
		exit_push_swap(push_swap, EXIT_FAILURE);
	return (1);
}

int	swap_instruction(t_push_swap *push_swap, char stack)
{
	t_stack	*instruction_node;

	instruction_node = NULL;
	if (stack == STACK_A && swap_stack(push_swap->stack_a) >= 0)
		instruction_node = create_node_stack(SA, 0);
	else if (stack == STACK_B && swap_stack(push_swap->stack_b) >= 0)
		instruction_node = create_node_stack(SB, 0);
	else
		return (0);
	if (add_stack(push_swap->instructions, instruction_node) < 0)
		exit_push_swap(push_swap, EXIT_FAILURE);
	return (1);
}

int	multiple_rotate_instruction(t_push_swap *push_swap,
								char stack, int quantity)
{
	t_stack	*instruction_node;
	int		count;

	instruction_node = NULL;
	count = 0;
	while (count < quantity)
	{
		if (stack == STACK_A && rotate_stack(push_swap->stack_a) >= 0)
			instruction_node = create_node_stack(RA, 0);
		else if (stack == STACK_B && rotate_stack(push_swap->stack_b) >= 0)
			instruction_node = create_node_stack(RB, 0);
		else
			return (0);
		if (add_stack(push_swap->instructions, instruction_node) < 0)
			exit_push_swap(push_swap, EXIT_FAILURE);
		count++;
	}
	return (1);
}

int	multiple_reverse_rotate_instruction(t_push_swap *push_swap,
										char stack, int quantity)
{
	t_stack	*instruction_node;
	int		count;

	instruction_node = NULL;
	count = 0;
	while (count < quantity)
	{
		if (stack == STACK_A && reverse_rotate_stack(push_swap->stack_a) >= 0)
			instruction_node = create_node_stack(RRA, 0);
		else if (stack == STACK_B
			&& reverse_rotate_stack(push_swap->stack_b) >= 0)
			instruction_node = create_node_stack(RRB, 0);
		else
			return (0);
		if (add_stack(push_swap->instructions, instruction_node) < 0)
			exit_push_swap(push_swap, EXIT_FAILURE);
		count++;
	}
	return (1);
}
