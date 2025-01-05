/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:20:33 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/04 12:06:33 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

t_stack		*free_stack(t_stack *node, t_stack *tmp);
t_stack		*create_node_with_int(int nb);
t_stack		*init_stack(char **values);
t_stack		*ft_find_max(t_stack *stack);
t_stack		*ft_find_min(t_stack *stack);
int		swap_top(t_stack **top_a, char c);
int		ss(t_stack **top_a, t_stack **top_b);
int		pa(t_stack **top_a, t_stack **top_b);
int		pb(t_stack **top_a, t_stack **top_b);
int		rab(t_stack **top, char c);
int		rr(t_stack **top_a, t_stack **top_b);
int		rrab(t_stack **top, char c);
int		rrr(t_stack **top_a, t_stack **top_b);
int		check_str_content(char *str);
int		check_are_nums(char **inputs);
int		check_num_duplicate(char **inputs);
int		is_sorted(t_stack *stack_a);
int		check_inputs(char **inputs);
int		ft_abs(int num);
int		ft_lst_find(t_stack *stack, t_stack *node_to_find);
int		sort_stack_of_three(t_stack **stack_a);

#endif