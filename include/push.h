/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:48:25 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/12 13:48:25 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "stack.h"

void	push_all_small(t_push_swap *push_swap, int median, int n, char stack);
void	push_all_greater(t_push_swap *push_swap, int median, int n, char stack);

#endif
