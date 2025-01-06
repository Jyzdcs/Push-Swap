/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:08:57 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/06 22:08:57 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_closest_smaller(t_stack *node_a, t_stack *stack_b)
{
	t_stack	*closest_smaller;
	t_stack	*tmp;
	int		diff_bw;
	int		tmp_diff_bw;

	diff_bw = ft_abs(*node_a->content - *stack_b->content);
	closest_smaller = stack_b;
	tmp = stack_b;
	while (stack_b)
	{
		tmp_diff_bw = ft_abs(*node_a->content - *stack_b->content);
		if (tmp_diff_bw < diff_bw && *stack_b->content < *node_a->content)
		{
			diff_bw = tmp_diff_bw;
			closest_smaller = stack_b;
		}
		stack_b = stack_b->next;
	}
	if (*node_a->content < *closest_smaller->content)
		return (ft_find_max(tmp));
	return (closest_smaller);
}

int	opti_handler(int ops_a, int ops_b)
{
	if (ops_a >= ops_b)
		return (ops_a);
	else
		return (ops_b);
}

int	count_operations(int size_a, int index_a, t_stack *node, t_stack *stack_b)
{
	int		ops_a;
	int		ops_b;
	int		i_b;
	int		size_b;
	t_stack	*closest_smallest;

	ops_a = 0;
	ops_b = 0;
	size_b = ft_lstsize(stack_b);
	closest_smallest = find_closest_smaller(node, stack_b);
	i_b = ft_lst_find(stack_b, closest_smallest);
	if (index_a <= size_a / 2 + 1)
		ops_a = index_a - 1;
	else
		ops_a = size_a - index_a + 1;
	if (i_b == index_a || (i_b == ft_lstsize(stack_b) && index_a >= i_b))
		return (ops_a);
	if (i_b <= size_b / 2 + 1)
		ops_b = i_b - 1;
	else
		ops_b = size_b - i_b + 1;
	if ((index_a <= size_a / 2 + 1 && i_b <= size_b / 2 + 1)
		|| (index_a > size_a / 2 + 1 && i_b > size_b / 2 + 1))
		return (opti_handler(ops_a, ops_b));
	return (ops_a + ops_b);
}

t_stack	*find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	int		cheapest_operations;
	int		i;
	t_stack	*cheapest_node;
	int		size;

	i = 1;
	size = ft_lstsize(stack_a);
	cheapest_operations = count_operations(size, i, stack_a, stack_b);
	cheapest_node = stack_a;
	stack_a = stack_a->next;
	while (stack_a)
	{
		i++;
		if (cheapest_operations > count_operations(size, i, stack_a, stack_b))
		{
			cheapest_operations = count_operations(size, i, stack_a, stack_b);
			cheapest_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (cheapest_node);
}

int	push_back_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*closest_bigger;
	int		operations;
	int		target_i;
	int		size_a;

	operations = 0;
	closest_bigger = find_closest_bigger(*stack_b, *stack_a);
	target_i = ft_lst_find(*stack_a, closest_bigger);
	size_a = ft_lstsize(*stack_a);
	while (target_i != 1)
	{
		if (target_i > size_a / 2 + 1)
			operations += rrab(stack_a, 'a', 1);
		else
			operations += rab(stack_a, 'a', 1);
		target_i = ft_lst_find(*stack_a, closest_bigger);
	}
	operations += pa(stack_a, stack_b);
	return (operations);
}
