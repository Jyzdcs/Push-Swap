/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:24:29 by kclaudan          #+#    #+#             */
/*   Updated: 2024/12/29 17:44:16 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_negative_num(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) < 2 && str[i] == '-')
		return (0);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int		check_str_content(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
				return (0);
		i++;
	}
	return (1);
}

int		check_are_nums(char **inputs)
{
	int		i;

	i = 0;
	while (inputs[i])
	{
		if (!check_str_content(inputs[i]))
		{
			if (!is_negative_num(inputs[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

int		check_num_duplicate(char **inputs)
{
	int		i;
	int		j;

	i = 0;
	while (inputs[i])
	{
		j = i + 1;
		while (inputs[j])
		{
			if (ft_atoi(inputs[j]) == ft_atoi(inputs[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_inputs(char **inputs)
{
	if (!check_are_nums(inputs) || !check_num_duplicate(inputs))
	{
		ft_printf("ERROR\n");
		return (0);
	}
	return (1);
}