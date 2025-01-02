/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:08:30 by nax_lyk           #+#    #+#             */
/*   Updated: 2025/01/02 01:22:00 by kclaudan         ###   ########.fr       */
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

t_stack		*find_closest_smaller(t_stack *node_a, t_stack *stack_b)
{
	t_stack		*closest_smaller;
	t_stack		*tmp;
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

int		ft_lst_find(t_stack *stack, t_stack *node_to_find)
{
	int		i;

	i = 0;
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

int		count_operations(int size, int index, t_stack *node, t_stack *stack_b)
{
	int			nb_operations;
	int			tmp_index;
	t_stack		*closest_smallest;

	nb_operations = 0;
    if (index <= size / 2 + 1)
        nb_operations += index - 1;
    else
        nb_operations += size - index + 1;
	if (!node || !stack_b)
		return (nb_operations);
	closest_smallest = find_closest_smaller(node, stack_b);
	tmp_index = ft_lst_find(stack_b, closest_smallest) + 1;
	if (tmp_index == index || (tmp_index == ft_lstsize(stack_b) && index > size / 2 + 1))
		return (nb_operations);
	nb_operations += count_operations(ft_lstsize(stack_b), tmp_index, NULL, NULL);
	return (nb_operations);
}

t_stack		*find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	int			cheapest_operations;
	int			index;
	t_stack		*cheapest_node;
	int			size;

	index = 1;
	size = ft_lstsize(stack_a);
	cheapest_operations = count_operations(size, index, stack_a, stack_b);
	cheapest_node = stack_a;
	stack_a = stack_a->next;
	printf("%d : %d\n", *cheapest_node->content, cheapest_operations);
	while (stack_a)
	{
		index++;
		printf("%d : %d\n", *stack_a->content, count_operations(size, index, stack_a, stack_b));
		if (cheapest_operations > count_operations(size, index, stack_a, stack_b))
		{
			cheapest_operations = count_operations(size, index, stack_a, stack_b);
			cheapest_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (cheapest_node);
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
		pb(stack_a, stack_b);
		printf("Cheapest node number is %d\n", *find_cheapest(*stack_a, *stack_b)->content);
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
	// ft_printf("\n\n----BEFORE OPERATIONS----\n");
	// ft_printf("------\n");
	// print_stacks_content(stack_a, stack_b);

	// turk_algo(&stack_a, &stack_b);

	// ft_printf("----AFTER OPERATIONS----\n");
	// ft_printf("------\n");
	// print_stacks_content(stack_a, stack_b);


	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return ;
}

int		main(__attribute__((unused))int ac, char **av)
{
	printf("----------------------\n");
	ft_push_swap(&av[1]);
}
