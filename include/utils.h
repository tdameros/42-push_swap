/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:24:00 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/10 10:24:00 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "stack.h"

void	exit_push_swap(t_push_swap *push_swap, int exit_code);
int		free_stack(t_stack **stack);
int		free_stack_exit(t_stack **stack, int exit_code);
void	raise_error(void);

#endif
