/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:54:00 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/09 16:54:00 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "sort.h"
#include "instruction.h"
#include "optimization.h"
#include "sort.h"

static void	thirds_sort(t_push_swap *push_swap, int size);

/**
 * Sorting a stack (A) with a temporary stack (B) and imposed instructions.
 * The stack A must contain sorted index.
 * sa or sb: Swap the first 2 elements at the top of stack
 * ss: sa and sb at the same time
 * pa or pb: Take the first element at the top of B and put it at the top of A
 * ra or rb: Shift up all elements of stack a by 1
 * rr: ra and rb at the same time
 * rra or rrb: Shift down all elements of stack a by 1
 * rrr: rra and rrb at the same time
 * Exit with the FAILURE code if an error is encountered.
 * All used instructions are stored in the instructions stack.
 * @param size of the stack A
 * @return 0
 */
int	push_swap_sort(t_push_swap *push_swap, int size)
{
	if (is_sort_stack(*push_swap->stack_a, size, ASC))
		return (0);
	if (size > 5)
	{
		thirds_sort(push_swap, size);
		quicksort(push_swap, STACK_A, (size / 3) + (size % 3));
		quicksort(push_swap, STACK_B, (size / 3));
		while (size_stack(*push_swap->stack_b) > size / 3)
			push_instruction(push_swap, STACK_A);
		quicksort(push_swap, STACK_B, (size / 3));
		while (size_stack(*push_swap->stack_b) > 0)
			push_instruction(push_swap, STACK_A);
	}
	else if (size == 3 && (*push_swap->stack_a)->index == 3
		&& (*push_swap->stack_a)->next->index == 1)
		multiple_rotate_instruction(push_swap, STACK_A, 1);
	else
		quicksort(push_swap, STACK_A, size);
	reverse_stack(push_swap->instructions);
	return (0);
}

/**
 * Separate two smaller thirds in a temporary stack (B)
 * Exit with the FAILURE code if an error is encountered.
 * All used instructions are stored in the instructions stack.
 * @param push_swap
 * @param size of the stack A
 */
static void	thirds_sort(t_push_swap *push_swap, int size)
{
	int	two_thirds;
	int	count;

	two_thirds = (size / 3) * 2;
	count = 0;
	while (count < two_thirds)
	{
		swap_if_near(push_swap);
		if ((*push_swap->stack_a)->index <= two_thirds)
		{
			push_instruction(push_swap, STACK_B);
			count++;
			if ((*push_swap->stack_b)->index <= (size / 3))
				multiple_rotate_instruction(push_swap, STACK_B, 1);
		}
		else
			multiple_rotate_instruction(push_swap, STACK_A, 1);
	}
}
