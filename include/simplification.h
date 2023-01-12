/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplification.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomy <tomy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:04:00 by tomy              #+#    #+#             */
/*   Updated: 2023/01/09 22:04:00 by tomy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLIFICATION_H
# define SIMPLIFICATION_H

int	simplify_two_instructions(t_stack *node, t_stack **instructions);
int	simplify_three_instructions(t_stack *node, t_stack **instructions);
int	simplify_four_instructions(t_stack *node, t_stack **instructions);

#endif