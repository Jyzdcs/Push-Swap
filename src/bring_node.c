/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:31:56 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/06 22:31:56 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bring_target_to_top(t_stack *target, t_stack **stack_b)
{
	int	size_b;
	int	target_i;
	int	operations;

	operations = 0;
	target_i = ft_lst_find(*stack_b, target);
	size_b = ft_lstsize(*stack_b);
	while (target_i != 1)
	{
		if (target_i <= size_b / 2 + 1)
			operations += rab(stack_b, 'b', 1);
		else
			operations += rrab(stack_b, 'b', 1);
		target_i = ft_lst_find(*stack_b, target);
	}
	return (operations);
}

static int	opti(t_stack **s_b, t_stack **s_a, t_stack *target, t_stack *cheap)
{
	int	cheapest_i;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*s_a);
	size_b = ft_lstsize(*s_b);
	cheapest_i = ft_lst_find(*s_a, cheap);
	if (cheapest_i <= size_a / 2 + 1
		&& ft_lst_find(*s_b, target) <= size_b / 2 + 1
		&& ft_lst_find(*s_b, target) != 1)
		return (rr(s_a, s_b));
	else if (cheapest_i > size_a / 2 + 1
		&& ft_lst_find(*s_b, target) > size_b / 2 + 1)
		return (rrr(s_a, s_b));
	else
		return (0);
}

int	bring_cheap_to_top(t_stack *cheapest, t_stack **stack_b, t_stack **stack_a)
{
	int		cheapest_i;
	t_stack	*target;
	int		operations;
	int		size_a;

	target = find_closest_smaller(cheapest, *stack_b);
	operations = 0;
	cheapest_i = ft_lst_find(*stack_a, cheapest);
	size_a = ft_lstsize(*stack_a);
	while (cheapest_i != 1)
	{
		if (opti(stack_b, stack_a, target, cheapest))
			operations++;
		else if (cheapest_i <= size_a / 2 + 1)
			operations += rab(stack_a, 'a', 1);
		else
			operations += rrab(stack_a, 'a', 1);
		cheapest_i = ft_lst_find(*stack_a, cheapest);
	}
	operations += bring_target_to_top(target, stack_b);
	operations += pb(stack_a, stack_b);
	return (operations);
}
