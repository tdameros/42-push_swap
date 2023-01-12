/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomy <tomy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:06:00 by tomy              #+#    #+#             */
/*   Updated: 2023/01/09 12:06:00 by tomy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

int	push_stack(t_stack **dst, t_stack **src)
{
	t_stack	*temp_node;

	if (src == NULL || dst == NULL || *src == NULL)
		return (-1);
	temp_node = *src;
	*src = (*src)->next;
	temp_node->next = *dst;
	*dst = temp_node;
	return (0);
}

int	swap_stack(t_stack **stack)
{
	t_stack	*temp_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (-1);
	temp_node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp_node->next = *stack;
	*stack = temp_node;
	return (0);
}

int	rotate_stack(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*temp_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (-1);
	first_node = *stack;
	temp_node = first_node->next;
	while (temp_node->next != NULL)
		temp_node = temp_node->next;
	*stack = first_node->next;
	first_node->next = NULL;
	temp_node->next = first_node;
	return (0);
}

int	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*temp_node;
	t_stack	*before_last_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (-1);
	temp_node = *stack;
	while (temp_node->next->next != NULL)
		temp_node = temp_node->next;
	before_last_node = temp_node;
	temp_node = before_last_node->next;
	temp_node->next = *stack;
	*stack = temp_node;
	before_last_node->next = NULL;
	return (0);
}

void	reverse_stack(t_stack **stack)
{
	t_stack	*previous_node;
	t_stack	*current_node;
	t_stack	*next_node;

	previous_node = NULL;
	current_node = *stack;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		current_node->next = previous_node;
		previous_node = current_node;
		current_node = next_node;
	}
	*stack = previous_node;
}
