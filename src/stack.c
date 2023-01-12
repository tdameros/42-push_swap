/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:15:13 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/09 15:15:14 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

t_stack	*create_node_stack(int value, int index)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	new_node->index = index;
	new_node->value = value;
	return (new_node);
}

int	add_stack(t_stack **stack, t_stack *node)
{
	if (stack == NULL || node == NULL)
		return (-1);
	node->next = *stack;
	*stack = node;
	return (1);
}

int	pop_stack(t_stack **stack)
{
	t_stack	*temp_node;

	if (stack == NULL)
		return (-1);
	temp_node = *stack;
	*stack = (*stack)->next;
	free(temp_node);
	return (0);
}

int	size_stack(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	is_sort_stack(t_stack *stack, int n, int order)
{
	int	index;
	int	current_index;

	if (n == 1)
		return (1);
	index = 1;
	current_index = stack->index;
	if (order != DESC && order != ASC)
		return (0);
	while (index < n)
	{
		stack = stack->next;
		if (stack->index < current_index && order == ASC)
			return (0);
		if (stack->index > current_index && order == DESC)
			return (0);
		current_index = stack->index;
		index++;
	}
	return (1);
}
