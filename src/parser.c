/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:19:23 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/12 16:52:11 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "stack.h"
#include "utils.h"
#include "sort.h"

static int	parse_param(char *param, t_stack **stack);
static int	add_sorted_index_in_stack(t_stack *stack, int size);
static int	*convert_stack_in_sorted_array(t_stack *stack, int size);
static int	get_index_in_array(int *array, int size, int value);

/**
 * Parse string array and return allocated stack with sorted index.
 * Exit with the FAILURE code if the string array does not contain only numbers,
 * contains duplicates number, int overflow or if an error is encountered.
 * @return allocated stack with sorted index
 */
t_stack	*create_stack_with_params(char **params, int len)
{
	t_stack	*stack;
	int		index;
	int		size;

	index = 0;
	stack = NULL;
	while (index < len)
	{
		if (ft_strlen(params[index]) == 0
			|| parse_param(params[index], &stack) < 0)
			free_stack_exit(&stack, EXIT_FAILURE);
		index++;
	}
	size = size_stack(stack);
	if (size == 0)
		return (stack);
	if (add_sorted_index_in_stack(stack, size) < 0)
		free_stack_exit(&stack, EXIT_FAILURE);
	reverse_stack(&stack);
	return (stack);
}

/**
 * Parse string in numbers and push them on the stack.
 * @return negative value if string does not contain only numbers,
 * int overflow or if an error is encountered
 */
static int	parse_param(char *param, t_stack **stack)
{
	char	**split_param;
	int		index;
	int		conversion;

	split_param = ft_split(param, ' ');
	index = 0;
	if (split_param == NULL)
		return (-1);
	while (split_param[index] != NULL)
	{
		conversion = ft_atoi(split_param[index]);
		if (!ft_is_number(split_param[index]) || errno == -1)
		{
			ft_free_split(split_param);
			return (-1);
		}
		if (add_stack(stack, create_node_stack(conversion, 0)) < 0)
		{
			ft_free_split(split_param);
			return (-1);
		}
		index++;
	}
	ft_free_split(split_param);
	return (0);
}

/**
 * Add sorted index in a stack using merge sort and binary search.
 * @return negative value if an error is encountered
 */
static int	add_sorted_index_in_stack(t_stack *stack, int size)
{
	int	*sorted_array;
	int	index;

	sorted_array = convert_stack_in_sorted_array(stack, size);
	if (sorted_array == NULL)
		return (-1);
	index = 1;
	while (index < size)
	{
		if (!(sorted_array[index - 1] < sorted_array[index]))
		{
			free(sorted_array);
			return (-1);
		}
		index++;
	}
	while (stack != NULL)
	{
		stack->index = get_index_in_array(sorted_array, size, stack->value) + 1;
		stack = stack->next;
	}
	free(sorted_array);
	return (1);
}

/**
 * Convert stack in a sorted array allocated using merge sort.
 * @return sorted array allocated or NULL if an error is encountered
 */
static int	*convert_stack_in_sorted_array(t_stack *stack, int size)
{
	int	*array;
	int	index;

	array = malloc(sizeof(*array) * size);
	index = 0;
	if (array == NULL)
		return (NULL);
	while (stack != NULL)
	{
		array[index] = stack->value;
		index++;
		stack = stack->next;
	}
	merge_sort(array, 0, size - 1);
	return (array);
}

/**
 * Search index of a value in a sorted array (binary search).
 * @param array sorted
 * @param size of the array
 * @param value
 * @return index of the value in the array or
 * negative value if index is not found
 */
static int	get_index_in_array(int *array, int size, int value)
{
	int	left_index;
	int	right_index;
	int	middle;

	left_index = 0;
	right_index = size - 1;
	while (left_index <= right_index)
	{
		middle = (left_index + right_index) / 2;
		if (array[middle] == value)
			return (middle);
		if (array[middle] > value)
			right_index = middle - 1;
		else
			left_index = middle + 1;
	}
	return (-1);
}
