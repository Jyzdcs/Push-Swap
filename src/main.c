/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:08:30 by nax_lyk           #+#    #+#             */
/*   Updated: 2024/12/18 20:23:29 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_content(t_list **head)
{
	t_list		*tmp;

	tmp = *head;
	while (tmp->next != NULL)
	{
		ft_printf("%d\n", *(int*)tmp->content);
		tmp = tmp->next;
	}
}

void	ft_push_swap(int *arr)
{
	(void)arr;
	return ;
}

int		main(int ac, char **av)
{
	(void)ac;
	t_list		*stack_a;

	stack_a = initialize(av);
	
	print_stack_content(&stack_a);
	ft_lstclear(&stack_a, free);
}
