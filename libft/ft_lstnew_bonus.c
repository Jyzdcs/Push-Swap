/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:24:46 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/29 16:24:46 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(void	*content)
{
	t_stack		*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	t_list	*node = ft_lstnew("salut");
	t_list	*tmp = node;

	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}
*/