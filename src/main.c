/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:08:30 by nax_lyk           #+#    #+#             */
/*   Updated: 2024/12/30 14:32:11 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks_content(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a && stack_b)
		{
			ft_printf("%d   %d\n", *stack_a->content, *stack_b->content);
			stack_a = stack_a->next;
			stack_b = stack_b->next;
		}
		else if (stack_a && !stack_b)
		{
			ft_printf("%d   .\n", *stack_a->content);
			stack_a = stack_a->next;
		}
		else
		{
			ft_printf(".   %d\n", *stack_b->content);
			stack_b = stack_b->next;
		}
	}
}

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

void	sort_stack_of_three(t_stack **stack_a)
{
	t_stack		*max;

	max = ft_find_max(*stack_a);
	while (*ft_lstlast(*stack_a)->content != *max->content)
		rab(stack_a);
	if (!is_sorted(*stack_a))
		swap_top(stack_a);
}

int		ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int		find_closest_smaller(t_stack *node_a, t_stack *stack_b)
{
	int		closest_smaller;
	int		diff_bw;
	int		tmp_diff_bw;
	
	diff_bw = ft_abs(*node_a->content - *stack_b->content);
	closest_smaller = *stack_b->content;
	while (stack_b)
	{
		tmp_diff_bw = ft_abs(*node_a->content - *stack_b->content);
		if (tmp_diff_bw < diff_bw)
		{
			diff_bw = tmp_diff_bw;
			closest_smaller = *stack_b->content;
		}
		stack_b = stack_b->next;
	}
	return (closest_smaller);
}

void	turk_algo(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) == 4)
	{
		pb(stack_a, stack_b);
		sort_stack_of_three(stack_a);
	}
	else 
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
}

void	ft_push_swap(char **inputs)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (!check_inputs(inputs))
		return ;
	stack_a = init_stack(inputs);
	stack_b = NULL;
	
	turk_algo(&stack_a, &stack_b);
	print_stacks_content(stack_a, stack_b);
	printf("smallest closer of '%d' is '%d'", *stack_a->content, find_closest_smaller(stack_a, stack_b));
	// ft_printf("\n\n----BEFORE OPERATIONS----\n");
	// ft_printf("------\n");
	// print_stacks_content(stack_a, stack_b);

	// turk_algo(&stack_a, &stack_b);

	// ft_printf("----AFTER OPERATIONS----\n");
	// ft_printf("------\n");
	// print_stacks_content(stack_a, stack_b);


	ft_lstclear(&stack_a, free);
	//ft_lstclear(&stack_b, free);
	return ;
}

int		main(__attribute__((unused))int ac, char **av)
{
	ft_push_swap(&av[1]);
}
