/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:33:00 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/10 11:33:00 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"

static int	print_instruction(t_stack *instruction);

void	print_instructions(t_stack **instructions)
{
	t_stack	*instruction;

	instruction = *instructions;
	while (instruction != NULL)
	{
		if (print_instruction(instruction) < 0)
			free_stack_exit(instructions, EXIT_FAILURE);
		instruction = instruction->next;
	}
}

static int	print_instruction(t_stack *instruction)
{
	if (instruction->value == PA)
		return (ft_printf("pa\n"));
	else if (instruction->value == PB)
		return (ft_printf("pb\n"));
	else if (instruction->value == SA)
		return (ft_printf("sa\n"));
	else if (instruction->value == SB)
		return (ft_printf("sb\n"));
	else if (instruction->value == SS)
		return (ft_printf("ss\n"));
	else if (instruction->value == RA)
		return (ft_printf("ra\n"));
	else if (instruction->value == RB)
		return (ft_printf("rb\n"));
	else if (instruction->value == RR)
		return (ft_printf("rr\n"));
	else if (instruction->value == RRB)
		return (ft_printf("rrb\n"));
	else if (instruction->value == RRA)
		return (ft_printf("rra\n"));
	else if (instruction->value == RRR)
		return (ft_printf("rrr\n"));
	return (0);
}
