/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:19:59 by kclaudan          #+#    #+#             */
/*   Updated: 2024/12/19 15:51:16 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*free_stack(t_list *node, t_list *tmp)
{
	ft_lstdelone(tmp, &free);
	ft_lstclear(&node, free);
	return (NULL);
}

t_list		*create_node_with_int(int nb)
{
	int		*nb_ptr;
	t_list	*tmp;

	nb_ptr = malloc(sizeof(int));
	if (!nb_ptr)
	{
		free(nb_ptr);
		return (NULL);
	}
	*nb_ptr = nb;
	tmp = ft_lstnew(nb_ptr);
	return (tmp);
}

t_list		*init_stack(char **values)
{
	t_list	*node;
	t_list	*tmp;
	int		i;

	if (!values)
		return (NULL);
	node = create_node_with_int(ft_atoi(values[0]));
	if (!node)
		return (NULL);
	i = 1;
	while (values[i] != NULL)
	{
		tmp = create_node_with_int(ft_atoi(values[i]));
		if (!tmp)
			return (free_stack(node, tmp));
		ft_lstadd_back(&node, tmp);
		i++;
	}
	return (node);
}
