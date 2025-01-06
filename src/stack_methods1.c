/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:34:27 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/06 19:42:17 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		swap_top(t_stack **top_a, char c, int dis)
{
	t_stack		*tmp;

	if (dis)
		ft_printf("s%c\n", c);
	if (!*top_a || !(*top_a)->next)
		return (0);
	tmp = *top_a;
	*top_a = tmp->next;
	tmp->next = tmp->next->next;
	(*top_a)->next = tmp;
	return (1);
}

int		ss(t_stack **top_a, t_stack **top_b)
{
	swap_top(top_a, 'a', 0);
	swap_top(top_b, 'b', 0);
	ft_printf("ss\n");
	return (1);
}

int		pa(t_stack **top_a, t_stack **top_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	ft_printf("pa\n");
	if (!*top_b)
		return (0);
	tmp_a = *top_a;
	tmp_b = *top_b;
	*top_b = tmp_b->next;
	*top_a = tmp_b;
	(*top_a)->next = tmp_a;
	return (1);
}

int		pb(t_stack **top_a, t_stack **top_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (!top_a)
		return 0;
	ft_printf("pb\n");
	tmp_a = *top_a;
	tmp_b = *top_b;
	*top_a = tmp_a->next;
	*top_b = tmp_a;
	(*top_b)->next = tmp_b;
	return (1);
}

int		rab(t_stack **top, char c, int dis)
{
	t_stack	*tmp;
	t_stack	*last_node;

	if (!*top || !(*top)->next)
		return (0);
	if (dis)
		ft_printf("r%c\n", c);
	last_node = ft_lstlast(*top);
	tmp = *top;
	*top = (*top)->next;
	last_node->next = tmp;
	tmp->next = NULL;
	return (1);
}
