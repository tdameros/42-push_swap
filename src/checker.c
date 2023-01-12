/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:12:00 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/12 14:12:00 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "stack.h"
#include "utils.h"

static int	get_all_instructions(t_stack **instructions);
static int	is_valid_instruction(char *instruction);
static void	execute_instructions(t_stack *instructions,
				t_stack **stack_a, t_stack **stack_b);
static int	execute_instruction(char instruction,
				t_stack **stack_a, t_stack **stack_b);

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*instructions;

	if (argc <= 1)
		return (0);
	stack_a = create_stack_with_params(++argv, argc - 1);
	stack_b = NULL;
	instructions = NULL;
	if (get_all_instructions(&instructions) < 0)
		return (free_stack_exit(&instructions, EXIT_FAILURE));
	execute_instructions(instructions, &stack_a, &stack_b);
	if (size_stack(stack_b) == 0
		&& is_sort_stack(stack_a, size_stack(stack_a), ASC))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&instructions);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

static int	get_all_instructions(t_stack **instructions)
{
	char	*instruction;
	int		validity;

	instruction = get_next_line(0);
	while (instruction != NULL && ft_strcmp(instruction, "") != 0)
	{
		validity = is_valid_instruction(instruction);
		if (validity == 0)
			return (-1);
		if (add_stack(instructions, create_node_stack(validity, 0)) < 0)
			return (-1);
		free(instruction);
		instruction = get_next_line(0);
	}
	free(instruction);
	reverse_stack(instructions);
	return (1);
}

static int	is_valid_instruction(char *instruction)
{
	if (ft_strcmp(instruction, "pa\n") == 0)
		return (PA);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		return (PB);
	else if (ft_strcmp(instruction, "sa\n") == 0)
		return (SA);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		return (SB);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		return (SS);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		return (RA);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		return (RB);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		return (RR);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		return (RRA);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		return (RRB);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		return (RRR);
	return (0);
}

static void	execute_instructions(t_stack *instructions,
									t_stack **stack_a, t_stack **stack_b)
{
	while (instructions != NULL)
	{
		execute_instruction(instructions->value, stack_a, stack_b);
		instructions = instructions->next;
	}
}

static int	execute_instruction(char instruction,
								t_stack **stack_a, t_stack **stack_b)
{
	if (instruction == PB)
		return (push_stack(stack_b, stack_a));
	else if (instruction == PA)
		return (push_stack(stack_a, stack_b));
	else if (instruction == SA)
		return (swap_stack(stack_a));
	else if (instruction == SB)
		return (swap_stack(stack_b));
	else if (instruction == SS)
		return (swap_stack(stack_a), swap_stack(stack_b));
	else if (instruction == RA)
		return (rotate_stack(stack_a));
	else if (instruction == RB)
		return (rotate_stack(stack_b));
	else if (instruction == RR)
		return (rotate_stack(stack_b), rotate_stack(stack_a));
	else if (instruction == RRA)
		return (reverse_rotate_stack(stack_a));
	else if (instruction == RRB)
		return (reverse_rotate_stack(stack_b));
	else if (instruction == RRR)
		return (reverse_rotate_stack(stack_b), reverse_rotate_stack(stack_a));
	return (0);
}
