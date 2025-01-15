/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:08:30 by nax_lyk           #+#    #+#             */
/*   Updated: 2025/01/06 23:53:27 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (*stack->content < *min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*find_closest_bigger(t_stack *node_b, t_stack *stack_a)
{
	t_stack	*closest_bigger;
	t_stack	*tmp;
	int		diff_bw;
	int		tmp_diff_bw;

	diff_bw = 2147483647;
	closest_bigger = stack_a;
	tmp = stack_a;
	while (stack_a)
	{
		if (*stack_a->content > *node_b->content)
		{
			tmp_diff_bw = *stack_a->content - *node_b->content;
			if (tmp_diff_bw < diff_bw)
			{
				diff_bw = tmp_diff_bw;
				closest_bigger = stack_a;
			}
		}
		stack_a = stack_a->next;
	}
	if (diff_bw == 2147483647)
		return (ft_find_min(tmp));
	return (closest_bigger);
}

int	turk_algo(t_stack **stack_a, t_stack **stack_b)
{
	int		operations;
	t_stack	*cheapest;

	operations = 0;
	if (ft_lstsize(*stack_a) < 5)
		return (sort_small_stack(stack_a, stack_b));
	else
	{
		operations += pb(stack_a, stack_b);
		operations += pb(stack_a, stack_b);
		while (ft_lstsize(*stack_a) != 3)
		{
			cheapest = find_cheapest(*stack_a, *stack_b);
			operations += bring_cheap_to_top(cheapest, stack_b, stack_a);
		}
		operations += sort_stack_of_three(stack_a);
		while (ft_lstsize(*stack_b) != 0)
			operations += push_back_stack_a(stack_a, stack_b);
		operations += sort_stack_a(stack_a);
	}
	return (operations);
}

void	ft_push_swap(char **inputs)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!check_inputs(inputs))
		return ;
	stack_a = init_stack(inputs);
	stack_b = NULL;
	if (is_sorted(stack_a))
	{
		ft_lstclear(&stack_a, free);
		ft_lstclear(&stack_b, free);
		return ;
	}
	turk_algo(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return ;
}

int	main(__attribute__((unused))int ac, char **av)
{
	char	**inputs;

	if (ac > 1)
	{
		if (!av[2])
		{
			if (!ft_strlen(av[1]))
				return (0);
			inputs = ft_split(av[1], ' ');
			ft_push_swap(inputs);
			free_all_ptr(inputs);
		}
		else
			ft_push_swap(&av[1]);
	}
}
