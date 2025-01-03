/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:08:30 by nax_lyk           #+#    #+#             */
/*   Updated: 2025/01/03 13:25:27 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*ft_find_min(t_stack *stack)
{
	t_stack		*min;

	min = stack;
	while (stack)
	{
		if (*stack->content < *min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

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

t_stack		*find_closest_bigger(t_stack *node_b, t_stack *stack_a)
{
	t_stack		*closest_bigger;
	t_stack		*tmp;
	int		diff_bw;
	int		tmp_diff_bw;
	
	diff_bw = ft_abs(*node_b->content - *stack_a->content);
	closest_bigger = stack_a;
	tmp = stack_a;
	while (stack_a)
	{
		tmp_diff_bw = ft_abs(*node_b->content - *stack_a->content);
		if (tmp_diff_bw < diff_bw && *stack_a->content > *node_b->content)
		{
			diff_bw = tmp_diff_bw;
			closest_bigger = stack_a;
		}
		stack_a = stack_a->next;
	}
	if (*node_b->content > *closest_bigger->content)
		return (ft_find_min(tmp));
	return (closest_bigger);
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
	tmp_index = ft_lst_find(stack_b, closest_smallest);
	if (tmp_index == index || (tmp_index == ft_lstsize(stack_b) && index >= tmp_index))
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
	//printf("%d : %d\n", *stack_a->content, count_operations(size, index, stack_a, stack_b));
	stack_a = stack_a->next;
	while (stack_a)
	{
		index++;
		//printf("%d : %d\n", *stack_a->content, count_operations(size, index, stack_a, stack_b));
		if (cheapest_operations > count_operations(size, index, stack_a, stack_b))
		{
			cheapest_operations = count_operations(size, index, stack_a, stack_b);
			cheapest_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (cheapest_node);
}

int		bring_target_to_top(t_stack *target, t_stack **stack_b)
{
	int		size_b;
	int		target_i;
	int		operations;

	operations = 0;
	target_i = ft_lst_find(*stack_b, target);
	size_b = ft_lstsize(*stack_b);
	while (target_i != 1)
	{
		if (target_i <= size_b / 2 + 1)
		{
			rab(stack_b);
			printf("rb\n");
		}
		else
		{
			rrab(stack_b);
			printf("rrb\n");
		}
		target_i = ft_lst_find(*stack_b, target);
		operations++;
	}
	return (operations);
}

int		bring_cheapest_to_top(t_stack *cheapest, t_stack **stack_b, t_stack **stack_a)
{
	int		cheapest_i;
	int		target_i;
	int		operations;
	int		size_a;

	operations = 1;
	cheapest_i = ft_lst_find(*stack_a, cheapest);
	target_i = ft_lst_find(*stack_b, find_closest_smaller(cheapest, *stack_b));
	size_a = ft_lstsize(*stack_a);
	while (cheapest_i != 1)
	{
		if (target_i == cheapest_i || (target_i == ft_lstsize(*stack_b) && cheapest_i >= target_i))
		{
			rr(stack_a, stack_b);
			printf("rr\n");
		}
		else if (cheapest_i <= size_a / 2 + 1)
		{
			rab(stack_a);
			printf("ra\n");
		}
		else
		{
			rrab(stack_a);
			printf("rra\n");
		}
		cheapest_i = ft_lst_find(*stack_a, cheapest);
		operations++;
	}
	operations += bring_target_to_top(find_closest_smaller(cheapest, *stack_b), stack_b);
	pb(stack_a, stack_b);
	printf("pb\n");
	return (operations);
}

int		push_back_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*closest_bigger;
	int			operations;
	int			target_i;
	int			size_a;

	operations = 1;
	closest_bigger = find_closest_bigger(*stack_b, *stack_a);
	target_i = ft_lst_find(*stack_a, closest_bigger);
	size_a = ft_lstsize(*stack_a);
	while (target_i != 1)
	{
		if (target_i > size_a / 2 + 1)
		{
			rrab(stack_a);
			printf("rra\n");
		}
		else
		{
			rab(stack_a);
			printf("ra\n");
		}
		operations++;
		target_i = ft_lst_find(*stack_a, closest_bigger);
	}
	return (operations);
}

int		turk_algo(t_stack **stack_a, t_stack **stack_b)
{
	int		operations;

	operations = 0;
	if (ft_lstsize(*stack_a) == 4)
	{
		pb(stack_a, stack_b);
		sort_stack_of_three(stack_a);
	}
	else 
	{
		operations = 2;
		pb(stack_a, stack_b);
		printf("pb\npb\n");
		pb(stack_a, stack_b);
		while (ft_lstsize(*stack_a) != 3)
		{
			t_stack		*cheapest = find_cheapest(*stack_a, *stack_b);
			//printf("Cheapest node number is %d\n", *cheapest->content);
			operations += bring_cheapest_to_top(cheapest, stack_b, stack_a);
		}
		operations += sort_stack_of_three(stack_a);
		while (ft_lstsize(*stack_b) != 0)
		{
			operations += push_back_stack_a(stack_a, stack_b);
			pa(stack_a, stack_b);
			printf("pa\n");
		}
		while (!is_sorted(*stack_a))
		{
			printf("ra\n");
			rab(stack_a);
		}
	}
	return (operations);
}

void	ft_push_swap(char **inputs)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (!check_inputs(inputs))
		return ;
	stack_a = init_stack(inputs);
	stack_b = NULL;
	
//	printf("BEFORE TURK ALGO\n");
	printf("nb operations : %d\n", turk_algo(&stack_a, &stack_b));
//	printf("\nAFTER TURK ALGO\n");
	print_stacks_content(stack_a, stack_b);

	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return ;
}

int		main(__attribute__((unused))int ac, char **av)
{
	printf("----------------------\n");
	ft_push_swap(&av[1]);
}
