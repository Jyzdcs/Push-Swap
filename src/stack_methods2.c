/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:42:24 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/06 23:55:26 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr(t_stack **top_a, t_stack **top_b)
{
	rab(top_a, 'a', 0);
	rab(top_b, 'b', 0);
	ft_printf("rr\n");
	return (1);
}

int	rrab(t_stack **top, char c, int dis)
{
	t_stack	*prev;
	t_stack	*curr;

	if (!*top)
		return (0);
	if (dis)
		ft_printf("rr%c\n", c);
	curr = *top;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *top;
	*top = curr;
	return (1);
}

int	rrr(t_stack **top_a, t_stack **top_b)
{
	rrab(top_a, 'a', 0);
	rrab(top_b, 'b', 0);
	ft_printf("rrr\n");
	return (1);
}
