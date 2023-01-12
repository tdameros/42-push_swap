/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:46:06 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/12 13:46:07 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include "stack.h"

int		push_instruction(t_push_swap *push_swap, char stack);
int		reverse_push_instruction(t_push_swap *push_swap, char stack);
int		swap_instruction(t_push_swap *push_swap, char stack);
int		multiple_rotate_instruction(t_push_swap *push_swap, char stack,
			int quantity);
int		multiple_reverse_rotate_instruction(t_push_swap *push_swap, char stack,
			int quantity);

#endif
