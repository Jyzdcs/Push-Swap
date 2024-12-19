/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:34:27 by kclaudan          #+#    #+#             */
/*   Updated: 2024/12/19 16:23:31 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_list **top_a)
{
	t_list		*tmp;

	if (!*top_a || !(*top_a)->next)
		return ;
	tmp = *top_a;
	*top_a = tmp->next;
	tmp->next = tmp->next->next;
	(*top_a)->next = tmp;
}

void	ss(t_list **top_a, t_list **top_b)
{
	swap_top(top_a);
	swap_top(top_b);
}

void	pa(t_list **top_a, t_list **top_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (!*top_b)
		return ;
	tmp_a = *top_a;
	tmp_b = *top_b;
	*top_b = tmp_b->next;
	*top_a = tmp_b;
	(*top_a)->next = tmp_a;
}

void	pb(t_list **top_a, t_list **top_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (!top_a)
		return ;
	tmp_a = *top_a;
	tmp_b = *top_b;
	*top_a = tmp_a->next;
	*top_b = tmp_a;
	(*top_b)->next = tmp_b;
}

void	rab(t_list **top)
{
	t_list	*tmp;
	t_list	*last_node;

	if (!*top)
		return ;
	last_node = ft_lstlast(*top);
	tmp = *top;
	*top = (*top)->next;
	last_node->next = tmp;
	tmp->next = NULL;
}

void	rr(t_list **top_a, t_list **top_b)
{
	rab(top_a);
	rab(top_b);
}

void	rrab(t_list **top)
{
	t_list	*prev;
	t_list	*curr;

	if (!*top)
		return ;
	curr = *top;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}

	prev->next = NULL;
	curr->next = *top;
	*top = curr;
}

void	rrr(t_list **top_a, t_list **top_b)
{
	rrab(top_a);
	rrab(top_b);
}