/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:52:04 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/03 13:35:16 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (*stack_a->content > *stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

t_stack		*ft_find_max(t_stack *stack)
{
	t_stack		*max;

	max = stack;
	while (stack)
	{
		if (*stack->content > *max->content)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

int		ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int		ft_lst_find(t_stack *stack, t_stack *node_to_find)
{
	int		i;

	i = 1;
	if (!stack)
		return (-1);
	while (stack)
	{
		if (*stack->content == *node_to_find->content)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

int		sort_stack_of_three(t_stack **stack_a)
{
	t_stack		*max;
	int			operations;

	operations = 0;
	max = ft_find_max(*stack_a);
	while (*ft_lstlast(*stack_a)->content != *max->content)
	{
		operations++;
		rab(stack_a);
	}
	if (!is_sorted(*stack_a))
	{
		operations++;
		swap_top(stack_a);
		printf("sa\n");
	}
	return (operations);
}