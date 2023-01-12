/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplification.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:36:49 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/12 13:37:03 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"

static int	add_two_instructions(t_stack **instructions,
				int instruction1, int instruction2);
static int	add_three_instructions(t_stack **instructions, int instruction1,
				int instruction2, int instruction3);

int	simplify_two_instructions(t_stack *node, t_stack **instructions)
{
	int	return_code;

	return_code = 0;
	if (size_stack(node) < 2)
		return (return_code);
	if ((node->value == RA && node->next->value == RB)
		|| (node->value == RB && node->next->value == RA))
		return_code = add_stack(instructions, create_node_stack(RR, 0));
	else if ((node->value == RRA && node->next->value == RA)
		|| (node->value == RA && node->next->value == RRA))
		return (1);
	else if ((node->value == RRB && node->next->value == RB)
		|| (node->value == RB && node->next->value == RRB))
		return (1);
	else if ((node->value == PA && node->next->value == PB)
		|| (node->value == PB && node->next->value == PA))
		return (1);
	else if ((node->value == SB && node->next->value == SA)
		|| (node->value == SA && node->next->value == SB))
		return_code = add_stack(instructions, create_node_stack(SS, 0));
	if (return_code < 0)
		return (free_stack(&node), free_stack_exit(instructions, EXIT_FAILURE));
	return (return_code);
}

int	simplify_three_instructions(t_stack *node, t_stack **instructions)
{
	int	return_code;

	return_code = 0;
	if (size_stack(node) < 3)
		return (return_code);
	if (node->value == RA && node->next->value == PB
		&& node->next->next->value == RRA)
		return_code = add_two_instructions(instructions, SA, PB);
	else if (node->value == RB && node->next->value == PA
		&& node->next->next->value == RRB)
		return_code = add_two_instructions(instructions, SB, PA);
	else if (node->value == RA && node->next->value == PA
		&& node->next->next->value == RRA)
		return_code = add_two_instructions(instructions, PA, SA);
	else if (node->value == RB && node->next->value == PB
		&& node->next->next->value == RRB)
		return_code = add_two_instructions(instructions, PB, SB);
	else if (node->value == SA && node->next->value == RRB
		&& node->next->next->value == SB)
		return_code = add_two_instructions(instructions, RRB, SS);
	if (return_code < 0)
		return (free_stack(&node), free_stack_exit(instructions, EXIT_FAILURE));
	return (return_code);
}

static int	add_two_instructions(t_stack **instructions, int instruction1,
									int instruction2)
{
	if (add_stack(instructions, create_node_stack(instruction1, 0)) < 0)
		return (-1);
	if (add_stack(instructions, create_node_stack(instruction2, 0)) < 0)
		return (-1);
	return (1);
}

int	simplify_four_instructions(t_stack *node, t_stack **instructions)
{
	int	return_code;

	return_code = 0;
	if (size_stack(node) < 4)
		return (return_code);
	if (node->value == RA && node->next->value == PB
		&& node->next->next->value == SB
		&& node->next->next->next->value == RRA)
	{
		return_code = add_three_instructions(instructions, SA, PB, SB);
	}
	else if (node->value == RB && node->next->value == PA
		&& node->next->next->value == SA
		&& node->next->next->next->value == RRB)
	{
		return_code = add_three_instructions(instructions, SB, PA, SA);
	}
	if (return_code < 0)
		return (free_stack(&node), free_stack_exit(instructions, EXIT_FAILURE));
	return (return_code);
}

static int	add_three_instructions(t_stack **instructions, int instruction1,
									int instruction2, int instruction3)
{
	if (add_stack(instructions, create_node_stack(instruction1, 0)) < 0)
		return (-1);
	if (add_stack(instructions, create_node_stack(instruction2, 0)) < 0)
		return (-1);
	if (add_stack(instructions, create_node_stack(instruction3, 0)) < 0)
		return (-1);
	return (1);
}
