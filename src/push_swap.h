/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:20:33 by kclaudan          #+#    #+#             */
/*   Updated: 2024/12/29 16:31:40 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

t_stack		*free_stack(t_stack *node, t_stack *tmp);
t_stack		*create_node_with_int(int nb);
t_stack		*init_stack(char **values);
void	swap_top(t_stack **top_a);
void	ss(t_stack **top_a, t_stack **top_b);
void	pa(t_stack **top_a, t_stack **top_b);
void	pb(t_stack **top_a, t_stack **top_b);
void	rab(t_stack **top);
void	rr(t_stack **top_a, t_stack **top_b);
void	rrab(t_stack **top);
void	rrr(t_stack **top_a, t_stack **top_b);
int		check_str_content(char *str);
int		check_are_nums(char **inputs);
int		check_num_duplicate(char **inputs);
int		check_inputs(char **inputs);

#endif