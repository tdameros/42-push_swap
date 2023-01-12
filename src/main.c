/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:33:48 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/09 23:33:49 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "optimization.h"
#include "sort.h"
#include "utils.h"
#include "print.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*instructions;
	t_push_swap	push_swap;
	int			size;

	if (argc <= 1)
		return (0);
	stack_a = create_stack_with_params(++argv, argc - 1);
	stack_b = NULL;
	instructions = NULL;
	size = size_stack(stack_a);
	push_swap.stack_a = &stack_a;
	push_swap.stack_b = &stack_b;
	push_swap.instructions = &instructions;
	push_swap_sort(&push_swap, size);
	free_stack(push_swap.stack_a);
	free_stack(push_swap.stack_b);
	search_optimization(push_swap.instructions);
	print_instructions(push_swap.instructions);
	free_stack(push_swap.instructions);
	return (0);
}
