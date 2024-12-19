/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:08:30 by nax_lyk           #+#    #+#             */
/*   Updated: 2024/12/19 17:00:29 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_content(t_list **head)
{
	t_list		*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		ft_printf("%d\n", *(int*)tmp->content);
		tmp = tmp->next;
	}
}

void	ft_push_swap(char **inputs)
{
	t_list		*stack_a;
	t_list		*stack_b;

	if (!check_inputs(inputs))
		return ;
	stack_a = init_stack(inputs);
	stack_b = NULL;

/*
	ft_printf("----STACK A :\n");
	print_stack_content(&stack_a);
	ft_printf("----STACK B :\n");
	print_stack_content(&stack_b);

	//swap_top(&stack_a);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	ss(&stack_a, &stack_b);

	ft_printf("----METHODS----\n");
	ft_printf("----STACK A :\n");
	print_stack_content(&stack_a);
	ft_printf("----STACK B :\n");
	print_stack_content(&stack_b);
*/
	
	ft_lstclear(&stack_a, free);
	//ft_lstclear(&stack_b, free);
	return ;
}

int		main(__attribute__((unused))int ac, char **av)
{
	ft_push_swap(&av[1]);
}
