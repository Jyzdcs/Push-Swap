/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:44:39 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/06 22:44:39 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stack_a(t_stack **stack_a)
{
	int	operations;
	int	max_i;

	operations = 0;
	while (!is_sorted(*stack_a))
	{
		max_i = ft_lst_find(*stack_a, ft_find_max(*stack_a));
		if (max_i < ft_lstsize(*stack_a) / 2 + 1)
			operations += rab(stack_a, 'a', 1);
		else
			operations += rrab(stack_a, 'a', 1);
	}
	return (operations);
}

int	sort_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	operations;

	operations = 0;
	if (ft_lstsize(*stack_a) == 3)
		return (sort_stack_of_three(stack_a));
	else if (ft_lstsize(*stack_a) == 4)
	{
		operations += pb(stack_a, stack_b);
		operations += sort_stack_of_three(stack_a);
		operations += push_back_stack_a(stack_a, stack_b);
		operations += sort_stack_a(stack_a);
		return (operations);
	}
	else
		return (swap_top(stack_a, 'a', 1));
}
