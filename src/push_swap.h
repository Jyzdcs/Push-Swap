/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:20:33 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/07 00:01:23 by kclaudan         ###   ########.fr       */
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
t_stack		*find_closest_smaller(t_stack *node_a, t_stack *stack_b);
t_stack		*find_closest_bigger(t_stack *node_b, t_stack *stack_a);
t_stack		*find_cheapest(t_stack *stack_a, t_stack *stack_b);
int			bring_target_to_top(t_stack *target, t_stack **stack_b);
int			bring_cheap_to_top(t_stack *cheap, t_stack **s_b, t_stack **s_a);
int			push_back_stack_a(t_stack **stack_a, t_stack **stack_b);
int			sort_stack_a(t_stack **stack_a);
int			sort_small_stack(t_stack **stack_a, t_stack **stack_b);
int			opti_handler(int ops_a, int ops_b);
int			count_operations(int size_a, int i_a, t_stack *node, t_stack *s_b);
int			swap_top(t_stack **top_a, char c, int dis);
int			ss(t_stack **top_a, t_stack **top_b);
int			pa(t_stack **top_a, t_stack **top_b);
int			pb(t_stack **top_a, t_stack **top_b);
int			rab(t_stack **top, char c, int dis);
int			rr(t_stack **top_a, t_stack **top_b);
int			rrab(t_stack **top, char c, int dis);
int			rrr(t_stack **top_a, t_stack **top_b);
int			check_str_content(char *str);
int			check_are_nums(char **inputs);
int			check_num_duplicate(char **inputs);
int			is_sorted(t_stack *stack_a);
int			check_inputs(char **inputs);
int			ft_abs(int num);
int			ft_lst_find(t_stack *stack, t_stack *node_to_find);
int			sort_stack_of_three(t_stack **stack_a);

#endif