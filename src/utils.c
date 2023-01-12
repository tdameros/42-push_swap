/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:26:45 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/10 11:27:00 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"
#include <unistd.h>

void	exit_push_swap(t_push_swap *push_swap, int exit_code)
{
	free_stack(push_swap->stack_a);
	free_stack(push_swap->stack_b);
	free_stack_exit(push_swap->instructions, exit_code);
}

int	free_stack(t_stack **stack)
{
	if (stack != NULL)
	{
		while (*stack != NULL)
			pop_stack(stack);
	}
	else
		return (-1);
	return (0);
}

int	free_stack_exit(t_stack **stack, int exit_code)
{
	free_stack(stack);
	if (exit_code == EXIT_FAILURE)
		raise_error();
	exit(exit_code);
}

void	raise_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
}
