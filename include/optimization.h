/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:47:19 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/12 13:47:24 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMIZATION_H
# define OPTIMIZATION_H

# include "../lib/libft/include/libft.h"
# include "stack.h"

int		search_optimization(t_stack **instructions);
void	swap_if_near(t_push_swap *push_swap);

#endif
