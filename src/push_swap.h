/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:20:33 by kclaudan          #+#    #+#             */
/*   Updated: 2024/12/19 16:59:57 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

t_list		*free_stack(t_list *node, t_list *tmp);
t_list		*create_node_with_int(int nb);
t_list		*init_stack(char **values);
void	swap_top(t_list **top_a);
void	ss(t_list **top_a, t_list **top_b);
void	pa(t_list **top_a, t_list **top_b);
void	pb(t_list **top_a, t_list **top_b);
void	rab(t_list **top);
void	rr(t_list **top_a, t_list **top_b);
void	rrab(t_list **top);
void	rrr(t_list **top_a, t_list **top_b);
int		check_str_content(char *str);
int		check_are_nums(char **inputs);
int		check_num_duplicate(char **inputs);
int		check_inputs(char **inputs);

#endif