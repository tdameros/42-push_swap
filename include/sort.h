/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:59:00 by tdameros          #+#    #+#             */
/*   Updated: 2023/01/09 16:59:00 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "stack.h"

int		push_swap_sort(t_push_swap *push_swap, int size);
void	quicksort(t_push_swap *push_swap, char current_stack, int n);
int		merge_sort(int *tab, int index_left, int index_right);

#endif
